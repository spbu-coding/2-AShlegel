#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN_KEY_FROM 7
#define LEN_KEY_TO 5
#define SUITABLE_COMPLETELY 2

extern void bubbleSort(long long *array, unsigned size);

struct option {
	int exists;
	long long val;
};

int find_val(char *str, int len_key) {
    int val = 0;
    str += len_key;
    while(*str >= '0' && *str <= '9')
        val = val * 10 + *(str++) - '0';
    return val;
}

int capture_opt(char *str, struct option *opt_from, struct option *opt_to) {
    if (!strncmp("--from=", str, LEN_KEY_FROM)) {
        if (opt_from->exists)
            return -3;
        else {
            opt_from->exists = 1;
            opt_from->val = find_val(str, LEN_KEY_FROM);
        }
    }else if (!strncmp("--to=", str, LEN_KEY_TO)) {
        if (opt_to->exists)
            return -3;
        else {
            opt_to->exists = 1;
            opt_to->val = find_val(str, LEN_KEY_TO);
        }
    }
    return 0;
}

unsigned filtration(long long *array, struct option *opt_from, struct option *opt_to){
    unsigned elems_count = 0;
    long long a;
    while(scanf("%lld", &a) == 1) {
        int suitable_a = 0;
        if (opt_from->exists && opt_from->val >= a)
            fprintf(stdout, "%lld ", a);
        else
            suitable_a++;
        if (opt_to->exists && opt_to->val <= a)
            fprintf(stderr, "%lld ", a);
        else
            suitable_a++;
        if (suitable_a == SUITABLE_COMPLETELY) {
            array[elems_count] = a;
            elems_count++;
        }
    }
    return elems_count;
}

int compare_arrays(long long *array1, long long *array2, unsigned size){
    int diffrence_count = 0;
    while(size--){
        if(array1[size] != array2[size])
            diffrence_count++;
    }
    return diffrence_count;
}

int main(int argc,char* argv[]) {
    if (argc < 2)
        return -1;
    else if (argc > 3)
        return -2;

    struct option opt_from = {0, 0};
    struct option opt_to = {0, 0};

    capture_opt(argv[1], &opt_from, &opt_to);
    if (argc == 3 && capture_opt(argv[2], &opt_from, &opt_to))
        return -3;
    if (!opt_from.exists && !opt_to.exists)
        return -4;

    long long primary_array[100];

    unsigned elems_count = filtration(primary_array, &opt_from, &opt_to);

    if (elems_count == 0)
        return 0;

    long long sorted_array[100];
    memcpy(sorted_array, primary_array, sizeof(long long) * elems_count);
    bubbleSort(sorted_array, elems_count);

    return compare_arrays(primary_array, sorted_array, elems_count);
}
