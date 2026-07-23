#include <stdio.h>

#define MAX 100
#define INF 99999

struct Edge {
    int src, dest, weight;
};

struct Edge edges[MAX];

void bellmanFord(int vertices, int edgeCount, int start) {

    int distance[MAX];

    for(int i = 0; i < vertices; i++)
        distance[i] = INF;

    distance[start] = 0;

    for(int i = 1; i <= vertices - 1; i++) {

        for(int j = 0; j < edgeCount; j++) {

            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if(distance[u] != INF &&
               distance[u] + w < distance[v]) {

                distance[v] = distance[u] + w;
            }
        }
    }

    // Negative cycle check
    for(int j = 0; j < edgeCount; j++) {

        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;

        if(distance[u] != INF &&
           distance[u] + w < distance[v]) {

            printf("Negative weight cycle exists\n");
            return;
        }
    }

    printf("\nShortest distances from vertex %d:\n", start);

    for(int i = 0; i < vertices; i++) {
        printf("%d -> %d = %d\n", start, i, distance[i]);
    }
}

int main() {

    int vertices, edgeCount;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edgeCount);

    for(int i = 0; i < edgeCount; i++) {

        printf("Enter src dest weight: ");

        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);
    }

    int start;

    printf("Enter source vertex: ");
    scanf("%d", &start);

    bellmanFord(vertices, edgeCount, start);

    return 0;
}