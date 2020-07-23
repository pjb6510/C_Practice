#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedQueue.h"

// 비었을때는 Front와 Rear모두 Null
// 처음 추가 시에는 Front와 Rear 둘 다 새 노드를 가리키기.
// 마지막 아이템 삭제 시에도 둘 다 Null

Item get_item(const char* name);
void print_item(Item item);
void print_queue(Queue* pq);

int main()
{
	Queue queue;
	Item temp;

	InitializeQueue(&queue);

	EnQueue(get_item("Jack"), &queue);
	print_queue(&queue);

	EnQueue(get_item("Henry"), &queue);
	print_queue(&queue);

	EnQueue(get_item("Stan"), &queue);
	print_queue(&queue);

	EnQueue(get_item("Butters"), &queue); // MAX가 4이고 한 칸을 못쓰므로 입력에 실패해야함.
	print_queue(&queue);

	if (DeQueue(&temp, &queue))
		printf("Item from queue : %s\n", temp.name);
	print_queue(&queue);

	if (DeQueue(&temp, &queue))
		printf("Item from queue : %s\n", temp.name);
	print_queue(&queue);

	if (DeQueue(&temp, &queue))
		printf("Item from queue : %s\n", temp.name);
	print_queue(&queue);

	if (DeQueue(&temp, &queue)) // MAX가 4이므로 실패해야함.
		printf("Item from queue : %s\n", temp.name);
	print_queue(&queue);

	printf("------ Circulation Test ----------\n");

	InitializeQueue(&queue);

	for (int i = 0; i < 10; ++i)
	{
		EnQueue(get_item("Hello"), &queue);
		print_queue(&queue);

		if (DeQueue(&temp, &queue))
			printf("Item from queue: %s\n", temp.name);
		print_queue(&queue);
	}

	return 0;
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

