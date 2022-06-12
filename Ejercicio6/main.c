#include <stdio.h>
#include <stdlib.h>

///Ejercicio 6

double factorial (unsigned);
double seno (float, float);

int main()
{
    float numero, tol;
    double result;
    printf("\nIngrese numero:\t");
    scanf("%f", &numero);
    printf("\nTolerancia:\t");
    scanf("%f", &tol);
    result=seno(numero,tol);
    printf("\nSeno(%.f)=\t%.10lf\n\n", numero, result);
    return 1;
}

double factorial (unsigned numero)
{
    double aux = 1;
    if(numero > 0)
    {
        while(numero>1)
        {
            aux *= (double)numero;
            numero--;
        }
        return aux;
    }
    return aux;
}

double seno (float numero, float tol)
{
    int b=0, aux=1;
    double fact, result, termino, potencia;
    result = (double)numero;
    potencia = (double)numero;
    do
    {

        potencia*=numero*numero;
        aux+=2;
        fact=factorial(aux);
        termino = potencia/fact;
        if(b==0)
        {
            result-=termino;
            b=1;
        }
        else
        {
            result+=termino;
            b=0;
        }
    }
    while(termino>(double)tol);
    return result;
}

//int main()
//{
//    int numero;
//    double fact;
//    printf("\nIngrese numero: ");
//    scanf("%d", &numero);
//    fact = factorial(numero);
//    printf("\n%d! = %.f", numero, fact);
//    return 0;
//}
