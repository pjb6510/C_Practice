#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
	int ch_num = 0;
	int word_num = 1;
	int line_num = 1;
	char ch;
	bool was_space = false;

	while ((ch = getchar()) != '.') 
	{
		if (ch == '\n')
		{
			line_num++;
		}

		if (was_space && !isspace(ch))
		{
			word_num++;
			was_space = false;
		}

		if (!isspace(ch))
		{
			was_space = false;
			ch_num++;
		}
		else
			was_space = true;

	}
	printf("Characters = %d, Words = %d, Lines = %d\n", ch_num, word_num, line_num);
}

