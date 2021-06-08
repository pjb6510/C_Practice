#pragma once

#include "element.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 5

typedef struct stack
{
	element items[MAX_STACK_SIZE];
	int top; // index of the element added lastly
} Stack;

void Initialize(Stack* stack); // ������� �� top = -1
bool IsFull(const Stack* stack); // top(���� ���ÿ� ���� ������Ʈ�� ��)�� MAX_STACK_SIZE�� �̿��ؼ� ���������� �ִ��� Ȯ��.
bool IsEmpty(const Stack* stack);
void Push(Stack* stack, element item);
element Pop(Stack* stack);