#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct kid
{
	char name[100];
	int height;
};

int compare(const void* first, const void* second);

int main()
{
	struct kid my_friends[] = {
		"Jack Jack", 40, "Geenie", 300, "Aladdin", 170, "Piona", 150
	};

	const int n = sizeof(my_friends) / sizeof(struct kid);

	qsort(my_friends, n, sizeof(struct kid), compare);

	for (int i = 0; i < n; ++i)
		printf("%s    \t%d\n", my_friends[i].name, my_friends[i].height);

	return 0;
}

int compare(const void* first, const void* second)
{
	struct kid* first_k;
	struct kid*	second_k;
	first_k = first;
	second_k = second;

	if (first_k->height > second_k->height)
		return 1;
	else if (first_k->height < second_k->height)
		return -1;
	else
		return 0;
}