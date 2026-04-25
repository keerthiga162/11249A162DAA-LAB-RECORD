#include <stdio.h>
#include <limits.h>

#define MAX 10

int n, cost[MAX][MAX];
int visited[MAX];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int city) {
    int i, temp;
    int min_cost = INT_MAX;

    visited[city] = 1;

    for (i = 0; i < n; i++) {
        if (!visited[i] && cost[city][i] != 0) {
            temp = cost[city][i] + tsp(i);
            min_cost = min(min_cost, temp);
        }
    }

    visited[city] = 0;


    if (min_cost == INT_MAX)
        return cost[city][0];

    return min_cost;
}

int main() {
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }


    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int result = tsp(0);

    printf("Minimum tour cost: %d\n", result);

    return 0;
}