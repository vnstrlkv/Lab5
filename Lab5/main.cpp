#include <stdio.h>
#include <iostream>
#include <conio.h>

struct list
{
	int size;
	list *next;
};
const int m = 100;
char memory[m];

void* my_malloc(int n)
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

		}
	}
	return addres;
}

void* my_free(int n)
{

}
void print_list()
{
	while (a->next != NULL)
	{
		printf("%d. ", i++);
		print_size(tmp);
		tmp = tmp->next;
	}
	printf("\n\n");
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
	case '3':
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