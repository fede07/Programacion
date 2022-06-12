#include <stdio.h>
#include <stdlib.h>

unsigned sumaNNat(unsigned);

int main()
{
    unsigned num;
    do
    {
        printf("\nIngrese un numero natural, 0 para terminar: ");
        scanf("%d", &num);
        if(num !=0)
            printf("\nSuma de los primeros %d numeros naturales: %d\n", num, sumaNNat(num));
    }
    while(num != 0);
    return 0;
}

unsigned sumaNNat(unsigned cant)
{
    int i;
    unsigned result = 0;
    for(i=0; (unsigned)i<cant; i++)
    {
        result+=(unsigned)i;
    }
    return result;
}
