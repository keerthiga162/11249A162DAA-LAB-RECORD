#include <stdio.h>
#include <limits.h>

#define MAX 10

int main() {
    int n, i, j, u, v;
    int cost[MAX][MAX], visited[MAX] = {0};
    int min, totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    }

    visited[0] = 1;  

    printf("\nEdges in MST:\n");

    for (int count = 0; count < n - 1; count++) {
        min = INT_MAX;

        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", u, v, min);

        totalCost += min;
        visited[v] = 1;
    }

    printf("\nTotal cost of MST = %d\n", totalCost);

    return 0;
}