#include <stdio.h>
#include <limits.h>

#define N 4  // Number of cities

int tsp(int dist[N][N], int visited[], int currPos, int n, int count, int cost, int ans) {
    if (count == n) {
        return cost + dist[currPos][0];  // Return to the origin city
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            ans = tsp(dist, visited, i, n, count + 1, cost + dist[currPos][i], ans);
            visited[i] = 0;
        }
    }

    return ans;
}

int main() {
    int dist[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int visited[N] = {0};
    visited[0] = 1;

    int ans = INT_MAX;
    ans = tsp(dist, visited, 0, N, 1, 0, ans);
    printf("Minimum cost of travel: %d\n", ans);

    return 0;
}
