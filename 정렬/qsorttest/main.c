#include <stdio.h>

#include <stdlib.h>

void QuickSorat(int list[], int left, int right) {
	int i, j, pivot;
	int temp;

	if (left < right) {
		pivot = list[left];
		i = left, j = right + 1;

		do{
			do {
				i++;
			} while (list[i] > pivot);

			do {
				j--;
			} while (list[j] < pivot);

			if (i < j) {
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		} while (i < j);

		{
			temp = list[left];
			list[left] = list[j];
			list[j] = temp;
		}
		QuickSort(list, left, j - 1);
		QuickSort(list, j + 1, right);
	}
}

void QuickSort(int arr[], int low, int high) {
	int i, j, temp;
	int pivot;
	if (low < high) {
		i = low;
		j = high + 1;
		pivot = arr[i];
		
		do {
			do {
				i++;
			} while (arr[i] < pivot);

			do {
				j--;
			} while (arr[j] > pivot);

			if (i < j) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}


		} while (i < j);
		
		{
			temp = arr[low];
			arr[low] = arr[j];
			arr[j] = temp;
		}

		QuickSort(arr, low, j - 1);
		QuickSort(arr, j + 1, high);
	}
}

int main() {
	
	int arr[] = { 2,22,11,234,23,6,74,654,234,36,44,5698,3,1,50,30,60,70,80 };
	int leng = 18;

	QuickSort(arr, 0, leng);

	for (int i = 0; i <= leng; i++) {
		printf("%d\t", arr[i]); 
	}
	
}