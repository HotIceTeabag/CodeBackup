#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "matrix.h"


void printmat(int* mat, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)printf("%3d", *(mat + i * col + j));
		printf("\n");
	}
}

void genmat(int* mat, int row, int col, bool zero) {
	int a;
	if (zero)for (int i = 0; i < row * col; i++) {
		a = rand() % 10;
		if (a < 6) *(mat + i) = 0;
		else *(mat + i) = (rand() % 10) + 1;
	}
	else {
		for (int i = 0; i < row * col; i++) *(mat + i) = (rand() % 10) + 1;
	}
}

void mat_plus(int* mat1, int* mat2, int* answer, int row, int col) {
	for (int i = 0; i < row * col; i++)*(answer + i) = *(mat1 + i) + *(mat2 + i);
}

void mat_minus(int* mat1, int* mat2, int* answer, int row, int col) {
	for (int i = 0; i < row * col; i++)*(answer + i) = *(mat1 + i) - *(mat2 + i);
}

void mat_divide(int* mat1, int* mat2, int* answer, int row, int col) {
	for (int i = 0; i < row * col; i++)*(answer + i) = *(mat1 + i) / *(mat2 + i);
}

void mat_mult(int* mat1, int* mat2, int* answer, int row, int col, int col2) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col2; j++) {
			for (int k = 0; k < col; k++) {
				*(answer + i * col2 + j) +=
					*(mat1 + i * col + k) *
					*(mat2 + k * col2 + j);
			}
		}
	}
}