#include <stdio.h>

int main(){
    
    float base, altezza;

    printf("Inserire base rettangolo: ");
    scanf("%f", &base);
    printf("Inserire altezza rettangolo: ");
    scanf("%f", &altezza);

    printf("Base    Altezza     Perimetro   Area    Rapporto\n");
    printf("%.0f    ", base);
    printf("%.0f    ", altezza);
    printf("%.0f    ",(base * 2) + (altezza * 2));
    printf("%.0f    ", (base * altezza) / 2);
}