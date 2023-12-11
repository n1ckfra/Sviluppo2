#include <stdio.h>
#include <stdlib.h>

// input data
int N, M;
int *K;

// Structure to represent a subarray
typedef struct {
    int start;
    int end;
} Subarray;

// Structure to represent a list of subarrays
typedef struct {
    Subarray* subarrays;
    int size;
} SubarrayList;


// Function to find the subarray containing K
Subarray findSubarrayContainingK(SubarrayList current_subarrays, int K) {
    for (int i = 0; i < current_subarrays.size; i++) {
        if (K >= current_subarrays.subarrays[i].start && K <= current_subarrays.subarrays[i].end) {
            return current_subarrays.subarrays[i];
        }
    }
    Subarray null_subarray = {-1, -1}; // Return a null subarray if not found
    return null_subarray;
}

// Function to update the list of subarrays
SubarrayList updateSubarrays(SubarrayList current_subarrays, Subarray selected_subarray, int K) {
    SubarrayList new_subarrays;
    new_subarrays.subarrays = (Subarray*)malloc(sizeof(Subarray) * (current_subarrays.size + 1));
    new_subarrays.size = 0;

    for (int i = 0; i < current_subarrays.size; i++) {
        if (current_subarrays.subarrays[i].start != selected_subarray.start || 
            current_subarrays.subarrays[i].end != selected_subarray.end) {
            new_subarrays.subarrays[new_subarrays.size++] = current_subarrays.subarrays[i];
        } else {
            if (K != selected_subarray.start) {
                new_subarrays.subarrays[new_subarrays.size++] = (Subarray){selected_subarray.start, K - 1};
            }
            if (K != selected_subarray.end) {
                new_subarrays.subarrays[new_subarrays.size++] = (Subarray){K + 1, selected_subarray.end};
            }
        }
    }

    free(current_subarrays.subarrays); // Free the old subarrays
    return new_subarrays;
}

// Main function to find the minimum iterations
int findMinimumIterations(int N, int M, int K_indexes[]) {
    int total_iterations = M;
    SubarrayList current_subarrays;
    current_subarrays.subarrays = (Subarray*)malloc(sizeof(Subarray));
    current_subarrays.subarrays[0] = (Subarray){0, M - 1};
    current_subarrays.size = 1;

    for (int i = 0; i < N; i++) {
        Subarray selected_subarray = findSubarrayContainingK(current_subarrays, K_indexes[i]);
        total_iterations += selected_subarray.end - selected_subarray.start + 1;
        current_subarrays = updateSubarrays(current_subarrays, selected_subarray, K_indexes[i]);
    }

    free(current_subarrays.subarrays); // Free the final subarrays
    return total_iterations;
}


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

    int min_iterations = findMinimumIterations(N, M, K);
    printf("%d", min_iterations);

    // Free the allocated memory
    free(K);

    return 0;
}
