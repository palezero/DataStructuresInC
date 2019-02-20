#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElementType int
struct Node;
typedef struct Node* PtrToNode;
typedef struct Node* Stack;
struct Node
{
	ElementType value;
	PtrToNode Next; 
};
bool IsEmpty(); 
Stack CreateStack(); 
void DisposeStack(Stack S); 
void MakeEmpty(Stack S); 
void Push(ElementType X, Stack S); 
ElementType Pop(Stack S); 
bool IsEmpty(Stack S)
{
	return S->Next == NULL;
}

Stack CreateStack()
{
	Stack S;
	S = (Stack)malloc(sizeof(struct Node));//分配内存
	if(S == NULL)
		printf("Out of space!!!\n");
	else
		S->Next = NULL;
	MakeEmpty(S);
	return S;
} 
// void DisposeStack(Stack S); 
void MakeEmpty(Stack S)
{
	Stack Clear_Iter_S;
	if(!IsEmpty(S))
	{
		Clear_Iter_S = S->Next;
		S->Next = NULL;
		while(Clear_Iter_S != NULL)
		{
			free(Clear_Iter_S);
			Clear_Iter_S = Clear_Iter_S->Next;
		}
	}
			
}
void Push(ElementType X, Stack S)
{
	Stack new_node;
	new_node = (Stack)malloc(sizeof(struct Node));
	if(new_node == NULL)
		printf("Out of space!!!\n");
	else
	{
		new_node->value = X;
		new_node->Next = S->Next;
		S->Next = new_node;
		// printf("Pushing: %d\n", X);
	}
}

ElementType Pop(Stack S)
{
	Stack Poptemp;
	ElementType Popvalue;
	if(!IsEmpty(S))
	{
		Poptemp = S->Next;
		S->Next = Poptemp->Next;
		Popvalue = Poptemp->value;
		free(Poptemp);
		// printf("Poping:%d \n", Popvalue);
		return Popvalue;
	}
}
