#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define LEN 20

struct names {
	char given[LEN];
	char family[LEN];
};

struct reservation {
	struct names guest;
	struct names host;
	char food[LEN];
	char place[LEN];

	//TIME
	int year;
	int month;
	int day;
	int hours;
	int minutes;
};

int main()
{
	struct reservation res = {
		.guest = {"Nick", "Carraway"},
		.host = {"Jay", "Gatsby"},
		.place = {"the Gatsby mansion"},
		.food = {"Escargot"},
		.year = 1925,
		.month = 4,
		.day = 10,
		.hours = 18,
		.minutes = 30
	};

	/*
	Dear Nick Carraway,
	I would like to serve you Escargot.
	Please visit the Gatsby mansion on 10/4/1925 at 18:30.
	Sincerely,
	Jay Gatsby
	*/

	printf("Dear %s %s,\nI would like to serve you %s.\nPlease visit the %s on %d/%d/%d at %d:%d\nSincerely,\n%s %s\n",res.guest.given,res.guest.family, res.food, res.place, res.day, res.month, res.year, res.hours, res.minutes, res.host.given, res.host.family);

	return 0;
}
