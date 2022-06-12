#include <stdio.h>
#include <stdlib.h>

unsigned sumaNNatParMenor(unsigned);

int main()
{
    unsigned num;
    do
    {
        printf("\nIngrese un numero natural, 0 para terminar: ");
        scanf("%d", &num);
        if(num !=0)
            printf("\nSuma de los primeros %d numeros naturales: %d\n", num, sumaNNatParMenor(num));
    }
    while(num != 0);
    return 0;
}

unsigned sumaNNatParMenor(unsigned cant)
{
    int i;
    unsigned result = 0;
    for(i=0; (unsigned)i<cant; i++)
    {
        if(i%2==0)
        {
            result+=(unsigned)i;
        }
    }
    return result;
}
