#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void fit_str(char* str, unsigned int n)
{
	int i = 0;
	while (*str != '\0' && i < n)
	{
		putchar(*str++);
		i++;
	}
}
void fit_str2(char* str, unsigned int n)
{
	if (strlen(str) > n)
		str[n] = '\0';
}

int main()
{
	char map_cheat[] = "black sheep wall";
	fit_str2(map_cheat,10);

	printf("%s", map_cheat);


	return 0;
}

