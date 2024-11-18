	.file	"main.c"
	.text
	.section .rdata,"dr"
LC0:
	.ascii "%d\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef

_main:
	#���� ������ ����
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	call	___main

	#leng(�迭 ���� �Է�), ebp-4�� ��ġ
	leal	-4(%ebp), %eax		#eax�� ebp-4����
	movl	%eax, 4(%esp)		#
	movl	$LC0, (%esp)		#%d �÷��׸� ������ ù ��° ���ڷ� ����
	call	_scanf				#�Է¹���

	#mkarr(�迭 �����Ҵ� �� �����Լ�) �Էº�
	movl	-4(%ebp), %eax
	movl	%eax, (%esp)		#ù ��° ���ڷ� leng ����
	call	_mkarr
	movl	%eax, -8(%ebp)		#��ȯ�� ebp-8����

	#val(ã�� �� �Է�),		ebp-12�� ��ġ
	leal	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_scanf

	#���� ���� �� �Լ� ����
	movl	-8(%ebp), %eax
	movl	%eax, (%esp)
	movl	-4(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	call	binser

	#��ȯ�� ���
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	$0, %eax

	#����
	leave
	ret



binser:
	pushl	%ebp					#main�Լ��� ebp ���ÿ� Ǫ��
	movl	%esp, %ebp				#������ esp�� ebp�� �Ҵ�
	subl	$16, %esp				#�������� 4�� ���� �Ҵ�

	movl	$0, -4(%ebp)			#0�� ebp -4�� �Ҵ�(low)

	movl	12(%ebp), %eax			#ebp+12���� eax�� �Ҵ�
	subl	$1, %eax				#eax-1 �������
	movl	%eax, -8(%ebp)			#eax�� ebp-8�� �Ҵ�(high)

	jmp	While

Search:
	#mid���� ó��
	movl	-4(%ebp), -12(%ebp)		#low�� mid��
	addl	-8(%ebp), -12(%ebp)		#mid += high
	movl	-12(%ebp), %eax
	sarl	%eax
	movl	%eax, -12(%ebp)			#eax�� mid �Ҵ�
	#�迭 ó����
	movl	0(8(%ebp),%eax,4), %eax
	#�񱳿���
	cmpl	%eax, 16(%ebp)			#arr[mid]�� �� ° ���� ��
	jne	If_left						#�� ��� not equal�̸� If_left��
	movl	-12(%ebp), %eax			#equal�� ��쿡 eax�� mid�� �Ҵ� �� End�� ����
	jmp	End	

If_left:
	#���ǹ�
	cmpl	%eax, 16(%ebp)
	jle	Else						#���� <= arr[mid]��(������) ��� Else�� �̵� 
	#���� ���
	movl	-12(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -4(%ebp)			#low = mid+1
	jmp	While

Else:
	#high = mid-1
	movl	-12(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -8(%ebp)

While:
	cmpl	-8(%ebp), -4(%ebp)		#elow�� high '�񱳸� ��'
	jle	Search						#less or equal�̸� ����
	movl	$-1, %eax			#-1 ���ϰ� ����

End:
	leave
	ret