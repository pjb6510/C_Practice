#pragma once
#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define TSIZE 45
#define MAXITEMS 10

struct customer
{
	long arrival_time; //도착 시간.
	int processtime; //주문한 아이스크림 생산 시간.
} customer;

typedef struct customer Item;

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