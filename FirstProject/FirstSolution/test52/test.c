#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define limit 100

/*
	Program written in C

	Translating
	Preprocessing
	Compiling
	Linking

	Excutable
*/

struct movie {
	float rating;
	char movie[limit];
};

struct movie* file_open(int* n_ptr);
int show_func();
void print_all_item(const int n, const struct movie* movies);
void print_an_item(const int n, const struct movie* movies);
void edit_an_item(const int n, const struct movie* movies);
void add_an_item(int* n_ptr, struct movie** movies);
void insert_an_item(int* n_ptr, struct movie** movies);
void delete_an_item(int* n_ptr, struct movie** movies);
void save_file(const int n, const struct movie* movies);
void search_by_name(const int n, const struct movie* movies);

int main()
{
	int flag = 0;
	int n = 0;
	struct movie* movies;
	int input=0;

	movies = file_open(&n);

	while (input != 10)
	{
		while (1)
		{
			input = show_func();
			if (input < 1 || input>10)
				continue;
			else
				break;
		}

		switch (input)
		{
		case 1:
			print_all_item(n, movies);
			break;
		case 2:
			print_an_item(n, movies);
			break;
		case 3:
			edit_an_item(n, movies);
			break;
		case 4:
			add_an_item(&n, &movies);
			break;
		case 5:
			insert_an_item(&n, &movies);
			break;
		case 6:
			delete_an_item(&n, &movies);
			break;
		case 7:
			n = 0;
			break;
		case 8 :
			save_file(n, movies);
			break;
		case 9 :
			search_by_name(n, movies);
			break;
		default:
			break;
		}
	}
	free(movies);
	printf("Good bye.\n");
}

struct movie* file_open(int* n_ptr)
{
	char filename[limit] = { "\0", };
	int flag = 0;

	printf("Please input filename to read and press Enter.\n>> ");
	flag = scanf("%[^\n]%*c", &filename);
	if (flag != 1)
	{
		printf("scanf() Error");
	}

	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("ERROR : Can not open file.\n");
		exit(1);
	}

	flag = fscanf(fp, "%d%*c", n_ptr);
	if (flag != 1)
	{
		printf("fscanf() read failed\n");
		exit(1);
	}

	struct movie* movies = (struct movie*)malloc(sizeof(struct movie) * (*n_ptr));
	if (!movies) {
		printf("malloc error\n");
		exit(1);
	}

	for (int i = 0; i < *n_ptr; i++)
	{
		flag = fscanf(fp, "%[^\n]%*c%f%*c", &(movies[i].movie), &(movies[i].rating));
		if (flag != 2)
		{
			printf("fscanf() read failed\n");
			exit(1);
		}
	}

	printf("%d items have been read from the file.\n\n", *n_ptr);

	fclose(fp);
	return movies;
}

int show_func()
{
	int input;
	int flag;
	char* funclist[10] = { "Print all items", "Print an item", "Edit an item", "Add an item", "Insert an item",\
"Delete an item", "Delete all items", "Save file", "Search by name", "Quit" };

	printf("Please select an option and press enter.\n");
	for (int i = 1; i <= 10; i++)
	{
		if (i % 2 == 1)
			printf("%d. %s \t", i, funclist[i - 1]);
		else
			printf("%d. %s \n", i, funclist[i - 1]);
	}
	printf(">> ");

	flag = scanf("%d%*c", &input);
	if (flag != 1)
	{
		printf("Input error\n\n");
		while (getchar() != '\n') continue;
	}

	return input;
}

void print_all_item(const int n, const struct movie* movies)
{
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d : \"%s\", %.1f\n", i, movies[i].movie, movies[i].rating);
	}
	printf("\n");
}

void print_an_item(const int n, const struct movie* movies)
{
	int flag;
	int input;

	while (1)
	{
		printf("\nInput the index of item to print.\n >> ");
		flag = scanf("%d%*c", &input);
		if (flag != 1)
		{
			printf("\ninput error\n");
			while (getchar() != '\n') continue;
			continue;
		}
		if (input > n-1 || input < 0)
		{
			printf("\n You have %d items. Please input 0 ~ %d\n", n, n-1);
			continue;
		}
		break;
	}

	printf("\n%d : \"%s\", %.1f \n\n", input, movies[input].movie, movies[input].rating);
}

void edit_an_item(const int n, const struct movie* movies)
{
	int input;
	int flag;
	char edit_movie[limit];
	float edit_rating;

	while (1)
	{
		printf("\nInput the index of item to print.\n >> ");
		flag = scanf("%d%*c", &input);
		if (flag != 1)
		{
			printf("\ninput error\n");
			while (getchar() != '\n') continue;
			continue;
		}
		if (input > n - 1 || input < 0)
		{
			printf("\n You have %d items. Please input 0 ~ %d\n", n, n - 1);
			continue;
		}
		break;
	}

	printf("\n%d : \"%s\", %.1f \n", input, movies[input].movie, movies[input].rating);

	while (1)
	{
		printf("Input new title and press enter.\n");
		flag = scanf("%[^\n]%*c", &(movies[input].movie));
		if (flag != 1)
		{
			printf("input error\n");
			while (getchar() != '\n') continue;
			continue;
		}
		else
			break;
	}

	while (1)
	{
		printf("Input new rating and press enter.\n");
		flag = scanf("%f%*c", &(movies[input].rating));
		if (flag != 1)
		{
			printf("input error\n");
			while (getchar() != '\n') continue;
			continue;
		}
		else
			break;
	}
}

void add_an_item(int* n_ptr, struct movie** movies)
{
	// 포인터를 직접 다뤄야 할때는 이중포인터로 넣어놓고 다루자.

	int flag;
	struct movie* temp = *movies;
	*movies = (struct movie*)malloc(sizeof(struct movie) * ((*n_ptr) + 1));
	if (*movies == NULL)
	{
		printf("malloc Error\n");
		exit(1);
	}
	memcpy(*movies, temp, sizeof(struct movie) * (*n_ptr));
	free(temp);

	while (1)
	{
		printf("Input new title and press enter.\n");
		flag = scanf("%[^\n]%*c", &((*movies)[*n_ptr].movie));
		if (flag != 1)
		{
			printf("input error\n");
			while (getchar() != '\n') continue;
			continue;
		}
		else
			break;
	}

	while (1)
	{
		printf("Input new rating and press enter.\n");
		flag = scanf("%f%*c", &((*movies)[*n_ptr].rating));
		if (flag != 1)
		{
			printf("input error\n");
			while (getchar() != '\n') continue;
			continue;
		}
		else
			break;
	}

	*n_ptr += 1;

	printf("\n%d : \"%s\", %.1f \n\n", *n_ptr-1, (*movies)[*n_ptr - 1].movie, (*movies)[*n_ptr - 1].rating);
}

void insert_an_item(int* n_ptr, struct movie** movies)
{
	int flag;
	int index;

	struct movie* temp = *movies;
	*movies = (struct movie*)malloc(sizeof(struct movie) * (*n_ptr + 1));

	while (1)
	{
		printf("\nInput the index of item to insert.\n >> ");
		flag = scanf("%d%*c", &index);
		if (flag != 1)
		{
			printf("\ninput error\n");
			while (getchar() != '\n') continue;
			continue;
		}
		if (index > *n_ptr || index < 0)
		{
			printf("\n You have %d items. Please input 0 ~ %d\n", *n_ptr, *n_ptr);
			continue;
		}
		break;
	}

	for (int i = 0; i < *n_ptr; i++)
	{
		if (i < index)
		{
			strcpy((*movies)[i].movie, temp[i].movie);
			(*movies)[i].rating = temp[i].rating;
		}
		else
		{
			strcpy((*movies)[i + 1].movie, temp[i].movie);
			(*movies)[i+1].rating = temp[i].rating;
		}
	}

	while (1)
	{
		printf("Input new title and press enter.\n");
		flag = scanf("%[^\n]%*c", &((*movies)[index].movie));
		if (flag != 1)
		{
			printf("input error\n");
			while (getchar() != '\n') continue;
			continue;
		}
		else
			break;
	}

	while (1)
	{
		printf("Input new rating and press enter.\n");
		flag = scanf("%f%*c", &((*movies)[index].rating));
		if (flag != 1)
		{
			printf("input error\n");
			while (getchar() != '\n') continue;
			continue;
		}
		else
			break;
	}

	free(temp);
	*n_ptr += 1;
}

void delete_an_item(int *n_ptr, struct movie** movies)
{
	struct movie* temp;
	int flag = 0;
	int index;

	while (1)
	{
		printf("\nInput the index of item to delete.\n >> ");
		flag = scanf("%d%*c", &index);
		if (flag != 1)
		{
			printf("input error\n");
			while (getchar() != '\n') continue;
			continue;
		}
		if (index < 0 || index > (*n_ptr - 1))
		{
			printf("\n You have %d items. Please input 0 ~ %d\n", *n_ptr, (*n_ptr - 1));
			continue;
		}
		break;
	}

	temp = *movies;
	*movies = (struct movie*)malloc(sizeof(struct movie) * (*n_ptr - 1));
	for (int i = 0; i < (*n_ptr - 1); i++)
	{
		if (i < index)
		{
			strcpy((*movies)[i].movie, temp[i].movie);
			(*movies)[i].rating = temp[i].rating;
		}
		else
		{
			strcpy((*movies)[i].movie, temp[i+1].movie);
			(*movies)[i].rating = temp[i+1].rating;
		}
	}

	*n_ptr -= 1;
	free(temp);
}

void save_file(const int n, const struct movie* movies)
{
	int flag;
	char filename[FILENAME_MAX] = { 0, };
	printf("Please input filename to write and press Enter.\n >> ");
	flag = scanf("%[^\n]%*c", filename);
	if (flag != 1)
	{
		printf("scanf error\n");
		exit(1);
	}
	FILE* fp = fopen(filename, "w");
	if (fp == NULL)
	{
		fputs("Can't open file.", stderr);
		exit(1);
	}
	
	fprintf(fp, "%d\n", n);

	for (int i = 0; i < n; i++)
	{
		fprintf(fp, "%s\n%.1f\n", movies[i].movie, movies[i].rating);
	}

	fclose(fp);
}

void search_by_name(const int n, const struct movie* movies)
{
	int is_found = 0;
	int flag;
	char movie_name[limit];
	printf("Input title to search and press enter.\n >> ");
	flag = scanf("%[^\n]%*c", movie_name);
	if (flag != 1)
	{
		printf("scanf error\n");
		exit(1);
	}

	for (int i = 0; i < n; i++)
	{
		if (strcmp(movie_name, movies[i].movie) == 0)
		{
			printf("\n%d : \"%s\", %.1f \n\n", i, movies[i].movie, movies[i].rating);
			is_found = 1;
		}
		else
			continue;
	}

	if (is_found == 0)
		printf("No movie found : %s\n", movie_name);
}