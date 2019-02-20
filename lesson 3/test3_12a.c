#include "./DataStructuresInC/headfile/list.h"
void invert(List L);
int main()
{
	List L;
	L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	Insert(100, L);
	Insert(80, L);
	Insert(60, L);
	Insert(40, L);
	Insert(20, L);
	Insert(0, L);
	printallvalue(L);
	invert(L);
	printallvalue(L);
	return 0;
}
void invert(List head)
{
	Position P, temp;
	P = head->Next;
	while(P->Next != NULL)
	{
		temp = P->Next;
		P->Next = temp->Next;
		temp->Next = head->Next;
		head->Next = temp;
	}
}