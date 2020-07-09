#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

unsigned char to_decimal(const char bi[]);
void print_binary(const unsigned char num);

int main()
{
	print_binary(-127);
	print_binary(~127+1);
	print_binary(127);
	printf("\n");

	print_binary(-12);
	print_binary(~12 + 1);
	print_binary(12);
	printf("\n");

	print_binary(-7);
	print_binary(~7 + 1);
	print_binary(7);
	print_binary(~-7 + 1);

	//2의 보수 : -n = ~n + 1
}

unsigned char to_decimal(const char bi[])
{
	unsigned int p;
	size_t n = strlen(bi);
	unsigned int result = 0;

	size_t i = 0;

	while (i < n)
	{
		p = (int)pow(2, n - i - 1);
		if (bi[i] == '1')
			result += p;
		++i;
	}

	return result;
}

void print_binary(const char num)
{
	int max = 7;
	if (abs(num) > (int)pow(2,max))
		printf("plz input value less than %d\n", (int)pow(2, max));
	else
	{
		printf("%d\t == Binary ", num);
		for (int i = max; i >= 0; i--)
		{
			int bits = num;
			int mask = (int)pow(2, i);
			if ((bits & mask) == mask)
				printf("1");
			else
				printf("0");
		}
		printf("\n");
	}
}

// for문에서 size_t 타입의 i를 쓸 경우, 감소하는 방향으로는 사용해선 안 됨.(0 아래로 내려가면 최대값으로 회귀하기 때문)