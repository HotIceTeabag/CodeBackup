#ifndef MATRIX_H
#define MATRIX_H

typedef struct mat

void printmat(int* mat, int row, int col);

void genmat(int* mat, int row, int col, bool zero);

void mat_plus(int* mat1, int* mat2, int* answer, int row, int col);

void mat_minus(int* mat1, int* mat2, int* answer, int row, int col);

void mat_divide(int* mat1, int* mat2, int* answer, int row, int col);

void mat_mult(int* mat1, int* mat2, int* answer, int row, int col, int col2);

#endif