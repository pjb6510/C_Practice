#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // exit()
#include <string.h> // strlen()
#include <math.h> //pow()

unsigned char to_decimal(const char bi[]);

int main()
{
	printf("Binary (string) to Decimal conversion\n");

	printf("%d\n", to_decimal("00000110"));
	printf("%d\n", to_decimal("00010110"));

	printf("%d\n", to_decimal("10010100"));
}

unsigned char to_decimal(const char bi[])
{
	unsigned int p;
	size_t n = strlen(bi);
	unsigned int result = 0;

	size_t i = 0;

	while (i < n)
	{
		p = (int)pow(2, n-i-1);
		if (bi[i] == '1')
			result += p;
		++i;
	}

	return result;
}