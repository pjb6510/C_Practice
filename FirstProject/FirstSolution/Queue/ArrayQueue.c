#include "ArrayQueue.h"

void InitializeQueue(Queue* pq)
{
	pq->front = 0;
	pq->rear = 0;
	pq->n_items = 0;
}
bool QueueIsFull(const Queue* pq)
{
	if ((pq->rear + 1) % MAXSIZE == pq->front)
		return true;
	else
		return false;
	// 경우의 수
	// rear front
	// 0,	3	3
	// 1,	0	3
	// 2,	1	3
	// 3,	2	3
}
bool QueueIsEmpty(const Queue* pq)
{
	if (pq->rear == pq->front)
		return true;
	else
		return false;
}
int QueueItemCount(const Queue* pq)
{
	return pq->n_items;
}
bool EnQueue(Item item, Queue* pq)
{
	if (QueueIsFull(pq) == true)
	{
		printf("EnQueue Error : Queue is Full.\n");
		return false;
	}
	else
	{
		pq->rear = (pq->rear + 1) % MAXSIZE;
		pq->items[pq->rear] = item;
		pq->n_items += 1;
		return true;
	}
}
bool DeQueue(Item* pitem, Queue* pq)
{
	if (QueueIsEmpty(pq) == true)
	{
		printf("DeQueue Error : Queue is Empty.\n");
		return false;
	}

	else
	{
		pq->front = (pq->front + 1) % MAXSIZE;
		pq->n_items -= 1;
		*pitem = pq->items[pq->front];
		return true;
	}
}
void EmptyTheQueue(Queue* pq);
void TraverseQueue(Queue* pq, void (*func)(Item item));