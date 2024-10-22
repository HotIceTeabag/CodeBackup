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
    float* answer;

    printf("1: Èñ¼ÒÇà·Ä, 0: ÀÏ¹ÝÇà·Ä\nOrder: ");
    scanf_s("%d", &order);
    zero = (order != 0);
    
    genmat(mat1, row1, col1, zero);
    genmat(mat2, row2, col2, zero);

    printf("1: µ¡¼À, 2 : »¬¼À, 3 : ³ª´°¼À, 4 : °ö¼À, 5 : Èñ¼ÒÇà·Ä, 6 : ÀüÄ¡Çà·Ä\nOrder : ");
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
    
    

    /*
    printf("mat1:\n");
    printmat(mat1, row1, col1);
    printf("\n");

    //printf("mat2:\n");
    //printmat(mat2, row2, col2);
    //printf("\n");
    if (order == 6) {
        printf("answer:\n");
        printans(answer, col1, row1);
    }
    else {
        printf("answer:\n");
        printans(answer, row1, col2);
    }
    */
    
    if (order == 5 && zero){
            answer = calloc(row1 * col1, sizeof(float));
            int arr[search(mat1, row1, col1) + 1][3];

            start = clock();
            aa(arr, search(mat1, row1, col1) + 1, mat1, row1, col1);
            end = clock();
            printf("rows: %2d cols: %2d cont: %2d\n", arr[0][0], arr[0][1], arr[0][2]);
            for (int i = 1; i <= search(mat1, row1, col1); i++) {
                printf("row: %2d col: %2d val: %2d\n", arr[i][0], arr[i][1], arr[i][2]);
            }
    }

    printf("¼Ò¿ä ½Ã°£: %.20lf\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(mat1);
    free(mat2);
    free(answer);
	return 0;
}