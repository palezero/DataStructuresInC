#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define NotAvertex (-1)
#define Infinity INT_MAX
#define Min 0
#define NumVertex 7
struct ListNode;
typedef struct ListNode* List;
struct ListNode {
	List Next;
	int Vertex;
	int Dist;
};
typedef int Vertex;
struct TableEntry
{
	List Header;//邻接表
	int Known;
	int Dist;
	Vertex Path;
};
typedef struct TableEntry Table[NumVertex];//定义节点信息结构体数组
typedef int Graph[NumVertex][NumVertex];
void ReadGraph(Graph G, Table T) {
	int i, j;
	List temp, temp2;
	for (i = 0; i < NumVertex; ++i) {
		T[i].Header = (List)malloc(sizeof(struct ListNode));
		T[i].Header->Vertex = i;
		T[i].Header->Next = NULL;
		temp = T[i].Header;
		for (j = 0; j < NumVertex; ++j) {
			if(G[i][j]) {
				temp2 = (List)malloc(sizeof(struct ListNode));
				temp2->Vertex = j;
				temp2->Dist = G[i][j];
				temp2->Next = NULL;
				temp->Next = temp2;
				temp = temp->Next;
			}
		}
		temp = T[i].Header->Next;
	}
}
void InitTable(Vertex Start, Graph G, Table T) {
	//初始化
	int i;
	ReadGraph(G, T);//将邻接矩阵转成邻接表
	for (int i = 0; i < NumVertex; ++i) {
		T[i].Known = false;//如果发现该节点，就设为True
		T[i].Dist = Infinity;//初始化所有节点都是无连接的，也就是距离为无穷大
		T[i].Path = NotAvertex;
	} 
	T[Start].Dist = 0;//定义起始节点，它和自身的距离为0
}
void PrintTable(Table T) {
	int i;
	List temp;
	printf("Adjust Table Output: \n");
	for (i = 0; i < NumVertex; ++i)	{
		temp = T[i].Header;
		printf("Vertex %d: ", temp->Vertex);
		temp = temp->Next;
		while(temp != NULL) {
			printf("%d(%d)", temp->Vertex, temp->Dist);
			if(temp->Next != NULL)
				printf(", ");
			temp = temp->Next;
		}
		printf("\n");
	}
}
void Dijkstra(Table T) {
	int Max;
	Vertex MinDist_Vertex;
	Vertex Each_Adjust_Vertex;
	printf("For A chosen Start, the Following Vertex would be found:\n");
	while( 1) {
		Max = INT_MAX;
		MinDist_Vertex = NotAvertex;
		for (int i = 0; i < NumVertex; ++i) {
			//在每一个未知节点中找出距离最短的那个
			if(T[ i].Known == false && T[ i].Dist < Max) {
				MinDist_Vertex = i;
				Max = T[ i].Dist;
			}
		}
		if(MinDist_Vertex == NotAvertex)
			break;
		printf("%d\n", MinDist_Vertex + 1);
		T[ MinDist_Vertex].Known = true;
		if(T[ MinDist_Vertex].Header->Next != NULL)
			for ( List First = T[MinDist_Vertex].Header->Next; First != NULL; First = First->Next) {
				Each_Adjust_Vertex = First->Vertex;
				if( !T[ Each_Adjust_Vertex].Known) {
					if( T[ MinDist_Vertex].Dist + First->Dist < T[ Each_Adjust_Vertex].Dist) {
						T[ Each_Adjust_Vertex].Dist = T[ MinDist_Vertex].Dist + First->Dist;
						//这里可用二叉堆优化节点较稀疏时的情况
						T[ Each_Adjust_Vertex].Path = MinDist_Vertex;
					}
				}
			}
	}
}

void PrintPath(Vertex V, Table T) {
	if(T[V].Path != NotAvertex) {
		PrintPath(T[V].Path, T);
		printf(" to ");
	}
	printf("%d", V);
}
int main()
{
	const int Node = 5;
	int i;
	Graph Adjust;
	memset(Adjust, 0, NumVertex * NumVertex * sizeof(Vertex));
	Table T;//7个元素的结构体数组
	Adjust[1-1][2-1] = 2;//邻接矩阵
	Adjust[1-1][4-1] = 1;
	Adjust[2-1][4-1] = 3;
	Adjust[2-1][5-1] = 10;
	Adjust[3-1][1-1] = 4;
	Adjust[3-1][6-1] = 5;
	Adjust[4-1][3-1] = 2;
	Adjust[4-1][5-1] = 2;
	Adjust[4-1][6-1] = 8;
	Adjust[4-1][7-1] = 4;
	Adjust[5-1][7-1] = 6;
	Adjust[7-1][6-1] = 1;
	InitTable(1-1, Adjust, T);
	PrintTable(T);
	Dijkstra(T);
	printf("Path between the Start and other Vertex\n");
	for (i = 0; i < NumVertex; ++i) {
		PrintPath(i, T); //输出每一条最短路径
		printf("\n");
	}
	return 0;
}