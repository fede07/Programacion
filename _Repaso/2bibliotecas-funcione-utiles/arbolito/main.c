#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "alumnos.h"
#include "utiles.h"

int compararIndice (const void * a, const void * b)
{
    return ((tidx*)a)->key - ((tidx*)b)->key;
}

void mostrarIndice (const void * a)
{
    printf("%d/%d\n",((tidx*)a)->key,((tidx*)a)->position);
}

void guardarRegIndice (const void * dato, void * contexto)
{
    fwrite(dato,sizeof(tidx),1,(FILE*)contexto);
}

/**







EL ARCHIVO TEMPORAL ESTA CREADO EN ARBOL.C










**/





int main()
{
    char op;
    int size;
    t_arbol arbol;


    const char opciones [][TAM_MENU] = {"coimvabrxyq",
                    "Crear archivo y cargar indice",///carga el arbol desbalanceado
                    "Cargar indice desde el archivo de datos",///lo mismo que la de arriba solo que el archivo ya esta creado desde antes

                    "Cargar indice desde archivo indice",///
                    "Mostrar Arbol",
                    "Ver caracteristicas",///ver si es AVL/balanceado/comp
                    "Alta",///insertar
                    "Baja",///modificar el campo deleted
                    "Regenerar como arbol balanceado",///balancea el arbol
                    "Buscar 1000 en archivo",
                    "Buscar 1000 en indice",
                    "Salir"
                                    };

    crearArbol(&arbol);


//                createBigFile(BIGFILENAME,15);
//                cargarIndice(BIGFILENAME,&arbol,compararIndice);


    do{
        switch(op){
            case 'C':///crear archivo y cargar indice en el arbol (queda desordenado)
                printf("Ingrese tamano deseado: ");
                scanf("%d",&size);
                createBigFile(BIGFILENAME,size);
                cargarIndice(BIGFILENAME,&arbol,compararIndice);
                pausa("");
                break;

            case 'O':///solo cargar indice en el arbol desde un archivo ya existente
                cargarIndice(BIGFILENAME,&arbol,compararIndice);
                pausa("");
                break;

            case 'I':///escribir los datos del arbol balanceado en un nuevo archivo
                pausa("");
                break;

            case 'M':///mostrar
                rotar90g_i(&arbol,mostrarIndice);
                pausa("");
                break;

            case 'V':///balanceado, AVL, etc
                pausa("");
                break;

            case 'R':///levanta los datos del archivo y arma un arbol balanceado
                guardarOrdenadoGen(&arbol,guardarRegIndice);
                talar(&arbol);
                cargar_Idx_ArchivoInord(&arbol,compararIndice);
                pausa("");
                break;

            case 'B':///balancear
                pausa("");
                break;

            case 'X':
                pausa("");
                break;


            case 'Y':
                pausa("");
                break;


            default:
                fflush(stdin);
                break;
        }
        op = pedir_opcion(opciones, "----Opciones----", "->");


    }while(op!='Q');

    return 0;
}
