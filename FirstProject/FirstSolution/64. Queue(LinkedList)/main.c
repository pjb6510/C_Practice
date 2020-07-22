#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedQueue.h"

// 비었을때는 Front와 Rear모두 Null
// 처음 추가 시에는 Front와 Rear 둘 다 새 노드를 가리키기.
// 마지막 아이템 삭제 시에도 둘 다 Null

int main()
{

}

Item get_item(const char* name)
{
	Item new_item;
	strcpy(new_item.name, name);
	return new_item;
}

void print_item(Item item)
{
	printf("%s ", item.name);
}

void print_queue(Queue* pq)
{
	printf("Front : %s at %p, Rear : %s at %p, Size %d\n",
		pq->front == NULL ? "NULL" : pq->front->item.name, pq->front,
		pq->rear == NULL ? "NULL" : pq->rear->item.name, pq->rear, pq->n_items);

	printf("Queue : ");
	if (QueueIsEmpty(pq))
		printf("Empty");
	else
		TraverseQueue(pq, &print_item);
	printf("\n\n");
}

