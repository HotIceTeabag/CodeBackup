LC0:	#���ڿ� ����� LC0 ���� ����
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
	#leng(�迭 ���� �Է�)
	leal	24(%esp), %eax		#eax�� ebp-4����
	movl	%eax, 4(%esp)		#
	movl	$LC0, (%esp)		#%d �÷��׸� ������ ù ��° ���ڷ� ����
	call	_scanf				#�Է¹���
	#mkarr(�迭 �����Ҵ� �� �����Լ�) �Էº�
	movl	24(%esp), %eax
	movl	%eax, (%esp)		#ù ��° ���ڷ� leng ����
	call	_mkarr
	movl	%eax, 28(%esp)		#��ȯ�� ����
	#val(ã�� �� �Է�),
	leal	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_scanf
	#���� ���� �� �Լ� ����
	movl	20(%esp), %eax
	movl	%eax, 8(%esp)
	movl	24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	28(%esp), %eax
	movl	%eax, (%esp)		#�迭
	call	binser
	#����
	leave
	ret


binser:
	pushl	%ebp					#main�Լ��� ebp ���ÿ� Ǫ��
	movl	%esp, %ebp				#������ esp�� ebp�� �Ҵ�
	subl	$16, %esp				#�������� 4�� ���� �Ҵ�

	movl	$0, -4(%ebp)			#0�� ebp -4�� �Ҵ�(low)

	movl	12(%ebp), %eax			#leng���� eax�� �Ҵ�
	subl	$1, %eax				#eax-1 �������
	movl	%eax, -8(%ebp)			#eax�� ebp-8�� �Ҵ�(high)

	jmp	While

Search:
	#mid���� ó��
	movl	-4(%ebp), %edx
	movl	-8(%ebp), %eax
	addl	%edx, %eax
	shrl	$1, %eax
	movl	%eax, -12(%ebp)			#eax�� mid �Ҵ�
	#�迭 ó����
	movl    8(%ebp, %eax, 4), %eax
	#�񱳿���
	movl    16(%ebp), %edx
	cmpl	%eax, %edx				#arr[mid]�� �� ° ���� ��
	jne	If_left						#�� ��� not equal�̸� If_left��
	movl	-12(%ebp), %eax			#equal�� ��쿡 eax�� mid�� �Ҵ� �� End�� ����
	jmp	End	

If_left:
	#���ǹ�
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	#movl    8(%ebp, %eax, 4), %eax
	#movl	-8(%ebp), %edx
	cmpl	%eax, %edx
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
	movl	-4(%ebp), %eax
	cmpl	-8(%ebp), %eax		#elow�� high '�񱳸� ��'
	jle	Search					#less or equal�̸� ����
	movl	$-1, %eax			#-1 ���ϰ� ����

End:
	movl	$LC0, (%esp)
	call	_printf
	leave
	ret