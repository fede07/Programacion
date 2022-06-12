#include <stdio.h>
#include <stdlib.h>

double factorial (unsigned);

int main()
{
    unsigned x;
    double result;
    puts ("Ingrese un numero X: ");
    fflush(stdin);
    scanf("%d",&x);
    result = factorial(x);
    printf("\n%d! = %.0f\n\n",x,result);

    return 0;
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
