#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main()
{
	{
		FILE* fp = fopen("binary_file", "wb");

		double d = 1.0 / 3.0;
		int n = 123;
		int* parr = (int*)malloc(sizeof(int) * n);
		if (!parr) exit(1);
		for (int n = 0; n < 123; ++n)
			*(parr + n) = n * 2;

		fwrite(&d, sizeof(d), 1, fp); //fwrite(주소, 크기, 갯수, 파일포인터)
		fwrite(&n, sizeof(n), 1, fp);
		fwrite(parr, sizeof(int), n, fp);

		fclose(fp);
		free(parr);
	}

	{
		FILE* fp = fopen("binary_file", "rb");
		double d;
		int n = 0;
		fread(&d, sizeof(d), 1, fp);
		fread(&n, sizeof(n), 1, fp);

		int* parr = (int*)malloc(sizeof(int) * n);
		if (!parr) exit(1);

		fread(parr, sizeof(int), n, fp);

		printf("feof = %d\n", feof(fp));

		printf("%f\n", d);
		printf("%d\n", n);
		for (int i = 0; i < n; ++i)
			printf("%d ", *(parr + i));
		printf("\n");

	}
	// Total size is 8*1 + 4*1 + 123*4 = 504byte

	
}