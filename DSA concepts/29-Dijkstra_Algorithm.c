#include <stdio.h>

#define MAX 100
#define INF 99999

int graph[MAX][MAX];

void dijkstra(int vertices, int start) {
    int distance[MAX];
    int visited[MAX];

    for(int i = 0; i < vertices; i++) {
        distance[i] = INF;
        visited[i] = 0;
    }

    distance[start] = 0;

    for(int count = 0; count < vertices - 1; count++) {

        int min = INF, u;

        for(int i = 0; i < vertices; i++) {
            if(!visited[i] && distance[i] < min) {
                min = distance[i];
                u = i;
            }
        }

        visited[u] = 1;

        for(int v = 0; v < vertices; v++) {
            if(!visited[v] &&
               graph[u][v] &&
               distance[u] + graph[u][v] < distance[v]) {

                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", start);

    for(int i = 0; i < vertices; i++) {
        printf("%d -> %d = %d\n", start, i, distance[i]);
    }
}

int main() {
    int vertices;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter adjacency matrix:\n");

    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int start;

    printf("Enter source vertex: ");
    scanf("%d", &start);

    dijkstra(vertices, start);

    return 0;
}