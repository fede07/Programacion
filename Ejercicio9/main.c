#include <stdio.h>
#include <stdlib.h>
#define ERROR -1
#define COCIENTE 1
#define RESTO 2

unsigned cocienteResto(unsigned, unsigned, int);

int main()
{
    unsigned numero1, numero2;
    printf("\nIngrese Primer Operando: ");
    scanf("%d", &numero1);
    do
    {
        printf("\nIngrese segundo Operando distinto de 0: ");
        scanf("%d", &numero2);
    }while(numero2 == 0);
    printf("\nResultado: %d\tResto: %d\n", cocienteResto(numero1, numero2, COCIENTE), cocienteResto(numero1, numero2, RESTO));
    return 0;
}

unsigned cocienteResto(unsigned numero1, unsigned numero2, int funcion)
{
    int resultado = 0;
    if(numero2 == 0)
        return ERROR;
    if(funcion != COCIENTE && funcion != RESTO)
        return ERROR;
    while(numero1 >= numero2)
    {
        numero1-=numero2;
        resultado++;
    }
    if(funcion == COCIENTE)
        return resultado;
    else
        return numero1;
}
