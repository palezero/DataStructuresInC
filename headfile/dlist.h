#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node; 
typedef struct Node * 	Dlist;
typedef struct Node * 	Position;
struct Node
{
	Dlist Next;
	Dlist Prev;
	int value;
};
bool islast(Position P);//判断该节点是不是头节点
bool isfirst(Position P);//判断该节点是不是尾节点
bool isempty(Dlist L);//判断该链表是否为空
Position Find(int X, Dlist L);//在链表中查找某个值
Position FindPrevious(int X, Dlist L);//找值为X的前面一个值
Position FindNext(int X,Dlist L);//找值为X的后面一个值
void DeleteNext(int X, Dlist L);//删除某个值后的节点
void DeletePrev(int X, Dlist L);//删除某个值前的节点
void InsertNext(int X, Dlist L);//在某个节点后插入某个节点
void InsertPrev(int X, Dlist L);//在某个节点前插入某个节点
void DeleteDlist(Dlist L);//从表头或表尾删除一个表
void printallvalue(Dlist L);//输出表中所有数据
bool islast(Position P)//判断该节点是不是最后一个
{
	return P->Next == NULL;
}
bool isfirst(Position P)
{
	return P->Prev == NULL;
}
bool isempty(Dlist L)//判断该链表是否为空
{
	return (L->Next == NULL)&&(L->Prev == NULL);
}
Position Find(int X, Dlist L)
{
	Position P;
	P = L->Next;
	while((P != NULL)&&(P->value == X))
		P = P->Next;
	return P;
}
Position FindPrevious(int X, Dlist L)
{
	Position P;
	P = L->Next;
	while((P != NULL)&&(P->Next->value == X))
		P = P->Next;
	return P;
}
Position FindNext(int X,Dlist L)
{
	Position P;
	P = L->Next;
	while((P != NULL)&&(P->Prev->value == X))
		P = P->Next;
	return P;
}
void DeleteNext(int X, Dlist L)
{
	Position P,temp,temp_next;
	if(!islast(L))
	{
		P = FindPrevious(X,L);//找到值为X的前面一个节点的地址
		temp = P->Next;//值为X的节点
		temp_next = temp->Next;
		P->Next = temp_next;
		temp_next->Prev = P;
		free(temp);
	}
}
void DeletePrev(int X, Dlist L)
{
	Position P,temp,temp_prev;
	if(!isfirst(L))
	{
		P = FindNext(X,L);//找到值为X的后面一个节点的地址
		temp = P->Prev;//值为X的节点
		temp_prev = temp->Prev;
		P->Prev = temp_prev;
		temp_prev->Next = P;
		free(temp);
	}
}
void InsertNext(int X, Position P)
{
	Position temp, P1;
	temp = malloc(sizeof(struct Node));
	if(temp == NULL)
		printf("Out of space\n");
	else
	{
		if(P->Next != NULL)
		{
			P1 = P->Next;
			temp->Prev = P;
			temp->Next = P1;
			temp->value = X;
			P->Next = temp;
			P1->Prev = temp;
		}
		else
		{
			temp->Next = P->Next;
			P->Next = temp;
			temp->Prev = P;
			temp->value = X;
		}
	}
}
void InsertPrev(int X, Position P)
{
	Position temp, P1;
	temp = malloc(sizeof(struct Node));
	if(temp == NULL)
		printf("Out of space\n");
	else
	{
		if(P->Prev != NULL)
		{
			P1 = P->Prev;
			temp->Prev = P1;
			temp->Next = P;
			temp->value = X;
			P1->Next = temp;
			P->Prev = temp;
		}
		else
		{
			temp->Prev = P->Prev;
			P->Prev = temp;
			temp->Next = P;
			temp->value = X;
		}
	}
}
void DeleteDlist(Dlist L)//从表头或表尾删除一个表
{
	Position P;
	if(!isempty(L))//这个表不是空表
	{
		if(isfirst(L))//该节点为表头
		{
			P = L->Next;
			L->Next = NULL;
			while(P!=NULL)
			{
				free(P);
				P = P->Next;
			}
		}
		else if(islast(L))//该节点为表尾
		{
			P = L->Prev;
			L->Prev = NULL;
			while(P!=NULL)
			{
				free(P);
				P = P->Prev;
			}
		}
	}
}
void printallvalue(Dlist L)//输出表中所有数据
{
	Position P;
	if(!isempty(L))
	{
		if(islast(L))//为表尾
		{
			printf("this node is the end,and the value of the node%d\n",L->value);
			P = L->Prev;
			while(P!=NULL)
			{
				printf("%d\n",P->value);
				P = P->Prev;
			}
		}
		else if(isfirst(L))//为表头
		{
			printf("this node is the start,and the value of the node%d\n",L->value);
			P = L->Next;
			while(P!=NULL)
			{
				printf("%d\n",P->value);
				P = P->Next;
			}
		}
	}
}
