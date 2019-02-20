#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<iostream>
using namespace std;
#define NotAVertex -1

void TopSort(int Matrix[7][7]) {
    int Counter = 0;
    int V, W;
    int i, j;
    int InDegree[7];
    int Visited[7];
    int TopNum[7];
    queue<int> Q;
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
    for (i = 0; i < 7; ++i) {
        if(!InDegree[i]) {
            Q.push(i);
            Visited[i] = 1;
        }
    }
    while(!Q.empty()) {
        V = Q.front();
        Q.pop();
        TopNum[V] = ++Counter;
        for (i = 0; i < 7; ++i) {
            if(Matrix[V][i]) {
                if(--InDegree[i] == 0)
                    Q.push(i);
            }
        }
    }
    if(Counter != 7)
        printf("Graph has a cycle\n");
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