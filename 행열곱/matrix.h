#ifndef MATRIX_H
#define MATRIX_H

typedef struct mat {
	int row;
	int col;
	int value;
}maat;

void printmat(int* mat, int row, int col);
void printans(float* mat, int row, int col);

int search(int* arr, int row, int col);
void aa(int arr[][3], int number/*0이 아닌 값을 갯수 + 1*/, int* mat, int row, int col);

void trans(maat* matarr, int number);

void genmat(int* mat, int row, int col, bool zero);

void mat_plus(int* mat1, int* mat2, float* answer, int row, int col);
void mat_minus(int* mat1, int* mat2, float* answer, int row, int col);
void mat_divide(int* mat1, int* mat2, float* answer, int row, int col);
void mat_mult(int* mat1, int* mat2, float* answer, int row, int col, int col2);

#endif