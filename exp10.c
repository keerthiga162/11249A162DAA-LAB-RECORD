#include <stdio.h>
#include <limits.h>

#define MAX 10

int main() {
    int n, i, j, src, u;
    int cost[MAX][MAX], dist[MAX], visited[MAX] = {0};
    int min;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            
            if (i != j && cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    
    for (i = 0; i < n; i++) {
        dist[i] = cost[src][i];
        visited[i] = 0;
    }

    dist[src] = 0;
    visited[src] = 1;

    
    for (i = 1; i < n; i++) {
        min = INT_MAX;

        
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

    
        for (j = 0; j < n; j++) {
            if (!visited[j] && cost[u][j] != INT_MAX &&
                dist[u] + cost[u][j] < dist[j]) {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }


    printf("\nShortest distances from vertex %d:\n", src);
    for (i = 0; i < n; i++) {
        printf("%d -> %d = %d\n", src, i, dist[i]);
    }

    return 0;
}