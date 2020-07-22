#pragma once

#include <stdbool.h>
#include <stdlib.h>

#define TSIZE 45
#define MAXITEMS 3 // optional (���� ����Ʈ���� ��� ��. �޸� �Ѱ� ������ �Ѱ踦 �����ϴ°� �Ϲ����̱� �ϳ� �ξ� �����ο�)

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