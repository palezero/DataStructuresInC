#include ".\DataStructuresInC\headfile\list.h"
void bing(List L1, List L2);
int main()
{
	int data1[]={1,1,2,4,6,8};
	int data2[]={1,2,4,7,8,10};
	List L1,L2;
	int i;
	L1 = malloc(sizeof(struct Node));
	L1->Next = NULL;
	L2 = malloc(sizeof(struct Node));
	L2->Next = NULL;
	for(i = sizeof(data1)/sizeof(int)-1;i >= 0;i--)
		Insert(data1[i],L1);
	for(i = sizeof(data2)/sizeof(int)-1;i >= 0;i--)
		Insert(data2[i],L2);
	printallvalue(L1);
	printallvalue(L2);
	bing(L1,L2);
	return 0;
}
void bing(List L1, List L2)
{
	Position P1 = L1->Next;
	Position P2 = L2->Next;
	List new_list,temp;
	new_list = malloc(sizeof(struct Node));
	new_list->Next = NULL;
	temp = new_list;
	while(!(P1==NULL&&P2==NULL))//P1,P2
	{
		if(P1 == NULL && P2 !=NULL)
		{
			while(P2!=NULL)
			{
				Insert(P2->value,temp);
				P2 = P2->Next;
			}
		}
		else if(P1 != NULL && P2 ==NULL)
		{
			while(P1!=NULL)
			{
				Insert(P1->value,temp);
				P1 = P1->Next;
			}
		}
		else
		{
			if((P1->value)==(P2->value))
			{
				Insert(P1->value, temp);
				temp = temp->Next;
				P1 = P1->Next;
				P2 = P2->Next;
			}
			else if(P1->value>P2->value)
			{
				Insert(P2->value, temp);
				temp = temp->Next;
				P2 = P2->Next;
			}
			else
			{
				Insert(P1->value, temp);
				temp = temp->Next;
				P1 = P1->Next;
			}
		}
		
	}
	printallvalue(new_list);
}
