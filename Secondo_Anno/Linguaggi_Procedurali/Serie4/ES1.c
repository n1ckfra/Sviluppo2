#include <stdio.h>

void minMax(int vect[], int len, int *min, int *max){

    *max = *min = vect[0];

    // Ciclare array e aggiornare i valori di max e di min
    for (int i = 0; i < len; i++)
    {
        if (vect[i] > *max)
        {
            *max = vect[i];
        }
        if (vect[i] < *min)
        {
            *min = vect[i];
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    int vect[] = {1,3,4,-5,78,-67};
    int min, max;

    minMax(vect, 6, &min, &max);

    printf("Max is %d and min is %d", max, min);
}
