#include <stdio.h>
#include <stdlib.h>

struct frazione {
    long num; // Numeratore
    long den; // Denominatore
};

typedef struct frazione Frazione;

// Prototipi delle funzioni
Frazione creaFrazione(long num, long den);
Frazione semplifica(Frazione f);
void stampaFrazione(Frazione f);
Frazione somma(Frazione f1, Frazione f2);
Frazione sottrazione(Frazione f1, Frazione f2);
Frazione mult(Frazione f1, Frazione f2);
Frazione div(Frazione f1, Frazione f2);
long mcd(long a, long b);

// Implementazione delle funzioni

Frazione creaFrazione(long num, long den) {
    if (den == 0) {
        printf("Denominatore non può essere zero.\n");
        exit(1); // Termina il programma con un codice di errore
    }
    Frazione f = {num, den};
    return semplifica(f);
}

Frazione semplifica(Frazione f) {
    long m = mcd(f.num, f.den);
    f.num /= m;
    f.den /= m;
    return f;
}

void stampaFrazione(Frazione f) {
    printf("%ld/%ld\n", f.num, f.den);
}

Frazione somma(Frazione f1, Frazione f2) {
    long num = f1.num * f2.den + f2.num * f1.den;
    long den = f1.den * f2.den;
    return creaFrazione(num, den);
}

Frazione sottrazione(Frazione f1, Frazione f2) {
    long num = f1.num * f2.den - f2.num * f1.den;
    long den = f1.den * f2.den;
    return creaFrazione(num, den);
}

Frazione mult(Frazione f1, Frazione f2) {
    long num = f1.num * f2.num;
    long den = f1.den * f2.den;
    return creaFrazione(num, den);
}

Frazione div(Frazione f1, Frazione f2) {
    long num = f1.num * f2.den;
    long den = f1.den * f2.num;
    if (den == 0) {
        printf("Divisione per zero.\n");
        exit(1);
    }
    return creaFrazione(num, den);
}

long mcd(long a, long b) {
    if (b == 0) return a;
    return mcd(b, a % b);
}

// Funzione principale per dimostrare l'uso delle frazioni
int main() {
    Frazione f1 = creaFrazione(4, 8);
    Frazione f2 = creaFrazione(2, 5);

    printf("Frazione 1: ");
    stampaFrazione(f1);

    printf("Frazione 2: ");
    stampaFrazione(f2);

    Frazione sommaFra = somma(f1, f2);
    printf("Somma: ");
    stampaFrazione(sommaFra);

    Frazione diffFra = sottrazione(f1, f2);
    printf("Differenza: ");
    stampaFrazione(diffFra);

    Frazione prodFra = mult(f1, f2);
    printf("Prodotto: ");
    stampaFrazione(prodFra);

    Frazione divFra = div(f1, f2);
    printf("Divisione: ");
    stampaFrazione(divFra);

    return 0;
}
