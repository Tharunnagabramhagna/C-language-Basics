#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];

void DFS(int vertex, int vertices) {
    visited[vertex] = 1;

    printf("%d ", vertex);

    for(int i = 0; i < vertices; i++) {
        if(graph[vertex][i] == 1 && !visited[i]) {
            DFS(i, vertices);
        }
    }
}

int main() {
    int vertices, edges;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(int i = 0; i < edges; i++) {
        int u, v;

        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1; // remove for directed graph
    }

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start, vertices);

    return 0;
}