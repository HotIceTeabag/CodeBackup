/*
Problem 1:	두 다항식을 입력받아 가감(덧셈,뺄셈)을 수행하는 프로그램의 설계

Problem 2:	다항식의 입력형태가 있어야하며 다항식의 표현방법을 두 가지 이상 설계하여야 하며,
			각 자료구조에 따른 다항식의 덧셈을 테스트

Problem 3:	다항식의 가감을 수행하는 함수로 확장시켜 설계된 프로그램의 테스트

1차로, 두 다항식의 입력 설계-> 링크드 리스트 통해 다항식 자료구조 구현

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "poly.h"


int main(void) {
	int order;
	int dim = 1, val = 1;
	
	printf("배열을 이용한 다항식: 1\n링크드 리스트를 이용한 다항식: 2\nOrder: ");
	scanf("%d", &order);

	switch (order) {
		case 1:
			printf("1번 입력됨!");





			printf("구현 안 됐지롱!");

			break;
		default:
			printf("2번 입력됨!");

			polyList p1 = NULL, p2 = NULL;			//다항식 선언

			printf("첫 번쨰 다항식 입력(0 0입력시 입력 종료)\n");
			int index = 1;
			while (dim != 0 || val != 0) {					//dim과 val 다 0을 입력받기 전까지 반복
				printf("%d번째 입력, 차수, 계수 입력: ", index);
				scanf("%d %d", &dim, &val);
				if (val != 0)insert(&p1, dim, val);
				else if(dim != 0) printf("0을 곱하면 의미가 없어요!\n");
				index++;
			}

			printf("두 번쨰 다항식 입력(0 0입력시 덧셈 실행)\n");
			index = 1;
			dim = val = 1;
			while (dim != 0 || val != 0) {					//dim과 val 다 0을 입력받기 전까지 반복
				printf("%d번째 입력, 차수, 계수 입력: ", index);
				scanf("%d %d", &dim, &val);
				if (val != 0)insert(&p2, dim, val);
				else if(dim != 0) printf("0을 곱하면 의미가 없어요!\n");
				index++;
			}

			polyList answer = NULL;
			
			printf("첫 다항식: \n");
			prt_poly(p1);
			printf("두 번째 다항식: \n");
			prt_poly(p2);

			add_poly(&answer, p1, p2);
			printf("덧셈 결과: \n");
			prt_poly(answer);

			free_list(p1);
			free_list(p2);
			free_list(answer);
			break;
	}








	return 0;
}
