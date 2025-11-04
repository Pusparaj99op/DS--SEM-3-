#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int graph[MAX][MAX], visited[MAX], n;

void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("%d ", start);
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int vertex = queue[front++];

        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int edges, u, v, choice, start;

    printf("=== GRAPH TRAVERSAL (DFS & BFS) ===\n");
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }

    while (1) {
        printf("\n1. DFS Traversal\n2. BFS Traversal\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                for (int i = 0; i < n; i++) {
                    visited[i] = 0;
                }
                printf("DFS Traversal: ");
                DFS(start);
                printf("\n");
                break;
            case 2:
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                printf("BFS Traversal: ");
                BFS(start);
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
