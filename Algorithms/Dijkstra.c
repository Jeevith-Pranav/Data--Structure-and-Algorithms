//Dijkstra’s Algorithm:
//Dijkstra’s Algorithm is a graph algorithm used to find the shortest path from a single source vertex to all other vertices in a weighted graph.

#include <stdio.h>

#define INF 9999
#define V 5

int minDistance(int dist[], int visited[]) {
    int min = INF, index = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void printPath(int parent[], int dest) {
    if (dest == -1)
        return;
    printPath(parent, parent[dest]);
    printf("%d ", dest);
}

void dijkstra(int graph[V][V], int src, int dest) {
    int dist[V], visited[V] = {0}, parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        if (u == -1) break;

        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    if (dist[dest] == INF) {
        printf("No path exists from %d to %d\n", src, dest);
        return;
    }

    printf("Shortest distance from %d to %d is: %d\n",
           src, dest, dist[dest]);

    printf("Path: ");
    printPath(parent, dest);
    printf("\n");
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}
    };

    int src, dest;
    printf("Enter source (0-4): ");
    scanf("%d", &src);

    printf("Enter destination (0-4): ");
    scanf("%d", &dest);

    dijkstra(graph, src, dest);
    return 0;
}
