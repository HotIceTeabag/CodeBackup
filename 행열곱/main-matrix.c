#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "matrix.h"

int main() {
    srand(time(0));
    int row1, col1, row2, col2, order;
    bool zero = false;

    printf("행, 열, 행2, 열2\nOrder: ");
    scanf_s("%d %d %d %d", &row1, &col1, &row2, &col2);
    
    int* mat1 = calloc(row1 * col1, sizeof(int)),
        * mat2 = calloc(row2 * col2, sizeof(int));
    float* answer;

    printf("1: 희소행렬, 0: 일반행렬\nOrder: ");
    scanf_s("%d", &order);
    zero = (order != 0);
    
    genmat(mat1, row1, col1, zero);
    genmat(mat2, row2, col2, zero);

    printf("1: 덧셈, 2 : 뺄셈, 3 : 나눗셈, 4 : 곱셈, 5 : 희소행렬, 6 : 전치행렬\nOrder : ");
    scanf_s("%d", &order);

    clock_t start;
    clock_t end;
    switch (order) {
    case 1:
        answer = calloc(row1 * col1, sizeof(float));
        start = clock();
        mat_plus(mat1, mat2, answer, row1, col1);
        end = clock();
        break;

    case 2:
        answer = calloc(row1 * col1, sizeof(float));
        start = clock();
        mat_minus(mat1, mat2, answer, row1, col1);
        end = clock();
        break;

    case 3:
        answer = calloc(row1 * col1, sizeof(float));
        start = clock();
        mat_divide(mat1, mat2, answer, row1, col1);
        end = clock();
        break;

    case 4:
        answer = calloc(row1 * col2, sizeof(float));
        start = clock();
        mat_mult(mat1, mat2, answer,row1, col1, col2);
        end = clock();
        break;

    case 5:
        free(mat2);
        break;

    case 6:
        answer = calloc(col1 * row1, sizeof(float));
        start = clock();
        mat_reverse(mat1, answer, row1, col1, zero);
        end = clock();
        break;

    default:
        break;
    }

    
    if (order == 5 && zero){
            answer = calloc(1, sizeof(float));

            int ser = search(mat1, row1, col1);
            int** arr = (int**)malloc((ser + 1) * sizeof(int*));
            for (int i = 0; i < ser + 1; i++) arr[i] = (int*)malloc(3 * sizeof(int));

            start = clock();
            aa(arr, search(mat1, row1, col1), mat1, row1, col1);
            end = clock();
            
            printf("rows: %2d cols: %2d cont: %2d\n", arr[0][0], arr[0][1], arr[0][2]);/*
            for (int i = 1; i <= ser; i++) {
                printf("row: %2d col: %2d val: %2d\n", arr[i][0], arr[i][1], arr[i][2]);
            }*/
            free(arr);
    }
    printf("소요 시간: %.20lf\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(mat1);
    if(order != 5)free(mat2);
    free(answer);
	return 0;
}
