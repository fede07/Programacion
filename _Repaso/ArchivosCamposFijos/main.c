#include <stdio.h>
#include <stdlib.h>
#include "camposfijos.h"

#define TAM 100

int main()
{

    FILE * pfLect, *pfEscr;
    char cadena[81];
    t_alumno alumno;

    /*if(!crearLote())
    {
        printf("ERROR lote");
        return 100;
    }*/

    if(!abrirArh(&pfLect,"alumnos.txt","rt"))
    {
        printf("ERROR pfLect");
        return 110;
    }

    if(!abrirArh(&pfEscr,"alumnos2.txt","wt"))
    {
        printf("ERROR pfEscr");
        fclose(pfLect);
        return 120;
    }


            ///tiene que leer la cantidad de caracteres que vienen en el archivo
            ///esto lo dicen en el ejercicio, +2 por el \n\0
    while(fgets(cadena,81,pfLect))
    {
        ///aca se ve que la cadena corta despues de la direccion por el \000
            dezglozamiento(cadena,&alumno);
            printf("%d|%s|%s|%d\n",alumno.dni,alumno.nyap,alumno.direccion,alumno.altura);
            fprintf(pfEscr,"%d|%s|%s|%d\n",alumno.dni,alumno.nyap,alumno.direccion,alumno.altura);
    }



//    while(fgets(cadena,81,pfLect))
//    {
//            sscanf(cadena,"%8d%33c[^!]%33c%5d\n",&alumno.dni,alumno.nyap,alumno.direccion,&alumno.altura);
//            printf("%d|%s|%s|%d\n",alumno.dni,alumno.nyap,alumno.direccion,alumno.altura);
//            fprintf(pfEscr,"%d|%s|%s|%d\n",alumno.dni,alumno.nyap,alumno.direccion,alumno.altura);
//    }


//    while(fgets(cadena,81,pfLect))
//    {
//            sscanf(cadena,"%8d%[A-Z,a-z,' '][^' ']33s%33s%5d\n",&alumno.dni,alumno.nyap,alumno.direccion,&alumno.altura);
//            printf("%d|%s|%s|%d\n",alumno.dni,alumno.nyap,alumno.direccion,alumno.altura);
//            fprintf(pfEscr,"%d|%s|%s|%d\n",alumno.dni,alumno.nyap,alumno.direccion,alumno.altura);
//    }

                    ///%8d%33s%33s%5d
//    while(fscanf(pfLect,"%d%33c%33c%d\n",&alumno.dni,alumno.nyap,alumno.direccion,&alumno.altura))
//    {
//            printf("%d|%s|%s|%d\n",alumno.dni,alumno.nyap,alumno.direccion,alumno.altura);
//                exit(1);
//            fprintf(pfEscr,"%d|%s|%s|%d\n",alumno.dni,alumno.nyap,alumno.direccion,alumno.altura);
//    }


//    while(fscanf(pfLect,"%d%33c%33c%d\n",&alumno.dni,alumno.nyap,alumno.direccion,&alumno.altura))
//    {
//            printf("%d|%s|%s|%d\n",alumno.dni,alumno.nyap,alumno.direccion,alumno.altura);
//                exit(1);
//            fprintf(pfEscr,"%d|%s|%s|%d\n",alumno.dni,alumno.nyap,alumno.direccion,alumno.altura);
//    }

    fclose(pfEscr);
    fclose(pfLect);

    return 0;
}

