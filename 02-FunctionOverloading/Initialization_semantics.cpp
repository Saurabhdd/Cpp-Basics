#include <stdio.h>
#include <stdlib.h>

void test_function();

int main(void)
{
	int i;
	for (i = 0; i < 5; i++)
		test_function();

	return 0;
}

void test_function()
{
	int m = 10;
	int n;
	static int m1 = 0;
	static int n1;

	n = 0;
	n1 = 0;
	int i;

	i = 0;

	while (i < 10)
	{
		m1 = m1 + 1;
		n = n + 1;
		n1 = n1 + 1;
		i = i + 1;
	}

	printf("Final values of m1 = %d, n = %d, n1 = %d\n", m1, n, n1);
}