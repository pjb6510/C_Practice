#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

/*
	Fibonacci sequence
	1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144

	ex) fibonacci(5) = 3 + 2 = fibonacci(4) + fibonacci(3)

*/

int fibonacci_loop(int n)
{
	int index;
	int sum;
	int temp;
	int before;
	for (int index = 1; index <= n;index++)
	{
		if (index == 1 || index == 2)
		{
			sum = 1;
			before = 1;
		}
		else
		{
			temp = sum;
			sum += before;
			before = temp;
		}
	}
	return sum;
}

int fibonacci(int n)
{
	/* 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 */
	int sec = 1;
	
	if (n > 2)
	{
		sec = fibonacci(n - 1) + fibonacci(n - 2);
	}
	return sec;

	//메모리 및 속도 비효율!
}

int main()
{
	int number;
	for (int i = 1; i <= 40; i++)
	{
		number = fibonacci(i);
		printf("%d ", number);
	}
}

