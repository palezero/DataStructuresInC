#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define TIME_MAX 1000
#define THIS_IS_LEFT -1
#define THIS_IS_RIGHT 1
#define THIS_IS_ROOT 0
struct TreeNode;
typedef struct TreeNode* Tree;
struct TreeNode {
	int Element;//节点元素
	int Time;//重复的元素的信息可放在节点元素中以频率显示
	int Deep;//深度
	Tree Left;//左子树
	Tree Right;//右子树
	Tree Father;//父节点
	char WhoAmI;//左子树还是右子树
};
struct QueueNode;
typedef struct QueueNode* Queue;
struct QueueNode {
	Tree* Element; // 数组，待定义长度
	int Front;//队头
	int Rear;//队尾
	int max;//数组最大长度
	int size;//队列当前长度
};
void Insert(Tree Ancestor, Tree* BST, int insert_value, int Now_Deep, int Branch) {
	if(*BST == NULL) {
		(*BST) = (Tree)malloc(sizeof(struct TreeNode));
		(*BST)->Element = insert_value;
		(*BST)->Time = 1;
		(*BST)->Left = (*BST)->Right = NULL;
		(*BST)->Deep = Now_Deep;
		(*BST)->WhoAmI = Branch;
		(*BST)->Father = Ancestor;
		if((*BST)->WhoAmI == THIS_IS_LEFT)
			printf("	Element = %d, Time = %d, Deep = %d, And I am The Left\n", (*BST)->Element, (*BST)->Time, (*BST)->Deep);
		else if((*BST)->WhoAmI == THIS_IS_RIGHT)
			printf("	Element = %d, Time = %d, Deep = %d, And I am The Right\n", (*BST)->Element, (*BST)->Time, (*BST)->Deep);
	}
	else {
		if(insert_value < (*BST)->Element) 
			Insert((*BST), (&(*BST)->Left), insert_value, Now_Deep + 1, THIS_IS_LEFT);
		else if(insert_value > (*BST)->Element) 
			Insert((*BST), (&(*BST)->Right), insert_value, Now_Deep + 1, THIS_IS_RIGHT);
		else {
			if((*BST)->Time < TIME_MAX)
				(*BST)->Time++;
			else 
				printf("Out Of The Same Element Frequency Limit");
		}
	}
}
Tree MakeTree(int init_value) {
	Tree Root;
	Root = (Tree)malloc(sizeof(struct TreeNode));
	Root->Left = Root->Right = NULL;
	Root->Element = init_value;
	Root->Time = 1;
	Root->Deep = 0;
	Root->WhoAmI = THIS_IS_ROOT;
	Root->Father = NULL;
	printf("Making A New Tree...\n");
	printf("Here are the element inserted:\n");
	return Root;
}
Tree MakeNewTree(int box[], int len) {
	Tree Root;
	int i;
	Root = MakeTree(box[0]);
	printf("	Element = %d, Time = %d, Deep = %d, And I am The Root\n", Root->Element, Root->Time, Root->Deep);
	for (i = 1; i < len; ++i)
		Insert(Root, &Root, box[i], Root->Deep, THIS_IS_LEFT);
	return Root;
}
void Max_Deep(Tree Root, int* max) {
	if(Root->Deep > *max) {
		*max = Root->Deep;
	}
	if(Root->Left != NULL)
		Max_Deep(Root->Left, max);
	if(Root->Right != NULL)
		Max_Deep(Root->Right, max);
}
Tree Dequeue(Queue* Q) {
	//出队
	Tree temp = (*Q)->Element[(*Q)->Rear];
	if((*Q)->Rear == (*Q)->Front) 
		printf("Out Of Queue\n");
	else {
		if(++(*Q)->Rear == (*Q)->max)
			(*Q)->Rear++;
		(*Q)->size--;
		// printf("Dequeue, Now size=%d, front=%d, rear=%d\n", (*Q)->size, (*Q)->Front, (*Q)->Rear);// Debug Mode
	}
	return temp;
}
Queue Enqueue(Queue Q, Tree T) {
	//入队
	Q->Element[Q->Front] = T;
	if(++Q->Front == Q->max) 
		Q->Front = 0;
	Q->size++;
	// printf("Enqueue, Now size=%d, front=%d, rear=%d\n", Q->size, Q->Front, Q->Rear);// Debug Mode
	return Q;
}
int HowManyRealSpaceShouldIPrint(Tree T, int max) {
	//这里索性用一个函数递归计算出来一个节点需要打印的空格了
	//这个好像是绝对位置哦，还要考虑和同一层前面节点的相对位置
	if(T->WhoAmI == THIS_IS_ROOT)
		return max;
	else if(T->WhoAmI == THIS_IS_LEFT) 
		return HowManyRealSpaceShouldIPrint(T->Father, max) - 1;
	else if(T->WhoAmI == THIS_IS_RIGHT)
		return HowManyRealSpaceShouldIPrint(T->Father, max) + 1; 
}
void PrintTree(Queue Q, int max) {
	//利用层次遍历算法实现画树，使用队列暂时存储树节点
	int i;
	int Now_Deep = 0;//当前遍历层次
	int count = 0;
	int temp = 0;
	Tree Position;
	while(Q->Front != Q->Rear) {
		//队列不为空
		Position = Dequeue(&Q);//出队
		// printf("Printing:");// Debug Mode
		count = temp;//更新
		temp = HowManyRealSpaceShouldIPrint(Position, max);//计算绝对位置
		
		if(Position->Deep > Now_Deep) {
			Now_Deep = Position->Deep;
			count = 0;
			for(i = 0; i < 100; i++)
				printf("-");
			printf("\n");//每一层最后一个节点换行
		}

		for(i = 0; i < (temp - count); i++) //相对位置
			printf("---");
		if(Position->WhoAmI == THIS_IS_RIGHT)
			printf("-\\%d-", Position->Element);
		if(Position->WhoAmI == THIS_IS_ROOT) 
			printf("--%d-", Position->Element);
		else if (Position->WhoAmI == THIS_IS_LEFT)
			printf("-%d/-", Position->Element);
		if(Position->Left != NULL) {
			Q = Enqueue(Q, Position->Left);
		}
		if(Position->Right != NULL) {
			Q = Enqueue(Q, Position->Right);
		}
	}
	for(i = 0; i < 100; i++)
		printf("-");
	printf("\n");
}
Queue MakeQueue(int length) {
	Queue Q;
	Q = (Queue)malloc(sizeof(struct QueueNode));
	Q->Element = (Tree*)malloc(sizeof(Tree) * length);
	Q->max = length;
	Q->Front = Q->Rear = Q->size = 0;
	return Q;
}
int main() {
	int box[] = {3, 1, 4, 6, 9, 2, 5, 7, 10, 20, 8, 4,6,17,13,42,55,76,23,35,7,203,35,54,65,8,3,7,223};
	int Max_Deep_Value = 0;
	Queue Q = MakeQueue(100);//创建队列
	Tree New_Tree = MakeNewTree(box, sizeof(box)/sizeof(int));
	Max_Deep(New_Tree, &Max_Deep_Value);
	Q = Enqueue(Q, New_Tree);
	PrintTree(Q, Max_Deep_Value);
	return 0;
}