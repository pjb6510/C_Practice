#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TSIZE 45

struct movie
{
	char title[TSIZE];
	float rating;
};

typedef struct movie Item;

typedef struct node
{
	Item item;
	struct node* next;
} Node;

typedef struct list
{
	Node* head;
	int size;
} List;

void InitializeList(List* plist);
bool IsEmpty(const List* plist);
bool IsFull(const List* plist);
bool AddItem(Item item, List* plist);
void InsertByIndex(Item item, List* plist, int index);
void RemoveByIndex(List* plist, int index);
bool InsertItemFront(Item item, List* plist);
bool Find(const List* plist, Item item_tofind, int* index, Item* item_found, bool (*compare_func)(Item a, Item b));

unsigned int CountItems(const List* plist);
unsigned int PrintAllItems(const List* plist, void (*print_an_item_func)(Item item));
unsigned int WriteAllItems(const List* plist, FILE* file, void(*write_an_item_func)(FILE* file, Item item));

void Treaverse(const List* plist, void (*pfun)(Item item)); // 입력해준 함수를, 노드를 돌며, 모든 노드에 적용.
void ClearList(List* plist);

bool FindItemByIndex(const List* plist, const int index, Item** item);
void RemoveFirstItem(List* plist);