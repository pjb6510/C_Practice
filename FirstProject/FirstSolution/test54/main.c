#define _CRT_SECURE_NO_WARNINGS

#include "SimpleList.h"

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void read_file(List* plist)
{
	char filename[TSIZE] = { 0, };

	printf("Please input filename to read and press Enter.\n");
	printf(">> ");

	if (scanf("%[^\n]%*c", filename) != 1)
	{
		printf("Wrong input. Terminating.\n");
		exit(1);
	}

	FILE* file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("ERROR : Cannot open file.\n");
		exit(1);
	}

	int num;
	if (fscanf(file, "%d%*c", &num) != 1)
	{
		printf("ERROR : Wrong file format.");
		exit(1);
	}

	for (int n = 0; n < num; ++n)
	{
		Item new_item;

		if (fscanf(file, "%[^\n]%*c", new_item.title) != 1 ||
			fscanf(file, "%f%*c", &new_item.rating) != 1)
		{
			printf("Error : Wrong file format.\n");
			exit(1);
		}

		AddItem(new_item, plist);
	}

	fclose(file);

	printf("%d items have been read from the file.\n", num);
}

unsigned int count_items(const List* const plist) // 전체 아이템 수 확인
{
	return CountItems(plist);
}

void write_an_item(FILE* const file, const Item item)
{
	fprintf(file, "%s\n", item.title);
	fprintf(file, "%.1f\n", item.rating);
}

void write_file(const List * const plist)
{
	char filename[TSIZE] = { 0, };

	printf("Please input filename to write nd press Enter.\n");
	printf(">> ");

	if (scanf("%[^\n]%*c", filename) != 1)
	{
		printf("Wrong input. Terminating. \n");
		exit(1);
	}

	FILE* file = fopen(filename, "w");

	if (file == NULL)
	{
		printf("ERROR : Cannot open file.\n");
		exit(1);
	}

	unsigned int num = CountItems(plist);

	fprintf(file, "%d\n", num);

	unsigned int count = WriteAllItems(plist, file, &write_an_item);

	fclose(file);

	assert(num == count); // 저장한 항목 수 == 현재 메모리에 갖고 있는 항목 수

	printf("%d items have been saved to the file.\n", count);
}

int input_int()
{
	int input;

	while (1)
	{
		printf(">> ");
		if (scanf("%d%*c", &input) == 1) return input;
		else {
			printf("Please input an integer and press enter. Try again.\n");
			while (getchar() != '\n') continue;
		}
	}
}

int input_menu()
{
	while (1)
	{
		printf("\nPlease select an option and press enter.\n");
		printf("1. Print all items		2. Print an item\n");
		printf("3. Edit an item			4. Add an item\n");
		printf("5. Insert an item		6. Delete an item\n");
		printf("7. Delete all items		8. Save file\n");
		printf("9. Search by name		10. Quit\n");

		int input = input_int();

		if (input >= 1 && input <= 10) return input;
		else
			printf("%d is invalied. Please try again.\n", input);
	}
}

void print_an_item(Item item)
{
	printf("\"%s\", %.1f\n", item.title, item.rating);
}

void print_all(const List* plist)
{
	PrintAllItems(plist, print_an_item);
}

void find_and_print_an_item(const List* const plist)
{
	printf("Input the index of item to print.\n");
	int index = input_int();

	Item* pitem; // FindItemByIndex에서 여기에 index에 해당하는 item의 주소를 넘겨줌.
	const flag = FindItemByIndex(plist, index, &pitem);

	if (flag == true)
	{
		printf("%d : ", index);
		print_an_item(*pitem);
	}
	else
		printf("Invalid item.\n");
}

void edit_an_item(List* plist)
{
	printf("Input the index of item to edit.\n");
	int index = input_int();

	Item* pitem;
	const bool flag = FindItemByIndex(plist, index, &pitem);

	if (flag == true)
	{
		printf("%d : ", index);
		print_an_item(*pitem);

		Item new_item;
		printf("Input new title and press enter.\n");
		printf(">> ");
		int f = scanf("%[^\n]%*c", new_item.title);
		printf("Input new rating and press enter. \n");
		printf(">> ");
		f = scanf("%f%*c", &new_item.rating);

		*pitem = new_item;

		printf("%d : ", index);
		print_an_item(*pitem);
	}
	else
		printf("invalid item.\n");
}

void add_an_item(List* plist)
{
	printf("Input title and press enter.\n");
	printf(">> ");

	Item new_item;

	int f = scanf("%[^\n]%*c", new_item.title);
	printf("Input new rating and press enter. \n");
	printf(">> ");
	f = scanf("%f%*c", &new_item.rating);

	AddItem(new_item, plist);

	printf("%d : \"%s\", %.1f\n", CountItems(plist) - 1, new_item.title, new_item.rating);
}

void insert_an_item(List* plist)
{
	printf("Input the index of item to insert.\n");
	int index = input_int();

	Item* pitem;
	const bool flag = FindItemByIndex(plist, index, &pitem);
	
	if (flag == false)
	{
		printf("Wrong index");
		return;
	}

	Item new_item;

	printf("Input title and press enter. \n");
	printf(">> ");
	int f = scanf("%[^\n]%*c", new_item.title);
	printf("Input new rating and press enter. \n");
	printf(">> ");
	f = scanf("%f%*c", &new_item.rating);

	InsertByIndex(new_item, plist, index);

	printf("%d : \"%s\", %.1f\n", index, new_item.title, new_item.rating);
}

void delete_an_item(List* plist)
{
	printf("Input the index of item to delete.\n");
	int index = input_int();

	Item* pitem; // 여기선 실질적으로 사용하지 않음.
	const bool flag = FindItemByIndex(plist, index, &pitem);

	if (flag == false)
	{
		printf("Wrong index\n");
		return;
	}

	RemoveByIndex(plist, index);
}

void delete_all_items(List* plist)
{
	ClearList(plist);
}

bool compare_items(Item a, Item b)
{
	if (strcmp(a.title, b.title) == 0)
		return true;
	else
		return false;
}

void search_by_name(const List* plist)
{
	printf("Input title to search and press enter.\n");
	printf(">> ");

	Item item_to_find;
	if (scanf("%[^\n]%*c", item_to_find.title) != 1)
	{
		printf("Wrong input.\n");
		return;
	}

	Item item_found;
	int index;	

	if (Find(plist, item_to_find, &index, &item_found, compare_items) == true)
	{
		printf("%d : \"%s\", %.1f\n", index, item_found.title, item_found.rating);
		return;
	}
	else
		printf("No movie found : %s\n", item_to_find.title);
}

int main()
{
	List movie_list;

	InitializeList(&movie_list);

	read_file(&movie_list);

	while (1)
	{
		printf("\n");
		int s = input_menu();

		switch (s)
		{
		case 1:
			print_all(&movie_list);
			break;
		case 2:
			find_and_print_an_item(&movie_list);
			break;
		case 3:
			edit_an_item(&movie_list);
			break;
		case 4:
			add_an_item(&movie_list);
			break;
		case 5:
			insert_an_item(&movie_list);
			break;
		case 6:
			delete_an_item(&movie_list);
			break;
		case 7:
			delete_all_items(&movie_list);
			break;
		case 8:
			write_file(&movie_list);
			break;
		case 9:
			search_by_name(&movie_list);
			break;
		case 10:
			printf("Good bye\n");
			delete_all_items(&movie_list);
			return 0;
		default :
			printf("%d is not implemented.\n", s);
		}
	}
}