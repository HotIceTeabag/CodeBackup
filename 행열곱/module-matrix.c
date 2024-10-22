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

void printans(float* mat, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)printf("%6.3f\t", *(mat + i * col + j));
		printf("\n");
	}
}

int search(int* arr, int row, int col) {
	int count = 0;

	for (int i = 0; i < row * col; i++) {
		if (*(arr + i))count++;
	}
	return count;
}

void aa(int arr[][3], int number/*0ÀÌ ¾Æ´Ñ °ªÀ» °¹¼ö + 1*/, int* mat, int row, int col) {
	arr[0][0] = row; // ÃÑ ÇàÀÇ ¼ö
	arr[0][1] = col; // ÃÑ ¿­ÀÇ ¼ö
	arr[0][2] = number-1;

	int index = 1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (*(mat + i * col + j) != 0) {
				arr[index][0] = i;
				arr[index][1] = j;
				arr[index][2] = *(mat + i * col + j);

				index++;
				if (index == number)return;
			}
		}
	}
	
}

void genmat(int* mat, int row, int col, bool zero) {
	int a;

	if (zero)for (int i = 0; i < row * col; i++) {
		a = rand() % 10;
		if (a < 8) *(mat + i) = 0;
		else *(mat + i) = (rand() % 10) + 1;
	}
	else {
		for (int i = 0; i < row * col; i++) *(mat + i) = (rand() % 10) + 1;
	}
}

void mat_plus(int* mat1, int* mat2, float* answer, int row, int col) {
	for (int i = 0; i < row * col; i++)*(answer + i) = *(mat1 + i) + *(mat2 + i);
}

void mat_minus(int* mat1, int* mat2, float* answer, int row, int col) {
	for (int i = 0; i < row * col; i++)*(answer + i) = *(mat1 + i) - *(mat2 + i);
}

void mat_divide(int* mat1, int* mat2, float* answer, int row, int col) {
	for (int i = 0; i < row * col; i++)*(answer + i) = (float)*(mat1 + i) / (float)*(mat2 + i);
}

void mat_mult(int* mat1, int* mat2, float* answer, int row, int col, int col2) {

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