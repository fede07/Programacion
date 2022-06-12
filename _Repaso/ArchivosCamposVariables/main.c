#include <stdio.h>
#include <stdlib.h>
#include "lotes.h"

int main()
{
    FILE* pf, *ps;
    t_alumno alumno;
    char cadena [LARGO];
    if(crearLoteVar()==0)
    {
        printf("\n\nERROR DE ESCRITURA");
        return 1;
    }

    if(abrirArchivo(&pf, NOMBREARCHLOTE,"rt")==0)
    {
        printf("\n\nERROR DE LECTURA");
        return 2;
    }

    if(abrirArchivo(&ps, "loteDeEsc.txt","wt")==0)
    {
        printf("\n\nERROR DE LECTURA");
        fclose(pf);
        return 2;
    }

    while(fgets(cadena, sizeof(cadena), pf))
    {
        //fprintf(stdout, "%s",cadena);
        if(parseo(cadena,&alumno))
        {
            printf("%s|%d|%c|%f\n", alumno.nyap, alumno.dni, alumno.dpto, alumno.promedio);
            fprintf(ps,"%s|%d|%c|%f\n", alumno.nyap, alumno.dni, alumno.dpto, alumno.promedio);
        }
        else
        {
            printf("\n\nError de Parseo");
            fprintf(ps,"ERROR DE PARSEO\n");
        }

    }
    fclose(pf);
    return 0;
}
