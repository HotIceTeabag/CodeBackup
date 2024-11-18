LC0:	#인자에 사용할 LC0 사전 정의
	.ascii "%d\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef


_main:
	#스택 프레임 설정
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	#leng(배열 길이 입력)
	leal	24(%esp), %eax		#eax에 ebp-4전달
	movl	%eax, 4(%esp)		#
	movl	$LC0, (%esp)		#%d 플래그를 스택의 첫 번째 인자로 전달
	call	_scanf				#입력받음
	#mkarr(배열 동적할당 및 정렬함수) 입력부
	movl	24(%esp), %eax
	movl	%eax, (%esp)		#첫 번째 인자로 leng 전달
	call	_mkarr
	movl	%eax, 28(%esp)		#반환값 전달
	#val(찾을 값 입력),
	leal	20(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_scanf
	#인자 전달 및 함수 실행
	movl	20(%esp), %eax
	movl	%eax, 8(%esp)
	movl	24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	28(%esp), %eax
	movl	%eax, (%esp)		#배열
	call	binser
	#종료
	leave
	ret


binser:
	pushl	%ebp					#main함수의 ebp 스택에 푸쉬
	movl	%esp, %ebp				#기존의 esp를 ebp에 할당
	subl	$16, %esp				#지역변수 4개 공간 할당

	movl	$0, -4(%ebp)			#0을 ebp -4에 할당(low)

	movl	12(%ebp), %eax			#leng값을 eax에 할당
	subl	$1, %eax				#eax-1 산술연산
	movl	%eax, -8(%ebp)			#eax값 ebp-8에 할당(high)

	jmp	While

Search:
	#mid변수 처리
	movl	-4(%ebp), %edx
	movl	-8(%ebp), %eax
	addl	%edx, %eax
	shrl	$1, %eax
	movl	%eax, -12(%ebp)			#eax에 mid 할당
	#배열 처리부
	movl    8(%ebp, %eax, 4), %eax
	#비교연산
	movl    16(%ebp), %edx
	cmpl	%eax, %edx				#arr[mid]와 셋 째 인자 비교
	jne	If_left						#비교 결과 not equal이면 If_left로
	movl	-12(%ebp), %eax			#equal인 경우에 eax에 mid값 할당 후 End로 점프
	jmp	End	

If_left:
	#조건문
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movl	(%eax), %eax
	#movl    8(%ebp, %eax, 4), %eax
	#movl	-8(%ebp), %edx
	cmpl	%eax, %edx
	jle	Else						#인자 <= arr[mid]인(거짓인) 경우 Else로 이동 
	#참인 경우
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
	cmpl	-8(%ebp), %eax		#elow와 high '비교만 함'
	jle	Search					#less or equal이면 점프
	movl	$-1, %eax			#-1 리턴값 설정

End:
	movl	$LC0, (%esp)
	call	_printf
	leave
	ret