#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Date
{
	int day;
	int month;
	int year;
};

struct Date* make_date(int _d, int _m, int _y);
struct Date* make_date(char* date);
struct Date* make_date(void);

int main(void)
{

}

struct Date* make_date(int _d, int _m, int _y)
{
	struct Date* d = (struct Date*)malloc(sizeof(struct Date));
	assert(d != null);
	d->day = _d;
	d->month = _m;
	d->year = _y;

	return d;
}

struct Date* make_date(char* date)
{
	char* date_part = null;
	char* month_part = null;
	char* year_part = null;

	int length = strlen(date);
	char* newStr = (char*)malloc(length + 1);
	strncpy(newStr, date, length);

	day_part = strtok(newStr, "-");
	month_part = strtok(null, "-");
	year_part = strtok(null, "-");

	struct Date* d = (struct Date*)malloc(sizeof(struct Date));
	assert(d != null);

	d->day = atoi(day_part);
	d->month = atoi(month_part);
	d_year = atoi(year_part);

	return d;

}

struct Date* make_date(void)
{
	struct Date* d = (struct Date*)malloc(sizeof(struct Date));
	assert(d != null);

	d->day = 1;
	d->month = 1;
	d->year = 1970;
}

