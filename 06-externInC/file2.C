#include <stdio.h>

extern int X;
extern int test_func_2(int, int);

void test_func_1(void)
{
	int rs;
	rs = test_func_2(10, 30);
	printf("file2: test_func(): X = %d\n", X);
	printf("file2: test_func(): rs = %d\n", rs);
}