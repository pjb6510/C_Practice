#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

struct person
{
	char name[MAX];
	int age;
	float height;

	// 구조체 선언 단계에서는 메모리를 할당받지 않음.
};

int main()
{
	int flag;

	struct person genie; //메모리 할당.
	strcpy(genie.name, "Will Smith");
	genie.age = 1000;
	flag = scanf("%f", &genie.height);
	printf("%f\n", genie.height);

	struct person princess = { "Naomi Scott", 18, 160.0f };

	struct person beauty = {
		.age = 19,
		.name = "Bell",
		.height = 150.0f
	};

	struct person* someone;
	someone = &genie;

	someone->age = 1001; // 포인터는 '.' 이 아니라 '->'으로 접근
	printf("%s %d\n", someone->name, (*someone).age); // (*구조체포인터).변수 로 접근가능.

	struct book
	{
		char title[MAX];
		float price;
	};

	/* NO TAG */

	struct {
		char farm[MAX];
		float price;
	} apple, apple2;

	strcpy(apple.farm, "Trade Joe");
	apple.price = 1.2f;


	typedef struct person my_person; //struct person을 my_person으로 치환.
	my_person p3;

	typedef struct person person; // 같은 이름도 가능. struct 치기 귀찮으므로 이러한 용법이 자주 사용됨.
	person p4;

	typedef struct {
		char name[MAX];
		char hobby[MAX];
	} friend; // 이런 모양으로, 구조체 선언할때도 가능.

	friend f4;
}