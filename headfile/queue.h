#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ElementType int
struct QueueRecord;
typedef struct QueueRecord *Queue; 
bool IsEmpty(Queue Q);
bool IsFull(Queue Q);
Queue CreateQueue(int MaxElements, ElementType seed);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
ElementType Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);
struct QueueRecord
{
	int Capacity;  			//容量
	int Front;				//前面的指针
	int Rear;				//后面的指针
	int Size;				//数组大小
	ElementType *Array;		//队列数组
};
void Enqueue(ElementType X, Queue Q)
{
	if(!IsFull(Q))
	{
		Q->Size++;
		if((Q->Rear) < (Q->Capacity - 1))
		{
			Q->Rear++;
			Q->Array[Q->Rear] = X;
		}
		printf("Enqueue:Size = %d,\tFront = %d,\tRear = %d,\tElement = %d\n", Q->Size, Q->Front, Q->Rear, Q->Array[Q->Rear]);
	}
	else
		printf("The Queue is full!!!!\n");
}
bool IsEmpty(Queue Q)
{
	return Q->Size == 0;
}
bool IsFull(Queue Q)
{
	return Q->Size == Q->Capacity;
}
Queue CreateQueue(int MaxElements, ElementType seed)
{
	Queue Q;
	Q = malloc(sizeof(struct QueueRecord));//给队列结构体分配空间
	Q->Array = malloc(sizeof(ElementType)*MaxElements);//给队列数组分配空间
	Q->Rear = 0;
	Q->Front = 0;
	Q->Size = 0;
	Q->Capacity = MaxElements;
	Q->Array[0] = seed;
	return Q;
}
void DisposeQueue(Queue Q)
{
	MakeEmpty(Q);
	free(Q->Array);
}
void MakeEmpty(Queue Q)
{
	Q->Rear = 0;
	Q->Front = 0;
	Q->Size = 0;
}
ElementType Dequeue(Queue Q)
{
	if(!IsEmpty(Q))
	{
		ElementType return_value;
		Q->Size--;
		return_value = Q->Array[Q->Front];
		if(!Q->Front)
		{
			Q->Front = Q->Capacity - 1;
			printf("Now this Dequeue is the seed!\n");
		}
		else
			Q->Front--;
		printf("Dequeue:Size = %d,\tFront = %d,\tRear = %d,\t", Q->Size, Q->Front, Q->Rear);
		return return_value;
	}
	else
		printf("The Queue is empty!!!!\n");
	
}