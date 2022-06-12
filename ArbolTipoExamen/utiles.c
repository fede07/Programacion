#include "utiles.h"
#include "../Arbol/arbol.h"
#include <stdio.h>

int cargarIndice(t_arbol *arbol, const char* nombre, int(*comparar)(const void*, const void*))
{
    int registro = 0;
    tdat alumno;
    tidx indice;
    FILE* arch;

    arch = fopen(nombre, "rb");

    if(!arch)
    {
        return 0;
    }

    fread(&alumno, sizeof(tdat), 1, arch);
    while(!feof(arch))
    {
        indice.key = alumno.key;
        indice.position = registro;
        insertarArbolRec(arbol, &indice, sizeof(tidx), comparar);
        registro++;
        fread(&alumno, sizeof(tdat), 1, arch);
    }

    return 1;

}
