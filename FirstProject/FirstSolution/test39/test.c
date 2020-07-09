#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define SLEN 101



struct book
{
	char name[SLEN];
	char author[SLEN];
};

void print_books(const struct book* books, int n);
void write_books(const char* filename, const struct book* books, int n);
struct book* read_books(const char* filename, int* n);
void read_books2(const char* filename, struct book** book_dptr, int* n);

int main()
{
	int temp;
	int n = 3;
	

	struct book* my_books = (struct book*)malloc(sizeof(struct book) * n);

	if (!my_books)
	{
		printf("Malloc Failed");
		exit(1);
	}

	my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
	my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
	my_books[2] = (struct book){ "The Odyssey", "Homer" };

	print_books(my_books, n);

	printf("\nWriting to a file.\n");
	write_books("books.txt", my_books, n);
	free(my_books);
	n = 0;
	printf("Done.\n");

	printf("\nPress any key to read data from a file.\n\n");
	temp = _getch();

	//my_books = read_books("books.txt", &n);
	read_books2("books.txt", &my_books, &n);
	print_books(my_books, n);
	free(my_books);
	n = 0;

	return 0;
}

void print_books(const struct book* books, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("Book %d : \"%s\" written by \"%s\"\n", i + 1, books[i].name, books[i].author);
	}
}

void write_books(const char* filename, const struct book* books, int n)
{
	FILE* fp;
	if ((fp = fopen(filename, "w")) == NULL)
	{
		fprintf(stderr, "Can't open \"%s\" file.\n", filename);
		exit(EXIT_FAILURE);
	}

	fprintf(fp, "%d\n", n);
	for (int i = 0; i < n; ++i)
	{
		fprintf(fp, "%s\n", books[i].name);
		fprintf(fp, "%s\n", books[i].author);
	}

	fclose(fp);
}

struct book* read_books(const char* filename, int* n)
{
	FILE* fp;
	
	if ((fp = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "Can't open \"%s\" file.\n", filename);
		exit(EXIT_FAILURE);
	}

	int flag;
	flag = fscanf(fp, "%d%*c", n); // %*□ 형태는 □에 해당하는 입력값 하나를 무시함. 여기선 수를 입력받고 \n을 무시하기 위해 적용.
	if (flag != 1)
	{
		printf("File read failed");
		exit(1);
	}

	struct book* books = (struct book*)malloc(sizeof(struct book) * (*n));

	if (books == NULL)
	{
		printf("malloc() error");
		exit(1);
	}

	for (int i = 0; i < *n; ++i)
	{
		flag = fscanf(fp, "%[^\n]%*c%[^\n]%*c", books[i].name, books[i].author);
		if (flag != 2)
		{
			printf("file scan error");
			exit(1);
		}
	}

	fclose(fp);

	return books;
}

void read_books2(const char* filename, struct book** book_dptr, int* n)
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Can't open file.\n");
		exit(1);
	}

	int flag;
	flag = fscanf(fp, "%d%*c", n);
	if (flag != 1)
	{
		printf("fscanf()error");
		exit(1);
	}
	
	struct book* books = (struct book*)malloc(sizeof(struct book) * (*n));
	if (books == NULL)
	{
		printf("malloc()error");
		exit(1);
	}
	
	for (int i = 0; i < *n; ++i)
	{
		flag = fscanf(fp, "%[^\n]%*c%[^\n]%*c", books[i].name, books[i].author);

		if (flag != 2)
		{
			printf("fscanf()error");
			exit(1);
		}
	}

	fclose(fp);
	
	*book_dptr = books;
}