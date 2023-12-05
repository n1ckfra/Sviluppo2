#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int N, M;
int *K;

void find_optimal_sequence(int arr[]) {
    int start = 0, end = M - 1, total_steps = 0;
    for (int i = 0; i < N; i++) {
        total_steps += end - start + 1;
        if (i < N - 1) {
            if (K[i + 1] > K[i]) {
                start = K[i] + 1;
            } else {
                end = K[i] - 1;
            }
        }
    }

    // Scrivere result su file
    FILE *fileOutput = fopen("output0.txt", "w");
    fprintf(fileOutput, "%d", total_steps);
    fclose(fileOutput);

}

int main() {

    FILE *fileInput = fopen("input0.txt", "r");
    fscanf(fileInput, "%d %d", &N, &M);
    int *K= (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        fscanf(fileInput, "%d", &K[i]);
    fclose(fileInput);

    int *arr = (int *)malloc(M * sizeof(int));

    find_optimal_sequence(arr);

    free(K);
    free(arr);
    return 0;
}
