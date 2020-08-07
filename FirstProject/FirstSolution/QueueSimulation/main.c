#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedQueue.h"

/*
	min_per_cust = 60.0f / average_n_customers_per_hour;
	x : probabilistic number of n_queued_customers per an hour
*/

bool new_customer_visit(double x)
{
	if (rand() * x / RAND_MAX < 1.0)
		return true;
	else
		return false;
}

Item get_customer(long arrival_time)
{
	Item cust;

	cust.processtime = rand() % 3 + 1; // 1 ~ 3 중 하나를 반환
	cust.arrival_time = arrival_time;

	return cust;
}

int main()
{
	Queue wating_queue;
	int simulation_length_in_hours;
	int average_n_customers_per_hour;
	double min_per_cust;
	long cycle, cyclelimit;

	long n_lost_customers = 0; // 잃어버린 손님 수
	long n_queued_customers = 0; // 큐에 들어온 손님 수
	long n_served_customers = 0; // 상품을 받은 손님 수(큐에서 나온 손님 수)
	long sum_line = 0; // 평균을 알기 위해, 전부 몇명의 손님들이 들어왔는지 세는 변수
	int wait_time = 0; // 만들기 시작한 시점부터 다 만들 때 까지 몇 분 남았는가

	long line_wait = 0; // 누적시간

	InitializeQueue(&wating_queue);

	srand((unsigned int)time(0));
	//srand(0) 디버깅용

	printf("How many hours do you want to simulate?\n>> ");
	if(scanf("%d%*c", &simulation_length_in_hours) != 1)
	{
		printf("scanf error.\n");
		exit(1);
	}
	printf("How many customers per hour do you expect?\n>> ");
	if (scanf("%d%*c", &average_n_customers_per_hour) != 1)
	{
		printf("scanf error.\n");
		exit(1);
	}

	cyclelimit = simulation_length_in_hours * 60;
	min_per_cust = 60.0f / average_n_customers_per_hour;

	for (cycle = 1; cycle <= cyclelimit; cycle++)
	{
		if (new_customer_visit(min_per_cust))
		{
			if (QueueIsFull(&wating_queue))
			{
				n_lost_customers += 1;
				printf("%3ld : Customer lost\n", cycle);
			}
			else
			{
				n_queued_customers += 1;

				EnQueue(get_customer(cycle), &wating_queue);
				printf("%3ld : a new customer enqueue.\n", cycle);
			}
		}

		if (wait_time <= 0 && !QueueIsEmpty(&wating_queue))
		{
			Item customer_ready;
			DeQueue(&customer_ready, &wating_queue);

			printf("%3ld : start serving a customer for %d minutes.\n", cycle, customer_ready.processtime);
			wait_time = customer_ready.processtime;
			line_wait += cycle - customer_ready.arrival_time;
			n_served_customers += 1;

		}

		if (wait_time > 0)
			wait_time -= 1;

		sum_line += QueueItemCount(&wating_queue);
	}

	printf("\n");

	if (n_queued_customers > 0)
	{
		printf("customers accepted : %ld\n", n_queued_customers);
		printf("  customers served : %ld\n", n_served_customers);
		printf("              Lost : %ld\n", n_lost_customers);
		printf("average queue size : %.2f\n", (double)sum_line / cyclelimit);
		printf(" average wait time : %.2f minutes\n", (double)line_wait / n_served_customers);
	}
	else
		puts("No customers!");

	EmptyTheQueue(&wating_queue);

	return 0;
}