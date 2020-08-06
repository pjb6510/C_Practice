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
	Queue cust_queue;
	int hours;
	int n_cust;

	printf("How many hours do you want to simulate?\n>> ");
	scanf("%d%*c", &hours);
	printf("How many customers per hour do you expect?\n>> ");
	scanf("%d%*c", &n_cust);

	
}