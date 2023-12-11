#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    int *K;

    // Uncommented the lines for file input/output
    freopen("input0.txt", "r", stdin);
    freopen("output0.txt", "w", stdout);

    // Read N and M from the file
    scanf("%d %d", &N, &M);

    // Dynamically allocate memory for K
    K = (int *)malloc(N * sizeof(int));

    // Read the K values from the file
    for (int i = 0; i < N; ++i) {
        scanf("%d", &K[i]);
    }

    int min_iterations = findMinimumIterationsDP(N, M, K_indexes);
    printf("Minimum iterations: %d\n", min_iterations);

    // Free the allocated memory
    free(K);

    return 0;
}