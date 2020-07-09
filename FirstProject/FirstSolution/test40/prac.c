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
	write_books("books.dat", my_books, n);
	free(my_books);
	n = 0;
	printf("Done.\n");

	printf("\nPress any key to read data from a file.\n\n");
	temp = _getch();

	my_books = read_books("books.dat", &n);
	//read_books2("books.dat", &my_books, &n);
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
	FILE* fp = fopen(filename, "wb");
	if (fp == NULL)
	{
		printf("fopen()Error");
		exit(1);
	}

	//fprintf(fp, "%d\n", n);
	fwrite(&n, sizeof(n), 1, fp);

	//fprintf(fp, "%s\n%s\n", books[i].name, books[i].author);
	fwrite(books, sizeof(struct book), n, fp);


	fclose(fp);
}

struct book* read_books(const char* filename, int* n)
{
	FILE* fp = fopen(filename, "rb");
	if (fp == NULL)
	{
		printf("fopen()Error");
		exit(1);
	}

	//fscanf(fp, "%d%*c", n);
	fread(n, sizeof(*n), 1, fp);

	struct book* books = (struct book*)malloc(sizeof(struct book) * (*n));
	if (books == NULL)
	{
		printf("malloc()Error");
		exit(1);
	}
	

	fread(books, sizeof(struct book), *n, fp);
	//fscanf(fp, "%[^\n]%*c%[^\n]%*c", books[i].name, books[i].author);	
	

	fclose(fp);
	
	return books;
}

void read_books2(const char* filename, struct book** book_dptr, int* n)
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("fopen()Error");
		exit(1);
	}

	int flag;
	flag = fscanf(fp, "%d%*c", n);
	if (flag != 1)
	{
		printf("fscnaf()Error n");
		exit(1);
	}

	struct book* books = (struct book*)malloc(sizeof(struct book) * (*n));
	if (books == NULL)
	{
		printf("malloc()Error");
		exit(1);
	}

	for (int i = 0; i < *n; i++)
	{
		flag = fscanf(fp, "%[^\n]%*c%[^\n]%*c", books[i].name, books[i].author);
		if (flag != 2)
		{
			printf("fscanf()Error contents");
			exit(1);
		}
	}

	*book_dptr = books;
}