#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	const const const const const const const const int n = 0;
	// const n = 0;

	typedef const int zip;
	const zip q = 8;
	// const const int zip

	float f1 = 0.0, f2 = 3.14;
	const float* pf1 = &f1;
	// *pf1 = 5.0f;//error
	pf1 = &f2;

	float* const pf2 = &f1;
	*pf2 = 6.0f;
	//pf2 = &f2;//error

	const float* const pf3 = &f1;
	// *pf3 = 2.0f; //error
	// pf3 = &f2; // error



	/*
		volatile : 
		컴파일러 니가 건드리지 마라.(초기화, 최적화(캐시메모리) 등)
		외부적인 요인으로 그 값이 언제든지 바뀔 수 있을 때 사용된다.
	*/
	volatile int vi = 1;


	/*
		restrict
		특정 메모리영역에 접근하는 포인터는 restrict로 선언한 이 포인터 하나 뿐이다.
		컴파일러에게 특정 메모리영역에 접근하는 수단이 이 포인터 외엔 없다고 알려주어,
		더 나은 최적화를 하도록 컴파일러를 도와준다.
	*/

	int ar[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* par = ar;
	//이 경우 par이라는 포인터를 통해 ar배열에 접근 가능.

	int* __restrict restar = (int*)malloc(10 * sizeof(int));
	if (!restar)exit(1);

	free(restar);


	return 0;
}

