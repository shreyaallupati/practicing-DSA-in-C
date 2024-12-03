#include <stdio.h>
#include <stdlib.h>

#define INF 999  // Large value representing "infinity"
#define MAX 10

void dijkstra(int cost[MAX][MAX], int n, int start_node);

int main()
{
    int cost[MAX][MAX];
    int n, start_node;

    FILE *file = fopen("inDiAdjMat1.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);

    // Read the cost matrix from the file
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(file, "%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)  // No path between nodes
                cost[i][j] = INF;
        }
    }
    fclose(file);

    printf("Enter the Source Vertex: ");
    scanf("%d", &start_node);
    start_node--;  // Adjust for zero-based indexing

    dijkstra(cost, n, start_node);

    return 0;
}

void dijkstra(int cost[MAX][MAX], int n, int start_node)
{
    int distance[MAX], pred[MAX], visited[MAX];
    int count, min_dist, next_node;

    // Initialize distances and predecessors
    for (int i = 0; i < n; i++)
    {
        distance[i] = cost[start_node][i];
        pred[i] = (distance[i] < INF) ? start_node : -1;
        visited[i] = 0;
    }

    distance[start_node] = 0;
    visited[start_node] = 1;
    count = 1;

    while (count < n - 1)
    {
        min_dist = INF;
        next_node = -1;

        for (int i = 0; i < n; i++)
        {
            if (distance[i] < min_dist && !visited[i])
            {
                min_dist = distance[i];
                next_node = i;
            }
        }

        if (next_node == -1)  // No more reachable nodes
            break;

        visited[next_node] = 1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && min_dist + cost[next_node][i] < distance[i])
            {
                distance[i] = min_dist + cost[next_node][i];
                pred[i] = next_node;
            }
        }
        count++;
    }

    // Display distances and paths in the required format
    printf("Source   Destination   Cost   Path\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d         %d           ", start_node + 1, i + 1);
		if (distance[i] == INF)
        {
            printf("INF       -\n");
        }
        else
        {
            printf("%d        ", distance[i]);
            if (i == start_node)
            {
                printf("-\n");  // No path to itself
            }
            else
            {
                int path[MAX], path_length = 0;
                int j = i;

                // Trace the path backwards from the destination to the start node
                while (j != start_node)
                {
                    path[path_length++] = j;
                    j = pred[j];
                }
                path[path_length++] = start_node;

                // Print the path in correct order
                for (int k = path_length - 1; k > 0; k--)
                {
                    printf("%d->", path[k] + 1);
                }
                printf("%d\n", path[0] + 1);
            }
        }
    }
}

