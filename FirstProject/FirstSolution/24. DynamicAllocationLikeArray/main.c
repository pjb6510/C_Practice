#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
	int row = 1000, col = 10;
	int* ptr = (int*)malloc(row * col * sizeof(int));
	if (!ptr) exit(1);

	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
			ptr[c + col * r] = c + col * r;
	}

	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
			printf("%d ", *(ptr + c + col * r));
		printf("\n");
	}
	
	return 0;
}

