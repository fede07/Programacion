#include <stdio.h>
#include <stdlib.h>
#include "parcial.h"



int main()
{


//    char cadena[5]="abs";
//    char res[5]="hola";
    int cantidad;
//
//    memmove2(res,cadena,2);

    ///faltan los if para ver si las funciones salieron bien
    fusionArchivos ();

    elimDupl();


    ///NO VALIDO NUMEROS INGRESADOS
    printf("Ingresar cantidad de productos a eliminar (desde el final)");
    scanf("%d",&cantidad);
    eliminarNult(cantidad);

    actualizar();

    return 0;
}






































