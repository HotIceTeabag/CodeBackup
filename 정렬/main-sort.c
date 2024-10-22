#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "sort.h"

int main() {
    srand(time(0));
    int leng, order;
    bool zero = false;

    printf("�迭�� ����\nOrder: ");
    scanf_s("%d", &leng);

    int* arr = calloc(leng, sizeof(int));

    genarr(arr, leng);

    printf("1: ����, 2 : �μ���, 3 : ������\nOrder : ");
    scanf_s("%d", &order);

    clock_t start = clock();

    switch (order) {
    case 1:
        bubble(arr, leng);
        break;

    case 2:
        insertion(arr, leng);
        break;

    case 3:
        selection(arr, leng);
        break;

    default:
        break;
    }

    clock_t end = clock();
    printf("�ҿ� �ð�: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

    printarr(arr, leng);

    free(arr);
    return 0;
}