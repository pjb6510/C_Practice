#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define limit 50

typedef struct movie* p_movie;

struct movie
{
	char title[limit];
	float rating;
	p_movie next;
};

p_movie file_open(int* n);
void print_all(p_movie head);

int main() 
{
	p_movie head;
	int n;

	head = file_open(&n);
	print_all(head);
}

p_movie file_open(int* n)
{
	int flag = 0;
	char FileName[FILENAME_MAX];
	p_movie temp = NULL;
	p_movie head = NULL;
	p_movie prev = NULL;

	printf("Please input filename to read and press Enter.\n >> ");
	flag = scanf("%[^\n]%*c", FileName);
	if (flag != 1)
	{
		printf("scanf error\n");
		exit(1);
	}

	FILE* fp = fopen(FileName, "r");
	if (fp == NULL)
	{
		printf("ERROR : Cannot open file.\n");
		exit(1);
	}

	flag = fscanf(fp, "%d%*c", n);
	if (flag != 1)
	{
		printf("fscanf error\n");
		exit(1);
	}

	for (int i = 0; i < *n; ++i)
	{
		temp = (p_movie)malloc(sizeof(struct movie));
	
		if (temp == NULL)
		{
			printf("malloc error\n");
			exit(1);
		}

		if (i == 0)
		{
			head = temp;
		}
		else
			prev->next = temp;

		flag = fscanf(fp, "%[^\n]%*c%f%*c", temp->title, &(temp->rating));
		if (flag != 2)
		{
			printf("fscanf error\n");
			exit(1);
		}
		temp->next = NULL;

		prev = temp;
	}

	return head;
}

void print_all(p_movie head)
{
	p_movie temp = head;
	int i = 0;
	while (temp!= NULL)
	{
		printf("%d : \"%s\". %.1f\n", i, temp->title, temp->rating);
		temp = temp->next;
		++i;
	}
}