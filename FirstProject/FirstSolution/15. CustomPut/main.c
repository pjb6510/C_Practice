#define _CRT_SECURE_NO_WARNINGS
#define TEST "A string from #define."
#include <stdio.h>
#include <stdbool.h>

void custom_put(const char* str)
{
	while((*str)!='\0')
		putchar(*str++);
}
int custom_put2(const char* str)
{
	int i = 0;
	while ((*str) != '\0')
	{
		putchar(*str++);
		i++;
	}	
	putchar('\n');
	return i;
}

int main()
{
	custom_put("Show me the money");
	printf("%d",custom_put2("Power overwhelming"));
	return 0;
}