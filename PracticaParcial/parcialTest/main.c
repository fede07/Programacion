#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"

///EJERCICIO 1
int main()
{
    char destino[] = "     ";
    char origen[]  = "PELO";

    printf("Before memmove dest = %s, src = %s\n", destino, origen);
    memcpy(origen+1, origen,2);
    printf("After memmove dest = %s, src = %s\n", destino, origen);

    return(0);
}


///EJERCICIO 2
//int main()
//{
//    if(!mergeArchs())
//    {
//        return 1;
//    }
//    printf("\nEJERCICIO 3\n");
//    if(!eliminarDupes())
//    {
//        return 2;
//    }
//
//    return 0;
//}
