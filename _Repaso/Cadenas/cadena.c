#include <stdio.h>
#include "cadena.h"

#define ESLETRA(x) ((x>='a'&&x<='z')||(x>='A'&&x<='Z'))

#define ESNUMERO(x) (x>='0'&&x<='9')

#define ESMAYUS(x) (x>='A'&&x<='Z')

#define ESMINUS(x) (x>='a'&&x<='z')

///('a'-'A') se puede reemplazar con 32

#define AMAYUS(x) (ESMINUS(x)?(x)-32:(x)) /// Sin verificación: AMAYUS(x) (x)-('a'-'A')

#define AMINUS(x) (ESMAYUS(x)?(x)+32:(x)) /// Sin verificacion: AMINUS(x) (x)+('a'-'A')

#define ESBLANCO(x) ((x)==' ' || (x)=='\t')

#define ESNULL(x) (x==0)

char* aMayusculaString(char *cadena) //STRLWR
{
    char* iniCad =cadena;
    while(*cadena)
    {
        if(*cadena>='a' && *cadena<='z')
        {
            *cadena-=('a'-'A');
        }
        cadena++;
    }
    return iniCad;
}

char* aMinusculaString(char *cadena) //STRUPR
{
    char* iniCad =cadena;
    while(*cadena)
    {
        if(*cadena>='A' && *cadena<='Z')
        {
            *cadena+=('a'-'A');
        }
        cadena++;
    }
    return iniCad;
}

char *copiarString( char *destino, const char *fuente) //STRCPY
{
    char *desti=destino;
    while(*fuente)
    {
        *desti=*fuente;
        fuente++;
        desti++;
    };
    *desti='\0';
    return(destino);
}

char *concatenarString(char *destino, const char *fuente) //STRCAT
{
    char *dest=destino;
    while(*destino)
        destino++;
    while(*fuente)
    {
        *destino=*fuente;
        fuente++;
        destino++;
    };
    *destino='\0';
    return dest;
}

int compararString (const char* cadena1, const char* cadena2) //STRCMP
{
    while((*cadena1)&&(*cadena1==*cadena2))
    {
        cadena1++;
        cadena2++;
    }
    if(*cadena1 != *cadena2)
    {
        if(*cadena1<*cadena2)
            return -1;
        return 1;
    }
    return 0;
}

int compararStringIg (const char *cadena1, const char *cadena2) ///STRCMP
{
    while((*cadena1 && *cadena2)&&((AMINUS(*cadena1))==(AMINUS(*cadena2))))
    {
        cadena1++;
        cadena2++;
    }
    return (AMINUS(*cadena1))-(AMINUS(*cadena2));
}

unsigned longitudString (const char* cadena) //strlen
{
    unsigned cantidad = 0;
    while(*cadena)
    {
        cadena++;
        cantidad++;
    }
    return cantidad;
}

int aMayuscula(int caracter)    //toUpper
{
    if(caracter>='a'&&caracter<='z')
    {
        return caracter-=('a'-'A');
    }
    return caracter;
}

int aMinuscula(int caracter) //toLower
{
    if(caracter>='A'&&caracter<='Z')
    {
        return caracter+=('a'-'A');
    }
    return caracter;
}

char* primerAparicionEnString(char *fuente, int caracter) //STRCHR
{
    while(*fuente && *fuente!=caracter)
    {
        fuente++;
    }
    return (*fuente == caracter)?fuente:NULL;
}

char* primerAparicionDeStringEnString(const char *cadena1,const char *cadena2) //STRSTR
{
    char *posEnCad=(char*)cadena1;  //Asigna un vector para mantener un puntero a la primera posicion de las cadenas
    char *posEnSubC=(char*)cadena2;
    char *posIniCad;                //Va a apuntar al pricipio de la ocurrencia
    if(!*cadena2)
        return posEnCad;            //Si cadena 2 esta vacia, devuelve el inicio de la cadena1
    while(*posEnCad && *posEnSubC)
    {
        posIniCad=posEnCad;         //Pone el puntero en un posible candidato a devolver
        while(*posEnCad == *posEnSubC && *(posEnCad))
        {
            posEnCad++;             //Muevo los punteros mientras sean iguales, termina cuando encuentra el \0;
            posEnSubC++;
        }
        //if(!*posEnSubC)           //verifica que cadena2 llego al final,
        //return posIniCad;     //Pregunta: Debo mantener la estructura del while y hacer el return afuera????????
        if(*posEnSubC)
            posEnSubC=(char*)cadena2; //si no hubo un match, vuelvo al principio de cadena2
        posEnCad=posIniCad+1;
    }
//    if(!*posEnSubC)
//        return posIniCad;
//    return 0;                     //<-- return (!*posEnSubC)?posIniCad:0;
    return (!*posEnSubC)?posIniCad:0;
}

char* ultimaAparicionEnString(const char* cadena, int caracter) //STRRCHR
{
    char *ultimo = NULL, *posicion=(char*)cadena;
    while(*posicion)
    {
        if(*posicion == caracter)
            ultimo=posicion;
        posicion++;
    }
    if(!caracter)
        ultimo=posicion;
    return ultimo;
}

int encontrada(char *punteroDeLectura, char *punteroDeLectura2)
{
    while(*punteroDeLectura==*punteroDeLectura2&&*punteroDeLectura2)
    {
        punteroDeLectura++;
        punteroDeLectura2++;
    }
    return !(*punteroDeLectura2);
}


char* buscarSubCadena(char *cadena,char *subcadena)
{
    int seEncontro;
    if(!*subcadena)
        return cadena;
    while(*cadena&&!(seEncontro=encontrada(cadena, subcadena)))
    {
        cadena++;
    }
    return(*cadena)?cadena:NULL;
}

void* memcpy_MI(void* destino, const void* origen, size_t n) ///EL ORIGINAL ES UNA B****
{
    int i;
    destino += n-1;
    origen += n-1;

    for(i=0; i<n; i++)
    {
        *((char*)destino) = *((char*)origen);
        (char*)destino--;
        (char*)origen--;
    }

    return destino;
}

void *memmove_MIO(void *str1, const void *str2, size_t n)
{
    int i;
    char temp[n];
    char* iniTemp=temp, * iniStr1=str1, * IniStr2=(char*)str2;

    for (i=0; i<n ; i++,IniStr2++,iniTemp++ )
    {
        *iniTemp=*((char*)IniStr2);
    }

    iniTemp=temp;

    for (i=0; i<n ; i++,str1++,iniTemp++ )
    {
        *((char*)str1)=*iniTemp;
    }
    return iniStr1;
}
