#include <stdio.h>
#include <stdlib.h>

class Test
{
private:
	int m, n;

public:
	Test(int _m, int _n) : m(_m), n(_n) {}

	void show()
	{
		printf("show(): m = %d, n = %d\n", m, n);
	}

	friend void friend_func(void);
};

void friend_func(void)
{
	printf("This is friend function which can access data members of class\n");
	//we need to create an object 
	//since this pointer is not availble in friend function
	//this is not a member function of a class

	Test t1(10, 20);

	t1.show();
	t1.m = 20;
	t1.n = 10;

	printf("friend_func(): m = %d, n = %d\n", t1.m, t1.n);
}



int main(void)
{
	Test t_obj(20, 30);
	//t_obj.friend_func();  //CTE not accessible over object

	friend_func();
}