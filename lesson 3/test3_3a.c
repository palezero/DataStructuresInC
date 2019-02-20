#include ".\DataStructuresInC\headfile\list.h"
void PrintLots(List L, List P);
void printvalue(List L, int i);
int main()
{
	List L;
	Position temp;
	int i;
	L = malloc(sizeof(struct Node));
	L->Next = NULL;
	for (i = 9; i >= 0; i--)
		Insert(i,L);
	temp = L;
	printallvalue(L);
	puts("Speaking!");
	scanf("%d",&i);
	while(i--)
		temp = temp->Next;
	swap(L,temp);
	printallvalue(L);
	return 0;
}
void swap(List L, Position P)
{
	Position before = L->Next;
	Position after = P->Next;
	while(before!=NULL&&before->Next!=P)
		before = before->Next;
	before->Next = after;
	P->Next = after->Next;
	after->Next = P;
}
