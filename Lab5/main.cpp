#include <stdio.h>
#include <iostream>

struct list
{
	int size;
	list *next;
};
const int m = 1000;
char memory[m];



void* my_malloc(int n)
{
	int *addres;
	list tmp;
	tmp.size = n;
	list *tmp_node = (list*)memory;
	if (tmp_node->next == NULL)
	{
		tmp.next = NULL;
		*((list*)(memory + m - sizeof(list) - n)) = tmp;
		tmp_node->next = (list*)(memory + m  - n-sizeof(list));
		addres = (int*)(memory + m - n);
		tmp_node->size -= n + sizeof(list);
	}
	else
	{
		tmp.next = tmp_node->next;
		*((list*)(memory + tmp_node->size  - n)) = tmp;
		tmp_node->next = (list*)(memory + tmp_node->size  - n);
		addres = (int*)(memory + tmp_node->size+sizeof(list)-n);
		tmp_node->size -= n+sizeof(list);	
	}

	return addres;
}

int my_free(int n)
{
	int flag=0;
	list *tmp=(list*)memory;
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			tmp = tmp->next;
		}

		if (tmp->size > 0)
		{
			tmp->size *= -1;
			flag = 0;
		}
	}
	return flag;
}
void menu()
{

}


void print_size(list *tmp)
{
	if (tmp->size < 0)
		printf("NOTfree: %d", tmp->size);
	else printf("free: %d", tmp->size);
	printf("\n");
}
void print_list()
{
	list* tmp = ((list*)memory)->next;
	while (tmp->next != NULL)
	{
		print_size(tmp);
		tmp = tmp->next;
	}
	print_size(tmp);

}

void main()
{
	list node;
	char *p;
	for (int i = 0; i < m; i++)
		memory[i]='1';
	node.size = m - sizeof(list);
	node.next = NULL;
	*((list*)memory) = node;
	my_malloc(2);
	my_malloc(3);
	my_malloc(4);
	p=(char*)my_malloc(16);
	p[0] = '5';
	p[1] = '5';
	p[2] = '5';
	p[3] = '5';
	my_free(1);
	my_free(3);
	print_list();
}

