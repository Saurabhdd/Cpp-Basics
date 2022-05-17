#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
	stack* p_stack = new stack;
	p_stack->push(10);
	p_stack->push(20);
	p_stack->push(30);
	p_stack->push(40);
	p_stack->push(50);

	int p1;
	p_stack->pop(&p1); // p1 = 50
	printf("%d  ", p1);
	p_stack->pop(&p1); //p1 = 40
	printf("%d  ", p1);

	if (p_stack->is_stack_empty())
	{
		printf("stack is empty\n");
	}

	p_stack->top(&p1); //p1 = 30
	printf("%d  ", p1);
	p_stack->pop(&p1); //p1 = 30
	printf("%d  ", p1);

}