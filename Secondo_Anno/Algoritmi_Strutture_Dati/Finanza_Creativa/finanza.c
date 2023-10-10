#include <stdio.h>
#include <assert.h>

#define MAXN 1000000

/*
POSSIBILE IMPLEMENTAZIONE:
    Escludere le cifre che non potranno essere le più significative
    ES. N=6 K=3 N=4-6 Non saranno le miei cifre

    Prendo un intervallo dimensione N-K e prendo la cifra minore dentro ogni intervallo
    L'intervallo viene poi spostato e rivalutato

    Intervallo N-1-(N-K-1)=k
    Intervallo [0, k]
    RIS = [Contiene 0, e 1 negli elementi che voglio tenere]
    for(int i = 0, < N-K-1)
        IndiceMinimo = trovaminimo(Intervallo[])
        RIS[IndiceMinimo] = 1
        I[0] = IndiceMinimo + 1
        I[1] = I[1] + 1
*/

void bianchetta(int N, int K, int U[], int C[]) {

    // Verifico la presenza di 0 nelle prime k posizioni
    if (U[K + 1] == 0)
    {
        for (int i = 0; i < K; i++)
        {
            /* code */
        }
        
    }
    
    for (int i = 0; i < K; i++)
    {
        if (U[i] == 0 )
        {
            
        }
        
    }
    
}


int U[MAXN], C[MAXN];

int main() {
    FILE *fr, *fw;
    int N, K, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(2 == fscanf(fr, "%d%d", &N, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &U[i]));

    bianchetta(N, K, U, C);
    for(i=0; i<N-K; i++)
        fprintf(fw, "%d ", C[i]);
    fprintf(fw, "\n" );
    fclose(fr);
    fclose(fw);
    return 0;
}
