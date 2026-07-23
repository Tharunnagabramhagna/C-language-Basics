#include <stdio.h>

#define MAX 100
#define INF 99999

void floydWarshall(int graph[MAX][MAX], int vertices) {

    int dist[MAX][MAX];

    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for(int k = 0; k < vertices; k++) {

        for(int i = 0; i < vertices; i++) {

            for(int j = 0; j < vertices; j++) {

                if(dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\nShortest distance matrix:\n");

    for(int i = 0; i < vertices; i++) {

        for(int j = 0; j < vertices; j++) {

            if(dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }

        printf("\n");
    }
}

int main() {

    int vertices;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter adjacency matrix:\n");

    for(int i = 0; i < vertices; i++) {

        for(int j = 0; j < vertices; j++) {

            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(graph, vertices);

    return 0;
}