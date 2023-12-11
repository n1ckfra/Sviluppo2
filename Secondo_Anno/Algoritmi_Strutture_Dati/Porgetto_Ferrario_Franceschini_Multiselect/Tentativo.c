#include <stdio.h>
#include <stdlib.h>

// Funziona
int countSteps(int K[][2], int N, int M){
    int totalSteps = 0;
    int boundSx = 0; int boundRx = M;
    for (int i = 0; i < N; i++)
    {
        totalSteps += boundRx - boundSx;
        if (K[i + 1][0] > K[i][0])
        {
            boundSx = K[i][0] + 1;
        } else if (K[i + 1][0] < K[i][0])
        {
            boundRx = K[i][0] - 1;
        }
    }
    return totalSteps;
}

void orderIndex(int K[][2], int N, int M) {
    for (int j = 0; j < N; j++) {
        int leftDistance = j == 0 ? K[j][0] : K[j][0] - K[j - 1][0] - 1;
        int rightDistance = j == N - 1 ? M - K[j][0] - 1 : K[j + 1][0] - K[j][0] - 1;
        K[j][1] = leftDistance + rightDistance;
    }
}

int compare(const void* a, const void* b) {
    int* arr1 = (int*)a;
    int* arr2 = (int*)b;
    return arr2[1] - arr1[1]; // For decreasing order
}

int main() {
    int N, M;
    
    // Uncommented the lines for file input/output
    freopen("input0.txt", "r", stdin);
    freopen("output0.txt", "w", stdout);

    // Read N and M from the file
    scanf("%d %d", &N, &M);

    // Create array K
    int K[N][2];
    int indexes[N];
    
    // Read the indexes values from the file
    for (int i = 0; i < N; ++i) {
        scanf("%d", &indexes[i]);
    }

    // Populate the array
    for (int i = 0; i < N; i++) {
        K[i][0] = indexes[i];
        K[i][1] = 0;
    }

    orderIndex(K, N, M);
    qsort(K, N, sizeof(K[0]), compare);
    printf("%d", countSteps(K, N, M));

    return 0;
}
