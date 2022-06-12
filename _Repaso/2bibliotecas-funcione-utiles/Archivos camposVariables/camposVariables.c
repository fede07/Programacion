#include <stdio.h>
#include <string.h>
#include "camposVariables.h"

int crearLote()
{
    char doc[TAM][LARGO] =
    {
        {"Pepito Feliz|12365678|d|99.9999\n"},
        {"Pepita Rica|420|r|400\n"},
        {"|25|n|1\n"},///no hay nombre
        {"Pepito Vacio||v|0\n"},///recibe dos pipes seguidos
        {"Feliz|PepitoIsHere|d|99.9999999\n"},///en vez de int recibe una cadena
        {"Marito Feliz|12|d|yo\n"},///en vez de float recibe cadena
        {"Pepito Soltero|65|so|99.9999999\n"},///en vez de 1 solo caracter recibe dos
        {"1546165|48|a|10\n"},///en vez de vez de una cadena de letras recibe numeros
        {"Pepito triste\n"}///la idea es que tire error con esta persona
    };
    int i;
    FILE * pf;
    pf=fopen("loteDePruebaVar.txt","wt");
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

int parseo(char * cadena,t_animo * animo)
{
    char * posicion;
    posicion = strrchr(cadena,'|');///voy hasta el ultimo |
    ///con esto ya estaria en el ultimo pipe

    ///si no encuentra el | va por el falso, pero tambien que el campo despues del pipe contenga datos
    if(posicion && *(posicion+1)!='\0')///aca lee la puntuacion
    {
        sscanf(posicion+1,"%f",&(animo->puntuacion));///leo la informacion desde ese ultimo | hasta el \0
        *posicion = '\0';
    }
    else
        return 0;

    posicion = strrchr(cadena,'|');
    if(posicion && *(posicion+1)!='\0')///aca lee el estado
    {
        sscanf(posicion+1,"%c",&(animo->estado));
        *posicion = '\0';
    }
    else
        return 0;

    posicion = strrchr(cadena,'|');
    if(posicion && *(posicion+1)!='\0')///aca lee el dni
    {
        sscanf(posicion+1,"%d",&(animo->dni));
        *posicion = '\0';
    }
    else
        return 0;

    ///aca lee el nyap
    if(*cadena)///va a entrar solo si hay un nombre cargado
    {
        strcpy(animo->nyap,cadena);
    }
    else
        return 0;

    return 1;

}
