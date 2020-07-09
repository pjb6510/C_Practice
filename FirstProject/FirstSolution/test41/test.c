#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main()
{
	/*
		Union
		- Store different data types in the same memory sapce
		- Structure vs Union
	*/

	union my_union
	{
		int i;
		double d;
		char c;
	};

	union my_union uni;

	// 구조체와 공용체의 차이 : 구조체 - 내부 멤버들이 메모리를 따로따로 점유하고 있음, 공용체 - 내부 멤버들이 메모리를 같이 사용하고 있음.(서로 다른 타입이더라도)
	// 즉 구조체는 여러 변수를 모아놓은 그룹에 가깝지만, 공용체는 여러 타입을 가진 하나의 변수임.

	printf("%zd\n", sizeof(union my_union));
	printf("%lld\n",(long long)&uni);
	printf("%lld %lld %lld\n", (long long)&uni.i, (long long)&uni.d, (long long)&uni.c);
	
}