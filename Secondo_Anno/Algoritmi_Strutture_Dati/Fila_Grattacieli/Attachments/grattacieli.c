#include <stdio.h>
#include <assert.h>

#define MAXN 100000

int osserva(int N, int H[]) {

    int maxHeight = 0;
    
    // Trovo altezza massima
    for (int i = 0; i < N; i++)
    {
        if (H[i] > maxHeight)
        {
            maxHeight = H[i];
        }
    }

    // Creo un array con tutti 0
    int H2[N]; 
    for (int i = 0; i < N; i++)
    {
        H2[i] = 0;     
    }
    
    // Metto 1 nella posizione del o dei grattacieli piu alti
    for (int i = 0; i < N; i++)
    {
        if (H[i] == maxHeight)
        {
            H2[i] = 1;
        }
    }
    
    //Partendo da sinistra verso destra, calcolo quanti grattacieli vede quello piu alto e lo aggiungo al valore nell'array
    int maxDX = 0;
    for(int i = 0; i < N; i++){
        maxDX += 1;
        if(H2[i] == 1){
            H2[i] = maxDX;
            maxDX = 1;
        }
    }

    //Partendo da destra verso sinistra, calcolo quanti grattacieli vede quello piu alto e lo aggiungo al valore nell'array
    int maxSX = 0;
    for(int i = N-1; i >= 0; i--){
        maxSX += 1;
        if(H2[i] > 0){
            H2[i] += maxSX;
            maxSX = 1;
        }
    }

    // Ritorno il valore massimo contenuto nell'array copia, che corrisponde al numero di grattacieli
    int maxValue = H2[0];
    for (int i = 0; i < N; i++)
    {
        if (H2[i] > maxValue)
        {
            maxValue = H2[i];
        }
    }

    return maxValue - 1;
    
}


int H[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &H[i]));

    fprintf(fw, "%d\n", osserva(N, H));
    fclose(fr);
    fclose(fw);
    return 0;
}
