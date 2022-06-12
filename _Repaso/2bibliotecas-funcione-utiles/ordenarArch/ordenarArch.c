#include <stdio.h>
#include <stdlib.h>
#include "ordenarArch.h"

int cmpStruct (const void * n, const void *n2)
{
    return ( ((t_orden*)(n))->id - ((t_orden*)(n2))->id );
}

int ordenar ()
{
    FILE * arch;
    FILE * ordenado;

    int contReg=0;
    int i;

    t_struct s;
    t_orden orden[TAM];

    arch = fopen("binario.dat","rb");
    ordenado = fopen("texto.txt","wt");

    fread(&s,sizeof(t_struct),1,arch);///leo primer registro

    while(!feof(arch))
    {
        ///guardo solo el ID porque solo quiero ordenar por eso
        orden[contReg].id = s.id;///guardo el ID leido del archivo
        orden[contReg].posArch = contReg;///guardo su posicion dentro del archivo
        contReg++;///aumento el contador para poder guardar la siguiente posicion
        fread(&s,sizeof(t_struct),1,arch);///leo el siguiente registro
    }

    fseek(arch,0L,SEEK_CUR);///vuelvo al inicio de archivo bin

    qsort(orden,TAM,sizeof(t_orden),cmpStruct);///el vector con los registros/ID esta ordenado

    ///vector de registros ya odenado, falta reescribir el archivo en orden

    for(i=0;i<contReg;i++)
    {           ///posiciono el puntero para leer lo que necesito
        fseek(arch,sizeof(t_struct)*orden[i].posArch,SEEK_SET);
        fread(&s,sizeof(t_struct),1,arch);///leo el registro que corresponda
        fprintf(ordenado,"%d %s %.2f\n",s.id,s.cadena,s.algo);
    }

    return 1;
}













