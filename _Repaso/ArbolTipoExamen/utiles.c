#include "utiles.h"
#include "../Arbol/arbol.h"
#include <stdio.h>

///carga un arbol con la KEY y la POSITION dentro del archivo
///queda el arbol escrito tal y como venia del archivo, probablemente desordenado
int cargarIndice(const char * nombre, t_arbol * arbol, int (*compar)(const void *, const void *))
{
    int regis = 0;///cantidad de registros
    tdat alumno;
    tidx indice;
    FILE * fp=fopen(nombre,"rb");

    if(!fp)
    {
        return 0;
    }

    fread(&alumno,sizeof(tdat),1,fp);

    while(!feof(fp))
    {
        indice.key = alumno.key;
        indice.position = regis;
        insertarArbol(arbol,&indice,sizeof(tidx),compar);



        ///validar si se pudo cargar o no



        fread(&alumno,sizeof(tdat),1,fp);
        regis++;
    }

    fclose(fp);

    return 1;

}

///lee el archivo temporal y lo reescribe en el arbol para poder balancearlo
///la llama el main
///despues de esta funcion queda SOLO EL ARBOL, el archivo temporal se borra
int cargar_Idx_ArchivoInord (t_arbol * arbol,int (*comparar)(const void *, const void *))
{
    int tam;
    FILE * fp = fopen("temp.idx","rb");
    if(!fp)
        return 0;

    fseek(fp,0L,SEEK_END);
    tam = ftell(fp)/sizeof(tidx);
    tam = cargar_Idx_ArchivoInord_i(arbol,0,tam-1,fp,comparar);

    fclose(fp);
    unlink("temp.idx");

    return tam;
}

///a partir del archivo que fue escrito como inorden se rearma el arbol para poder balancearlo
///complementa a cargar_Idx_ArchivoInord
                        ///_interna
int cargar_Idx_ArchivoInord_i (t_arbol * arbol, int ini, int fin, FILE * archivo, int (*comparar)(const void *, const void *))
{
    int pm = ini+(fin-ini)/2;
    tidx index;

    if(ini>fin)///ya se guardaron todos los datos de ese lado
        return 1;

    fseek(archivo,pm*sizeof(tidx),SEEK_SET);
    fread(&index,sizeof(tidx),1,archivo);
    if(!insertarArbol(arbol,&index,sizeof(tidx),comparar))
        return 0;

    return cargar_Idx_ArchivoInord_i(&(*arbol)->izq,ini,pm-1,archivo,comparar) && cargar_Idx_ArchivoInord_i(&(*arbol)->der,pm+1,fin,archivo,comparar);
}
















