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

	int get_month()
	{
		printf("Month = %d\n", this->month);
		return this->month;
	}
};

int main(void)
{
	Date d1(1, 2, 1970);

	d1.get_month();
	//here we will print address of d1 and address of all other private variables
	printf("Address of d1 = %p\n", &d1);
	
	//Address of d1 is also the adress of first non - static data member of the class
	int* p1 = (int*)&d1;

	printf("printing p1 = %d\n", *p1);

	//Deriving this further we can access other non-static data members of the class as well
	//for accessing the next integer variable we need to jump 4 bytes, since the object is typecasted  to 
	//integer then we can add 1 in the pointer value to jump to next non-static data member

	p1 = (int*)&d1 + 1;
	printf("Address of p1 = %p\n", p1);
	printf("Printing p1 for next non-static data member = %d\n", *p1);

	//this also can be done by typecasting object firstly to char and then pushing pointer with number of
	//required bytes
	p1 = (int*)((char*)&d1 + 4);
	printf("Address of p1 = %p\n", p1);
	printf("Printing p1 for next non-static data member = %d\n", *p1);

	//accessing the next by adding 8 bytes to d1
	p1 = (int*)((char*)&d1 + 8);
	printf("Address of p1 = %p\n", p1);
	printf("Printing p1 for next non-static data member = %d\n", *p1);
}