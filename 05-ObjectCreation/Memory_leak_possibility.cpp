#include <stdio.h>
#include <stdlib.h>

class Date
{
private:
	int day, month, year;

public:
	Date(int _d, int _m, int _y) : day(_d), month(_m), year(_y)
	{

	}

	void show()
	{
		printf("%d-%d-%d\n", day, month, year);
	}
};

Date* get_date_1(int, int, int);
Date& get_date_2(int, int, int);
Date& get_date_3(int, int, int);
Date& get_date_4(int, int, int);
Date get_date_5(int, int, int);

int main(void)
{
	Date* newDate = get_date_1(1, 1, 1970);
	newDate->show();

	Date& newRefDate = get_date_2(11, 5, 1992);
	newRefDate.show();

	delete newDate;
	delete &newRefDate;

	Date& newRefDate_2 = get_date_3(5, 9, 1989);
	printf("main(): Address of newRefDate_2 = %p\n", &newRefDate_2);
	(& newRefDate_2)->show();

	Date& newRefDate_3 = get_date_4(9, 5, 2022);
	printf("main(): Address of newDateRef_3 = %p\n", &newRefDate_3);
	newRefDate_3.show();
	delete &newRefDate_3;

	Date d = get_date_5(1, 1, 1970);
	printf("main(): address of d = %p\n", &d);
	d.show();

}

Date* get_date_1(int d, int m, int y)
{
	Date* d1 = new Date(d, m, y);
	//printf("Address of d1 = %p\n", d1);
	return d1;
}

Date& get_date_2(int d, int m, int y)
{
	return *(new Date(d, m, y));
}

Date& get_date_3(int d, int m, int y)
{
	Date local_object(d, m, y);
	printf("get_date_3():addr(local_date_obj):%p\n", &local_object);
	return local_object;
}

Date& get_date_4(int d, int m, int y)
{
	Date* d1 = new Date(d, m, y);
	printf("get_date_4(): address of pointer date : %p\n", d1);
	return *d1;
}

Date get_date_5(int d, int m, int y)
{
	Date* d2 = new Date(d, m, y);
	printf("get_date_5(): address of pointer date : %p\n", d2);
	return *d2;
}

//conclusion:
//always create pointer variable and not local variable
//in case of get_date_3 there is memory violation