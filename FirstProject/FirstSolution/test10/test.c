#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define MONTH 12
#define YEARS 3

int main()
{
	const double weather_2019[MONTH] = { -0.9,1.0,7.1,12.1,19.4,22.5,25.9,27.2,22.6,16.4,7.6,1.4 };
	const double weather_2018[MONTH] = { -4.0,-1.6,8.1,13.0,18.2,23.1,27.8,28.8,21.5,13.1,7.8,-0.6};
	const double weather_2017[MONTH] = { -1.8,-0.2,6.3,13.9,19.5,23.3,26.9,25.9,22.1,16.4,5.6,-1.9 };

	double weather[YEARS][MONTH];
	double temp[MONTH];

	int i;
	int j;
	double y_avg = 0;
	double m_avg = 0;

	for (i=0; i < YEARS; i++)
	{
		for (j=0; j < MONTH; j++)
		{
			switch (i)
			{
			case 0:
				weather[i][j] = weather_2017[j];
				break;
			case 1:
				weather[i][j] = weather_2018[j];
				break;
			case 2:
				weather[i][j] = weather_2019[j];
				break;
			}
		}
	}

	printf("[Temperatrue Data]\n");
	printf("Year index :\t");
	for (i = 0; i < MONTH; i++)
	{
		printf("%d\t", i + 1);
	}
	printf("\n");
	
	for (i = 0; i < YEARS; i++)
	{
		printf("Year %d\t   :\t",i);
		for (j = 0; j < MONTH; j++)
		{
			printf("%.1lf\t", weather[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	printf("[Yearly average temperatrues of 3 years]\n");
	for (i = 0; i < YEARS; i++)
	{
		for (j = 0; j < MONTH; j++)
		{
			y_avg += weather[i][j];
		}
		y_avg /= MONTH;
		printf("Year %d : average temperature = %.1lf\n", i, y_avg);
		y_avg = 0;
	}
	printf("\n");
	
	
	printf("[Monthly average temperatures for 3 years]\n");
	printf("Year index :\t");
	for (i = 0; i < MONTH; i++)
	{
		printf("%d\t", i + 1);
	}
	printf("\n");

	printf("Avg temps  :\t");
	for (j = 0; j < MONTH; j++)
	{
		for (i = 0; i < YEARS; i++)
		{
			m_avg += weather[i][j];
		}
		m_avg /= YEARS;
		printf("%.1lf\t", m_avg);
		m_avg = 0;
	}
	printf("\n");

	return 0;
}

