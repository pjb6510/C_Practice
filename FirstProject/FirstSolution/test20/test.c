#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 10;
	int* ptr = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; ++i)
		ptr[i] = i+1;

	for (int i = 0; i < n; ++i)
		printf("%d ", ptr[i]);

	printf("\n");

	int* ptr2 = NULL;
	ptr2 = realloc(ptr, 20 * sizeof(int));

	for (int i = 0; i < 20; ++i)
		printf("%d ", ptr2[i]);

	return 0;
}

