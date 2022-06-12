#include <stdio.h>
#include <stdlib.h>

///Ejercicio 4

double raiz (int, double);

int main()
{
    int x;
    double result, tol;
    puts ("Ingrese un numero X: ");
    fflush(stdin);
    scanf("%d",&x);
    puts("\nIngrese una tolerancia: ");
    fflush(stdin);
    scanf("%lf", &tol);
    result = raiz (x,tol);
    printf("\n Raiz de %d = %.10f",x,result);

    return 0;
}

double raiz (int x, double tol)
{
    int i = 0;
    double terminoAnt = 1, terminoSig = 1, aux;
    do
    {
        terminoSig = (x/terminoAnt);
        terminoSig = terminoAnt + terminoSig;
        terminoSig = terminoSig/2;
        aux=terminoAnt-terminoSig;
        terminoAnt=terminoSig;
        if(i == 0)
        {
            aux=2;
            i=1;
        }
    }while((aux)>tol);
    return terminoSig;
}
