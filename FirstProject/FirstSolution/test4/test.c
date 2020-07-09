#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void print_char(int num_of_bar,char ch,int is_changeline)
{
	for (int i = 0; i < num_of_bar; i++)
		printf("%c", ch);
	if (is_changeline==1)
		printf("\n");
}

int main()
{
	char name[] = {"Park Jeong been"};
	char addr[] = {"Goyang, Gyeonggi"};
	int margin = 10;

	int name_len = strlen(name);
	int addr_len = strlen(addr);
	int width = (name_len>addr_len)?name_len+margin:addr_len+margin;
	int blank = (width - ((name_len > addr_len) ? name_len : addr_len)) / 2;

	print_char(width, '*',1);
	print_char(blank, ' ', 0);
	printf("%s\n", name);
	print_char(blank, ' ', 0);
	printf("%s\n", addr);
	print_char(width, '*',1);
	
	return 0;
}

