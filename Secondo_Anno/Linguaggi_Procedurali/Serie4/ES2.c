#include <stdio.h>

// Funzione che restituisce un puntatore all'elemento più piccolo dell'array
int *smallest(int vect[], int len) {
    int *min = &vect[0]; // Puntatore all'elemento iniziale dell'array
    
    for (int i = 1; i < len; i++) {
        if (vect[i] < *min) {
            min = &vect[i]; // Aggiorniamo il puntatore se troviamo un elemento più piccolo
        }
    }
    return min;
}

int main() {
    int vect[] = {3, 1, 7, 9, 2, 4};
    int len = sizeof(vect) / sizeof(vect[0]);
    
    // Stampa dell'array
    printf("Array: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", vect[i]);
    }
    printf("\n");

    int *min_pointer = smallest(vect, len);

    // Stampa dell'indirizzo e del valore
    printf("Indirizzo dell'elemento più piccolo: %p\n", min_pointer);
    printf("Valore dell'elemento più piccolo: %d\n", *min_pointer);
    
    return 0;
}