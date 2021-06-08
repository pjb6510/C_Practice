#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

void print_binary_loop(unsigned long n)
{
	while (1) 
	{
		int j = n % 2;
		n /= 2;

		printf("%d", j);

		if (n == 0) break;
	}
	printf("%\n");
}

void print_binary(unsigned long n)
{
	int i = n / 2;
	int j = n % 2;

	if(i>0)
		print_binary(i);

	printf("%d", j);
}

int main()
{
	print_binary_loop(14);
	print_binary(14);
	return 0;
}

