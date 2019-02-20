#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100
struct self_adjusting;
typedef struct self_adjusting* Sa;
struct self_adjusting
{
	int now;
	int position[MAX];
};
void insert(int num,Sa S);
void Self_init(Sa S);
void printallvalue(Sa S);
int main()
{
	Sa S;
	int i;
	S = (Sa)malloc(sizeof(struct self_adjusting));
	Self_init(S);
	for (i = 0; i < 100; i++)
		insert(i,S);
	insert(1000, S );
	printallvalue(S);
	return 0;
}
void insert(int num,Sa S)
{
	int i;
	int temp;
	for (i = S->now;i >=1; i--)
	{
		S->position[i] = S->position[i-1];
	}
	if(S->now < MAX)
		S->now++;
	S->position[0] = num;
}
void printallvalue(Sa S)
{
	int i;
	for(i = 0; i < MAX; i++)
		printf("%d\n",S->position[i]);
}
void Self_init(Sa S)
{
	int i;
	for(i = 0; i < MAX; i++)
		S->position[i] = 0;
	S->now = 0;
}
