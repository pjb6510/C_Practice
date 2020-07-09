#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

void swap(int* xp, int* yp)
{
	int temp;
	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d\t", arr[i]);
	}
}

void selectionSort(int arr[], int size)
{
	int min_idx = 0;
	for (int i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[min_idx] > arr[j])
				min_idx = j;
		}
		swap(&arr[i], &arr[min_idx]);
	}
}

int main()
{
	int arr[] = { 13,14,18,51,26,74,10,5,1,100 };
	int size = sizeof(arr) / sizeof(arr[0]);

	selectionSort(arr, size);
	printArray(arr, size);

	return 0;
}

