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

int input_int(int min, int max);
void print_menu();
p_movie file_open(int* n);
void print_all_items(const int n, const p_movie head);
void print_an_item(const int n, const p_movie head);
void edit_an_item(const int n, const p_movie head);
void add_an_item(int* n, p_movie *head);
void insert_an_item(int* n, p_movie* head);
void delete_an_item(int* n, p_movie* head);
void delete_all_items(int* n, p_movie* head);
void save_file(const int n, const p_movie head);

int main() 
{
	p_movie head;
	int n;
	int input = 0;

	head = file_open(&n);

	while (input != 10)
	{
		print_menu();
		input = input_int(1, 10);

		switch (input)
		{
		case 1:
			print_all_items(n, head);
			break;
		case 2:
			print_an_item(n, head);
			break;
		case 3:
			edit_an_item(n, head);
			break;
		case 4:
			add_an_item(&n, &head);
			break;
		case 5:
			insert_an_item(&n, &head);
			break;
		case 6:
			delete_an_item(&n, &head);
			break;
		case 7:
			delete_all_items(&n, &head);
			break;
		case 8:
			save_file(n, head);
		default:
			break;
		}
	}
	printf("Good bye!");
}

int input_int(int min, int max)
{
	int input = 0;

	while (1)
	{
		printf("\n>> ");
		if ((scanf("%d%*c", &input)) != 1)
		{
			printf("Invalid value. Please input again.\n");
			while (getchar() != '\n') continue;
			continue;
		}

		if (input < min || input > max)
		{
			printf("Please input %d ~ %d", min, max);
			continue;
		}
		break;
	}
	return input;
}

void print_menu()
{
	int input;

	printf("\nPlease select an option and press enter.\n");
	printf("1. Print all items	2. Print an item\n");
	printf("3. Edit an item		4. Add an item\n");
	printf("5. Insert an item	6. Delete an item\n");
	printf("7. Delete all items	8. Save file\n");
	printf("9. Search by name	10. Quit\n");
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

	fclose(fp);
	return head;
}

void print_all_items(const int n, const p_movie head)
{
	p_movie temp = head;
	for (int i = 0; i < n; i++)
	{
		printf("%d : \"%s\". %.1f\n", i, temp->title, temp->rating);
		temp = temp->next;
	}
}

void print_an_item(const int n, const p_movie head)
{
	int flag;
	int input;
	p_movie temp = head;
	if (head == NULL)
	{
		printf("You have no item. Please add item.\n");
		return;
	}

	printf("Input the index of item to print");
	input = input_int(0, n-1);
	
	for (int i = 0; i < n; ++i)
	{
		if (i == input)
			printf("%d : \"%s\", %.1f\n", i, temp->title, temp->rating);
		temp = temp->next;
	}
}

void edit_an_item(const int n, const p_movie head)
{
	if (head == NULL)
	{
		printf("You have no item. Please add item.\n");
		return;
	}
	p_movie temp = head;
	p_movie prev = NULL;
	int input = 0;
	printf("Input the index of item to edit.");
	input = input_int(0, n - 1);

	p_movie new_node = (p_movie)malloc(sizeof(struct movie));
	if (new_node == NULL)
	{
		printf("malloc error");
		exit(1);
	}

	printf("Input new title and press enter.\n");

	if (scanf("%[^\n]%*c", new_node->title) != 1)
	{
		printf("scanf error\n");
		exit(1);
	}

	printf("Input new rating and press enter.\n");
	if (scanf("%f", &(new_node->rating)) != 1)
	{
		printf("scanf error\n");
		exit(1);
	}

	for (int i = 0; i < n; ++i)
	{
		if (i == input)
		{
			new_node->next = temp->next;
			free(temp);
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	prev->next = new_node;
}

void add_an_item(int* n, p_movie* head)
{
	p_movie temp = *head;
	p_movie new_node = (p_movie)malloc(sizeof(struct movie));
	if (new_node == NULL)
	{
		printf("malloc error");
		exit(1);
	}

	printf("Input title and press enter.\n");
	scanf("%[^\n]%*c", new_node->title);
	printf("Input rating and press enter.\n");
	scanf("%f", &(new_node->rating));
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return 0;
	}

	for (int i = 0; i < *n; ++i)
	{
		if (temp->next == NULL)
		{
			temp->next = new_node;
			break;
		}
		temp = temp->next;
	}

	*n += 1;
}

void insert_an_item(int* n, p_movie *head)
{
	if (*head == NULL)
	{
		printf("You have no item. Please add item.\n");
		return;
	}

	int input = 0;
	p_movie temp = *head;
	p_movie prev = NULL;
	p_movie new_node = (p_movie)malloc(sizeof(struct movie));
	if (new_node == NULL)
	{
		printf("malloc error\n");
		exit(1);
	}

	printf("Input the index of item to insert.");
	input = input_int(0, *n - 1);

	printf("Input title and press enter.\n");
	if (scanf("%[^\n]%*c", new_node->title) != 1)
	{
		printf("scanf error\n");
		exit(1);
	}
	printf("Input rating and press enter.\n");
	if (scanf("%f%*c", &(new_node->rating)) != 1)
	{
		printf("scanf error\n");
		exit(1);
	}

	for (int i = 0; i < *n; ++i)
	{
		if (i == input)
		{
			if (input == 0)
				*head = new_node;
			else
				prev->next = new_node;
			new_node->next = temp;
			break;
		}
		prev = temp;
		temp = temp->next;
	}

	*n += 1;
}

void delete_an_item(int* n, p_movie* head)
{
	if (*head == NULL)
	{
		printf("You have no item. Please add item.\n");
		return;
	}

	p_movie temp = *head;
	p_movie prev = NULL;
	int input = 0;

	printf("Input the index of item to delete.");
	input = input_int(0, *n - 1);

	for (int i = 0; i < *n; ++i)
	{
		if (i == input)
		{
			if (input == 0)
				*head = temp->next;
			else
				prev->next = temp->next;
			free(temp);
			break;
		}
		prev = temp;
		temp = temp->next;
	}

	*n -= 1;
}

void delete_all_items(int* n, p_movie* head)
{
	p_movie temp = *head;
	p_movie next = NULL;

	for (int i = 0; i < *n; i++)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}

	*n = 0;
	*head = NULL;
}

void save_file(const int n, const p_movie head)
{
	p_movie temp = head;
	printf("Input filename to save file.\n");
	char file_name[FILENAME_MAX] = { '\0', };
	if (scanf("%[^\n]%*c", file_name) != 1)
	{
		printf("scanf error\n");
		exit(1);
	}
	FILE* fp = fopen(file_name, "w");
	if (fp == NULL)
	{
		printf("fopen error\n");
		exit(1);
	}

	fprintf(fp, "%d\n", n);

	for (int i = 0; i < n; ++i)
	{
		fprintf(fp, "%s\n%.1f\n", temp->title, temp->rating);
		temp = temp->next;
	}

	fclose(fp);
}

//add error print error