#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

void printarr(int* arr, int leng) {
	for (int i = 0; i < leng; i++) {
		if (i % 20 == 0)printf("\n");
		printf("%8d", *(arr + i));
	}
}

void genarr(int* arr, int leng) {
	for (int i = 0; i < leng; i++) {
		*(arr + i) = rand() % 10000;
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

void selection(int* arr, int leng) {
	int most_small;
	for (int i = 0; i < leng - 1; i++) {
		most_small = i;
		for (int j = i+1; j < leng; j++) {
			if (arr[j] < arr[most_small])most_small = j;
		}
		swap(arr + i, arr + most_small);
	}
}

void insertion(int* arr, int leng) {
	int num, val;
	for (int i = 1; i < leng; i++) {
		val = arr[i];
		num = i;
		while (num > 0 && arr[num - 1] > val) {
			arr[num] = arr[num - 1];
			num--;
		}
		arr[num] = val;
	}
}
