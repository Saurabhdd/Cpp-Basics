#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>

class Singleton
{
private:
	int m, n;
	static int obj_count;
	
	Singleton(int _m, int _n) : m(_m), n(_n)
	{
		//what if friend betrays you!!
		if (obj_count > 0)
			throw std::runtime_error("Singleton!!!");
	}

public:

	static Singleton* get_singleton_object(int _m, int _n)
	{
		if (obj_count == 0)
		{
			Singleton* p = new Singleton(_m, _n);
			obj_count = 1;
			return p;
		}
		else
		{
			puts("Singleton object has already been created!");
			return (NULL);
		}
	}
};

int Singleton::obj_count = 0;

int main(void)
{
	Singleton* pSingleton = Singleton::get_singleton_object(100, 200);
	if (pSingleton != NULL)
		puts("The singleton object has been created\n");
	else
		puts("Either the singleton object has been created or memory allocation failed\n");

	Singleton* p2 = Singleton::get_singleton_object(10, 20);

}