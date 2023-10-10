#include <stdio.h>

int fattorialeRicorsivo(int numero){
    if (numero == 1)
    {
        return 1;
    }
    return numero * fattorialeRicorsivo(numero - 1);
}

int fattorialeIterativo(int numero){
    int ritorno = 1;
    for (int i = numero; i > 0; i--)
    {
        ritorno = ritorno * i;
    }
    return ritorno;
}

int main(int argc, char const *argv[])
{
    //diocane de dio
}
