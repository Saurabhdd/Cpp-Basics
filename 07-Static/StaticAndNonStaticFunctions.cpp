#include <stdio.h>
#include <stdlib.h>

class X
{
private:
	int p;
	//static int q;
public:
	static int r;
	static int q;

	int get_p()
	{
		return p;
	}

	void set_p(int _p)
	{
		this->p = _p;
	}

	void non_static_member_function()
	{
		printf("non_static_member_function: p = %d, q = %d\n", p, q);
	}

	static void static_function(void)
	{
		printf("static_member_function: q = %d , address of q = %p\n", q, &q);
	}
};


// int X::q = 10; //CTE cannot access private member out of class 
int X::r = 100;
int X::q = 200;

int main(void)
{
	X obj1;

	obj1.get_p();
	obj1.set_p(1000);
	obj1.non_static_member_function();

	//can call static function using object 
	obj1.static_function();
	//we can call static function using class name as well 
	X::static_function();
	X::r = 2;
	
	obj1.r = 20;
}