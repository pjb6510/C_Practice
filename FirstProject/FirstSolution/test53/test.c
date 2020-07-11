#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45

struct movie {
	char title[TSIZE];
	float rating;
	struct movie* next;
};

typedef struct movie* p_movie;

void print_all(struct movie* head)
{
	printf("----------------\n");
	printf("Head address = %zd\n", (size_t)head);
	struct movie* search = head;
	while (search != NULL)
	{
		printf("%zd \"%s\" %.1f %zd \n", (size_t)search, search->title,
			search->rating, (size_t)search->next);
		search = search->next;
	}
}

int main()
{
	p_movie head = NULL;

	/* first node */
	p_movie new_node = malloc(sizeof(struct movie));
	if (new_node == NULL)
	{
		printf("Malloc() Error\n");
		exit(1);
	}
	strcpy(new_node->title, "Avatar");
	new_node->rating = 9.5f;
	new_node->next = NULL;

	if (head == NULL)
		head = new_node;

	print_all(head);

	/* second node */
	new_node = malloc(sizeof(struct movie));
	if (new_node == NULL)
	{
		printf("Malloc() Error\n");
		exit(1);
	}
	strcpy(new_node->title, "Aladin");
	new_node->rating = 8.0f;
	new_node->next = NULL;

	/* Add front */
	p_movie temp = head;
	head = new_node;
	new_node->next = temp;

	print_all(head);

	/* third node */
	new_node = malloc(sizeof(struct movie));
	if (new_node == NULL)
	{
		printf("Malloc() Error\n");
		exit(1);
	}
	strcpy(new_node->title, "Wonder Woman");
	new_node->rating = 8.5f;
	new_node->next = NULL;

	/* Add back */
	
	// 1. find last node
	p_movie search = head;
	while (search->next != NULL)
	{
		search = search->next;
	}

	// 2. link
	search->next = new_node;

	print_all(head);

	/* Find and delete an item */

	search = head;
	p_movie prev = NULL;

	int count = 0;
	while (search != NULL)
	{
		if (strcmp(search->title, "Aladin") == 0) break; //알라딘 검색.

		prev = search;
		search = search->next;
		count++;
	}

	//헤드 -> 삭제할 노드 -> 다음노드...
	//헤드 -> 다음노드... 로 변경.
	//삭제할 노드를 free

	if (search == NULL) //못찾으면 검색내용이 잘못된것.
	{
		printf("Wrong title\n");
		return;
	}
	if (prev == NULL) //첫 값(head)이 검색한 값이면[이전값(prev)가 null이면 삭제할 값이 첫값이니까.] head완장을 두 번째 값에게 넘겨줌. (검색한 값은 삭제되어야 하니까)
		head = search->next;
	else // 첫 값이 검색한 값이 아니면, 삭제할 값의 이전값(prev)에 삭제할 값의 다음값(next) 주소를 연결해줌.
		prev->next = search->next;
	free(search); //삭제.
	
	print_all(head);

	return 0;
}	
