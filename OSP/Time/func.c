#include <stdio.h>
#include <stdlib.h>
#include "mat.h"

void printmat(int* mat, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)printf("%5d", *(mat + i * col + j));
		printf("\n");
	}
}

void genmat(int* mat, int row, int col) {
	for (int i = 0; i < row * col; i++) {
		*(mat + i) = (rand() % 10);
	}
}

void mat_mult_old(int* mat1, int* mat2, int* answer, int row, int col, int col2) {

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

void mat_mult_new(int* mat1, int* mat2, int* answer, int row, int col, int col2) {
	int r;

	for (int k = 0; k < col; k++) {
		for (int i = 0; i < row; i++) {
			r = *(mat1 + i * col + k);

			for (int j = 0; j < col2; j++) {
				*(answer + i * col2 + j) += r * *(mat2 + k * col2 + j);
			}
		}
	}
}