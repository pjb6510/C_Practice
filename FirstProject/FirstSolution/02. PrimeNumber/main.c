#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	unsigned num;
	bool isPrime = true;
	
	scanf("%u", &num);
	
	for (int i = 2; i < num; i++) {
		if (num % i == 0)
		{
			isPrime = false;
			printf("%d 는 %d 로 나누어집니다.\n", num, i);
		}
	}

	if (isPrime)
		printf("%u 은(는) 소수입니다. \n", num);
	else
		printf("%u 은(는) 소수가 아닙니다. \n", num);

	return 0;
}
