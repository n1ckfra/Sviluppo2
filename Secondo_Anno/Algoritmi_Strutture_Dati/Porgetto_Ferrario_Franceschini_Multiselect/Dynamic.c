#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the minimum iterations using dynamic programming
int findMinimumIterationsDP(int N, int M, int K_indexes[]) {
    int **DP;
    int i, j, k, min_iter, cost;

    // Allocate memory for the DP table
    DP = (int **)malloc((N + 1) * sizeof(int *));
    for (i = 0; i <= N; i++) {
        DP[i] = (int *)malloc(M * sizeof(int));
        for (j = 0; j < M; j++) {
            DP[i][j] = INT_MAX;
        }
    }

    // Base case: cost of the first selection
    for (j = 0; j < M; j++) {
        DP[0][j] = M;
    }

    // Fill the DP table
    for (i = 1; i <= N; i++) {
        for (j = 0; j < M; j++) {
            for (k = 0; k < N; k++) {
                int K = K_indexes[k];
                if (j <= K) {
                    cost = (K - j) + 1; // Cost of selecting K in the current range
                    if (DP[i - 1][j] != INT_MAX && DP[i - 1][j] + cost < DP[i][K]) {
                        DP[i][K] = DP[i - 1][j] + cost;
                    }
                }
            }
        }
    }

    // Find the minimum iterations from the last row of DP
    min_iter = INT_MAX;
    for (j = 0; j < M; j++) {
        if (DP[N][j] < min_iter) {
            min_iter = DP[N][j];
        }
    }

    // Free the allocated memory
    for (i = 0; i <= N; i++) {
        free(DP[i]);
    }
    free(DP);

    return min_iter;
}

int main() {
    // Example usage
    int N = 3;
    int M = 11;
    int K_indexes[] = {2, 4, 10};

    int min_iterations = findMinimumIterationsDP(N, M, K_indexes);
    printf("Minimum iterations: %d\n", min_iterations);

    return 0;
}
