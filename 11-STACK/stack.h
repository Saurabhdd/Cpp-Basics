#ifndef _STACK_H
#define _STACK_H

#include"list.h"

const int STACK_EMPTY = LIST_EMPTY;

class stack
{
private:
	list* p_list;

public:
	//constructor
	stack();

	//destructor
	~stack();

	//interface functionalities
	status_t push(data_t);
	status_t pop(data_t*);
	status_t top(data_t*);
	bool is_stack_empty();

};

#endif // !_STACK_H
