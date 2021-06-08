#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc(), free()
#include <string.h> // strlen(), strcmp()
#define SLEN 81

struct namect {
	char* fname; // Use malloc()
	char* lname; // Use malloc()
	int letters;
};

void getinfo(struct namect*);
void makeinfo(struct namect*);
void showinfo(const struct namect*);
void cleanup(struct namect*);
char* s_gets(char* st, int n);

int main()
{
	struct namect person;

	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);

	return 0;
}

void getinfo(struct namect* strc)
{
	printf("Input your first name.\n");
	char buffer[SLEN];
	int f1 = scanf("%[^\n]%*c", buffer);
	if (f1 == 1)
		strc->fname = (char*)malloc(strlen(buffer) + 1); // '\0'자리를 포함하기 위해 +1
	else
		printf("Input error");
	if (strc->fname != NULL) // malloc이 에러가 나면 NULL값을 반환.
		strcpy(strc->fname, buffer);
	else
		printf("malloc() error");
	
	printf("Input your last name.\n");
	int f2 = scanf("%[^\n]%*c", buffer);
	if (f2 == 1)
		strc->lname = (char*)malloc(strlen(buffer) + 1);
	else
		printf("Input error");
	if (strc->lname != NULL)
		strcpy(strc->lname, buffer);
	else
		printf("malloc() error");
}

void makeinfo(struct namect* strc)
{
	strc->letters = strlen(strc->fname) + strlen(strc->lname);
}

void showinfo(const struct namect* strc)
{
	printf("Hi %s %s. Your name has %d characters.", strc->fname, strc->lname, strc->letters);
}

void cleanup(struct namect* strc)
{
	free(strc->fname);
	free(strc->lname);
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
		{
			*find = '\0';
		}
		else
			while (getchar() != '\n') continue;
	}

	return ret_val;
}