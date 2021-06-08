#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct  names
{
	char first[20];
	char last[20];
};

struct person
{
	int id;
	struct names name; //nested structure member
};

struct person2
{
	int id;
	struct { char first[20]; char last[20]; }; // anonymous structure
};

int main()
{
	struct person ted = { 123, {"Bill", "Gates"} };
	puts(ted.name.first);

	struct person2 ted2 = { 124, {"Steve", "wozniak"} };
	puts(ted2.first);
}