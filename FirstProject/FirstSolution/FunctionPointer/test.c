#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char* str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}

// 함수 패턴이 동일. 고로 아래와 같이 변경가능. 파라미터로 함수포인터를 받기.

void UpdatingString(char* str, int(*pf)(int))
{
	while (*str)
	{
		*str = (*pf)(*str);
		str++;
	}
}

int main()
{
	char str[] = "Hello, World";

	void (*pf)(char*);
	
	pf = ToUpper;
	//pf = &ToUpper;

	(*pf)(str); //ToUpper(str);
	//pf(str);

	printf("ToUpper %s\n", str);

	pf = ToLower;

	pf(str);

	printf("ToLower %s\n", str);


	UpdatingString(str, toupper);
	printf("ToUpper %s\n", str);
	UpdatingString(str, tolower);
	printf("ToLower %s \n", str);

	return 0;
}