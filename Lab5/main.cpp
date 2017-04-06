#include <stdio.h>
#include <iostream>

struct list
{
	int size;
	list *next;
}first_list;



list* my_malloc(char *a)
{
	printf("\n%d", ((list*)a)->size);
	return 0;
}

void my_free()
{

}

void main()
{
	int m = 200;
	char *memory = (char*)malloc(m);
	for (int i = 0; i < m; i++)
	{
		memory[i] = '0';
	}
	first_list.size = m-sizeof(list);
	*((list*)memory) = first_list;
	for (int i = 0; i < m; i++)
	{
		printf("%c ", memory[i]);
	}
	my_malloc(memory);
}