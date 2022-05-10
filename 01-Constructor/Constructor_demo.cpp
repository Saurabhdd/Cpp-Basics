#include <stdio.h>
#include <stdlib.h>

class Date
{
private:
	int day;
	int month;
	int year;

public:
	//parameterized constructor
	Date(int _day, int _month, int _year)
	{
		printf("Address of this = %p\n", this);
		printf("_day=%d, _month=%d, _year=%d\n", _day, _month, _year);

		this->day = _day;
		this->month = _month;
		this->year = _year;
	}

	//default constructor
	Date()
	{
		printf("This is default constructor this = %p\n", this);
		this->day = 1;
		this->month = 1;
		this->year = 1970;
	}

	void show()
	{
		printf("Date = %d - %d - %d\n", this->day, this->month, this->year);
	}


};

int main(void)
{
	Date d1(11, 1, 2022);
	Date d2;

	printf("Address of D1 = %p\n", &d1);
	printf("Address of D2 = %p\n", &d2);

	d1.show();
	d2.show();
}