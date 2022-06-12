#include "normaliza.h"
#include <stdio.h>

#include <strings.h>

char * borrarBlancosExtras (char* cadena)
{
    char * inicioCadena = cadena,
           * lector = cadena;

    while (*lector)///si la cadena no llego al \0 entra
    {
        while(ESBLANCO(*lector))///si esta en un espacio va al siguiente lugar
            lector++;

        while (/* *lector!=' ' && */*lector && !ESBLANCO(*lector))///mientras no haya un espacio, y el lector no llegue a \0 guarda los caracteres en cadena
        {
            *cadena = *lector;
            lector++;
            cadena++;
        }

        if(!ESBLANCO(*(cadena-1)))///si el lector no llego al fin de la cadena quiere decir que hay un espacio, entonces pongo solo uno en el caso de que no lo haya puesto antes
        {
            *cadena = ' ';
            cadena++;
        }

    }
    *(cadena-1) = '\0';
    return inicioCadena;
}

char * tipoTitulo (char* lectura)
{
    char* iniCad=lectura, *escritura=lectura;

    while(*lectura)
    {
        while(!ESLETRA(*lectura)&&*lectura!='\0')
        {
            lectura++;
        }

        if(ESLETRA(*lectura))
        {
            *escritura=ESMAYUS(*lectura);
            escritura++;
            lectura++;
        }

        while(ESLETRA(*lectura))
        {
            *escritura=ESMINUS(*lectura);
            escritura++;
            lectura++;
        }

        if(ESLETRA(*(escritura-1))&&*lectura)
        {
            *escritura=' ';
            escritura++;
            lectura++;
        }
    }

    if(ESBLANCO(*(escritura-1)))
    {
        *(escritura-1)='\0';
    }
    else
    {
        *(escritura)='\0';
    }

    return iniCad;
}

char * tipoOracion (char * lectura)
{
    char* iniCad=lectura, *escritura=lectura;

    while(!ESLETRA(*lectura)&&*lectura!='\0')
    {
        lectura++;
    }
    if(ESLETRA(*lectura))
    {
        *escritura=AMAYUS(*lectura);
        escritura++;
        lectura++;
    }

    while(*lectura)
    {
        while(!ESLETRA(*lectura)&&*lectura!='\0')
        {
            lectura++;
        }

        while(ESLETRA(*lectura))
        {
            *escritura=AMINUS(*lectura);
            escritura++;
            lectura++;
        }
        if(ESLETRA(*(escritura-1))&&*lectura)
        {
            *escritura=' ';
            escritura++;
            lectura++;
        }
    }

    if(ESBLANCO(*(escritura-1)))
    {
        *(escritura-1)='\0';
    }

    else
    {
        *(escritura)='\0';
    }
    return iniCad;
}

char * primerPalabraMayus (char* cadena)
{
    char * inicioCadena = cadena;
    char * escritura = cadena;

    while(!ESLETRA(*cadena) && *cadena)
    {
        cadena++;
    }

    while(*cadena && ESLETRA(*cadena))///mientras no llegue al \0 y no llegue al espacio pasa a mayusculas
    {
        *escritura = AMAYUS((*cadena));
        cadena++;
        escritura++;
    }

    ///aca ya estaria en mayuscula la primer palabra

    while(*cadena)
    {
        if(ESLETRA(*cadena))///si hay una mayuscula la pasa a minuscula
        {
            *escritura = AMINUS(*cadena);
            escritura++;
        }
        if(ESLETRA(*(cadena-1)) && !ESLETRA(*(cadena)))
        {
            *escritura = ' ';
            escritura++;
        }
        cadena++;
    }

    if(ESBLANCO(*(escritura)))
        *escritura='\0';
    else
        *(escritura-1)='\0';


    return inicioCadena;
}

char * todoMayus (char * cadena)
{
    char * inicioCadena = cadena;
    char * escritura = cadena;

    while(*cadena)
    {
        while(!ESLETRA(*cadena) && *cadena)///salteo lo que no es espacio
            cadena++;

        while(ESLETRA(*cadena))///si son letras las paso a mayuscula
        {
            *escritura = AMAYUS((*cadena));
            escritura++;
            cadena++;
        }
        if(ESLETRA(*(escritura-1)) && !ESLETRA(*cadena))
           {
               *escritura = ' ';
                escritura++;
           }
    }

    if(ESBLANCO(*(escritura)))
        *escritura='\0';
    else
        *(escritura-1)='\0';

    return inicioCadena;
}

char * apellidoInicialesMayuscula (char* cadena)
{
    char * inicioCadena = cadena;
    char * escritura = cadena;

    while(!ESLETRA(*cadena) && *cadena)///salteo todo lo que no sea letra
        cadena++;

    while(*cadena && ESLETRA(*cadena))///si hay letra hay que pasar todo a mayuscula
    {
        *escritura = AMAYUS((*cadena));
        cadena++;
        escritura++;
    }
    ///aca el apellido esta en mayuscula


    while(*cadena)
    {
        if( ( !ESLETRA(*(cadena-1)) && ESLETRA(*(cadena)) ) ) ///seria la primer letra del nombre si el caracter anterior es un espacio
        {
            *escritura = ' ';
            escritura++;
            *escritura = AMAYUS((*cadena));
            cadena++;
            escritura++;
            *escritura = '.';///despues de la inicial va un punto
            cadena++;
            escritura++;
        }
        cadena++;
    }

    *(escritura)='\0';


    return inicioCadena;
}






