#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	float x;
	char str[] = "Dancing with a Star";

	int arr[100];
	
	/*
		malloc() returns a void type poinster.
		void* : generic pointer

		free() deallocates the memory
	*/

	double* ptr = NULL;
	ptr = (double*)malloc(30 * sizeof(double));
	// double 30개가 들어갈 메모리가 필요하다!(240byte 요청)
	// 240byte에 해당하는 메모리 덩어리의 첫 번째 주소를 포인터로 반환해줌.
	// generic pointer 를 주기 때문에 double*로 캐스팅 해주고 있음.
	// 형변환(캐스팅)을 통해 특정한 자료형의 배열인 것처럼 사용할 수 있음.
	// 만약 받을 수 있는 메모리 공간이 없을 경우 NULL을 반환함.
	// 동적할당 받은 메모리의 변수를 잃어버려서(블록 밖 등) 할당받은 메모리에 접근하지 못하는 경우도 발생하곤 함.
	//	그러나 이 경우 메모리가 반납되지 않았으므로 메모리 주소만 잃어버렸을 뿐, 여전히 할당된 자리를 차지하고 있음.

	if (ptr == NULL)
	{
		puts("Memory allocation failed.");

		exit(1);
	}

	printf("Before free %p\n", ptr);
	free(ptr); //반납! 만약 ptr이 NULL일 경우 아무 일도 일어나지 않음.
	printf("After free %p\n", ptr); //반납을 한 후에도 해당 주소를 포인터는 여전히 갖고 있음.
	ptr = NULL; //반납 후 포인터변수 비우기.
	

	int n = 5;
	ptr = (double*)malloc(n * sizeof(double));

	if (ptr != NULL)
	{
		for (int i = 0; i < n; ++i)
			printf("%f", ptr[i]); // malloc함수는 메모리를 초기화 해주지 않음.
		printf("\n");

		for (int i = 0; i < n; ++i)
			*(ptr + i) = (double)i;

		for (int i = 0; i < n; ++i)
			printf("%f", ptr[i]);
		printf("\n");
	}
	free(ptr);
	ptr = NULL;

	return 0;
}

