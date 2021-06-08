#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int ch;
	FILE* fr;
	FILE* fw;

	unsigned long count = 0;

	if (argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fr = fopen(argv[1], "r")) == NULL)
	{
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((fw = fopen("output.txt", "w")) == NULL)
	{
		printf("can't write");
		exit(EXIT_FAILURE);
	}
	

	/*
		fopen mode strings for text files
		- r : reading
		- w : creating-and-writing or over-writing
		- a : appending or creating-and-writing
		- r+ : both reading and writing
		- w+ : reading and writing, over-writing or creating
		- a+ : reading and writing, appending or creating
	*/

	//while ((ch = fgetc(fr)) != EOF)
	//{
	//	//putc(ch, stdout); // same as putchar(ch);
	//	fputc(ch, stdout);

	//	count++;
	//}

	while ((ch = fgetc(fr)) != EOF)
	{
		//putc(ch, stdout); // same as putchar(ch);
		fputc(ch, stdout);
		fputc(ch, fw);

		count++;
	}

	fputs("\n\nthis file is created by test23", fw);


	fclose(fr);
	fclose(fw);
	printf("\n");
	printf("FILE %s has %lu characters\n", argv[1], count);
}