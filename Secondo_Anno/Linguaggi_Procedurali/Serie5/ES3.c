#include <stdio.h>

// Definizione della struttura per rappresentare un registro a 8 bit
typedef union Register {
    struct {
        unsigned bit0 : 1;
        unsigned bit1 : 1;
        unsigned bit2 : 1;
        unsigned bit3 : 1;
        unsigned bit4 : 1;
        unsigned bit5 : 1;
        unsigned bit6 : 1;
        unsigned bit7 : 1;
    };
    unsigned char val;
} Register;

int main(void) {
    Register r;
    r.val = 55; // Imposta il valore del registro a 55
    
    // Stampa il valore intero del byte e i valori dei singoli bit
    printf("Valore byte completo %d\n", r.val);
    printf("Valori singoli bit:\n");
    printf("b7: %d, b6: %d, b5: %d, b4: %d, b3: %d, b2: %d, b1: %d, b0: %d\n",
           r.bit7, r.bit6, r.bit5, r.bit4, r.bit3, r.bit2, r.bit1, r.bit0);
    return 0;
}
