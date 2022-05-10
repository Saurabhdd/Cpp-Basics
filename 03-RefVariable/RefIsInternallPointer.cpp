#include <stdio.h>
#include <stdlib.h>

void f1(int*);
void f2(int&);

int main(void)
{
	int m = 10;
	f1(&m);
	f2(m);
	printf("m = %d\n", m);
}

void f1(int* p)
{
	*p = 500;
}

void f2(int& ref)
{
	ref = 600;
}