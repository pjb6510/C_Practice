#define _CRT_SECURE_NO_WARNINGS

#include "SimpleList.h"

#include <stdio.h>
#include <stdlib.h>

void file_open(List* plist, int* num);
void print_an_item(Item item);
void print_all_item(List* plist);
void print_name_start_with_word(List* plist, char* start_word);
void print_year_joined_in(List* plist, unsigned int year);

int main() 
{
	int num;
	List avengers;
	int select_menu = 0;

	InitializeList(&avengers);

	file_open(&avengers, &num);
	
	while (select_menu != 4)
	{
		printf("\n1. Print all members.\n");
		printf("2. Print all members whose names start with \"Black\".\n");
		printf("3. Print all members who joined in 1965.\n");
		printf("4. Quit\n\n");
		printf("Please input number what you want to do.\n>> ");
		scanf("%d%*c", &select_menu);

		switch (select_menu)
		{
		case 1:
			print_all_item(&avengers);
			break;
		case 2:
			print_name_start_with_word(&avengers, "Black");
			break;
		case 3:
			print_year_joined_in(&avengers, (unsigned int)1965);
		default:
			break;
		}
	}
	printf("Good bye!\n");
}

void file_open(List* plist, int* num)
{
	char filename[FILENAME_MAX];

	printf("Please input filename to load data.\n>> ");
	scanf("%[^\n]%*c", filename);

	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Error : Can't open file.\n");
		exit(1);
	}

	fscanf(fp, "%d%*c", num);

	for (int i = 0; i < *num; ++i)
	{
		Item avenger;
		fscanf(fp, "%[^\n]%*c", avenger.name);
		fscanf(fp, "%u%*c", &avenger.year);
		AddItem(avenger, plist);
	}
}

void print_an_item(Item item)
{
	printf("%s : %u\n", item.name, item.year);
}

void print_all_item(List* plist)
{
	PrintAllItems(plist, &print_an_item);
}

bool is_name_start_with_black(Item item)
{
	char* word = "Black";
	if (strncmp(word, item.name, strlen(word)) == 0)
		return true;
	else
		return false;
}

bool is_joined_in_1965(Item item)
{
	if (item.year == (unsigned int)1965)
		return true;
	else
		return false;
}

//void print_name_start_with_word(List* plist, char* start_word)
//{
//	Node* pnode = plist->head;
//	while (pnode != NULL)
//	{
//		if (strncmp(start_word, pnode->item.name, strlen(start_word)) == 0)
//			print_an_item(pnode->item);
//		pnode = pnode->next;
//	}
//}
//
//void print_year_joined_in(List* plist, unsigned int year)
//{
//	Node* pnode = plist->head;
//	while (pnode != NULL)
//	{
//		if (pnode->item.year == year)
//			print_an_item(pnode->item);
//		pnode = pnode->next;
//	}
//}

void print_name_start_with_word(List* plist, char* start_word)
{
	print_with_criterion(plist, &is_name_start_with_black);
}

void print_year_joined_in(List* plist, unsigned int year)
{
	print_with_criterion(plist, &is_joined_in_1965);
}