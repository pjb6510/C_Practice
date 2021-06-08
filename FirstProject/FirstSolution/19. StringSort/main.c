#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void swap(char** xp, char** yp)
{
	char* temp;
	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void printStringArray(char* arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%s\t", arr[i]);
	}
	printf("\n");
}

void selectionSort(char* arr[], int size)
{
	int min_idx;

	for (int i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (int j = i + 1; j < size; j++)
		{
			if (strcmp(arr[min_idx],arr[j]) == 1)
			{
				min_idx = j;
			}
		}
		swap(&arr[i], &arr[min_idx]);
	}
}

int main()
{
	char* arr[] = {"Cherry", "AppleBee", "Pineapple", "Apple", "Orange"};
	int size = sizeof(arr) / sizeof(arr[0]);

	printStringArray(arr, size);
	selectionSort(arr, size);
	printStringArray(arr, size);

	return 0;
}

