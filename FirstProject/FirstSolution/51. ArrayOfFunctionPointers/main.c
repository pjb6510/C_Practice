#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void update_string(char* str, int (*pf)(int));
void ToUpper(char* str);
void ToLower(char* str);
void Transpose(char* str);

int main()
{
	char options[] = { 'u', 'l', 't' };
	int n = sizeof(options);

	typedef void (*FUNC_TYPE)(char*);
	FUNC_TYPE operations[] = { ToUpper, ToLower, Transpose };
	char* func_str[] = { "to upper", "to lower", "Transpose" };

	bool is_find = false;
	int index = 0;

	printf("Enter a string\n>> ");

	char input[100];
	char func = '0';

	while (scanf("%[^\n]%*c", input) != 1)
		printf("Please try again. \n >> ");

	for (int i = 0; i < n; i++)
	{
		printf("%c) %s\n", options[i], func_str[i]);
	}
		
	while (1)
	{
		scanf("%c%*c", &func);
		for (index = 0; index < n; index++)
		{
			if (func == options[index])
			{
				is_find = true;
				break;
			}
		}
		if (is_find)
		{
			operations[index](input);
			printf("%s\n", input);
			break;
		}
		else
			printf("Please try again. \n");
	}
}

void update_string(char* str, int (*pf)(int))
{
	while (*str != '\0')
	{
		*str = pf(*str);
		str++;
	}
}

void ToUpper(char* str)
{
	update_string(str, toupper);
}

void ToLower(char* str)
{
	update_string(str, tolower);
}

void Transpose(char* str)
{
	while (*str)
	{
		if (islower(*str))
			*str = toupper(*str);
		else if (isupper(*str))
			*str = tolower(*str);
		str++;
	}
}