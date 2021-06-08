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

char* s_gets(char* st, int n);
void receive_input(struct name_count*);
void count_characters(struct name_count*);
void show_result(const struct name_count*);


int main()
{
	struct name_count user_name;

	receive_input(&user_name);
	count_characters(&user_name);
	show_result(&user_name);

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

void receive_input(struct name_count* strc)
{
	printf("Input your first name:\n>>");
	s_gets((*strc).first, NLEN);
	printf("\nInput your last name:\n>>");
	s_gets((*strc).last, NLEN);
}
void count_characters(struct name_count* strc)
{
	int first_len;
	int last_len;
	first_len = strlen((*strc).first);
	last_len = strlen((*strc).last);
	
	(*strc).num = first_len + last_len;
}
void show_result(const struct name_count* strc)
{
	printf("Hi, %s %s. Your name has %d characters.", strc->first, strc->last, strc->num);
}