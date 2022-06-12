#include <stdio.h>
#include <stdlib.h>

unsigned productosSumaSus(unsigned, unsigned);

int main()
{
    unsigned numero1, numero2;
    printf("\nIngrese primer operando: ");
    scanf("%d", &numero1);
    printf("\nIngrese segundo operando: ");
    scanf("%d", &numero2);
    printf("\nResultado: %d", productosSumaSus(numero1, numero2));
    return 0;
}

unsigned productosSumaSus(unsigned num1, unsigned num2)
{
    int i;
    unsigned aux = 0;
    if(!num1 || !num2)
        return 0;
    for(i=0;(unsigned)i<num2;i++)
    {
        aux+=num1;
    }
    return aux;
}
