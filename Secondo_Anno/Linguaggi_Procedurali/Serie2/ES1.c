#include <stdio.h>
#include <math.h>

int controlloInput(){
    int input;

    do
    {
        printf("Inserire un numero intero di 3 cifre: ");
        scanf("%d", &input);
    } while (input < 100 || input > 999);
    
    return input;
}

int sommaCubi(int input){
    int unita, decine, centinaia;
    unita = decine = centinaia = 0;

    centinaia = input / 100;
    decine = (input % 100) / 10;
    unita = input % 10;

    if (pow(centinaia, 3) + pow(decine, 3) + pow(unita, 3) == input)
    {
        return 0;
    } else {
    }
    return 1;
}

void generaAutomaticamenteNumeri(){
    for (int i = 100; i < 1000; i++)
    {
        if (sommaCubi(i) == 0)
        {
            printf("Il numero %d è valido\n", i);
        }  
    }
    
}

int main(int argc, char const *argv[])
{
    generaAutomaticamenteNumeri();
}
