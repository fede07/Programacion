#include <stdio.h>
#include <stdlib.h>

///Ejercicio 3

double calculoE (int, double);

int main()
{
    int x;
    double result, tol;
    puts ("Ingrese un numero X para calcular f(x) = e^x: ");
    fflush(stdin);
    scanf("%d",&x);
    puts("\nIngrese una tolerancia: ");
    fflush(stdin);
    scanf("%lf", &tol);
    result = calculoE (x,tol);
    printf("\n e^%d = %.20f\n",x,result);
    return 0;
}

double calculoE (int x, double tol)
{
    int i=1;
    double result = 1, poten = 1, denom = 1, termino;
    do
    {
        poten = poten*(double)x;
        denom = denom*i++;
        termino = poten/denom;
        result += termino;

    }
    while(termino>tol);
    return result;
}
