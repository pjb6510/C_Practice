#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern int g_int;
//main.c�� g_int�� ������.
//���������� �ʱ�ȭ�� file_scope������ ����. block_scope���� �Ұ���.
//��� �� ���Ͽ��� ���������� �ʱ�ȭ �Ǿ��ٸ�, �ٸ� ������ �Ұ���.
//(g_int�� ����� main.c���� �ʱ�ȭ�� ���� �ʾҴٸ� second.c������ �ʱ�ȭ ����)

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

