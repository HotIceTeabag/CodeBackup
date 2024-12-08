#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mat.h"

void initialize_matrices(int* mat1, int* mat2) {
    // mat1 초기화 (2x2 행렬)
    mat1[0 * 2 + 0] = 1; // mat1[0][0]
    mat1[0 * 2 + 1] = 2; // mat1[0][1]
    mat1[1 * 2 + 0] = 3; // mat1[1][0]
    mat1[1 * 2 + 1] = 4; // mat1[1][1]

    // mat2 초기화 (2x2 행렬)
    mat2[0 * 2 + 0] = 5; // mat2[0][0]
    mat2[0 * 2 + 1] = 6; // mat2[0][1]
    mat2[1 * 2 + 0] = 7; // mat2[1][0]
    mat2[1 * 2 + 1] = 8; // mat2[1][1]
}

int main() {
    int row1, col1, row2, col2, order;

    printf("행, 열, 행2, 열2\nOrder: ");
    scanf_s("%d %d %d %d", &row1, &col1, &row2, &col2);

    int* mat1 = calloc(row1 * col1, sizeof(int)),
        * mat2 = calloc(row2 * col2, sizeof(int));
    int* answer;

    clock_t start;
    clock_t end;

    printf("Order: ");
    scanf_s("%d", &order);

    while (order < 4) {
        if (order == 1) {
            srand(999);
            genmat(mat1, row1, col1);
            genmat(mat2, row2, col2);
            /*
            printf("mat1: \n");
            printmat(mat1, row1, col1);

            printf("mat2: \n");
            printmat(mat2, row2, col2);
            */
            answer = calloc(row1 * col2, sizeof(int));

            start = clock();
            mat_mult_old(mat1, mat2, answer, row1, col1, col2);
            end = clock();
            /*
            printf("answer: \n");
            printmat(answer, row2, col2);
            */
            printf("기존 함수 소요 시간: %.20lf\n", (double)(end - start) / CLOCKS_PER_SEC);
        }
        if (order == 2) {
            srand(999);
            genmat(mat1, row1, col1);
            genmat(mat2, row2, col2);
            /*
            printf("mat1: \n");
            printmat(mat1, row1, col1);

            printf("mat2: \n");
            printmat(mat2, row2, col2);
            */
            answer = calloc(row1 * col2, sizeof(int));

            start = clock();
            mat_mult_new(mat1, mat2, answer, row1, col1, col2);
            end = clock();
            /*
            printf("answer: \n");
            printmat(answer, row2, col2);
            */
            printf("최적화 후 소요 시간: %.20lf\n", (double)(end - start) / CLOCKS_PER_SEC);
        }
        if (order == 3) {
            initialize_matrices(mat1, mat2);

            answer = calloc(row1 * col2, sizeof(int));

            mat_mult_new(mat1, mat2, answer, 2, 2, 2);

            printf("answer: \n");
            printmat(answer, row2, col2);
        }
        printf("Order: ");
        scanf_s("%d", &order);
    }

    free(mat1);
    free(mat2);
    free(answer);
    return 0;
}