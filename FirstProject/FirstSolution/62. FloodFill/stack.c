#include "stack.h"

void Initialize(Stack* stack)
{
	stack->top = -1;
}

bool IsFull(const Stack* stack)
{
	if (stack->top >= MAX_STACK_SIZE - 1)
		return true;
	else
		return false;
}

bool IsEmpty(const Stack* stack)
{
	if (stack->top <= -1)
		return true;
	else
		return false;
}

void Push(Stack* stack, element item)
{
	if (IsFull(stack) == true)
	{
		printf("Push Error : Stack is full.\n");
	}

	else
	{
		stack->items[++stack->top] = item;
	}
}

element Pop(Stack* stack)
{
	if (IsEmpty(stack) == true)
	{
		printf("Pop Error : Stack is Empty.\n");
		element dummy = { -1 };
		return dummy;
	}

	else
	{
		return stack->items[stack->top--];
	}
}