#include <stdio.h>
#include <stdlib.h>

unsigned sumaNNatPar(unsigned);

int main()
{
    unsigned num;
    printf("\nIngrese un numero natural: ");
    scanf("%d", &num);
    printf("\nSuma de los primeros %d numeros naturales pares: %d", num, sumaNNatPar(num));
    return 0;
}

unsigned sumaNNatPar(unsigned cant)
{
    int i=0;
    unsigned result = 0, aux = 0;
    while(i<cant)
    {
        if(aux%2==0)
        {
            result+=aux;
            i++;
        }
        aux++;
    }
    return result;
}
