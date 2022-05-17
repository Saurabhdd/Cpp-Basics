#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

stack::stack()
{
	//initializing stack
	p_list = list::create_list();
}

stack::~stack()
{
	delete p_list;
	p_list = 0;
}


status_t stack::push(data_t data_to_push)
{
	p_list->insert_at_end(data_to_push);
	return SUCCESS;
}

status_t stack::pop(data_t* data_to_pop)
{
	p_list->pop_end(data_to_pop);
	return SUCCESS;
}

status_t stack::top(data_t* top_data)
{
	 p_list->get_end(top_data);
	 return SUCCESS;
}

bool stack::is_stack_empty()
{
	return p_list->is_list_empty();
}