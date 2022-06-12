#include <stdio.h>
#include <stdlib.h>

///Ejercicio 5

int fibonacci (int);

int main()
{
    int num, esFibonnaci;
    do
    {
        printf("\nIngrese numero, 0 para terminar: ");
        fflush(stdin);
        scanf("%d", &num);
        esFibonnaci=fibonacci(num);
        if(esFibonnaci)
            printf("\n\nEs parte de la secuencia");
        else
            printf("\n\nNo es parte de la secuencia");
    }
    while(num != 0);
    return 0;
}

int fibonacci (int num)
{
    int serie1 = 1, serie2 = 1, aux;
    if(serie1 == num)
        return 1;
    do
    {
        aux = serie1;
        serie1 = serie1+serie2;
        serie2 =aux;
        if(serie1 == num)
            return 1;
    }
    while(serie1 <= num);
    return 0;
}
