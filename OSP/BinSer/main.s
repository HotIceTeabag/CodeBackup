	.file	"main.c"
	.text
	.p2align 4
	.globl	binser
	.def	binser;	.scl	2;	.type	32;	.endef
	.seh_proc	binser

binser:
	subl	$1, %edx
	js	.L6
	xorl	%r9d, %r9d
	jmp	.L5

.L9:
	leal	1(%rax), %r9d
	cmpl	%r9d, %edx
	jl	.L6
.L5:
	movl	%edx, %eax
	subl	%r9d, %eax
	sarl	%eax
	addl	%r9d, %eax
	movslq	%eax, %r10
	cmpl	%r8d, (%rcx,%r10,4)
	je	.L1
	jl	.L9
	leal	-1(%rax), %edx
	cmpl	%r9d, %edx
	jge	.L5
.L6:
	movl	$-1, %eax
.L1:
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "%d\0"
	.section	.text.startup,"x"
	.p2align 4
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main


main:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	leaq	.LC0(%rip), %rbx
	leaq	40(%rsp), %rdx
	movq	%rbx, %rcx
	call	scanf
	movl	40(%rsp), %ecx
	call	mkarr
	leaq	44(%rsp), %rdx
	movq	%rbx, %rcx
	movq	%rax, %rsi
	call	scanf
	movl	40(%rsp), %edx
	movq	%rsi, %rcx
	movl	44(%rsp), %r8d
	call	binser
	movq	%rbx, %rcx
	movl	%eax, %edx
	call	printf
	xorl	%eax, %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-Builds project) 14.2.0"
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	mkarr;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
