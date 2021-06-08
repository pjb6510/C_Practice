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

void Initialize(Stack* stack); // 비어있을 때 top = -1
bool IsFull(const Stack* stack); // top(현재 스택에 쌓인 엘리먼트의 수)과 MAX_STACK_SIZE를 이용해서 여유공간이 있는지 확인.
bool IsEmpty(const Stack* stack);
void Push(Stack* stack, element item);
element Pop(Stack* stack);