#include <stdio.h>
#include <iostream>

struct list
{
	int size;
	list *next;
}first_list;



void* my_malloc(int size ,char *memory)
{
	int m = 200;
	list temp;
	if (first_list.next == NULL)
	{
	
		temp.size = sizeof(list);
		temp.next = NULL;
		*((list*)(memory+ first_list.size)) = temp;
		first_list.next = (list*)(memory + first_list.size);
		first_list.size -= temp.size;
	}
	else
	{
		temp.size = sizeof(list);
		temp.next = (first_list.next+sizeof(list));
		*((list*)(memory + first_list.size)) = temp;
		first_list.next = (list*)(memory + first_list.size);
		first_list.size -= temp.size;
	}

	return first_list.next;
}

void my_free()
{

}

void print_next(list* a)
{
	while (a->next != NULL)
	{
		print_next(a->next);
		printf("%d", a->size);
	}
}

void main()
{
	int m = 200;
	char *memory = (char*)malloc(m);
	for (int i = 0; i < m; i++)
	{
		memory[i] ='0';
	}
	first_list.size = m-sizeof(list);
	*((list*)memory) = first_list;
	for (int i = 0; i < m; i++)
	{
		printf("%c ", memory[i]);
	}
		printf("\n");
	printf("%d", first_list.size);
	printf("\n");

	for (int i = 0; i < 5; i++)
	{
		my_malloc(6, memory);
		printf("\n ");
		for (int i = 0; i < m; i++)
		{
			printf("%c ", memory[i]);
		}
		printf("\n");
		printf("%d", first_list.size);
		printf("\n");
	}
	printf("\n");
	print_next(first_list.next);



}