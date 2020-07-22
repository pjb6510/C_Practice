#pragma once

#include <stdbool.h>
#include <stdlib.h>

#define TSIZE 45
#define MAXITEMS 3 // optional (연결 리스트에선 없어도 됨. 메모리 한계 때문에 한계를 정의하는게 일반적이긴 하나 훨씬 자유로움)

struct element
{
	char name[TSIZE];
} element;

typedef struct element Item;

typedef struct node
{
	Item item;
	struct node* next;
} Node;

typedef struct queue
{
	Node* front;
	Node* rear;
	int n_items;
} Queue;

void InitializeQueue(Queue* pq);
bool QueueIsFull(const Queue* pq);
bool QueueIsEmpty(const Queue* pq);
int QueueItemCount(const Queue* pq);
bool EnQueue(Item item, Queue* pq);
bool DeQueue(Item* pitem, Queue* pq);
void EmptyTheQueue(Queue* pq);
void TraverseQueue(Queue* pq, void (*func)(Item item));