	.file	"test.c"
	.text
	.def	_printf;	.scl	3;	.type	32;	.endef
_printf:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$36, %esp
	leal	12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %ebx
	movl	$1, (%esp)
	movl	__imp____acrt_iob_func, %eax
	call	*%eax
	movl	%ebx, 8(%esp)
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	___mingw_vfprintf
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	ret
	.globl	_a
	.data
	.align 4
_a:
	.long	2
	.globl	_b
	.align 4
_b:
	.long	3
	.globl	_c
	.bss
	.align 4
_c:
	.space 4
	.globl	_d
	.align 4
_d:
	.space 4
	.globl	_e
	.align 4
_e:
	.space 4
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "c = %d, d = %d, e = %d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$16, %esp
	call	___main
	movl	_a, %edx
	movl	_b, %eax
	subl	%eax, %edx
	movl	%edx, _c
	movl	_b, %eax
	sall	$2, %eax
	movl	%eax, _d
	movl	_e, %ecx
	movl	_d, %edx
	movl	_c, %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	$0, %eax
	leave
	ret
	.ident	"GCC: (GNU) 13.2.0"
	.def	___mingw_vfprintf;	.scl	2;	.type	32;	.endef
