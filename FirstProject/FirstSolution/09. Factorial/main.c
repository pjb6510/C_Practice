#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

// 답
//long loop_factorial(int n)
//{
//	for (int i=n;i>1;i--)
//	{
//		n = n * (i - 1);
//	}
//	return n;
//}
//
//long recursive_factorial(int n)
//{
//	int i = n - 1;
//	if (i != 1)
//		n*=recursive_factorial(i);
//	else
//	{
//		n *= i;
//		return n;
//	}
//	return n;
//}
// 아래는 모범답안.

long recursive_factorial(int n)
{
	if (n > 0)
	{
		return n *= recursive_factorial(n - 1);
	}
	else
		return 1;
}

int main()
{
	int n = 4;
	long result;
	result = recursive_factorial(n);
	printf("%ld", result);
	return 0;
}

