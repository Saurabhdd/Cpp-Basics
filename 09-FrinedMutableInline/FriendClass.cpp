#include <stdio.h>
#include <stdlib.h>

class Test
{
private:
	int m, n;

public:
	Test(int _m, int _n) : m(_m), n(_n) {}

	friend class X;
};

class X
{
public:
	void f1()
	{
		Test t1(10, 20);
		t1.m = 100;
		t1.n = 200;
	}

	void f2()
	{
		Test* t2 = new Test(30, 40);
		t2->m = 300;
		t2->n = 400;

		delete t2;
		t2 = 0;
	}

	void f3()
	{
		Test& t3 = *(new Test(50, 60));
		t3.m = 500;
		t3.n = 600;

		delete& t3;
	}
};


int main(void)
{
	X obj_X;
	obj_X.f1();
	obj_X.f2();
	obj_X.f3();
}