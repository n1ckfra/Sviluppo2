#include <stdio.h>

void stampaAbaco(int numero) {
    if (numero < 0 || numero > 999) {
        printf("Il numero deve essere compreso tra 0 e 999.\n");
        return;
    }

    int centinaia = numero / 100;
    int decine = (numero % 100) / 10;
    int unita = numero % 10;

    int num[] = {centinaia, decine, unita};

    for (int i = 0; i < 3; i++)
    {
        printf("|");
        for (int j = 0; j < num[i]; j++)
        {
            printf("x");
        }
        printf("------");
        for (int j = 0; j < (10 - num[i]); j++)
        {
            printf("x");
        }
        
        printf("|\n");
    }
}

int main() {
    int numero;

    printf("Inserire un numero da 0 a 999: ");
    scanf("%d", &numero);

    stampaAbaco(numero);

    return 0;
}