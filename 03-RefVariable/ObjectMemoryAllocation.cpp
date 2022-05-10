#include <stdio.h>
#include <stdlib.h>

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date()
	{
		this->day = 1;
		this->month = 1;
		this->year = 1970;
	}

	Date(int _day, int _month, int _year)
	{
		this->day = _day;
		this->month = _month;
		this->year = _year;
	}

	void Show()
	{
		printf("Date = %d - %d - %d \n", this->day, this->month, this->year);
	}


};


//different types of memory allocation
int main(void)
{
	Date* pDate = 0;
	pDate = new Date;

	pDate->Show();

	Date* pDate_1 = new Date(11, 5, 1992);
	pDate_1->Show();

	delete pDate;
	delete pDate_1;
	pDate = 0;
	pDate_1 = 0;

	return 0;
}