#include <stdio.h>
#include <stdlib.h>
#include "camposVariables.h"


int main()
{
    FILE *pfLectura, *pfEscritura;
    t_animo animo;
    char cadena[LARGO];


    if(crearLote()==0)
    {
        printf("Error al crear lote de pruebas");
        return 1;
    }

    if(abrirArchivo(&pfLectura,"loteDePruebaVar.txt","rt")==0)
    {
        printf("Error al leer archivo de lotes de prueba");
        return 2;
    }

    if(abrirArchivo(&pfEscritura,"loteSinPipes.txt","wt")==0)
    {
        printf("Error al leer archivo de lotes de prueba sin pipes");
        fclose(pfLectura);
        return 3;
    }


    while(fgets(cadena,sizeof(cadena),pfLectura))
    {
        printf("<%s",cadena);
        if(parseo(cadena,&animo))
        {
            printf("Nombre y apellido: %s, DNI: %d, Estado: %c, Puntuacion: %f\n",animo.nyap,animo.dni,animo.estado,animo.puntuacion);
            fprintf(pfEscritura,"%s|%d|%c|%f\n",animo.nyap,animo.dni,animo.estado,animo.puntuacion);
        }
        else
        {
            printf("Error al leer los campos\n");
            fprintf(pfEscritura,"ERROR\n");
        }
        printf("\n");

//        if(sscanf(cadena,"%[^|]s|%d|%c|%f",animo.nyap,&animo.dni,&animo.estado,&animo.puntuacion))
//        {
//            printf("Nombre y apellido: %s, DNI: %d, Estado: %c, Puntuacion: %f\n",animo.nyap,animo.dni,animo.estado,animo.puntuacion);
//            fprintf(pfEscritura,"%s|%d|%c|%f\n",animo.nyap,animo.dni,animo.estado,animo.puntuacion);
//        }
//        else
//        {
//            printf("Error al leer los campos\n");
//            fprintf(pfEscritura,"ERROR\n");
//        }
//        printf("\n");

    }

    fclose(pfLectura);
    fclose(pfEscritura);

    return 0;
}
