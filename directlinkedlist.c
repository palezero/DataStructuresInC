#include "list.h"
int main()
{
	List head;
	List now;
	int i;
	head = malloc(sizeof(struct Node));
	head->Next = NULL;
	head->value = 100;
	now = head;
	for (i = 0; i < 100; i++)
	{
		Insert(i,now);
		now = now->Next;
	}
	printf("head = %d\n", head->Next->Next->value);
	printallvalue(head);
	return 0;
}

