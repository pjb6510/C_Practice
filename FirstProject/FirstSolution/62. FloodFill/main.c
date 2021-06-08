#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "stack.h"

#define WIDTH 7
#define HEIGHT 7

static int map[HEIGHT][WIDTH] = {
	0,0,0,0,0,0,0,
	0,1,1,1,1,1,0,
	0,1,0,0,0,1,0,
	0,1,0,0,0,1,0,
	0,1,0,0,0,1,0,
	0,1,1,1,1,1,0,
	0,0,0,0,0,0,0
};

void print_map()
{
	for (int j = 0; j < 7; j++) 
	{
		for (int i = 0; i < 7; i++)
		{
			printf("%d ", map[j][i]);
		}
		printf("\n");
	}
	printf("\n");
}

element get_element(const int i, const int j)
{
	element new_element;
	new_element.i = i;
	new_element.j = j;
	return new_element;
}

print_stack(const Stack* stack)
{
	printf("Stack : ");
	if (IsEmpty(stack) == true)
		printf("Empty");
	else
		for (int i = 0; i <= stack->top; i++)
			printf("(%d, %d) ", stack->items[i].i, stack->items[i].j);
	printf("\n");
}


int main() 
{
	print_map();

	Stack to_visit;
	Initialize(&to_visit);

	Push(&to_visit, get_element(0, 0));
	//Push(&to_visit, get_element(3, 3));

	while (IsEmpty(&to_visit) != true)
	{
		element cell = Pop(&to_visit);
		
		if (map[cell.j][cell.i] == 1)
			continue;

		map[cell.j][cell.i] = 1;

		//--------------------------------------------------
		if (cell.i != 0 && map[cell.j][cell.i - 1] == 0) //push to left
			Push(&to_visit, get_element(cell.i-1, cell.j));
		if (cell.j != HEIGHT-1 && map[cell.j + 1][cell.i] == 0) //push to down
			Push(&to_visit, get_element(cell.i, cell.j+1));
		if (cell.i != WIDTH-1 && map[cell.j][cell.i + 1] == 0) //push to right
			Push(&to_visit, get_element(cell.i+1, cell.j));
		if (cell.j != 0 && map[cell.j - 1][cell.i] == 0) //push to up
			Push(&to_visit, get_element(cell.i, cell.j-1));

		//--------------------------------------------------
		system("cls");
		print_stack(&to_visit);
		printf("Cell : (%d, %d)\n", cell.i, cell.j);
		print_map();
		int dummy = _getch();
	}

	printf("Result : \n");
	print_map();
}