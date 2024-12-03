#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge {
    int u, v, w;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to find the parent of an element (with path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to unite two subsets
void Union(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Comparison function for sorting edges by weight
int compareEdges(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->w - edgeB->w;
}

int main() {
    FILE *inputFile, *outputFile;
    inputFile = fopen("in_kruskal.txt", "r");
    outputFile = fopen("out_kruskal.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int n, m;
    fscanf(inputFile, "%d %d", &n, &m);  // Read number of nodes and edges

    struct Edge edges[m];

    // Read all the edges
    int i;
    for (i = 0; i < m; i++) {
        fscanf(inputFile, "%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        // Adjust node numbers to 0-based index
        edges[i].u -= 1;
        edges[i].v -= 1;
    }

    // Sort edges by their weight
    qsort(edges, m, sizeof(edges[0]), compareEdges);

    // Create subsets for union-find
    struct Subset *subsets = (struct Subset*)malloc(n * sizeof(struct Subset));
    int v;
    for (v = 0; v < n; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int totalWeight = 0;
    fprintf(outputFile, "Edge Cost\n");

    // Kruskal's algorithm
    int e;
    for (i = 0, e = 0; e < n - 1 && i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int rootU = find(subsets, u);
        int rootV = find(subsets, v);

        // If including this edge doesn't cause a cycle
        if (rootU != rootV) {
            fprintf(outputFile, "%d--%d %d\n", u + 1, v + 1, w);
            totalWeight += w;
            Union(subsets, rootU, rootV);
            e++;
        }
    }

    fprintf(outputFile, "Total Weight of the Spanning Tree: %d\n", totalWeight);

    // Clean up
    free(subsets);
    fclose(inputFile);
    fclose(outputFile);

    printf("MST calculated and written to output.txt.\n");
    return 0;
}

