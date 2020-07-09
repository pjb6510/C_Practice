#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define FUNDLEN 50

struct fortune {
	char bank_name[FUNDLEN];
	double bank_saving;
	char fund_name[FUNDLEN];
	double fund_saving;
};

double sum(struct fortune *my_fortune);

int main()
{
	struct fortune my_fortune = {
		"Wells-Fargo",
		4032.27,
		"JPMorgan Chase",
		8543.94
	};

	printf("Total : $%.2f.\n",
		sum(&my_fortune)
	);
}


double sum(const struct fortune *mf)
{
	double result = 0.0f;
	result = (*mf).bank_saving + (*mf).fund_saving;
	return result;
}

/*
	구조체를 함수에 전달 할 때, 파라미터로 구조체 자체를 넣으면 구조체가 파라미터로 전달될 때, 값들이 복사가 됨.
	모든 값을 복사하기 때문에 구조체의 내용이 방대하면, 프로그램이 느려질 수 있음.
	그러므로 보통 함수에 구조체를 전달 할 때는 포인터를 사용함.
	포인터로 넘겼을 때는 구조체 내부 값을 변경할 것이 아니라면 파라미터에 const를 붙여주는 것이 좋음.
	(구조체 내부 값을 변경하려 할 경우 컴파일러가 차단해줌.)
*/