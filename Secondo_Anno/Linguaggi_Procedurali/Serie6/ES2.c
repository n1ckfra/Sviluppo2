#include <stdio.h>

typedef struct {
    int numeratore;
    int denominatore;
} Frazione;

Frazione sommaFrazioni(Frazione f1, Frazione f2) {
    Frazione risultato;
    risultato.numeratore = f1.numeratore * f2.denominatore + f2.numeratore * f1.denominatore;
    risultato.denominatore = f1.denominatore * f2.denominatore;
    return risultato;
}

int main() {
    Frazione f1, f2, risultato;

    // Creare due frazioni
    f1.numeratore = 1;
    f1.denominatore = 2;
    f2.numeratore = 3;
    f2.denominatore = 4;

    // Registrare le frazioni su un file
    FILE *file = fopen("frazioni.txt", "w");
    if (file == NULL) {
        printf("Errore nell'apertura del file\n");
        return 1;
    }
    fprintf(file, "%d/%d\n%d/%d\n", f1.numeratore, f1.denominatore, f2.numeratore, f2.denominatore);
    fclose(file);

    // Rileggere le frazioni dal file
    file = fopen("frazioni.txt", "r");
    if (file == NULL) {
        printf("Errore nell'apertura del file\n");
        return 1;
    }
    fscanf(file, "%d/%d\n%d/%d\n", &f1.numeratore, &f1.denominatore, &f2.numeratore, &f2.denominatore);
    fclose(file);

    // Calcolare e mostrare il risultato della loro somma
    risultato = sommaFrazioni(f1, f2);
    printf("La somma delle frazioni è: %d/%d\n", risultato.numeratore, risultato.denominatore);

    return 0;
}
