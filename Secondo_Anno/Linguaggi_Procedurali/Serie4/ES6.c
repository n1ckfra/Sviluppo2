#include <stdio.h>
#include <stdlib.h>

// Definizione della funzione quadrato()
double quadrato(double x) {
    return x * x;
}

// Definizione della funzione integrale() con il metodo del rettangolo
double integraleRettangolo(double min, double max, double step, double (*f)(double)) {
    double area = 0.0;
    double x;

    for (x = min; x < max; x += step) {
        area += f(x + step / 2) * step; // Altezza al centro della base
    }

    return area;
}

double integraleTrapezio(double min, double max, double step, double (*f)(double)) {
    double area = 0.0;
    double x;

    for (x = min; x < max; x += step) {
        area += (f(x) + f(x + step)) * step / 2; // Metodo del trapezio
    }

    return area;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <min> <max>\n", argv[0]);
        return 1;
    }

    double min = atof(argv[1]);
    double max = atof(argv[2]);

    // Mostra una tabella con la differenza di risultato in funzione del valore del passo
    printf("Passo | Integrale\n");
    printf("------|-----------\n");
    for (double step = 1.0; step >= 0.01; step /= 10) {
        printf("%.2f  | %.4f\n", step, integrale(min, max, step, quadrato));
    }

    // Dopo aver capito questa cosa posso (Fare il cazzo che mi pare diocan) (Metter questo la) () (Metter questo qua)

    // Test con un'altra funzione, ad esempio una funzione lineare
    double lineare(double x) {
        return 2 * x + 1;
    }
    printf("\nIntegrale funzione lineare con passo 0.01: %.4f\n", integrale(min, max, 0.01, lineare));

    return 0;
}