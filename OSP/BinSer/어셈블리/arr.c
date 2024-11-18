#include <stdio.h>
#include <stdlib.h>
#include "comb.h"

/*
1) C언어로 정렬 프로그램을 작성한 후 어셈블리 코드를 분석하기

-배열을 입력으로 받아 정렬하는 함수를 작성하되 별도의 소스 파일로 분리할 것

2) 이진 탐색 알고리즘을 어셈블리 프로그램으로 구현하기
*/

void bubble(int* arr, int leng) {
	int temp;

	for (int i = 0; i < leng - 1; i++) {
		for (int j = 0; j < leng - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int* mkarr(int leng) {
	int* a = (int*)malloc(sizeof(int) * leng);

	for (int i = 0; i < leng; i++) {
		scanf("%d", &a[i]);
	}

	bubble(a, leng);

	for (int i = 0; i < leng; i++)printf("%d ", a[i]);
	printf("\n");
	return a;
}