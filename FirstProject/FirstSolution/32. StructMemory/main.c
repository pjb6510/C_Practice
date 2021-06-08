#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct Aligned
	{
		int a;		//4byte
		float b;	//4byte
		double c;	//8byte

		// 4+4+8 = 16byte
	};

	//구조체 선언에서는 메모리 할당이 이루어지지 않음.

	struct Aligned a1, a2;

	printf("struct Aligned a1\n");
	printf("Sizof %zd\n", sizeof(struct Aligned));
	printf("%lld\n", (long long)&a1);
	printf("%lld\n", (long long)&a1.a);
	printf("%lld\n", (long long)&a1.b);
	printf("%lld\n", (long long)&a1.c);

	printf("\nstruct Aligned a2\n");
	printf("Sizof %zd\n", sizeof(a2));
	printf("%lld\n", (long long)&a2);
	printf("%lld\n", (long long)&a2.a);
	printf("%lld\n", (long long)&a2.b);
	printf("%lld\n", (long long)&a2.c);

	struct Padded1
	{
		char a;		//1byte
		float b;	//4byte
		double c;	//8byte
	};

	//without padding : 1+4+8 = 13
	//with padding : 4+4+8 = 16 // char에 4byte를 할당.

	struct Padded1 p1;

	printf("\nstruct Aligned p1\n");
	printf("Sizof %zd\n", sizeof(p1));
	printf("%lld\n", (long long)&p1);
	printf("%lld\n", (long long)&p1.a);
	printf("%lld\n", (long long)&p1.b);
	printf("%lld\n", (long long)&p1.c);
}