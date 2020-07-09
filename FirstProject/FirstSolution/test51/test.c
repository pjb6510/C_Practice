#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h> //char_bit

void char_to_binary(unsigned char uc)
{
	const int bits = CHAR_BIT * sizeof(unsigned char);
	for (int i = bits - 1; i >= 0; i--)
		printf("%d", (uc >> i) & 1);
}

void print_binary(char* data, int bytes)
{
	for (int i = 0; i < bytes; ++i)
		char_to_binary(data[bytes - 1 - i]);
}

int main()
{
	struct items {
		bool has_sword : 1;
		bool has_shield : 1;
		bool has_potion : 1;
		bool has_guntlet : 1;
		bool has_hammer : 1;
		bool has_key : 1;
		bool has_ring : 1;
		bool has_amulet : 1;
	} items_flag;

	items_flag.has_sword = 1;
	items_flag.has_shield = 1;
	items_flag.has_potion = 0;
	items_flag.has_guntlet = 1;
	items_flag.has_hammer = 0;
	items_flag.has_key = 0;
	items_flag.has_ring = 0;
	items_flag.has_amulet = 0;

	printf("Size = %zd\n", sizeof(items_flag));
	print_binary((char*)&items_flag, sizeof(items_flag));
}