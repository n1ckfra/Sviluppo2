#include <stdio.h>
#include <stdlib.h>

// Function to calculate total distance for each index
void calculateDistances(int *K, int N, int M, int *distances) {
    for (int i = 0; i < N; ++i) {
        int leftDistance = i == 0 ? K[i] : K[i] - K[i - 1];
        int rightDistance = i == N - 1 ? M - K[i] : K[i + 1] - K[i];
        distances[i] = leftDistance + rightDistance;
    }
}

// Comparator function for qsort (for macOS)
int compare(void *distances, const void *a, const void *b) {
    int *dist = (int *)distances;
    int indexA = *(const int *)a;
    int indexB = *(const int *)b;
    return dist[indexB] - dist[indexA]; // Decreasing order
}

int main() {
    int N, M;
    int *K, *distances;

    freopen("input0.txt", "r", stdin);
    freopen("output0.txt", "w", stdout);

    scanf("%d %d", &N, &M);

    K = (int *)malloc(N * sizeof(int));
    distances = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; ++i) {
        scanf("%d", &K[i]);
    }

    calculateDistances(K, N, M, distances);

    // Sort the indexes based on the distances (for macOS)
    qsort_r(K, N, sizeof(int), distances, compare);

    // Write the sorted indexes to the output file
    for (int i = 0; i < N; ++i) {
        printf("%d\n", K[i]);
    }

    free(K);
    free(distances);
    return 0;
}
