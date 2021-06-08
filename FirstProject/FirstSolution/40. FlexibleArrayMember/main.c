#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main()
{
	struct flex
	{
		size_t count;
		double average;
		double values[]; // 반드시 마지막 멤버여야 한다, 동적할당을 해야한다.
	};

	const size_t n = 3;

	struct flex* pf = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
	if (pf == NULL) exit(1);
	// 구조체의 크기에 추가로 배열로 사용하고 싶은 길이 만큼 동적할당을 받아야함.
	// double vlaues[]에 추가로 3만큼 더 사용하고 싶음.

	printf("\nFlexible array member\n");
	printf("Sizeof struct flex %zd\n", sizeof(struct flex));
	printf("Sizeof *pf %zd\n", sizeof(*pf));
	printf("Sizeof malloc %zd\n", sizeof(struct flex) + n * sizeof(double));

	printf("%lld\n", (long long)&pf->average);
	printf("Address of pf->valuees %lld\n", (long long)&pf->values);
	printf("Value of pf->values %lld\n", (long long)pf->values);
	printf("Sizoef pf->values %zd\n", sizeof(pf->values));

	pf->count = n;
	// 동적할당을 한 번 받고나면 그 이후 사이즈를 측정할 수 없음. 그러므로 count에 몇 칸을 배정받았는지 대입해두기.
	pf->values[0] = 1.1;
	pf->values[1] = 1.1;
	pf->values[2] = 1.1;

	pf->average = 0.0;
	for (unsigned i = 0; i < pf->count; ++i)
		pf->average += pf->values[i];
	pf->average /= (double)pf->count;

	printf("Average = %f\n", pf->average);

	/*flexible array member 사용과 
	멤버 중 하나를 동적할당 배열로 사용하는 것의 차이 :
	
	1. flexible array member의 경우 추가 메모리가 연속적으로 붙음. 동적할당배열의 경우 어느 위치의 메모리가 할당될지 모름.
	2. flexible array member의 경우 마지막 배열 멤버의 메모리 용량이 카운트되지 않음. 동적할당배열의 경우 마지막 멤버(포인터)의 용량이 카운트됨.

	*/
}