#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];

int front = -1, rear = -1;

void enqueue(int value) {
    if(rear == MAX - 1)
        return;

    if(front == -1)
        front = 0;

    queue[++rear] = value;
}

int dequeue() {
    if(front == -1 || front > rear)
        return -1;

    return queue[front++];
}

void BFS(int start, int vertices) {
    enqueue(start);
    visited[start] = 1;

    while(front <= rear) {
        int current = dequeue();

        printf("%d ", current);

        for(int i = 0; i < vertices; i++) {
            if(graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
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

    printf("BFS Traversal: ");
    BFS(start, vertices);

    return 0;
}