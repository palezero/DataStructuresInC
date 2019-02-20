#include "stack.h"
int main() 
{
	Stack S;
	int i;
	S = CreateStack();
	for (i = 0; i < 100; i++)
		Push(i,S);
	for (i = 0; i < 100; i++)
	{
		printf("Order %d is %d\n",i+1, Pop(S)); 
	}
	printf("%d\n", IsEmpty(S));
	return 0; 
}
