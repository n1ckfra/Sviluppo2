#include <stdio.h>
#include <limits.h>

int trova_max_dei_minimi(int matrice[10][10], int righe, int colonne) {
    int minimo, riga_max = 0;
    int max_dei_minimi = INT_MIN; //inizializzo a un valore molto piccolo
    
    for (int i = 0; i < righe; i++) {
        minimo = INT_MAX; //inizializzo a un valore molto grande
        for (int j = 0; j < colonne; j++) {
            if (matrice[i][j] < minimo) {
                minimo = matrice[i][j];
            }
        }
        if (minimo > max_dei_minimi) {
            max_dei_minimi = minimo;
            riga_max = i;
        }
    }
    
    return riga_max;
}

int trova_max_dei_minimi_puntatore(int *matrice, int righe, int colonne) {
    int minimo, riga_max = 0;
    int max_dei_minimi = INT_MIN;
    
    for (int i = 0; i < righe; i++) {
        minimo = INT_MAX;
        for (int j = 0; j < colonne; j++) {
            if (*(matrice + i*10 + j) < minimo) {  // nota: qui uso "10" perché è la dimensione fisica della matrice
                minimo = *(matrice + i*10 + j);
            }
        }
        if (minimo > max_dei_minimi) {
            max_dei_minimi = minimo;
            riga_max = i;
        }
    }
    
    return riga_max;
}

int main() {
    int mat[10][10] = {
        {10, 20, 30, 40, 50, 60, 70, 80, 90, 100},
        {5, 15, 25, 35, 45, 55, 65, 75, 85, 95},
        // ... altre righe ...
    };

    int risultato = trova_max_dei_minimi(mat, 10, 10);
    printf("Risultato con notazione di matrice: Riga %d\n", risultato);
    
    risultato = trova_max_dei_minimi_puntatore(&mat[0][0], 10, 10);
    printf("Risultato con notazione di puntatore: Riga %d\n", risultato);

    return 0;
}