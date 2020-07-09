#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

void custom_strcat(char* str1, char* str2)
{
	for (int i = 0, j = 0; str2[j] != '\0'; i++)
	{
		if (str1[i] == '\0')
		{
			str1[i] = str2[j];
			j++;
		}
	}
}

int custom_strcmp(char* str1, char* str2)
{
	for (int i = 0;; i++)
	{
		if (str1[i] < str2[i])
			return -1;
		else if (str1[i] > str2[i])
			return 1;
		else
			if (str1[i] == '\0' && str2[i == '\0'])
				return 0;
	}
}

int main()
{
	printf("%d\n", custom_strcmp("Bananas", "Banana"));

	return 0;
}

