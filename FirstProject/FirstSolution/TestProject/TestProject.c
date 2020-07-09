#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
	int i = 0;
	int hour = 0;
	int min = 0;
	int sec = 0;
	int temp = 0;

	printf("Input seconds : ");
	scanf("%d", &i);

	hour = i / 3600;
	temp = i % 3600;
	min = temp / 60;
	sec = temp % 60;


	return 0;
}