#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 10;
	int& X = n;

	printf("Address of n= %p\n", &n);
	printf("Address of X= %p\n", &X);

	printf("n = %d\n", n);
	X = 600;
	printf("n = %d\n", n);
}