#include "SimpleList.h"

//item = {title, rating}
//node = {item, next}
//list = {head, size}

bool AddItem(Item item, List* plist)
{
	Node* pnode = plist->head;

	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->item = item;
	new_node->next = NULL;

	if (plist->head == NULL)
		plist->head = new_node;
	else
	{
		while (pnode->next != NULL)
			pnode = pnode->next;

		pnode->next = new_node;
	}
	plist->size += 1;
}

void InsertByIndex(Item item, List* plist, int index)
{
	Node* pnode = plist->head;

	unsigned int i = 0;
	while (pnode != NULL)
	{
		if (i == index)
		{
			pnode->item = item;
		}

		pnode = pnode->next;
		i += 1;
	}
}

void RemoveByIndex(List* plist, int index)
{
	unsigned int i = 0;
	Node* pnode = plist->head;
	Node* prev = NULL;
	while (pnode != NULL)
	{
		if (index == i)
		{
			prev->next = pnode->next;
			free(pnode);
		}
		prev = pnode;
		pnode = pnode->next;
		i++;
	}
}

unsigned int CountItems(const List* plist)
{
	unsigned int count = 0;
	Node* pnode = plist->head;
	while (pnode != NULL)
	{
		pnode = pnode->next;
		count += 1;
	}

	return count;
}

unsigned int PrintAllItems(const List* plist, void (*print_an_item_func)(Item item))
{
	Node* pnode = plist->head;

	int count = 0;
	while (pnode != NULL)
	{
		(*print_an_item_func)(pnode->item);
		pnode = pnode->next;
		count++;
	}

	return count;
}

unsigned int WriteAllItems(const List* plist, FILE* file, void(*write_an_item_func)(FILE* file, Item item))
{
	unsigned int count = 0;
	Node* pnode = plist->head;
	while(pnode != NULL)
	{
		(*write_an_item_func)(file, pnode->item);
		pnode = pnode->next;
		count += 1;
	}

	return count;
}

void ClearList(List* plist)
{
	if (plist->head == NULL)
	{
		printf("Nothing to delete.\n");
		return;
	}

	unsigned int count = 0;
	Node* pnode = plist->head;
	Node* temp;

	while (pnode != NULL)
	{
		printf("%s is deleted. \n", pnode->item.title);
		temp = pnode->next;
		free(pnode);
		pnode = temp;
		count++;
	}

	plist->head = NULL;
	printf("%d items deleted.\n", count);
}

bool FindItemByIndex(const List* plist, const int index, Item** item)
{
	bool is_found = false;
	int i = 0;
	Node* pnode = plist->head;
	while (pnode != NULL)
	{
		if (index == i)
		{
			*item = &(pnode->item);
			is_found = true;
			break;
		}
		pnode = pnode->next;
		i++;
	}

	return is_found;
}

