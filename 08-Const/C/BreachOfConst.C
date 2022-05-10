#include <stdio.h>
#include <stdlib.h>

const int g_num = 10;

int main(void)
{
	const int l_num = 20;

	int* p1 = NULL;
	int* p2 = NULL;

	printf("main(): Initial values of const variables g_num = %d, l_num = %d\n", g_num, l_num);

	p1 = &g_num; //CTW
	p2 = &l_num; //CTW

	//*p1 = 200; //RTE memory violation exception 
	//since global const data is stored in h/w guranteed RO data section
	*p2 = 2000;

	printf("main():  values of const variables after accessed using pointer g_num = %d, l_num = %d\n", g_num, l_num);
}

