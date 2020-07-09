#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;

}

int main()
{
	int a = 3;
	int b = 5;
	swap(&a, &b);
	printf("%d %d", a, b);

	return 0;
}

