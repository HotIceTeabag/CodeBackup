	.file	"arr.c"
	.text
	.globl	_bubble
	.def	_bubble;	.scl	2;	.type	32;	.endef
_bubble:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$0, -4(%ebp)
	jmp	L2
L6:
	movl	$0, -8(%ebp)
	jmp	L3
L5:
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-8(%ebp), %eax
	addl	$1, %eax
	leal	0(,%eax,4), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jle	L4
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	-8(%ebp), %eax
	addl	$1, %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movl	(%edx), %edx
	movl	%edx, (%eax)
	movl	-8(%ebp), %eax
	addl	$1, %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%eax)
L4:
	addl	$1, -8(%ebp)
L3:
	movl	12(%ebp), %eax
	subl	-4(%ebp), %eax
	subl	$1, %eax
	cmpl	%eax, -8(%ebp)
	jl	L5
	addl	$1, -4(%ebp)
L2:
	movl	12(%ebp), %eax
	subl	$1, %eax
	cmpl	%eax, -4(%ebp)
	jl	L6
	nop
	nop
	leave
	ret
	.section .rdata,"dr"
LC0:
	.ascii "%d\0"
LC1:
	.ascii "%d \0"
	.text
	.globl	_mkarr
	.def	_mkarr;	.scl	2;	.type	32;	.endef
_mkarr:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	8(%ebp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	%eax, -20(%ebp)
	movl	$0, -12(%ebp)
	jmp	L8
L9:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_scanf
	addl	$1, -12(%ebp)
L8:
	movl	-12(%ebp), %eax
	cmpl	8(%ebp), %eax
	jl	L9
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_bubble
	movl	$0, -16(%ebp)
	jmp	L10
L11:
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-20(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	addl	$1, -16(%ebp)
L10:
	movl	-16(%ebp), %eax
	cmpl	8(%ebp), %eax
	jl	L11
	movl	$10, (%esp)
	call	_putchar
	movl	-20(%ebp), %eax
	leave
	ret
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-Builds project) 14.2.0"
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_putchar;	.scl	2;	.type	32;	.endef
