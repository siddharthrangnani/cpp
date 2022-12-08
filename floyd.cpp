#include<bits/stdc++.h>
using namespace std;

#define V 5

#define inf 999

void printMatrix(int matrix[][V]);

void floydWarshall(int graph[][V]) {
  int matrix[V][V], i, j, k;

  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      matrix[i][j] = graph[i][j];

  for (k = 0; k < V; k++) {
    for (i = 0; i < V; i++) {
      for (j = 0; j < V; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printMatrix(matrix);
}

void printMatrix(int matrix[][V]) {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (matrix[i][j] == inf)
        printf("%4s", "inf");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main() {
 int graph[V][V]={
        {0,6,8,inf,-4},
        {inf,0,inf,1,7},
        {inf,4,0,inf,inf},
        {2,inf,-5,0,inf},
        {inf,inf,inf,3,0}
    };
  floydWarshall(graph);
}