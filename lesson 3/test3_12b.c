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
void invert(List L)
{
	List L2;
	Position P;
	L2 = (List)malloc(sizeof(struct Node));
	L2->Next = NULL;
	while(L->Next != NULL)
	{
		P = L->Next;
		L->Next = P->Next;
		P->Next = L2->Next;
		L2->Next = P;	
	}
	L->Next = L2->Next;
}