#include <stdio.h>
#include <stdlib.h>

void swap_1(int*, int*);
void swap_2(int&, int&);

int main(void)
{
	int m = 10;
	int n = 20;

	printf("Before swap_1 m = %d, n = %d\n", m, n);
	swap_1(&m, &n);

	printf("After swap_1 m = %d, n = %d\n", m, n);

	swap_2(m, n);
	printf("After swap_2 m = %d, n = %d\n", m, n);
}

void swap_1(int* p, int* q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void swap_2(int& p, int& q)
{
	int temp;
	temp = p;
	p = q;
	q = temp;
}