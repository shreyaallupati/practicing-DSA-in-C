#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define INF 99999

// Structure to store the paths
typedef struct {
    int dist[MAX][MAX];
    int next[MAX][MAX];
} Graph;

// Function to initialize the graph
void initializeGraph(Graph *g, int n) {
	int i,j;
    for(i = 0; i < n; i++) {
        for( j = 0; j < n; j++) {
            g->next[i][j] = -1;
            if(i == j)
                g->dist[i][j] = 0;
            else
                g->dist[i][j] = INF;
        }
    }
}

// Function to add edge
void addEdge(Graph *g, int u, int v, int w) {
    g->dist[u][v] = w;
}

// Floyd Warshall Algorithm
void floydWarshall(Graph *g, int n) {
    // Initialize next array for path reconstruction
    int i,j,k;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(g->dist[i][j] != INF && i != j) {
                g->next[i][j] = j;
            }
        }
    }

    // Main Floyd-Warshall Algorithm
    for( k = 0; k < n; k++) {
        for( i = 0; i < n; i++) {
            for( j = 0; j < n; j++) {
                if(g->dist[i][k] != INF && g->dist[k][j] != INF && g->dist[i][k] + g->dist[k][j] < g->dist[i][j]) {
                    g->dist[i][j] = g->dist[i][k] + g->dist[k][j];
                    g->next[i][j] = g->next[i][k];
                }
            }
        }
    }
}

// Function to print the path
void printPath(Graph *g, int src, int dest) {
    if(g->next[src][dest] == -1) {
        printf("No path exists\n");
        return;
    }

    printf("\nShortest Path from vertex %d to vertex %d: ", src + 1, dest + 1);
    int current = src;
    while(current != dest) {
        printf("%d->", current + 1);
        current = g->next[current][dest];
    }
    printf("%d\n", dest + 1);
    printf("Path weight: %d\n", g->dist[src][dest]);
}

// Function to print distance matrix
void printDistanceMatrix(Graph *g, int n) {
	int i,j;
    printf("\nFinal Distance Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(g->dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", g->dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, src, dest, i, j;
    Graph g;
    
    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    // Initialize the graph
    initializeGraph(&g, n);
    
    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for( j = 0; j < n; j++) {
            int weight;
            scanf("%d", &weight);
            if(weight != 0 || i == j) {
                addEdge(&g, i, j, weight);
            }
        }
    }
    
    // Input source and destination
    printf("Enter source and destination vertex: ");
    scanf("%d %d", &src, &dest);
    src--; // Convert to 0-based indexing
    dest--; // Convert to 0-based indexing
    
    // Apply Floyd-Warshall algorithm
    floydWarshall(&g, n);
    
    // Print the distance matrix
    printDistanceMatrix(&g, n);
    
    // Print the shortest path
    printPath(&g, src, dest);
    
    return 0;
}
