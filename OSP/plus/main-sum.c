#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void genarr(int* arr, int leng) {
    for (int i = 0; i < leng; i++) {
        *(arr + i) = (rand() % 10);
    }
}

void printarr(int* arr, int leng) {
    for (int i = 0; i < leng; i++) {
        printf("%2d", *(arr + i));
        if (i % 10 == 9) printf("\n");
    }
}

void sum_arr_old(int* arr, unsigned long long* sum, int leng) {

    for (int i = 0; i < leng; i++) {
        *sum += arr[i];
    }
}

void sum_arr_new(int* arr, unsigned long long* sum, int leng) {

    for (int k = 0; k < leng - 1; k += 2) {
        *sum += arr[k] + arr[k + 1];
    }

    for (int k = leng - (leng % 2); k < leng; k++) {
        *sum += arr[k];
    }
}

void sum_arr_new2(int* arr, unsigned long long* sum, int leng) {

    for (int k = 0; k < leng - 2; k += 3) {
        *sum += arr[k] + arr[k + 1] + arr[k + 2];
    }

    for (int k = leng - (leng % 3); k < leng; k++) {
        *sum += arr[k];
    }
}

int main() {
    int leng, seed = 11;

    unsigned long long sum;
    unsigned long long* sumP = &sum;

    scanf_s("%d", &leng);

    int* arr1 = malloc(leng * sizeof(int));

    clock_t start;
    clock_t end;

    for (int i = 0; i < 5; i++) {
        srand(seed);
        genarr(arr1, leng);

       // printf("arr: ");
        //printarr(arr1, leng);
        //printf("\n");

        sum = 0;

        start = clock();
        sum_arr_old(arr1, sumP, leng);
        end = clock();
        printf("sum: %llu\n", sum);
        printf("하나씩 덧셈 소요시간: %.20lf\n", (double)(end - start) / CLOCKS_PER_SEC);
        printf("\n");

        //구분
        srand(seed);
        genarr(arr1, leng);

        sum = 0;

        start = clock();
        sum_arr_new(arr1, sumP, leng);
        end = clock();
        printf("sum: %llu\n", sum);
        printf("2개 루프 언롤링 소요시간: %.20lf\n", (double)(end - start) / CLOCKS_PER_SEC);
        printf("\n");

        //구분
        srand(seed);
        genarr(arr1, leng);

        sum = 0;

        start = clock();
        sum_arr_new2(arr1, sumP, leng);
        end = clock();
        printf("sum: %llu\n", sum);
        printf("3개 루프 언롤링 소요시간: %.20lf\n", (double)(end - start) / CLOCKS_PER_SEC);
        printf("\n");

        seed++;
    }


    free(arr1);
    return 0;
}