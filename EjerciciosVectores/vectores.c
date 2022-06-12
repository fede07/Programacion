#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "vectores.h"
#define TAM 100

int menu()
{
    int opcion, i;
    do
    {
        i=1;
        printf("\t*******************************************\n");
        printf("\t*          FUNCIONES DE VECTORES          *\n");
        printf("\t*******************************************\n\n\n");
        printf("\t\t%d.Cargar Vector\n",i);
        i++;
        printf("\t\t%d.Mostrar Vector\n",i);
        i++;
        printf("\t\t%d.Insertar Elemento\n",i);
        i++;
        printf("\t\t%d.Insertar Elemento Ordenado\n",i);
        i++;
        printf("\t\t%d.Eliminar Elemento\n",i);
        i++;
        printf("\t\t%d.Eliminar primera aparicion de un  Elemento\n",i);
        i++;
        printf("\t\t%d.Eliminar todas las apariciones de un Elemento\n",i);
        i++;
        printf("\t\t%d.Debug: Forzar cantidad de elementos\n",i);
        i++;
        printf("\t\t%d.Ordenar Vector\n",i);
        i++;
        printf("\t\t0.Salir\n");
        i++;
        scanf("%d", &opcion);
        system("cls");
    }
    while(opcion<0 || opcion>i);
    return opcion;
}

void cargarVectorInt(int *vec, int cant)
{
    unsigned i;
    for(i=0; i<cant; i++)
    {
        printf("Elemento %d=\t",i+1);
        scanf("%d", vec);
        vec++;
    }
}

void mostrarVectorInt(int *vec, int cant)
{
    unsigned i;
    for(i=0; i<cant; i++)
    {
        printf("\nPosicion %2.d=\t%d",i+1,*vec);
        vec++;
    }
}

int insertarIntComp(int *vect, int elemento, int posicion, int *cant)
{
    int *vecTemp = vect;
    vect+= posicion-1;
    vecTemp += *cant;

    while(vecTemp != vect)
    {
        *vecTemp = *(vecTemp-1);
        vecTemp--;
    }

    *vecTemp = elemento;

    if(*cant+1 >TAM)
        return *cant;

    (*cant)++;
    return *cant;
}
//    int j, *vSigPos;
//    vect+=cant-2;
//    vSigPos=vect;
//    vSigPos++;
//
//    for(j=cant-1; j>=posicion; j--)
//    {
//        *vSigPos=*vect;
//        vect--;
//        vSigPos--;
//    }
//
//    if(j == posicion)
//    {
//        vect--;
//        vSigPos--;
//    }
//
//    *vSigPos=elemento;
//    return 1;
//}

int insertarIntOrdenado(int *vect, int elemento, int tam, int *cant)
{
    int *iniVec;
    iniVec = vect;
    vect+= *cant;

    ordenarSelecc(vect, *cant);

    while(iniVec != vect && *(vect-1)>elemento)
    {
        *vect = *(vect-1);
        vect--;
    }

    if(*cant+1 >TAM)
        return *cant;

    (*cant)++;
    return *cant;

}
//    int pos=cant, i=0, j, b=1, *vSigPos;
//    while(i<cant && pos==cant)
//    {
//        if(elemento<*vect)
//        {
//            pos=i-1;
//        }
//        vect++;
//        i++;
//    }
//    vect-=i;
//    vect+=cant;
//    vSigPos=vect+1;
//    for(j=cant; j>pos; j--)
//    {
//        *vSigPos=*vect;
//        vect--;
//        vSigPos--;
//        b=0;
//    }
//    if(b==0)
//        *vSigPos=elemento;
//    else
//        *vect=elemento;
//}

int eliminarElementoInt(int *vect, int posicion, int *cantidad)
{
    int i;

    if(*cantidad == 0)
        return 0;

    vect+=posicion;

    for(i=posicion; i<*cantidad-1; i++)
    {
        *vect=*(vect+1);
        vect++;
    }
    *cantidad-=1;
    return 1;
}

int eliminarPrimeraAparicionInt(int *vect, int elemento, int *cantidad)
{
    int i, posRec = 0;

    if(*cantidad == 0)
        return 0;

    while(*vect!=elemento && posRec<*cantidad)
    {
        posRec++;
        vect++;
    }
    for(i=0; i<*cantidad-posRec; i++)
    {
        *vect=*(vect+1);
        vect++;
    }

    if(posRec<=*cantidad)
        (*cantidad)--;

    return 1;
}


int eliminarTodaAparicionInt(int *vect,int elemElim,int *cant)
{
    int *vectTemp, *vectFin;

    if(*cant == 0)
        return 0;

    vectFin = vect + *cant;

    while(vectTemp<=vectFin && *cant > 0)
    {
        if(*vectTemp == elemElim)
        {
            vectTemp++;
            *cant-=1;
        }

        *vect = *vectTemp;
        vect++;
        vectTemp++;
    }

    return 1;
}

int cargarVectorIntFull(int *vect, int cant, int tam)
{
    int aux1;
    if(cant==tam)
    {
        return tam;
    }
    printf("\nCantidad de elementos a ingresar:");
    scanf("%d", &aux1);
    cargarVectorInt(vect+cant, aux1);
    cant+=aux1;
    mostrarVectorInt(vect, cant);
    return cant;
}

int esMayor(int valor1, int valor2)
{
    if(valor1>valor2) //
        return 1;
    return 0;
}

int* esMenor(int *valor1, int *valor2)  //Devuelve direccion del menor valor
{
    if(*valor1<*valor2)
        return valor1;
    return valor2;

}

int* buscarMenor (int *vector, int tam, int i) //Devuelve la direccion del menor numero en un vector
{
    int j, *menor=vector;
    for(j=i+1; j<tam; j++)
    {
        vector++;
        menor=esMenor(vector,menor);
    }
    return menor;
}

void intercambiar(int *vector, int *vecSig) //Intercambia dos valores en un vector
{
    int temp;
    temp = *vector;
    *vector=*vecSig;
    *vecSig=temp;
}

void ordenarSelecc(int *vector, int tam)
{
    int i, *menor;

    for(i=0; i<tam-1; i++)
    {
        menor=buscarMenor(vector, tam, i);
        intercambiar(menor,vector);
        vector++;
    }
}

//int* buscarMenor (int *vector, int tam)
//{
//    int j, *menor=vector;
//
//    for(j=1; j<tam; j++)
//    {
//        vector++;
//        if(*menor>*vector)
//            menor=vector;
//    }
//    return menor;
//}

//void ordenarSelecc(int *vector, int tam)
//{
//    int i, j, *vecSig, *menor;
//
//    for(i=0; i<tam-1; i++)
//    {
//        vecSig=vector;
//        menor=vecSig;
//        for(j=i+1; j<tam; j++)
//        {
//            vecSig++;
//            menor=esMenor(vecSig,menor);
//        }
//        intercambiar(menor,vector);
//        vector++;
//    }
//}
