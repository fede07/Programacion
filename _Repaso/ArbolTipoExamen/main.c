#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "alumnos.h"
#include "utiles.h"

int compararIndice (const void * a, const void * b);

void mostrarIndice (const void * a);

void guardarRegIndice (const void * dato, void * contexto);

int main()
{
    char op;
    int tam;
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

    t_arbol arbol;

    crearArbol(&arbol);

    createBigFile(BIGFILENAME,15);
    cargarIndice(BIGFILENAME,&arbol,compararIndice);

    do{
        switch(op){
            case 'C': ///Crear archivo y cargar indice

                printf("\nIngrese Tamaño: ");
                scanf("%d", &tam);
                createBigFile(BIGFILENAME, tam);
                cargarIndice(BIGFILENAME,&arbol,compararIndice);
                pausa("");
                break;

            case 'O':///Cargar indice desde el archivo de datos
                cargarIndice(BIGFILENAME,&arbol,compararIndice);
                pausa("");
                break;

            case 'I':
                pausa("");
                break;

            case 'M':
                rotar90g_i(&arbol, mostrarIndice);
                pausa("");
                break;

            case 'V':
                pausa("");
                break;

            case 'R':
                guardarOrdenadoGen(&arbol,guardarRegIndice);
                talar(&arbol);
                cargar_Idx_ArchivoInord(&arbol,compararIndice);
                pausa("");
                break;

            case 'B':
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
int compararIndice (const void * a, const void * b)
{
    return ((tidx*)a)->key - ((tidx*)b)->key;
}

void mostrarIndice (const void * a)
{
    printf("%u/%lu\n",((tidx*)a)->key,(unsigned long)((tidx*)a)->position);
}

void guardarRegIndice (const void * dato, void * contexto)
{
    fwrite(dato,sizeof(tidx),1,(FILE*)contexto);
}
