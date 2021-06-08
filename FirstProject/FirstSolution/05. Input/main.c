#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

void display(ch, height, width)
{
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			printf("%c", ch);
		}
		printf("\n");
	}
}

int main()
{
	char c;
	int row, col;

	while ((c = getchar()) != '\n')
	{
		scanf("%d %d", &row, &col);
		while (getchar() != '\n') continue;
		display(c, row, col);
	}

	return 0;
}

