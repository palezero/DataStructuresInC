#include"./DataStructuresInC/headfile/list.h"
#define MAX 100
void insert(int num, List L);
int main()
{
	List L;
	int i;
	L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	for (i = 0; i < MAX; i++)
		insert(i,L);
	printallvalue(L);
	return 0;
}
void insert(int num, List L)
{
	Position New;
	New = (Position)malloc(sizeof(struct Node));
	New->value = num;
	New->Next = L->Next;
	L->Next = New;
}