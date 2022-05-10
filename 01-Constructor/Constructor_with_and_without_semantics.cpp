#include <stdio.h>
#include <stdlib.h>

class Date
{
private:
	int day;
	int month;
	int year;

public:
	//constructor with initialization semantics
	Date(int _d, int _m, int _y) : day(_d), month(_m), year(_y)
	{
		printf("Date = %d - %d - %d\n", this->day, this->month, this->year);
	}

	//constructor without initialization semantics
	/*
	Date(int _d, int _m, int _y)
	{
		this->day = _d;
		this->month = _m;
		this->year = _y;
	}
	*/
};

int main(void)
{
	Date d(1, 1, 1970);
	Date* pDate = new Date(11, 5, 1992);

	delete pDate;
	pDate = 0;
}