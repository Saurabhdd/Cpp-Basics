#include <stdio.h>
#include <stdlib.h>

class X
{
private:
	int m;
	const int n;
	static const int p; //use case: a constant value required across the objects

public:
	X(int _m, int _n) : m(_m), n(_n)
	{
		//Initialization symantics is required in const member data 
		//assignment works on m but not on n
	}

	int get_m() const
	{
		return m;
	}

	int get_n() const
	{
		return n;
	}

	void set_m(int _m)
	{
		this->m = _m;
	}

	//set n will not work 

	//we can only read p in static or non-static member functions
	static void read_p(void)
	{
		printf("read_p(): address of p : %p\n", &p);
	}

	 void print_p() const
	{
		printf("print_p(): p = %d\n", p);
	}

};

const int X::p = 100;

int main(void)
{
	//object qualifies with const keyword 
	//can only call const member functions
	//However all objects can call member function qualified with const keyword

	const X obj_const(10, 20);

	//obj_const.set_m(24); //CTE
	int member_m = obj_const.get_m();
	printf("member_m = %d\n", member_m);

	obj_const.read_p();

	X::read_p();
	
	//printf("static const member data p == %d\n", X::p);  //CTE cannot access private members  of class
	obj_const.print_p();
}