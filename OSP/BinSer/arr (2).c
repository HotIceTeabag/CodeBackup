#include <stdio.h>
#include <stdlib.h>
#include "comb.h"

/*
1) C���� ���� ���α׷��� �ۼ��� �� ����� �ڵ带 �м��ϱ�

-�迭�� �Է����� �޾� �����ϴ� �Լ��� �ۼ��ϵ� ������ �ҽ� ���Ϸ� �и��� ��

2) ���� Ž�� �˰����� ����� ���α׷����� �����ϱ�
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