#include <stdio.h>

void stampaAbaco(int numero) {
    if (numero < 0 || numero > 999) {
        printf("Il numero deve essere compreso tra 0 e 999.\n");
        return;
    }

    int centinaia = numero / 100;
    int decine = (numero % 100) / 10;
    int unita = numero % 10;

    printf("|");
    for (int i = 0; i < centinaia; i++) {
        printf("x");
    }
    printf("------");

    printf("|");

    for (int i = 0; i < decine; i++) {
        printf("x");
    }
    printf("------");

    printf("|");

    for (int i = 0; i < unita; i++) {
        printf("x");
    }
    printf("------|\n");
}

int main() {
    int numero;

    printf("Inserire un numero da 0 a 999: ");
    scanf("%d", &numero);

    stampaAbaco(numero);

    return 0;
}