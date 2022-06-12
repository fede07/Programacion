#include <stdio.h>
#include <stdlib.h>
#include "fechas.h"

#define TAM 7

int main()
{
    t_fecha fecha[TAM]= {{9,6,2021},
                         {1,2,1900},
                         {29,2,2020},
                         {29,2,2021},
                         {32,5,2000},
                         {31,15,2000},
                         {31,11,1500},
                         };

    int i;

    for(i=0; i<TAM; i++)
    {
        printf("%d\n",validarFecha(fecha[i]));
    }
}
