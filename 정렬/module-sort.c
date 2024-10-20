#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

void printarr(int* arr, int leng) {
	for (int i = 0; i < leng; i++) {
		if (i % 20 == 0)printf("\n");
		printf("%2d", *(arr + i));
	}
}

void genarr(int* arr, int leng) {
	for (int i = 0; i < leng; i++) {
		*(arr + i) = rand() % 10;
	}
}

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void bubble(int* arr, int leng) {
	for (int i = 0; i < leng - 1; i++) {
		for (int j = 0; j < leng - i - 1; j++) {
			if (arr[j] > arr[j + 1])swap(arr + j, arr + j + 1);
		}
	}
}
