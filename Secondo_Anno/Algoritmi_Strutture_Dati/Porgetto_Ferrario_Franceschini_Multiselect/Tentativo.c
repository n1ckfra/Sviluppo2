#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/*
    Algoritmo Albero Binario
    Dobbiamo costruoire un albero binario partendo dal fondo. I padri delle foglie finali saranno gli indici con distaza minore.
    Le due foglie verranno combinate per diventare il nuobvo sottoarray di sinistra e di destra. A quel punto dobbiamo capire quale indice siede a cavallo tra questi sottoarray


    Algoritmo greedy
    Quando le distanze sono uguali implementare un migliore criterio di scelta siccome per ora va a caso
*/

// Funziona
int countSteps(int K[][2], int N, int M){
    int totalSteps = 0;
    int boundSx = 0; int boundRx = M;

    for (int i = 0; i < N; i++)
    {
        totalSteps += abs(boundRx - boundSx);
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

bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false;
    }
    return (n & (n - 1)) == 0;
}

int computeStepsNEqualsM(int M, int N, int totalSteps){
    if (M == N)
    {
        totalSteps = M;
        return computeStepsNEqualsM(M - 1, N, totalSteps);
    }
    if (M == 0)
    {
        return round(totalSteps / 2);
    }
    totalSteps += M;
    return computeStepsNEqualsM(M - 1, N, totalSteps);
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
    int totalSteps = 0;
    
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

    if (N == M){
        printf("%d", computeStepsNEqualsM(M, N, totalSteps));
    } else {
        orderIndex(K, N, M);
        qsort(K, N, sizeof(K[0]), compare);
        printf("%d", countSteps(K, N, M));
    }

    return 0;
}