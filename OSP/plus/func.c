#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printmat(int* mat, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)printf("%5d", *(mat + i * col + j));
		printf("\n");
	}
}

void printarr(int* arr, int leng) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)printf("%5d", *(mat + i * col + j));
		printf("\n");
	}
}

void genarr(int* arr, int leng) {
	for (int i = 0; i < leng; i++) {
		*(mat + i) = (rand() % 10);
	}
}

void sum_arr_old(int* arr, nt* answer, int leng) {

	for (int i = 0; i < row; i++) {
		
	}
}

void sum_arr_new(int* arr, int* answer, int leng) {

	for (int k = 0; k < col; k++) {
		
	}
}
