#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main()
{
	char input;
	int num_input;
	int num_count=1;

	while (1) {
		printf("Enter the letter of your choice:\n");
		printf("a. avengers    b. beep\n");
		printf("c. count       q. quit\n");
		
		input = getchar();
		while ((getchar()) != '\n') continue;
		if (input == 'a')
			printf("Avengers assemble\n");
		if (input == 'b')
			printf("\a");
		if (input == 'c') {
			printf("Enter an integer :\n");
			scanf("%d",&num_input);
			while (getchar() != '\n') continue;
			for (int i = 0; i < num_input; i++) {
				printf("%d\n", num_count);
				num_count++;
			}
			num_count = 1;
		}
		if (input == 'q') {
			break;
		}
	}
}

