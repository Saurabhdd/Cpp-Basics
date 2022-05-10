#include<stdio.h>
#include<stdlib.h>

void case_1(void);
void case_2(void);
void case_3(void);
void case_4(void);

int main(void)
{
	case_1();
	case_2();
	case_3();
	case_4();

	return 0;
}


void case_1(void)
{
	int m, n;
    int* p;
	int* p1;

	//reading and wrting the pointer
	p = &m; //wrting the pointer
	p1 = p;  //reading the pointer(in this case p is read)

	//reading and writing the pointee using pointer
	*p = 20; //writing on m through p
	n = *p; //reading m (the pointee)  through p

}

void case_2(void)
{
	int m, n;
	const int* p;
	const int* p1;

	//here the pointer  is pointing to const int (pointee)
	//pointer can be read or write
	//reading and writing the pointer
	p = &m; //writing the pointer
	p1 = p; //reading the pointer 

	//through p we can read from pointee but cannot write to it
	//*p = 10; //CTE
	n = *p; //we can read from m through p
}

void case_3(void)
{
	int m = 10;
	int n = 20;
	int* p1;
	int* const p = &m; //Initialzation is must as the pointer is this case is const

	//we can read and write pointee using pointer
	n = *p; //reading m using p
	*p = 100; //writing on m using p

	p1 = p; //we can read the pointer
	//however we cannot write the pointer
	//p = &n; //CTE
}

void case_4(void)
{
	int m = 10;
	int n = 20;

	int* p1;
	const int* const p = &m;

	//through p we cannot write pointer
	//we can read pointer
	p1 = p;

	//we cannot write pointer
	//p = &n; //CTE

	//we cannot write pointee using pointer 
	//since the pointer is pointing to constant integer
	//*p = 100; //CTE

	//we can read the pointee using pointer
	n = *p;
}