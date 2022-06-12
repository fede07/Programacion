#include <stdio.h>
#include <stdlib.h>
#define PRIMO 1
#define NOPRIMO 0

int esPrimo(unsigned);

int main()
{
    unsigned num;
    do
    {
        printf("\nIngrese un numero natural, 0 para terminar: ");
        scanf("%d", &num);
        if(num!=0)
        {
            if(esPrimo(num))
                printf("\nEl numero %d es primo\n", num);
            else
                printf("\nEl numero %d no es primo\n", num);
        }
    }
    while(num != 0);
    return 0;
}

int esPrimo(unsigned numero)
{
    int b = PRIMO, i=2;
    if(numero == 1)
        return NOPRIMO;
    while(b==PRIMO && i<numero)
    {
        if(numero%i==0)
            b = NOPRIMO;
        i++;
    }
    return b;
}
