#include <stdio.h>
#include <stdlib.h>
#include "ListaDoblementeEnlazada.h"

#define TAM 30
#define CANT 5

typedef struct{
    int codigo;
    char producto[TAM];
    int cantidad;
}t_producto;

//int comparar(const void*, const void*);
//void accion(const void*);
//void acumular(void* destino, const void* info);

//int main()
//{
//    int vec[10] = {1,3,5,15,36,78,10,14,30,100};
//    int i;
//    t_lista lista;
//    crearLista(&lista);
//    for(i = 0; i < 10; i++)
//    {
//        insertarListaOrd(&lista, &vec[i],sizeof(int),comparar);
//    }
//    recorrerListaIzq(&lista,accion);
//
//    return 0;
//}

int compararProd(const void*, const void*);
void accion(const void*);
void acumular(void* destino, const void* info);

int main()
{
    t_producto productos[CANT] = {  {5,"Leche", 5},
                                    {1,"Queso", 9},
                                    {6,"Pan", 1},
                                    {3,"Ajo", 3},
                                    {10,"Papa", 6}
                                    };
    t_producto elim = {4,"",0};
    t_lista lista;
    int i;
    crearLista(&lista);
    for(i=0; i< CANT; i++)
    {
        insertarListaOrd(&lista, &productos[i], sizeof(t_producto), compararProd);
    }

    recorrerListaIzq(&lista, accion);
    printf("\n--------------\n");
    eliminarPorClave(&lista, &elim, sizeof(t_producto), compararProd);
    recorrerListaIzq(&lista, accion);

    return 0;
}

int compararProd(const void* cmp1, const void* cmp2)
{
    return (int)(((t_producto*)cmp1)->codigo) - (int)(((t_producto*)cmp2)->codigo);
}

void accion(const void*a)
{
    printf("%d, %s, %d\n",((t_producto*)a)->codigo, ((t_producto*)a)->producto,((t_producto*)a)->cantidad);
}

void acumular(void* destino, const void* info)
{

}

//int comparar(const void* cmp1, const void* cmp2)
//{
//    return *(int*) cmp1 - *(int*)cmp2;
//}
//
//void accion(const void*a)
//{
//    printf("%d\n",*(int*)a);
//}
//
//void acumular(void* destino, const void* info)
//{
//
//}
