#include "cadenas.h"
#include <stdio.h>

///revisar dentro de un printf si los resultados son correctos


///devuelve positivo si la primer cadena es mayor, 0 si es igual, negativo si es menor
int mi_strcmp (const char * cadena1, const char * cadena2)
{
    while(*cadena1 && *cadena1==*cadena2)///si uno llega al final pero el otro no, entonces el caracter es distinto
    {
        cadena1++;
        cadena2++;
    }

    return *cadena1-*cadena2;
}


///copia s2 en s1 incluyendo el caracter nulo (pisa s1)
char * mi_strcpy(char * cadena1, const char * cadena2)
{
    char * resultado = cadena1;
    while(*cadena2)
    {
        *cadena1=*cadena2;
        cadena1++;
        cadena2++;
    }
    *cadena1='\0';

    return resultado;
}

///agrega s2 a lo de s1, poniendo el primer valor en el \0
char *mi_strcat(char * cadena1, const char * cadena2)
{
    char * resultado = cadena1;
    while(*cadena1)
        cadena1++;
    while(*cadena2)
    {
        *cadena1=*cadena2;
        cadena1++;
        cadena2++;
    }
    *cadena1='\0';
    return resultado;
}

///dice cuantos caracteres tiene la cadena sin contar el nulo
int mi_strlen(const char * cadena1)
{
    int contador=0;
    while(*cadena1)
    {
        cadena1++;
        contador++;
    }
    return contador;
}

///convierte una letra a mayuscula, si recibe otro caracter no le hace nada
int mi_toupper(char caracter)
{
    if(caracter>='a' && caracter<='z')
        return (caracter - ('a' - 'A'));
    return caracter;
}

///convierte una letra a minuscula, si recibe otro caracter no le hace nada
int mi_tolower(char caracter)
{
    if(caracter>='A' && caracter<='Z')
        return (caracter + ('a' - 'A'));
    return caracter;
}

///propia de c++? convierte toda la cadena a mayuscula
char * mi_strupr (char * cadena)
{
    char * resultado = cadena;
    while(*cadena)
    {
        if(*cadena>='a' && *cadena<='z')
            *cadena -= ('a' - 'A');
        cadena++;
    }
    return resultado;
}

///propia de c++? convierte toda la cadena a minuscula
char * mi_strlwr (char * cadena)
{
    char * resultado = cadena;
    while(*cadena)
    {
        if(*cadena>='A' && *cadena<='Z')
            *cadena += ('a' - 'A');
        cadena++;
    }
    return resultado;
}

///devuelve la posicion de la primera ocurrencia de c, sino devuelve un NULL
char * mi_strchr(char * cadena, int valorBuscado)
{
    while(*cadena&&*cadena!=valorBuscado)
        cadena++;
    return (*cadena==valorBuscado)?cadena:NULL;
}

char * mi_strrchr (char *str, int c)
{
    char * direccion=NULL;
    while(*str)
    {
        if(*str==c)
            direccion=str;
        str++;
    }
    return (*str==c)?str:direccion;
}


char *mi_strstr(const char * cadena1,const char * cadena2)
{
    char *posicion1=(char*)cadena1;
    char *posicion2=(char*)cadena2;
    char*posicionInicioCadena;
    if(!*cadena2)
    {
        return posicion1;
    }
    while(*posicion1)
    {
        posicionInicioCadena=posicion1;
        while(*posicion1 == *posicion2 && *(posicion1))
        {
            posicion1++;
            posicion2++;
        }
        if(!*posicion2)
            return posicionInicioCadena;
        posicion2=(char*)cadena2;
        if(*posicion1)
            posicion1++;
    }
    return NULL;
}

/// **************************
int sinRepeticion (char *cadena, char * busqueda)
{
    int ocu=0;
    char * iniBus = busqueda;
    if(!*busqueda)
        return ocu;
    while(*cadena)
    {
        while(*cadena==*busqueda && *busqueda)
        {
            cadena++;
            busqueda++;
        }
        if(!*busqueda)
        {
            ocu++;
            cadena--;
            busqueda = iniBus;
        }
        if(busqueda!=iniBus)///hubieron coincidencias, pero no toda la cadena
        {
            busqueda = iniBus;
            cadena--;
        }


        cadena++;
    }

    return ocu;
}

int conRepeticion (char *cadena, char * busqueda)
{
    int ocu=0;
    char * iniBus = busqueda;
    char * iniCoin = cadena;

    if(!*busqueda)
        return ocu;
    while(*cadena)
    {
        if(*cadena==*busqueda)
            iniCoin = (cadena);

        while(*cadena==*busqueda && *busqueda)
        {
            cadena++;
            busqueda++;
        }
        if(!*busqueda)///se encontro la cadena completa
        {
            ocu++;
        }
        cadena = iniCoin;
        iniCoin++;
        busqueda = iniBus;
        cadena++;
    }
    return ocu;
}

int esAnagrama (const char * cadena1, const char * cadena2)
{
    char copia[strlen(cadena1)+1];
    int resultado;

    strcpy(copia,cadena1);

    resultado = buscarCaracter(AMINUS(*cadena2),copia);

    while(*cadena2 && *copia && resultado)
    {
        cadena2++;
        while(*cadena2 && ESBLANCO(*cadena2))
            cadena2++;

        if(*cadena2)///podria haber un NULL despues de los blancos
        {
            resultado = buscarCaracter(AMINUS(*cadena2),copia);
        }
    }

    if(!*cadena2 && !hayLetras(copia))
        return 1;

    return 0;
}

int buscarCaracter (char letra, char * copia)
{
    ///mientras haya contenido en copia y la letra enviada sea distinta a la actual de copia
    ///letra nunca va a poder ser un espacio ni NULL
    while(*copia && letra!=AMINUS(*copia) )
    {
        copia++;
    }

    if(letra==AMINUS(*copia) )///si sale del while porque encontro la letra devuelve 1
    {
        *copia = ' ';///piso la letra con un espacio para evitar compararla otra vez despues
        return 1;
    }
    return 0;
}

int hayLetras (const char * cadena)
{
    while(*cadena && !ESLETRA(*cadena))
        cadena++;

    if(*cadena)
        return 1;

    return 0;
}

