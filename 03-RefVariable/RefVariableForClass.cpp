#include<stdio.h>
#include<stdlib.h>

class Date
{
private:
	int day, month, year;

public:
	Date(int _d, int _m, int _y) : day(_d), month(_m), year(_y)
	{

	}

	void Show()
	{
		printf("%d-%d-%d\n", day, month, year);
	}
};



Date* get_date_1(int d, int m, int y);
Date& get_date_2(int d, int m, int y);

int main(void)
{
	Date* d1 = get_date_1(11, 5, 1992);
	d1->Show();

	Date& d2 = get_date_2(5, 9, 1989);
	d2.Show();
}

Date* get_date_1(int d, int m, int y)
{
	return new Date(d, m, y);
}

Date& get_date_2(int d, int m, int y)
{
	return *(new Date(d, m, y));
}