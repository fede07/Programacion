#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "vectores.h"
#define TAM 100
#define TAMTEST 6

int main()
{
    int opcion,
    cant=0,
    salir = 0,
    elemento,
    pos,
//    vect[TAM]= {0,10,20,30,40,50,60,70,80,90,100};
//    vect[TAM]= {0,20,20,30,40,50,20,70,20,90,100};
    vect[TAM]= {43,8,21,3,94,77};
    cant+=TAMTEST;
    do
    {
        system("cls");
        opcion=menu();
        switch(opcion)
        {
        case 1:
            if(cant==TAM)
            {
                printf("VECTOR LLENO");
                getch();
                break;
            }
            cant = cargarVectorIntFull(vect, cant, TAM);
            break;
        case 2:
            if(cant)
            {
                mostrarVectorInt(vect, cant);
            }
            else
                printf("\nVECTOR VACIO");
            getch();
            break;
        case 3:
            if(!cant)
            {
                printf("VECTOR VACIO");
                getch();
                break;
            }
            if(cant<TAM)
            {
                printf("\nElemento a insertar:");
                scanf("%d", &elemento);
                do
                {
                    printf("\nPosicion, max %d: ", cant);
                    scanf("%d", &pos);
                }while(pos>cant || pos<0);

                insertarInt(vect, elemento, pos, &cant);
                mostrarVectorInt(vect, cant);
            }
            else
                printf("LIMITE DE VECTOR ALCANZADO");
            getch();
            break;
        case 4:
            if(!cant)
            {
                printf("VECTOR VACIO");
                getch();
                break;
            }
            if(cant<TAM)
            {
                printf("\nElemento a insertar:");
                scanf("%d", &elemento);
                insertarIntOrdenado(vect, elemento, TAM, &cant);
                cant++;
                mostrarVectorInt(vect, cant);
            }
            else
                printf("\nLIMITE DE VECTOR ALCANZADO");
            getch();
            break;
        case 5:
            if(!cant)
            {
                printf("\nVECTOR VACIO");
                getch();
                break;
            }
            mostrarVectorInt(vect, cant);
            printf("\n\nPosicion de elemento a eliminar:");
            scanf("%d", &pos);
            eliminarElementoInt(vect, pos-1, cant);
            cant--;
            if(cant)
                mostrarVectorInt(vect, cant);
            else
                printf("\nVECTOR VACIO");
            getch();
            break;
        case 6:
            if(!cant)
            {
                printf("\nVECTOR VACIO");
                getch();
                break;
            }
            mostrarVectorInt(vect, cant);
            printf("\n\nElemento a eliminar:");
            scanf("%d", &elemento);
            eliminarPrimeraAparicionInt(vect,elemento,cant);
            cant--;
            if(cant)
                mostrarVectorInt(vect, cant);
            else
                printf("\nVECTOR VACIO");
            getch();
            break;
        case 7:
            if(!cant)
            {
                printf("\nVECTOR VACIO");
                getch();
                break;
            }
            mostrarVectorInt(vect, cant);
            printf("\n\nElemento a eliminar:");
            scanf("%d", &elemento);
            cant=eliminarTodaAparicionInt(vect,elemento,cant);
            if(cant)
                mostrarVectorInt(vect, cant);
            else
                printf("\nVECTOR VACIO");
            getch();
            break;
        case 8:
            printf("\n*********************PELIGRO*********************\n");
            printf("\n***********NO EXCEDER DE 100 ELEMENTOS***********\n");
            printf("\nCantidad de elementos del vector:");
            scanf("%d", &elemento);
            cant=elemento;
            mostrarVectorInt(vect, cant);
            getch();
            break;
        case 9:
            printf("\nVector sin ordenar:\n");
            mostrarVectorInt(vect, cant);
            ordenarSelecc(vect, cant);
            printf("\n\nVector Ordenado:\n");
            mostrarVectorInt(vect, cant);
            getch();
            break;
        case 0:
            salir = 1;
            break;
        }
    }
    while(salir == 0);
    printf("\n\tGood night! =(^__^ )=\n");
    return 0;
}
