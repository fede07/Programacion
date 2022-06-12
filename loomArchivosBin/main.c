#include <stdio.h>
#include <stdlib.h>
#include "funcArchBinLoom.h"

///ordenados alfabéticamente por <apellido> / <nombre> /<dni>

int main()
{
    crearArchivos();
    FILE *archAlum, *archEmpl, *archUpdate;

    archEmpl=fopen("empleados.bin", "rb");
    if(!archEmpl)
    {
        printf("NO SE PUDO CREAR EMPLEADOS.BIN");
        exit(100);
    }

    archAlum=fopen("estudiantes.bin","rb");

    if(!archAlum)
    {
        printf("NO SE PUDO CREAR ESTUDIANTES.BIN");
        fclose(archEmpl);
        exit(101);
    }

    archUpdate=fopen("empleadosAct.bin", "wb");

    if(!archUpdate)
    {
        printf("NO SE PUDO CREAR EMPLEADOSACT.BIN");
        fclose(archEmpl);
        fclose(archAlum);
    }

    actualizarArch(archAlum, archEmpl, archUpdate);

    fclose(archEmpl);
    fclose(archAlum);
    return 0;
}
