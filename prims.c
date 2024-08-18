#include <stdio.h>

#define infinity 999

int prime(int cost[10][10], int source, int n) {
    int i, j, sum = 0, visited[10], cmp[10], vertex[10];
    int min, u, v;

    // Initialize arrays
    for (i = 1; i <= n; i++) {
        vertex[i] = source;
        visited[i] = 0;
        cmp[i] = cost[source][i];
    }
    visited[source] = 1;

    // Main loop for Prim's algorithm
    for (i = 1; i <= n - 1; i++) {
        min = infinity;
        for (j = 1; j <= n; j++) {
            if (!visited[j] && cmp[j] < min) {
                min = cmp[j];
                u = j;
            }
        }
        visited[u] = 1;
        sum = sum + cmp[u];
        printf("\n %d -> %d sum = %d", vertex[u], u, cmp[u]);

        for (v = 1; v <= n; v++) {
            if (!visited[v] && cost[u][v] < cmp[v]) {
                cmp[v] = cost[u][v];
                vertex[v] = u;
            }
        }
    }
    return sum;
}

void main() {
    int a[10][10], n, i, j, m, source;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix (0 for self-loop and 999 for no edge):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Check for symmetry and zero diagonal elements
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (a[i][j] != a[j][i] || (a[i][i] != 0)) {
                printf("\nInvalid entry\nCost matrix should be symmetrical & diagonal elements should be zero.");
                return;
            }
        }
    }

    printf("\nEnter the source vertex: ");
    scanf("%d", &source);

    m = prime(a, source, n);

    printf("\n\nTotal cost = %d", m);
}
