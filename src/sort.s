	.file	"sort.c"
	.text
	.p2align 4,,15
	.globl	bubbleSort
	.type	bubbleSort, @function
bubbleSort:
.LFB0:
	.cfi_startproc
	movl	%esi, %r9d
	subl	$1, %r9d
	je	.L1
	leal	-2(%rsi), %eax
	xorl	%r8d, %r8d
	leaq	(%rdi,%rax,8), %r10
	movl	%r9d, %edi
	subq	%rax, %rdi
	.p2align 4,,10
	.p2align 3
.L5:
	movq	%r10, %rax
	movl	%r9d, %edx
	.p2align 4,,10
	.p2align 3
.L4:
	movq	(%rax), %rcx
	movq	(%rax,%rdi,8), %rsi
	subl	$1, %edx
	cmpq	%rsi, %rcx
	jle	.L3
	movq	%rsi, (%rax)
	movq	%rcx, (%rax,%rdi,8)
.L3:
	subq	$8, %rax
	cmpl	%r8d, %edx
	ja	.L4
	addl	$1, %r8d
	cmpl	%r9d, %r8d
	jne	.L5
.L1:
	ret
	.cfi_endproc
.LFE0:
	.size	bubbleSort, .-bubbleSort
	.ident	"GCC: (Debian 8.3.0-6) 8.3.0"
	.section	.note.GNU-stack,"",@progbits
