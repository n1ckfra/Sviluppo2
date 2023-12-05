#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int calcola_operazioni_minime(int N, int M, int indici[]) {
    qsort(indici, N, sizeof(int), compare);

    int operazioni = 0;
    int sinistra = 0;
    int destra = M - 1;

    for (int i = 0; i < N; ++i) {
        if (indici[i] - sinistra < destra - indici[i]) {
            operazioni += indici[i] - sinistra;
            sinistra = indici[i];
        } else {
            operazioni += destra - indici[i];
            destra = indici[i];
        }
    }

    return operazioni;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int *indici = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        scanf("%d", &indici[i]);
    }

    int risultato = calcola_operazioni_minime(N, M, indici);
    printf("%d\n", risultato);

    free(indici);
    return 0;
}
