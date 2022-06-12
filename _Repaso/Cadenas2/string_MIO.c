#include <stdio.h>
#include "string_MIO.h"

///('a'-'A') se puede reemplazar con 32

#define ESNUMERO(x) ((x)>='0'&&(x)<='9')

#define ESMAYUS(x)  ((x)>='A'&&(x)<='Z')

#define ESMINUS(x)  ((x)>='a'&&(x)<='z')

#define ESLETRA(x)  (ESMINUS(x) || ESMAYUS(x))

#define AMAYUS(x)   ((x)>='a'&&(x)<='z'?(x)-32:(x)) /// Sin verificación: AMAYUS(x) (x)-('a'-'A')

#define AMINUS(x)   ((x)>='A'&&(x)<='Z'?(x)+32:(x)) /// Sin verificacion: AMINUS(x) (x)+('a'-'A')

#define ESBLANCO(x) (((x)==' ')||((x)=='\n')||((x)=='\t'))

#define ESNULL(x)   ((x)==0)

char* strlwr_mio(char *cadena) //STRLWR
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

char* strupr_mio(char *cadena) //STRUPR
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

char *strcpy_mio( char *destino, const char *fuente) //STRCPY
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

char *strcat_mio(char *destino, const char *fuente) //STRCAT
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
//
//int strcmp_mio (const char* cadena1, const char* cadena2) //STRCMP
//{
//    while((*cadena1)&&(*cadena1==*cadena2))
//    {
//        cadena1++;
//        cadena2++;
//    }
//    if(*cadena1 != *cadena2)
//    {
//        if(*cadena1<*cadena2)
//            return -1;
//        return 1;
//    }
//    return 0;
//}

int strcmp_mio(const char *cadena1, const char *cadena2) ///STRCMP mas simple.
{
    while((*cadena1 && *cadena2)&&((AMINUS(*cadena1))==(AMINUS(*cadena2))))
    {
        cadena1++;
        cadena2++;
    }
    return (AMINUS(*cadena1))-(AMINUS(*cadena2));
}

//unsigned strlen_mio(const char* cadena) //strlen
//{
//    unsigned cantidad = 0;
//    while(*cadena)
//    {
//        cadena++;
//        cantidad++;
//    }
//    return cantidad;
//}

unsigned strlen_mio(const char* cadena) //strlen
{
    if(!(*cadena))
    {
        return 0;
    }
    return(strlen_mio(cadena)+1);
}

int toUpper_mio(int caracter)    //toUpper
{
    if(caracter>='a'&&caracter<='z')
    {
        return caracter-=('a'-'A');
    }
    return caracter;
}

int toLower_mio(int caracter) //toLower
{
    if(caracter>='A'&&caracter<='Z')
    {
        return caracter+=('a'-'A');
    }
    return caracter;
}

char* strchr_mio(char *fuente, int caracter) //STRCHR
{
    while(*fuente && *fuente!=caracter)
    {
        fuente++;
    }
    return (*fuente == caracter)?fuente:NULL;
}

char* strstr_mio(const char *cadena1,const char *cadena2) //STRSTR
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

char* strrchr_mio(const char* cadena, int caracter) //STRRCHR
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

void* memcpy_MI(void* destino, const void* origen, size_t n) ///El original se rompe más...
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

void *memmove_MIO(void *destino, const void *origen, size_t n)
{
    int i;
    char temp[n];
    char* iniTemp=temp, * iniDest=destino, * iniOrig=(char*)origen;

    for (i=0; i<n ; i++,iniOrig++,iniTemp++ )
    {
        *iniTemp=*((char*)iniOrig);
    }

    iniTemp=temp;

    for (i=0; i<n ; i++,destino++,iniTemp++ )
    {
        *((char*)destino)=*iniTemp;
    }
    return iniDest;
}

int rEsPalindromo(const char* cad, char* fin)
{
     if(cad>=fin)
    {
        return 1;
    }

    if(!ESLETRA(*cad))
    {
        return rEsPalindromo(cad+1,fin);
    }
    if(!ESLETRA(*fin))
    {
        return rEsPalindromo(cad,fin-1);
    }
    if(*cad==*fin)
    {
       return rEsPalindromo(cad+1,fin-1);
    }
    else
    {
        return 0;
    }
}

int esPalindromo(const char* cadena)
{
    char* fin;
    fin = (char*)cadena + strlen_mio(cadena) - 1;

    return rEsPalindromo(cadena, fin);

}
