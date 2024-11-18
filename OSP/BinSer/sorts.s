	.file	"module-sort.c"
	.text
	.section .rdata,"dr"
LC0:
	.ascii "%8d\0"
	.text
	.globl	_printarr
	.def	_printarr;	.scl	2;	.type	32;	.endef
_printarr:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	$0, -12(%ebp)
	jmp	L2
L4:
	movl	-12(%ebp), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$3, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	testl	%edx, %edx
	jne	L3
	movl	$10, (%esp)
	call	_putchar
L3:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	addl	$1, -12(%ebp)
L2:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jl	L4
	nop
	nop
	leave
	ret
	.globl	_genarr
	.def	_genarr;	.scl	2;	.type	32;	.endef
_genarr:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	movl	$0, -12(%ebp)
	jmp	L6
L7:
	call	_rand
	movl	%eax, %ecx
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	leal	(%edx,%eax), %ebx
	movl	$1759218605, %edx
	movl	%ecx, %eax
	imull	%edx
	movl	%edx, %eax
	sarl	$12, %eax
	movl	%ecx, %edx
	sarl	$31, %edx
	subl	%edx, %eax
	imull	$10000, %eax, %edx
	movl	%ecx, %eax
	subl	%edx, %eax
	movl	%eax, (%ebx)
	addl	$1, -12(%ebp)
L6:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jl	L7
	nop
	nop
	movl	-4(%ebp), %ebx
	leave
	ret
	.globl	_swap
	.def	_swap;	.scl	2;	.type	32;	.endef
_swap:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %eax
	movl	%edx, (%eax)
	movl	12(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	%edx, (%eax)
	nop
	leave
	ret
	.globl	_bubble
	.def	_bubble;	.scl	2;	.type	32;	.endef



_bubble:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$0, -4(%ebp)
	jmp	L10
L14:
	movl	$0, -8(%ebp)
	jmp	L11
L13:
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
	jle	L12
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
L12:
	addl	$1, -8(%ebp)
L11:
	movl	12(%ebp), %eax
	subl	-4(%ebp), %eax
	subl	$1, %eax
	cmpl	%eax, -8(%ebp)
	jl	L13
	addl	$1, -4(%ebp)
L10:
	movl	12(%ebp), %eax
	subl	$1, %eax
	cmpl	%eax, -4(%ebp)
	jl	L14
	nop
	nop
	leave
	ret
	.globl	_selection
	.def	_selection;	.scl	2;	.type	32;	.endef



_selection:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$0, -8(%ebp)
	jmp	L16
L20:
	movl	-8(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	-8(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -12(%ebp)
	jmp	L17
L19:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	leal	0(,%eax,4), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jge	L18
	movl	-12(%ebp), %eax
	movl	%eax, -4(%ebp)
L18:
	addl	$1, -12(%ebp)
L17:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jl	L19
	movl	-4(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_swap
	addl	$1, -8(%ebp)
L16:
	movl	12(%ebp), %eax
	subl	$1, %eax
	cmpl	%eax, -8(%ebp)
	jl	L20
	nop
	nop
	leave
	ret
	.globl	_insertion
	.def	_insertion;	.scl	2;	.type	32;	.endef



_insertion:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$1, -8(%ebp)
	jmp	L22
L26:
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	movl	%eax, -12(%ebp)
	movl	-8(%ebp), %eax
	movl	%eax, -4(%ebp)
	jmp	L23
L25:
	movl	-4(%ebp), %eax
	addl	$1073741823, %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%eax, %edx
	movl	-4(%ebp), %eax
	leal	0(,%eax,4), %ecx
	movl	8(%ebp), %eax
	addl	%ecx, %eax
	movl	(%edx), %edx
	movl	%edx, (%eax)
	subl	$1, -4(%ebp)
L23:
	cmpl	$0, -4(%ebp)
	jle	L24
	movl	-4(%ebp), %eax
	addl	$1073741823, %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	cmpl	%eax, -12(%ebp)
	jl	L25
L24:
	movl	-4(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	-12(%ebp), %edx
	movl	%edx, (%eax)
	addl	$1, -8(%ebp)
L22:
	movl	-8(%ebp), %eax
	cmpl	12(%ebp), %eax
	jl	L26
	nop
	nop
	leave
	ret
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-Builds project) 14.2.0"
	.def	_putchar;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_rand;	.scl	2;	.type	32;	.endef
