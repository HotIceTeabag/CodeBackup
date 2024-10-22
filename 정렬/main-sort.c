#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "sort.h"

int main() {
    srand(time(0));
    int leng, order;
    bool zero = false;

    printf("배열의 길이\nOrder: ");
    scanf_s("%d", &leng);

    int* arr = calloc(leng, sizeof(int));

    printf("1: 버블, 2 : 인설션, 3 : 셀렉션\nOrder : ");
    scanf_s("%d", &order);

    clock_t start, end;

    switch (order) {
    case 1:
        for (int i = 0; i < 5; i++) {
            genarr(arr, leng);
            start = clock();
            bubble(arr, leng);
            end = clock();
            printf("소요 시간: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
        }
        break;

    case 2:
        for (int i = 0; i < 5; i++) {
            genarr(arr, leng);
            start = clock();
            insertion(arr, leng);
            end = clock();
            printf("소요 시간: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
        }
        break;

    case 3:
        for (int i = 0; i < 5; i++) {
            genarr(arr, leng);
            start = clock();
            selection(arr, leng);
            end = clock();
            printf("소요 시간: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
        }
        break;

    default:
        break;
    }

    printf("소요 시간: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

    //printarr(arr, leng);

    free(arr);
    return 0;
}