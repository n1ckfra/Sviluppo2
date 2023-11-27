#include <stdio.h>

int powof2plus1(int exp) {
    return (1 << exp) + 1;
}

int getBitAtPos(unsigned char value, int pos) {
    return (value >> pos) & 1;
}

void printBinary(unsigned char value) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", getBitAtPos(value, i));
    }
    printf("\n");
}

unsigned char setBitAtPos(unsigned char value, int pos, int bitValue) {
    if (bitValue == 0) {
        // Imposta il bit a 0 usando l'AND con un numero che ha tutti i bit a 1 tranne quello alla posizione pos
        return value & ~(1 << pos);
    } else {
        // Imposta il bit a 1 usando l'OR con un numero che ha tutti i bit a 0 tranne quello alla posizione pos
        return value | (1 << pos);
    }
}

unsigned char reverseBits(unsigned char value) {
    unsigned char result = 0;
    for (int i = 0; i < 8; i++) {
        // Ottiene il bit alla posizione i e lo imposta nella posizione opposta (7 - i)
        result = setBitAtPos(result, 7 - i, (value >> i) & 1);
    }
    return result;
}

unsigned char setBits(unsigned char value, int pos, int n, unsigned char y) {
    // Passo 1: Isolamento degli n bit più a destra di y
    unsigned char rightmostBits = y & ((1 << n) - 1);

    // Passo 2: Spostamento di questi bit nella posizione corretta
    unsigned char shiftedBits = rightmostBits << (pos - n + 1);

    // Passo 3: Creazione della maschera
    unsigned char mask = ~(((1 << n) - 1) << (pos - n + 1));

    // Passo 4: Applicazione della maschera
    value &= mask;

    // Passo 5: Combinazione del valore modificato con i bit spostati
    return value | shiftedBits;
}


int main() {
    
    // Test funzione pow
    int exp = 2;
    printf("Results are: %d\n", powof2plus1(exp));

    // Stampa binaria di un numero come parametro
    unsigned char value1 = 150;
    printBinary(value1); // Stampa il valore binario di 150

    // Test funzione reverseBit
    unsigned char value2 = 0xEA; // 11101010 in binario
    unsigned char reversed = reverseBits(value2);

    // Stampa il risultato in formato binario, utilizzando una funzione come printBinary definita precedentemente
    printBinary(reversed);

    // Test funzione di spostamentoBit
    unsigned char value = 0xAA; // 10101010 in binario
    unsigned char y = 0xAF;    // 10101111 in binario
    unsigned char result = setBits(value, 5, 3, y);
    // Stampa il risultato in formato binario, utilizzando una funzione come printBinary definita precedentemente
    printBinary(result);

    // Stampa il risultato della funzione di test di spostamento di bit
}