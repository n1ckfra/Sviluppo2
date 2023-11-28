#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int** trasponiMatrice(int righe, int colonne, int** matrice) {
    // Allocazione dinamica della matrice trasposta
    int** trasposta = (int**)malloc(colonne * sizeof(int*));
    for (int i = 0; i < colonne; ++i) {
        trasposta[i] = (int*)malloc(righe * sizeof(int));
    }

    // Riempimento della matrice trasposta
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            trasposta[j][i] = matrice[i][j];
        }
    }

    return trasposta;
}

int main() {
    // Esempio di utilizzo della funzione
    int righe = 3, colonne = 2;
    int** matrice = (int**)malloc(righe * sizeof(int*));
    for (int i = 0; i < righe; ++i) {
        matrice[i] = (int*)malloc(colonne * sizeof(int));
    }

    // Riempimento matrice normale

    int** matriceTrasposta = trasponiMatrice(righe, colonne, matrice);

    // Utilizzo della matrice trasposta
    // ...

    // Deallocazione della memoria
    for (int i = 0; i < righe; ++i) {
        free(matrice[i]);
    }
    free(matrice);

    for (int i = 0; i < colonne; ++i) {
        free(matriceTrasposta[i]);
    }
    free(matriceTrasposta);

    return 0;
}
