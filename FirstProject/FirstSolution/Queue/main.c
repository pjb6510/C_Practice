#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayQueue.h"

// �⺻������ ť�� ���Ḯ��Ʈ�� ����°� ������� ���ϴ�.
// ������ ���� ��� �迭�� ��ȯť�� ������.
// �迭�� �̿��ؼ� ��ȯť�� ������ ���� �� ĭ�� ����� �� ���� �ȴ�. (full �� empty�� �Ǵ��ϱ� ����)
// Front = 0 Rear = 0 ���� ����� ������ �� Rear+=1�ڸ��� ����, ������ ���� Front +=1 ���� ���� // Ȥ�� ������ �ڸ��� �ӹ���.
// Rear = (����index + 1) % MAX = 0
// 1ȸ ��ȯ ���� Front���� Rear�� �۾����� ��찡 ���� �� �ֱ� ������ �ݺ����� Rear�� Front�� ����ϴµ� ���ǰ� �ʿ���.
// (Rear+1)%MAX == Front : �� ���ִ� ����
// Rear == Front : ����ִ� ����
// n_items�� ������ full, empty�� �������� ���� ��ȯť�� ������ �����ϱ� ���� ������ �����Ͽ� �����غ���.

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

	EnQueue(get_item("Butters"), &queue); // MAX�� 4�̰� �� ĭ�� �����Ƿ� �Է¿� �����ؾ���.
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

	if (DeQueue(&temp, &queue)) // MAX�� 4�̹Ƿ� �����ؾ���.
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

