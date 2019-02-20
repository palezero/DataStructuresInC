#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NotAVertex -1
void TopSort(int Matrix[7][7]) {
    int Counter;
    int V, W;
    int i, j;
    int InDegree[7];
    int Visited[7];
    int TopNum[7];
    for (i = 0; i < 7; ++i) {
        InDegree[i] = 0;
        Visited[i] = 0;
        TopNum[i] = 0;
    }
    for (i = 0; i < 7; ++i) {
        for (j = 0; j < 7; ++j) {
            if(Matrix[j][i])
                InDegree[i]++;
        }
    }
    for (Counter = 0; Counter < 7; ++Counter) {
        V = NotAVertex;
        for (i = 0; i < 7; ++i) {
            if(!InDegree[i] && !Visited[i])  {
                V = i;
                Visited[i] = 1;
                break;
            }
        }
        if(V == NotAVertex)
            printf("Graph has a cycle\n");
        TopNum[V] = Counter;
        for (i = 0; i < 7; ++i) {
            if(Matrix[V][i])
                InDegree[i]--;
        }
    }
    for (i = 0; i < 7; ++i)
        printf("Vertex %d sort is %d\n", i+1, TopNum[i]);
}
int main() {
    int Vertex = 7;
    int Vertex_temp;
    int Matrix[7][7];
    int i, j;
    for (i = 0; i < 7; ++i)	{
        for (j = 0; j < 7; ++j) {
            Matrix[i][j] = 0;
        }
    }
    Matrix[0][1] = 1; 	Matrix[0][2] = 1;	Matrix[0][3] = 1; 	Matrix[1][3] = 1;
    Matrix[1][4] = 1;	Matrix[2][5] = 1;	Matrix[3][2] = 1;	Matrix[3][5] = 1;
    Matrix[3][6] = 1;	Matrix[4][3] = 1;	Matrix[4][6] = 1;	Matrix[6][5] = 1;
    TopSort(Matrix);
    return 0;
}