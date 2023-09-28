#include <stdio.h>

int factorial(int num){
    if (num == 1)
    {
        return 1;
    }
    return num * factorial(num - 1);
    
}

int main(int argc, char const *argv[])
{
    
    printf("%d", factorial(6)/factorial(3));

    return 0;
}
