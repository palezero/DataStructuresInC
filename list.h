#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
struct Node;
typedef struct Node * List;
typedef struct Node * Position;
struct Node//链表的节点，含有值和指向下一个节点的指针
{
	int value;
	List Next;
};
List Listmake();
bool islast(Position P);//判断该节点是不是最后一个
bool isempty(List L);//判断该链表是否为空
Position Find(int X, List L);//在链表中查找某个值
Position FindPrevious(int X, List L);//找值为X的前面一个值
void Delete(int X, List L);//删除某个节点
void Insert(int X, List L);//在某个节点后插入某个节点
void Deletelist(List L);//删除一个表 
void printallvalue(List L);//输出表中所有数据

List Listmake()
{
	static List L;
	L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	return L;
}
bool islast( Position P)
{
	return P->Next == NULL;
}
bool isempty(List L)//判断一个链表是否为空表
//如果为空表就返回NULL，否则就不是空表
{
	return L->Next == NULL;
}
Position Find(int X, List L)
{
	Position P;
	P = L->Next;
	while( P != NULL && P->value != X)
		//当找到链表尾端或者找到该值时退出循环
		P = P->Next;
	return P;
}
Position FindPrevious(int X, List L)
{
	Position P;
	P = L;
	while( P -> Next && P->Next->value != X)
		P = P->Next;
	return P;
}
void Delete(int X, List L)
{
	Position PL;
	PL = FindPrevious(X, L);
	if(!islast(L))
	{
		PL->Next = L->Next;
		free(L);
	}
}
void Insert(int X, List L)
{
	Position P;
	if((P = (List)malloc(sizeof(struct Node))) == NULL)
		printf("Out of space!!!!!!");
	else
	{
		P->Next = L->Next;
		L->Next = P;
		P->value = X;
	}
}

void Deletelist(List L)
{
	Position P,temp;
	P = L->Next;//仅保存表头L的内容
	L->Next = NULL;//L后面的空间全部释放，直接指向NULL
	while(P!=NULL)//通过P来迭代释放空间
	{
		temp = P->Next;
		free(P);
		P = temp;
	} 
}

void printallvalue(List L)
{
	Position P = L;
	int count = 0;
	while(P!=NULL)
	{
		printf("Order %d is %d\n", count++, P->value);
		P = P->Next;
	}
}