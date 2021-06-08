#include "LinkedQueue.h"

void InitializeQueue(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
	pq->n_items = 0;
}

bool QueueIsFull(const Queue* pq)
{
	return pq->n_items == MAXITEMS;
}

bool QueueIsEmpty(const Queue* pq)
{
	return pq->n_items == 0;
}

int QueueItemCount(const Queue* pq)
{
	return pq->n_items;
}

bool EnQueue(Item item, Queue* pq)
{
	if (QueueIsFull(pq))
	{
		printf("EnQueue Error : Queue is full.\n");
		return false;
	}

	Node* new_node = (Node*)malloc(sizeof(Node));
	if (new_node == NULL)
	{
		printf("Malloc() Error.\n");
		return false;
	}
	new_node->item = item;
	new_node->next = NULL;

	if (QueueIsEmpty(pq))
		pq->front = new_node;
	else
		pq->rear->next = new_node;

	pq->rear = new_node;
	pq->n_items += 1;
	return true;
}

bool DeQueue(Item* pitem, Queue* pq)
{
	if (QueueIsEmpty(pq))
	{
		printf("DeQueue Error : Queue is empty.\n");
		return false;
	}

	else
	{
		Node* temp = pq->front;

		*pitem = pq->front->item;

		if (pq->front == pq->rear)
		{
			pq->rear = NULL;
			pq->front = NULL;
		}
		else
			pq->front = pq->front->next;

		free(temp);
		pq->n_items -= 1;
		return true;
	}
}

void EmptyTheQueue(Queue* pq)
{
	Node* pnode = pq->front;
	Node* temp;
	int count = 0;
	while (pnode != NULL)
	{
		temp = pnode->next;
		free(pnode);
		pnode = temp;
		count++;
	}

	InitializeQueue(pq);

	printf("%d items are deleted.\n", count);
}

void TraverseQueue(Queue* pq, void (*func)(Item item))
{
	Node* pnode = pq->front;
	while (pnode != NULL)
	{
		(*func)(pnode->item);
		pnode = pnode->next;
	}
}