#pragma once

#define SUCCESS 1
#define FAIL 0
#define LIST_EMPTY 0
#define LIST_DATA_NOT_FOUND 0

typedef int data_t;
typedef int status_t;
typedef int len_t;


//this is node class which represents struct node in C
class list_node
{
private:
	data_t data;
	list_node* prev;
	list_node* next;

public:
	list_node();

	//getters and setters
	data_t get_data();
	list_node* get_prev();
	list_node* get_next();
	void set_prev(list_node*);
	void set_next(list_node*);
	void set_data(data_t);
};

typedef list_node list_t;
typedef list_t node_t;





//this is list class which creates the list
//and provides functionalities over the list

class list
{
private:
	//data member
	//this is const pointer to head node
	//we do not want the head node to point to any other node
	list_node* const headNode = new list_node;

	//private member functions
	void generic_insert(list_node*, list_node*, list_node*);
	void generic_delete(list_node*);
	node_t* get_list_node(data_t);
	node_t* locate_node(data_t);
	void* xmalloc(size_t);
	list_node* get_headNode();


public:

	//public member functions
	list();

	
	//setter to headnode is not applicable

	//auxillary operations
	//********************************************************************
	static list* create_list(void);

	status_t insert_at_begin(data_t);

	////insert at end
	status_t insert_at_end(data_t);

	////insert at position
	//status_t insert_at_pos(list_t*, int, data_t);

	////get end
	status_t get_end(data_t*);

	////get begin
	status_t get_begin(data_t*);

	//pop begin
	status_t pop_begin(data_t*);

	//pop end
	status_t pop_end(data_t*);

	//remove begin
	status_t remove_begin();

	//remove end
	status_t remove_end();

	//remove data
	status_t remove_data(data_t);

	//Display list
	status_t show_list();

	//insert after data
	status_t insert_after(data_t, data_t);

	//insert before data
	status_t insert_before(data_t, data_t);

	//get length
	len_t get_length();

	//check if entry contains
	bool contains(data_t);

	//check if list is empty
	bool is_list_empty();
	
	//get repeat count
	int get_repeat_count(data_t);

	status_t destroy_list();


	//****************************************************************
	//extensive operations
	//concat this list with other list passed as parameter to concat function
	list* concat_list(list*);

	////merge list (means addition with sorting) 
	list* merge_list(list*);

	////reversing the list
	list* get_reversed_list();

	////convert list to array
	status_t list_to_array(int**);

	////convert array to list
	static list* array_to_list(int**, size_t);

	////append list(this will append the list
	////which is provided as parameter to the calling list
	//status_t append_list(list_t*);



};

