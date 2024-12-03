#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 40

int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;
	int v;
    for ( v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
	return min_index;
}

void printMST(int parent[], int graph[MAX][MAX], int V) {
    int total_cost = 0;
    int mst[MAX][MAX] = {0};  

    printf("Cost adjacency matrix of the Minimum Spanning Tree:\n");
    int i, j;
    for (i = 1; i < V; i++) {
        mst[i][parent[i]] = graph[i][parent[i]];
        mst[parent[i]][i] = graph[i][parent[i]];
        total_cost += graph[i][parent[i]];
    }

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("%d ", mst[i][j]);
        }
        printf("\n");
    }

    printf("Total Weight of the Spanning Tree: %d\n", total_cost);
}

void primMST(int graph[MAX][MAX], int V) {
    int parent[MAX];  
    int key[MAX];     
    bool mstSet[MAX]; 
	int i, count, v;
    
    for (i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    
    key[0] = 0;     
    parent[0] = -1;  

    
    for (count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
		mstSet[u] = true;
		for (v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            	parent[v] = u, key[v] = graph[u][v];
        }
    }
	printMST(parent, graph, V);
}

int main() {
    int graph[MAX][MAX];
    int V;  

    FILE *file = fopen("input_prims.txt", "r");
    if (!file) {
        printf("Error in opening file!\n");
        return -1;
    }

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }
    fclose(file);

    primMST(graph, V);

    return 0;
}

