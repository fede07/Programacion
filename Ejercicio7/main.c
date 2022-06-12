#include <stdio.h>
#include <stdlib.h>
#define CERO 0
#define PERFECTO 1
#define ABUNDANTE 2
#define DEFICIENTE 3

int detPerfection (unsigned);

int main()
{
    unsigned numero;
    printf("\nIngrese un numero entero positivo, 0 para terminar: ");
    scanf("%d", &numero);
    while(numero > 0)
    {
        printf("\nEl numero %d es ", numero);
        switch(detPerfection(numero))
        {
        case 0:
            puts("0");
            break;
        case 1:
            puts("perfecto");
            break;
        case 2:
            puts("abundante");
            break;
        case 3:
            puts("deficiente");
            break;
        }
        printf("\nIngrese un numero entero positivo, 0 para terminar: ");
        scanf("%d", &numero);
    };
    return 0;
}

int detPerfection (unsigned numero)
{
    unsigned aux = 0, i=1;
    if(numero == 0)
        return CERO;
    while(numero > i )
    {
        if(numero%i == 0)
        {
            aux+=i;
        }
        i++;
    }
    if(aux == numero)
        return PERFECTO;
    else
    {
        if(aux > numero)
            return 2;
        else
            return 3;
    }
}
