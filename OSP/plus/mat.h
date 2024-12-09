#ifndef MATRIX_H
#define MATRIX_H


void printmat(int* mat, int row, int col);
void genmat(int* mat, int row, int col);

void mat_mult_old(int* mat1, int* mat2, int* answer, int row, int col, int col2);
void mat_mult_new(int* mat1, int* mat2, int* answer, int row, int col, int col2);

#endif