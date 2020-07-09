#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
	Unions and Structures
*/

struct personal_owner
{
	char rrn1[7]; // 주민등록번호 : 830422-1185600
	char rrn2[8];
};

struct company_owner
{
	char crn1[4]; // 법인등록번호 : 111 - 22 - 33333
	char crn2[3];
	char crn3[6];
};

struct car_data
{
	char model[15];
	int status; // 0 = personal, 1 = company
	union {
		struct personal_owner po;
		struct company_owner co;
	};
};

void print_car(struct car_data car)
{
	printf("----------------------------------------\n");
	printf("Car model : %s\n", car.model);

	if (car.status == 0)
		printf("Personal owner : %s-%s\n", car.po.rrn1, car.po.rrn2);
	else
		printf("Company owner : %s-%s-%s\n",
			car.co.crn1, car.co.crn2, car.co.crn3);
	printf("----------------------------------------\n");
}

int main()
{
	struct car_data my_car = { .model = "Avante", .status = 0, .po = {"830422", "1185600"} };
	struct car_data company_car = { .model = "Sonata", .status = 1, .co = {"111", "22", "33333"} };

	print_car(my_car);
	print_car(company_car);

	return 0;
}