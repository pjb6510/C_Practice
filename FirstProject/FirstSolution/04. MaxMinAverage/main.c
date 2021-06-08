#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <float.h>

int main()
{
	double num = 0;
	double max = -FLT_MAX;
	double min = FLT_MAX;
	double ave = 0;
	double i = 0;

	while ((scanf("%lf", &num)) == 1) {
		if (num >= 100 || num < 0)
		{
			printf("Input is ignored\n");
			continue;
		}
		
		i++;

		if (num > max)
			max = num;
		if (num < min)
			min = num;
		ave += num;
	}
	ave /= i;

	printf("min = %lf, max = %lf, ave = %lf\n", min, max, ave);

}

