/*
The server file implements the node and list class
node provides the basic data structure
And the list class provides the functionalities associated with it
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"header.h"

list_node::list_node()
{

}

data_t list_node::get_data()
{
	return data;
}

list_node* list_node::get_prev()
{
	return prev;
}

list_node* list_node::get_next()
{
	return next;
}

void list_node::set_data(data_t _data)
{
	this->data = _data;
}

void list_node::set_prev(list_node* _prev)
{
	this->prev = _prev;
}

void list_node::set_next(list_node* _next)
{
	this->next = _next;
}




/////////////////////////////////////////////////////////////////////////
//Implementation of list class

list::list()
{
	//this->headNode = NULL;
}

//this is private getter, since interface implementation does not requires this
list_node* list::get_headNode()
{
	return headNode;
}

 list* list::create_list()
{
	list* new_list = new list;
	new_list->get_headNode()->set_next(new_list->get_headNode());
	new_list->get_headNode()->set_prev(new_list->get_headNode());

	return new_list;
}

status_t list::insert_at_begin(data_t data)
{
	generic_insert(this->get_headNode(), get_list_node(data), this->get_headNode()->get_next());
	return SUCCESS;
}


status_t list::insert_at_end(data_t data)
{
	generic_insert(headNode->get_prev(), get_list_node(data), headNode);
	return SUCCESS;
}


status_t list::insert_after(data_t refData, data_t data)
{
	node_t* tempNode = locate_node(refData);
	if (tempNode == NULL)
	{
		return LIST_DATA_NOT_FOUND;
	}
	generic_insert(tempNode, get_list_node(data), tempNode->get_next());
	return SUCCESS;
}


status_t list::insert_before(data_t refData, data_t data)
{
	node_t* tempNode = locate_node(refData);
	if (tempNode == NULL)
	{
		return LIST_DATA_NOT_FOUND;
	}

	generic_insert(tempNode->get_prev(), get_list_node(data), tempNode);
	return SUCCESS;
}


status_t list::get_end(data_t* get_end_data)
{
	if (is_list_empty() == true)
	{
		return LIST_EMPTY;
	}
	node_t* end_node = headNode->get_prev();
	assert(end_node != NULL);
	*get_end_data = end_node->get_data();
	return SUCCESS;
}


status_t list::get_begin(data_t* get_begin_data)
{
	if (is_list_empty() == true)
	{
		return LIST_EMPTY;
	}
	node_t* begin_node = headNode->get_next();
	assert(begin_node != NULL);
	*get_begin_data = begin_node->get_data();
	return SUCCESS;
}

status_t list::pop_begin(data_t* pop_begin_data)
{
	if (is_list_empty() == true)
	{
		return LIST_EMPTY;
	}
	node_t* begin_node = headNode->get_next();
	assert(begin_node != NULL);
	*pop_begin_data = begin_node->get_data();

	generic_delete(begin_node);
	return SUCCESS;
}


status_t list::pop_end(data_t* pop_end_data)
{
	if (is_list_empty() == true)
	{
		return LIST_EMPTY;
	}
	node_t* end_node = headNode->get_prev();
	assert(end_node != NULL);
	*pop_end_data = end_node->get_data();

	generic_delete(end_node);

	return SUCCESS;
}


status_t list::remove_begin()
{
	if (is_list_empty() == true)
	{
		return LIST_EMPTY;
	}

	generic_delete(headNode->get_next());
	return SUCCESS;
}


status_t list::remove_end()
{
	if (is_list_empty() == true)
	{
		return LIST_EMPTY;
	}

	generic_delete(headNode->get_prev());
	return SUCCESS;
}


status_t list::remove_data(data_t rm_data)
{
	if (is_list_empty() == true)
	{
		return LIST_EMPTY;
	}

	node_t* node_to_remove = locate_node(rm_data);
	assert(node_to_remove != NULL);
	generic_delete(node_to_remove);

	return SUCCESS;
}


len_t list::get_length()
{
	len_t length = 1;

	if (is_list_empty() == true)
	{
		return LIST_EMPTY;
	}

	node_t* tempNode = headNode->get_next();
	while (tempNode->get_next() != headNode)
	{
		length++;
		tempNode = tempNode->get_next();
	}
	return length;
}


bool list::contains(data_t contains_data)
{
	if (is_list_empty() == true)
	{
		return LIST_EMPTY;
	}

	node_t* tempNode = headNode;
	while (tempNode->get_next() != headNode)
	{
		if (tempNode->get_data() == contains_data)
			return true;

		tempNode = tempNode->get_next();
	}
	return false;
}


int list::get_repeat_count(data_t repeat_data)
{
	if (is_list_empty() == true)
	{
		return LIST_EMPTY;
	}
	
	int repeat_count = 0;

	node_t* tempNode = headNode;
	while (tempNode->get_next() != headNode)
	{
		if (tempNode->get_data() == repeat_data)
		{
			repeat_count++;
		}
		tempNode = tempNode->get_next();
	}

	return repeat_count;
}



status_t list::show_list()
{
	if (headNode == NULL)
	{
		printf("show_list(): list is empty\n");
		return LIST_EMPTY;
	}

	node_t* tempNode = this->get_headNode();
	node_t* temp = tempNode->get_next();

	printf("show_list(): ");

	while (temp != tempNode)
	{
		printf("%d ", temp->get_data());
		temp = temp->get_next();
	}


}

list* list::concat_list(list* list_to_concat)
{
	if (list_to_concat == NULL)
	{
		return NULL;
	}

	list* newList = list::create_list();
	

	//node_t* tempNode = newList->headNode->get_next();

	node_t* tempNode1 = this->headNode->get_next();
	node_t* tempNode2 = list_to_concat->headNode->get_next();

	while (tempNode1 != this->headNode)
	{
		newList->insert_at_end(tempNode1->get_data());
		tempNode1 = tempNode1->get_next();
	}

	while (tempNode2 != list_to_concat->headNode)
	{
		newList->insert_at_end(tempNode2->get_data());
		tempNode2 = tempNode2->get_next();
	}

	return newList;
}


list* list::merge_list(list* list_to_merge)
{
	if (list_to_merge == NULL)
	{
		return NULL;
	}

	list* new_list = list::create_list();
	node_t* tempNode1 = this->get_headNode()->get_next();
	node_t* tempNode2 = list_to_merge->get_headNode()->get_next();

	while (true)
	{
		if (tempNode1 == this->get_headNode())
		{
			while (tempNode2 != list_to_merge->get_headNode())
			{
				new_list->insert_at_end(tempNode2->get_data());
				tempNode2 = tempNode2->get_next();
			}
			break;
		}

		if (tempNode2 == list_to_merge->get_headNode())
		{
			while (tempNode1 != this->get_headNode())
			{
				new_list->insert_at_end(tempNode1->get_data());
				tempNode1 = tempNode1->get_next();
			}
			break;
		}

		if (tempNode1->get_data() >= tempNode2->get_data())
		{
			new_list->insert_at_end(tempNode1->get_data());
			tempNode1 = tempNode1->get_next();
		}else
		{
			new_list->insert_at_end(tempNode2->get_data());
			tempNode2 = tempNode2->get_next();
		}
	}

	return new_list;
}


list* list::get_reversed_list()
{
	list* new_list = list::create_list();
	node_t* tempNode = this->get_headNode()->get_next();

	while (tempNode != this->get_headNode())
	{
		new_list->insert_at_begin(tempNode->get_data());
		tempNode = tempNode->get_next();
	}

	return new_list;
}


status_t list::list_to_array(int** pp_arr)
{
	if (is_list_empty())
	{
		return LIST_EMPTY;
	}

	int length = this->get_length();

	printf("list_to_array(): length = %d\n", length);
	*pp_arr = (int*)malloc(sizeof(int) * length);
	assert(*pp_arr != NULL);
	int counter = 0;

	node_t* tempNode = this->get_headNode()->get_next();
	while (tempNode != this->get_headNode() && counter < length)
	{
		printf("list_to_array(): %d -- ", counter);
		(* pp_arr)[counter++] = tempNode->get_data();
		tempNode = tempNode->get_next();
	}

	return SUCCESS;
}

 list* list::array_to_list(int** pp_arr, size_t arr_size)
{
	 list* new_list = list::create_list();
	 assert(new_list != NULL);

	 for (int i = 0; i < arr_size; i++)
	 {
		 new_list->insert_at_end(( * pp_arr)[i]);
	 }

	 return new_list;
}


 status_t list::destroy_list()
 {
	 node_t* tempNode = this->get_headNode()->get_next();
	 node_t* temp1 = tempNode;

	 while (tempNode != this->get_headNode())
	 {
		 temp1 = tempNode;
		 tempNode = tempNode->get_next();
		 delete temp1;

	 }
	 delete this->get_headNode();

	 return SUCCESS;
 }




//*************************************************************************

bool list::is_list_empty()
{
	if (headNode->get_next() == headNode || headNode->get_next() == NULL)
		return true;
	else
		return false;
}


void list::generic_insert(list_t* pBeg, list_t* pMid, list_t* pEnd)
{
	pMid->set_next(pEnd);
	pMid->set_prev(pBeg);
	pEnd->set_prev(pMid);
	pBeg->set_next(pMid);

}



void list::generic_delete(list_t* node_to_delete)
{
	node_to_delete->get_next()->set_prev(node_to_delete->get_prev());
	node_to_delete->get_prev()->set_next(node_to_delete->get_next());
	delete node_to_delete;
}



node_t* list::get_list_node(data_t data)
{
	node_t* newNode = NULL;
	newNode = (node_t*)xmalloc(sizeof(node_t));
	newNode->set_data(data);
	newNode->set_next(NULL);
	newNode->set_prev(NULL);
	return newNode;
}



void* list::xmalloc(size_t size)
{
	void* p = NULL;
	p = malloc(size);
	assert(p != NULL);
	return p;
}


node_t* list::locate_node(data_t data)
{
	node_t* tempNode = this->get_headNode()->get_next();

	while (tempNode != this->get_headNode())
	{
		if (tempNode->get_data() == data)
		{
			return tempNode;
		}
		tempNode = tempNode->get_next();
	}
	return NULL;
}






