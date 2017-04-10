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
	bool flag=true;
	int *addres=NULL;
	list tmp;
	tmp.size = n;
	list *tmp_node = (list*)memory;
	int freemem = tmp_node->size;
	if (n <= tmp_node->size && n>0)
	{
		if (tmp_node->next != NULL)
		{
			tmp_node = tmp_node->next;
		}
		{
			while (tmp_node)
			{
				if(tmp_node->size<0)
				freemem += tmp_node->size;
				if (n == (-1)*(tmp_node->size))
				{
					
					tmp_node->size = n;
					tmp_node = (list*)memory;
					tmp_node->size -= n;
					flag = false;
					addres = (int*)tmp_node->next + sizeof(list) / sizeof(int);
					break;
				}
				else tmp_node = tmp_node->next;
			}
		}
		if (flag == true && freemem>=n)
		{
			tmp_node = (list*)memory;
			if (tmp_node->next == NULL)
			{
				tmp.next = NULL;
				*((list*)(memory + m - sizeof(list) - n)) = tmp;
				tmp_node->next = (list*)(memory + m - n - sizeof(list));
				addres = (int*)(tmp_node->next) + sizeof(list) / sizeof(int);
				tmp_node->size -= n+sizeof(list);
			}
			else
			{
				tmp.next = tmp_node->next;
				*((list*)((char*)tmp_node->next - sizeof(list) - n)) = tmp;
				tmp_node->next = ((list*)((char*)tmp_node->next - sizeof(list) - n));
				addres = (int*)(tmp_node->next) + sizeof(list) / sizeof(int);
				tmp_node->size -= n+sizeof(list);
			}

		}
	}
	return addres;
}

void* my_free(void *addres)
{
	list *tmp = (list*)addres-1;
	list *tmp_node = (list*)memory;
		if (tmp_node->next == tmp)
			{
				tmp_node->next = tmp->next;
				addres = (int*)tmp+sizeof(list)/sizeof(int);
				if (tmp->size < 0)
					tmp_node->size += sizeof(list);
				else
				tmp_node->size += tmp->size + sizeof(list);
			}
			else if (tmp->size > 0)
			{
				tmp->size *= -1;
				addres = (int*)tmp+sizeof(list) / sizeof(int);
				tmp_node->size -= tmp->size;			
			}

	return addres;
}



void print_size(list *tmp)
{
	if (tmp->size > 0)
		printf("busy: %d byte by addres: %p", tmp->size, (char*)tmp+sizeof(list));
	else printf("free: %d byte by addres: %p", (-1)*tmp->size, (char*)tmp + sizeof(list));
	printf("\n");
}
void print_list()
{
	int i = 1;
	list* tmp = ((list*)memory);
	if(tmp->size>=0)
	printf("Total free: %d byte\n", tmp->size);
	else printf("Total free: %d byte\n", 0);
	tmp = tmp->next;
	while (tmp)
	{
		printf("%d. ", i++);
		print_size(tmp);
		tmp = tmp->next;
	}
	printf("\n\n");
}

void menu()
{
	printf("1. my_malloc\n2. my_free\n3. Show status\n0. exit\n\n");
	char key;
	key = getch();
	switch (key)
	{
	case '1':
	{
		int size; char *addres;
		printf("Input size (byte): ");
		scanf("%d", &size);
		printf("\n");
		addres=(char*)my_malloc(size);
		if (addres != NULL)
			printf("Allocated memory by addres: %p\n", addres);
		else
		{
			printf("Sorry, this can not be done. \n\n");
		}
		break;
	}
	case '2':
	{
		int number, *addres=NULL, i;

		printf("Enter the number of the area you want to free: ");
		scanf("%d", &number);
		printf("\n");
		list *tmp = (list*)memory;
		if (number > 0 && tmp->next != NULL)
		{
			for (i = 0; i < number; i++)
			{
				tmp = tmp->next;
				if (tmp == NULL)
					break;
			}
			if (i == number)
			{
				 addres = (int*)tmp + sizeof(list) / sizeof(int);
				addres= (int*)my_free(addres);
			}
		}

		if (addres != NULL)
			printf("Free memory by addres: %p\n", addres);
		else
		{
			printf("Sorry, this can not be done. \n\n");
		}
		break;
	}
	case '3':
	{
		print_list();
		break;
	}
	case '0':
	{	
		exit(0);
		break;
	}
	}
	menu();
}
void main()
{
	list node;
	char *p;
	node.size = m - 2*sizeof(list);
	node.next = NULL;
	*((list*)memory) = node;
	menu();
}

