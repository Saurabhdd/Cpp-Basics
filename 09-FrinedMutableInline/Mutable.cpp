#include <stdio.h>
#include <stdlib.h>

class Date
{
private:
	int day, month, year;
	const int test;
	mutable int nr_get_day_calls;

public:
	Date(int _d, int _m, int _y, int _t) : day(_d), month(_m), year(_y), test(_t) {}

	int get_day() const
	{
		nr_get_day_calls = nr_get_day_calls + 1;
		//test = test + 1; //CTE 
		// const member function cannot access data members 
		//Mutable qualifier allows const member function to access class data members

		printf("get_day(): accessing const member in const member function : test = %d\n", test);

		return day;
	}
};

int main(void)
{
	Date t1(11, 5, 1992, 3);

	t1.get_day();
}