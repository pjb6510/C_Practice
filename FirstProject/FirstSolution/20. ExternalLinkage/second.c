#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern int g_int;
//main.c의 g_int를 가져옴.
//전역변수의 초기화는 file_scope에서만 가능. block_scope에선 불가능.
//어느 한 파일에서 전역변수가 초기화 되었다면, 다른 곳에선 불가능.
//(g_int가 선언된 main.c에서 초기화가 되지 않았다면 second.c에서도 초기화 가능)

void temp()
{
	g_int += 1000;
}

void fun_sec()
{
	temp();

	g_int += 7;
	printf("g int in fun_sec() %d %p \n", g_int, &g_int);
}

