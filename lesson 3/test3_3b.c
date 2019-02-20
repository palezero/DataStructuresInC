#include ".\DataStructuresInC\headfile\dlist.h"
void PrintLots(Dlist L, Dlist P);
void printvalue(Dlist L, int i);
int main()
{
	Dlist L;
	Position temp;
	int i;
	L = malloc(sizeof(struct Node));
	L->Next = NULL;
	L->Prev = NULL;
	for (i = 9; i >= 0; i--)
		InsertNext(i,L);
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
void swap(Dlist DL, Position P)
{
	Position before = P->Prev;
	Position after = P->Next;
	before->Next = after;
	P->Next = after->Next;
	after->Prev = before;
	after->Next = P;
	P->Prev = after;
}