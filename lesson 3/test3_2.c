#include ".\DataStructuresInC\headfile\list.h"
void PrintLots(List L, List P);
void printvalue(List L, int i);
int main()
{
	int i;
	int num[4] = {1,3,4,6};
	List order_list;
	List data_list;
	order_list = malloc(sizeof(struct Node));
	order_list->Next = NULL;
	data_list = malloc(sizeof(struct Node));
	data_list->Next = NULL;
	for(i=3;i>=0;i--)//order init
		Insert(num[i],order_list);
	for(i=100;i>=1;i--)//DATA init
		Insert(i*2,data_list);
	printallvalue(data_list);
	PrintLots(data_list,order_list);
	return 0;
}
void PrintLots(List data_list, List order_list)
{
	List order = order_list->Next;
	List data;
	int count,temp;
	while(order!=NULL)
	{
		temp = order->value;
		count = temp-1;
		data = data_list->Next;
		while(count--)
		{
			if(data->Next==NULL)
				printf("Out of Order\n");
			data = data->Next;
		}
		printf("The order:%d is %d\n", temp,data->value);
		order = order->Next;
	}
}
void printvalue(List L, int i)
{
	List temp = L; 
	int count = i;
	while(count--)
	{
		printf("%d\n", temp->value);
		temp = temp->Next;
	}
}