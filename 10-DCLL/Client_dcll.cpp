#include<stdio.h>
#include<stdlib.h>
#include"header.h"

int main(void)
{
	list* pList = list::create_list();
	if (pList == NULL)
	{
		printf("Create_list() failed\n");
		exit(0);
	}

	if (pList->is_list_empty())
	{
		printf("main(): list is empty\n");
	}

	pList->insert_at_begin(10);
	pList->insert_at_begin(20);
	pList->insert_at_end(30);
	pList->insert_after(20, 15);
	pList->insert_before(30, 25);

	pList->show_list();

	int end, begin;
	pList->get_end(&end);
	printf("main(): end = %d\n", end);
	pList->get_begin(&begin);
	printf("main(): begin = %d\n", begin);
	pList->pop_begin(&begin);
	printf("main() popped begin = %d\n", begin);
	pList->pop_end(&end);
	printf("main(): popped end = %d\n", end);
	pList->show_list();
	pList->remove_begin();
	pList->remove_end();
	pList->insert_after(10, 20);
	pList->insert_before(10, 30);
	pList->insert_before(10, 30);

	pList->show_list();

	if (pList->contains(10))
	{
		printf("main(): contains successfuly\n");
	}

	if (pList->is_list_empty())
	{
		printf("main(): list is empty\n");
	}

	int repeat_count = pList->get_repeat_count(30);

	printf("main(): repeat conunt for 30 = %d\n", repeat_count);

	list* new_concat_list = list::create_list();
	new_concat_list->insert_at_begin(25);
	new_concat_list->insert_at_begin(35);
	new_concat_list->insert_at_begin(45);

	list* new_concated_list = pList->concat_list(new_concat_list);

	printf("\n\n");
	pList->show_list();
	printf("\n\n");
	new_concated_list->show_list();
	printf("\n\n");
	list* new_merge_list = pList->merge_list(new_concated_list);
	new_merge_list->show_list();

	list* reversed_list = pList->get_reversed_list();
	reversed_list->show_list();

	int* arr = NULL;
	pList->list_to_array(&arr);

	int counter = 0;
	printf("\n\n list to array: ");
	while (counter < pList->get_length())
	{
		printf("%d ", arr[counter++]);
	}

	list* array_to_list_check = list::array_to_list(&arr, 4);
	
	array_to_list_check->show_list();

}