#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	const double base[7] = { 0.0 , 12000000.0,46000000.0,88000000.0,150000000.0,300000000.0,500000000.0 };
	const double rate[7] = { (6.0 / 100.0),(15.0 / 100.0),(24.0 / 100.0),(35.0 / 100.0),(38.0 / 100.0),(40.0 / 100.0),(42.0 / 100.0) };
	const double basic_deduction = 1500000.0;

	double income = 0.0;
	double tax = 0.0;
	double temp = 0.0;
	int i = 0;
	int j = -1;

	scanf("%lf", &income);

	income -= basic_deduction;
	temp = income;

	//if (income <= base[1])
	//	tax = (income - base[0]) * rate[0];
	//else if (income <= base[2]) i=0,i=1  j=2 
	//	tax = (base[1] * rate[0]) + (income - base[1]) * rate[1];
	//else if (income <= base[3])
	//	tax = (base[1] * rate[0]) + (base[2] * rate[1]) + (income - base[2]) * rate[2];
	//else if (income <= base[4])
	//	tax = (base1 * rate1) + (base2 * rate2) + (base3 * rate3) + (income - base3) * rate4;

	for (i = 0;j==-1; i++) {
		if (income <= base[i])
			j = i;
	}

	for (i = 0;i+1<=j; i++) {
		if (i+1 == j)
			tax = tax + (temp - base[i]) * rate[i];
		else
			tax = tax + (base[i+1] * rate[i]);
	}

	printf("Income : %f, Tax : %f", income, tax);
}



