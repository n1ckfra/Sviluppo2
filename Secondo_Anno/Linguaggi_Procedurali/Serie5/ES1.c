#include <stdio.h>

// Definizione della struttura Punto
typedef struct Punto {
    float x;
    float y;
} Punto;

// Definizione della struttura Vettore
typedef struct Vettore {
    float deltaX;
    float deltaY;
} Vettore;

// Funzione che restituisce un nuovo punto sommando il punto di partenza con il vettore
Punto sommaPuntoVettore(Punto p, Vettore v) {
    Punto nuovoPunto = {p.x + v.deltaX, p.y + v.deltaY};
    return nuovoPunto;
}

// Funzione che modifica il punto di partenza sommando il vettore (senza restituire un nuovo punto)
void traslaPunto(Punto *p, Vettore v) {
    p->x += v.deltaX;
    p->y += v.deltaY;
}

int main() {
    // Creazione di un punto di partenza e di un vettore di spostamento
    Punto partenza = {0.0, 0.0};
    Vettore spostamento = {3.0, 4.0};
    
    // Utilizzo della funzione sommaPuntoVettore
    Punto arrivo = sommaPuntoVettore(partenza, spostamento);
    printf("Nuovo punto: (%.2f, %.2f)\n", arrivo.x, arrivo.y);
    
    // Utilizzo della funzione traslaPunto
    traslaPunto(&partenza, spostamento);
    printf("Punto traslato: (%.2f, %.2f)\n", partenza.x, partenza.y);

    return 0;
}
