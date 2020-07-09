#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SLEN 101

struct book
{
	char name[SLEN];
	char author[SLEN];
};

void print_books(const struct book books[], int n);
void print_books_ptr(const struct book* book_ptr, int n);

int main()
{
	//struct book my_books[3];
	//my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
	//my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
	//my_books[2] = (struct book){ "The Odyssey", "Homer" };

	//print_books(my_books, 3);

	struct book* my_books = (struct book*)malloc(sizeof(struct book) * 3);

	if (my_books == NULL)
	{
		printf("Malloc Faild");
		exit(1);
	}

	my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
	my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
	my_books[2] = (struct book){ "The Odyssey", "Homer" };

	print_books_ptr(my_books, 3);

	free(my_books);

	return 0;
}

void print_books(const struct book books[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Book %d : \"%s\" written by \"%s\"\n",i+1, books[i].name, books[i].author);
	}
}

void print_books_ptr(const struct book* book_ptr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Book %d : \"%s\" written by \"%s\"\n", i + 1, book_ptr[i].name, book_ptr[i].author);
	}
}