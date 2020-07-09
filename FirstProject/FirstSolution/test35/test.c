#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 41
#define MAXAUTL 31

struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float price;
};

struct rectangle
{
	double width;
	double height;
};

double rect_area(struct rectangle r)
{
	return r.width * r.height;
}

double rect_area_ptr(struct rectangle* r)
{
	return r->width * r->height;
}

int main()
{
	struct book book_to_read = { "Crime and punishment", "Fyodor Dostoyevsky", 11.25f };
	//구조체를 처음 만들때 초기화는 가능하지만 이후 직접 대입은 불가능함.
	//book_to_read = {"Alice in Wonderland", "Lewis Carroll", 20.3f}; //Error
	
	//첫 번째 방법
	strcpy(book_to_read.title, "Alice in Wonderland");
	strcpy(book_to_read.author, "Lewis Carroll");
	book_to_read.price = 20.3f;

	//두 번째 방법
	struct book book2 = { "Alice in Wonderland", "Lewis Carroll", 20.3f };
	book_to_read = book2;

	//세 번째 방법 - 복합리터럴
	book_to_read = (struct book){ "Alice in Wonderland", "Lewis Carroll", 20.3f };// '(struct~'는 l-value임. 즉, 주소를 가지고 있음.
	
	printf("%s %s\n", book_to_read.title, book_to_read.author);

	//너비 구하기 #1
	struct rectangle rec1 = { 1.0, 2.0 };
	double area = rect_area(rec1);

	//너비 구하기 #2 (한 번만 사용할 것인데, 굳이 구조체 변수 하나를 만들어야 하나 싶을때)
	area = rect_area((struct rectangle) { 1.0, 2.0 });
	area = rect_area_ptr(&(struct rectangle) { .height = 3.0, .width = 2.0 }); //주소를 가짐.
	printf("%f\n", area);

	return 0;
	
}