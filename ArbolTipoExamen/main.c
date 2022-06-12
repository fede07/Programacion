#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "alumnos.h"
#include "utiles.h"

int compararInt(const void* n1, const void* n2);

int main()
{
    char op;
    int tam;
    const char opciones [][TAM_MENU] = {"coimvabrxyq",
                                    "Crear archivo y cargar indice",
                                    "Cargar indice desde el archivo de datos",
                                    "Cargar indice desde archivo indice",
                                    "Mostrar Arbol",
                                    "Ver caracteristicas",
                                    "Alta",
                                    "Baja",
                                    "Regenerar como arbol balanceado",
                                    "Buscar 1000 en archivo",
                                    "Buscar 1000 en indice",
                                    "Salir"};

    t_arbol arbolAlum;

    crearArbol(&arbolAlum);

    do{
        switch(op){
            case 'C': ///Crear archivo y cargar indice

                printf("\nIngrese Tamaño: ");
                scanf("%d", &tam);
                createBigFile(BIGFILENAME, tam);
                pausa("");
                break;

            case 'O':///Cargar indice desde el archivo de datos
                pausa("");
                break;

            case 'I':
                pausa("");
                break;

            case 'M':
                rotar90Rec(&arbolAlum, )
                pausa("");
                break;

            case 'V':
                pausa("");
                break;

            case 'R':
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

int compararIndice(const void* n1, const void* n2)
{
    return (int)(((tdat*)(n1))->key) - (int)(((tdat*)(n2))->key);
}

void mostrarDat(const void *dato)
{
    printf("%d/%d", ((tidx*)dato)->key, ((tidx*)dato)->
}
