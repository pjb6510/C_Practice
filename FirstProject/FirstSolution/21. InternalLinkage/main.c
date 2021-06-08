#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

static int g_int = 123;
//static이라고 붙이는 것만으로도 파일외부에서 참조선언으로 가져다 쓸 수 없음.
//파일 내부에서는 다른 블록에서 쓸 수 있음.

int main()
{
	extern int g_int;
	printf("%d", g_int);
	return 0;
}

