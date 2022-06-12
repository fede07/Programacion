#include "archivos.h"
#include <stdio.h>

int crearLote()
{
    char doc[TAM][LARGO] =
    {
        {"Hola mundo\n"},
        {"Hello world\n"},
        {"Pepe loco\n"},
        {"Perez, Juan\n"},
        {"Pepito 123 Feliz\n"},
        {"5435893\n"},
        {""},
        {"hola893pepe\n"},
        {"p3p3\n"},
        {"xXxXxXxXep3pexXxXxXxX\n"}
    };
    int i;
    FILE * pf;
    pf=fopen("lotePrueba2.txt","wt");
    if(!pf)
    {
        return ERROR_ARCH;
    }
    for(i=0; i<TAM; i++)
    {
        fputs(doc[i],pf);
    }

    fclose(pf);

    return TODO_OK;
}

int abrirArchivo(FILE** archivo, char* nombre, char* modo)
{
    *archivo=fopen(nombre, modo);
    return (archivo)?1:0;
}

void invPalDeArch(FILE * pf)
{
    char cadena[LARGO];
    while(fgets(cadena,LARGO,pf))
    {
        printf("<%s",cadena);
        printf("<%s",invertirPalabras(cadena));
        printf("---------------\n");
    }
}

char * invertirPalabras(char * cadena)
{
    char * inicio = cadena,
           * fin = cadena,
             * cadenaInicial = cadena;
    while(*cadena)
    {
        if(!proximaPalabra(cadena, &inicio, &fin))
            return cadenaInicial;
        cadena = fin+1;
        while(inicio<fin)
        {
            intercambio (inicio,fin);
            inicio++;
            fin--;
        }
    }
    return cadenaInicial;
}

///devuelve inicio y fin porque en otro ejercicio capaz no se pide invertir pero si necesito la palabra
int proximaPalabra(char * cadena, char ** inicio, char ** fin)
{
    while(!ESLETRA(*cadena) && *cadena)
        (cadena)++;
    if(*cadena)
        *inicio = cadena;
    else
        return 0;

    while(ESLETRA(*cadena))
        (cadena)++;
    (cadena)--;
    *fin = cadena;

    return 1;
}

//int proximaPalabra(char * cadena, char ** inicio)
//{
//    int contador=0;
//    while(!ESLETRA(*cadena) && *cadena)
//        (cadena)++;
//    if(*cadena)
//        *inicio = cadena;
//    else
//        return contador;
//
//    while(ESLETRA(*cadena))
//    {
//        (cadena)++;
//        contador++;
//    }
//
//    return contador; ///devuelve la diferencia de posiciones de memoria entre el inicio y el fin
//}

void intercambio (char * inicio,char * fin)
{
    char auxiliar;
    auxiliar = *inicio;
    *inicio = *fin;
    *fin = auxiliar;
}


