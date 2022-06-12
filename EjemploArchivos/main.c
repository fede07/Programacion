#include <stdio.h>
#include <stdlib.h>
#include "../macroReemplazos/macros.h"
#include "archivos.h"
#include "lotesDePrueba.h"

#define ARCHIVOTEXTO "archivoTest.txt"
#define TAM 20

typedef struct{
    char* inicioPal;
    char* finalPal;
}Palabra;

int main()
{
    FILE* pf /*= fopen(ARCHIVOTEXTO, "wt")*/;
    char cadena[TAM];

//    if(!(abrirArchivo(&pf, ARCHIVOTEXTO, "wt")))
//    {
//        printf("No se pudo abrir el archivo para escritura");
//        exit(100);
//    }
//    if(!crearLoteDePrueba(&pf))
//    {
//        printf("No se pudo crear lote de prueba");
//        exit(100);
//    }

    if(!(abrirArchivo(&pf, ARCHIVOTEXTO, "rt")))
    {
        printf("No se pudo abrir el archivo para lectura");
        exit(100);
    }

    while(fgets(cadena, TAM, pf))
    {
        printf("%s", cadena);
    }

    fclose(pf);
    return 0;
}
