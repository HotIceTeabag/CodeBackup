#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "matrix.h"


/*
³­¼ö¸¦ 0~99 ¹üÀ§¿¡¼­ »ý¼ºÇÏ¿© È®·üÀ» ¼³Á¤
int randomValue = rand() % 100;
*/

int main() {
    srand(time(0));
    int row1, col1, row2, col2, order;
    bool zero = false;

    printf("Çà, ¿­, Çà2, ¿­2\nOrder: ");
    scanf_s("%d %d %d %d", &row1, &col1, &row2, &col2);
    
    int* mat1 = calloc(row1 * col1, sizeof(int)),
        * mat2 = calloc(row2 * col2, sizeof(int));
    float* answer = calloc(row1 * col2, sizeof(float));

    printf("1: Èñ¼ÒÇà·Ä, 0: ÀÏ¹ÝÇà·Ä\nOrder: ");
    scanf_s("%d", &order);
    zero = (order != 0);
    
    genmat(mat1, row1, col1, zero);
    genmat(mat2, row2, col2, zero);

    printf("1: µ¡¼À, 2 : »¬¼À, 3 : ³ª´°¼À, 4 : °ö¼À\nOrder : ");
    scanf_s("%d", &order);

    clock_t start;

    switch (order) {
    case 1:

        start = clock();
        mat_plus(mat1, mat2, answer, row1, col1);
        break;

    case 2:

        start = clock();
        mat_minus(mat1, mat2, answer, row1, col1);
        break;

    case 3:

        start = clock();
        mat_divide(mat1, mat2, answer, row1, col1);
        break;

    case 4:

        start = clock();
        mat_mult(mat1, mat2, answer,row1, col1, col2);
        break;

    case 5:

        start = clock();
        break;

    case 6:

        start = clock();
        break;

    default:
        break;
    }
    
    clock_t end = clock();
    printf("¼Ò¿ä ½Ã°£: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

    /*
    printf("mat1:\n");
    printmat(mat1, row1, col1);
    printf("\n");

    printf("mat2:\n");
    printmat(mat2, row2, col2);
    printf("\n");
    
    printf("answer:\n");
    printans(answer, row1, col2);
    */
    if (zero) {
        int arr[search(mat1, row1, col1) + 1][3];
        aa(arr, search(mat1, row1, col1) + 1, mat1, row1, col1);

        for (int i = 0; i <= search(mat1, row1, col1); i++)printf("row: %2d col: %2d val: %2d\n", arr[i][0], arr[i][1], arr[i][2]);
    }



    free(mat1);
    free(mat2);
    free(answer);
	return 0;
}