/***********************************************
Add Error check in day_of_year() and month_day()
************************************************/
#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(int argc, char const *argv[]) {
	int *month;
	int *day;
	printf("num of day is: %d\n", day_of_year(1994,2,9));
	printf("num of day is: %d\n", day_of_year(1994,13,9));
	printf("num of day is: %d\n", day_of_year(1994,2,32));
	month_day(1994,40,month,day);
	printf("month is: %d,day is: %d\n", *month,*day);
	month_day(1994,400,month,day);
	printf("month is: %d,day is: %d\n", *month,*day);
	return 0;
}


/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
	int i, leap;
	if (month <= 0 || month > 12) {
		printf("month is not in range!\n");
		return -1;
	}

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if (day <= 0 || day > daytab[leap][month]) {
		printf("day is not in range!\n");
		return -1;
	}

	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if ((leap && yearday > 366) || (!leap && yearday > 365)) {
		printf("number of days is not in range!\n");
		*pmonth = -1;
		*pday = -1;
	}

	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}