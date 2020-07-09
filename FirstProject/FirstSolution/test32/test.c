#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NLEN 30

struct name_count {
	char first[NLEN];
	char last[NLEN];
	int num;
};

struct name_count receive_input();
struct name_count count_characters(struct name_count);
void show_result(const struct name_count);
char* s_gets(char* st, int n);

int main()
{
	struct name_count user_name;

	user_name = receive_input();
	user_name = count_characters(user_name);
	show_result(user_name);

	return 0;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n') continue;
	}

	return ret_val;
}

struct name_count receive_input()
{
	struct name_count result;
	
	printf("Input your first name.\n>>>");
	s_gets(result.first, NLEN);

	printf("\nInput your last name.\n>>>");
	s_gets(result.last, NLEN);

	printf("\n");

	return result;
}
struct name_count count_characters(struct name_count strc)
{
	strc.num = strlen(strc.first) + strlen(strc.last);
	return strc;
}
void show_result(const struct name_count strc)
{
	printf("Hi, %s %s. Your name has %d characters.", strc.first, strc.last, strc.num);
}