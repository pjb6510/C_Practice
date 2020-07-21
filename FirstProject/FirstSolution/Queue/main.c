#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayQueue.h"

// 기본적으로 큐는 연결리스트로 만드는게 여러모로 편하다.
// 지금은 연습 삼아 배열로 순환큐를 만들어보자.
// 배열을 이용해서 순환큐를 구현할 때는 한 칸을 사용할 수 없게 된다. (full 과 empty를 판단하기 위해)
// Front = 0 Rear = 0 이후 멤버가 생성될 때 Rear+=1자리에 생성, 삭제할 때도 Front +=1 이후 삭제 // 혹은 삭제한 자리에 머무름.
// Rear = (현재index + 1) % MAX = 0
// 1회 순환 이후 Front보다 Rear가 작아지는 경우가 있을 수 있기 때문에 반복문에 Rear나 Front를 사용하는데 주의가 필요함.
// (Rear+1)%MAX == Front : 꽉 차있는 상태
// Rear == Front : 비어있는 상태
// n_items를 가지고 full, empty를 구현하지 말고 순환큐의 도식을 이해하기 위해 공식을 도출하여 구현해보자.

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
	printf("Front : %d, Rear : %d, Size %d\n", pq->front, pq->rear, pq->n_items);

	printf("Queue : ");
	if (QueueIsEmpty(pq))
		printf("Empty");
	else
		TraverseQueue(pq, &print_item);
	printf("\n\n");
}

