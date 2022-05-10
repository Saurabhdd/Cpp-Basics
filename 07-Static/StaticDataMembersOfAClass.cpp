#include <stdio.h>
#include <stdlib.h>

class X
{
private:
	int p;
	static int q;
public:
	static int r;

	void addrp()
	{
		printf("addrp: address of this: %p, address of this->p: %p\n", this, &p);
	}

	void addrq()
	{
		printf("addrq: address of q: %p\n", &q);
	}
};

int X::q = 10;
int X::r = 100;

int main(void)
{
	X obj;
	printf("main: size of object: X= %llu\n", sizeof(obj));

	X obj1, obj2;
	obj1.addrp();
	obj1.addrq();
	obj2.addrp();
	obj2.addrq();

	obj.r = 10;
	X::r = 20;

	return 0;

}