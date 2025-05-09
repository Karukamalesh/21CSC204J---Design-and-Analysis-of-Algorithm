#include <stdio.h>

struct Item {
    int value;
    int weight;
};

int knapsack(struct Item items[], int n, int W) {
    int i, w;
    int K[n + 1][W + 1];

    // Build the K[][] matrix using dynamic programming
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (items[i - 1].weight <= w)
                K[i][w] = (items[i - 1].value + K[i - 1][w - items[i - 1].weight] > K[i - 1][w]) 
                           ? (items[i - 1].value + K[i - 1][w - items[i - 1].weight]) 
                           : K[i - 1][w];
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() {
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;
    int n = sizeof(items) / sizeof(items[0]);

    printf("Max value in knapsack: %d\n", knapsack(items, n, W));

    return 0;
}
