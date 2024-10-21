#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "matrix.h"


/*
������ 0~99 �������� �����Ͽ� Ȯ���� ����
int randomValue = rand() % 100;
*/

int main() {
    srand(time(0));
    int row1, col, row2, col2, order;
    bool zero = false;

    printf("��, ��, ��2, ��2\nOrder: ");
    scanf_s("%d %d %d %d", &row1, &col, &row2, &col2);
    
    int *mat1 = calloc(row1*col, sizeof(int)),
        *mat2 = calloc(col*col2, sizeof(int)),
        *answer = calloc(row1*col2, sizeof(int));

    printf("1: ������, 0: �Ϲ����\nOrder: ");
    scanf_s("%d", &order);
    zero = (order != 0);
    
    genmat(mat1, row1, col, zero);
    genmat(mat2, row2, col2, zero);

    printf("1: ����, 2 : ����, 3 : ������, 4 : ����\nOrder : ");
    scanf_s("%d", &order);

    clock_t start = clock();

    switch (order) {
    case 1:
        mat_plus(mat1, mat2, answer, row1, col);
        break;

    case 2:
        mat_minus(mat1, mat2, answer, row1, col);
        break;

    case 3:
        mat_divide(mat1, mat2, answer, row1, col);
        break;

    case 4:
        mat_mult(mat1, mat2, answer,row1, col, col2);
        break;

    case 5:

        break;

    case 6:

        break;

    default:
        break;
    }
    
    clock_t end = clock();
    printf("�ҿ� �ð�: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);


    printf("mat1:\n");
    printmat(mat1, row1, col2);
    printf("\n");
    
    printf("mat2:\n");
    printmat(mat2, col, col2);
    printf("\n");
    
    printf("answer:\n");
    printmat(answer, row1, col2);

    free(mat1);
    free(mat2);
    free(answer);
	return 0;
}