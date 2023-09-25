#include <stdio.h>

int main(){

    int numero;

    while(1){
        
        printf("Inserire numero: ");
        scanf("%i", &numero);

         if (numero >= 1000 && numero <= 9999) {
            int migliaia = numero / 1000;
            int centinaia = (numero % 1000) / 100;
            int decine = (numero % 100) / 10;
            int unita = numero % 10;

            printf("SI\n");
            printf("%i %i %i %i\n", migliaia, centinaia, decine, unita);
        } else {
            printf("NO\n");
        }
    }
    return 0;
}

