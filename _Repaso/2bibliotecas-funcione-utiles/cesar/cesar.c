#include <stdio.h>
#include "cesar.h"

#define ESLETRA(x) (((x)>='a'&&(x)<='z')||((x)>='A'&&(x)<='Z'))
#define ESNUMERO(x) ((x)>='0'&&(x)<='9')
#define ESMAYUS(x) ((x)>='A'&&(x)<='Z')
#define ESMINUS(x) ((x)>='a'&&(x)<='z')
#define AMAYUS(x) ((x)>='a'&&(x)<='z'?(x)-32:(x)) /// Sin verificación: AMAYUS(x) (x)-('a'-'A')
#define AMINUS(x) ((x)>='A'&&(x)<='Z'?(x)+32:(x)) /// Sin verificacion: AMINUS(x) (x)+('a'-'A')
#define ESBLANCO(x) ((x)==' ')
#define ESNULL(x) ((x)==0)

#define TAM 5

char* codificarACesar(char *cadena, int desplazamiento)
{
    char *iniCad=cadena;///guardo el inicio de la cadena
    int numero = ('Z'-'A'+1); ///26, maxima cantidad de caracteres del abecedario
    int numeroDespl = ('9'-'0'+1);
    int desplazamientoNum;
    desplazamientoNum = desplazamiento % numeroDespl;
    desplazamiento = desplazamiento % numero;///por si el desplazamiento se pasa de 26
    ///desplazamiento va de 0 a 26
    if(desplazamiento>0)///si se pide un desplazamiento positivo (de A a Z)
    {
        while(*cadena)///mientras hayan caracteres en la cadena
        {
            if(ESLETRA(*cadena))///solo desplazo si es una letra
                *cadena+=((AMINUS(*cadena)+desplazamiento)>'z')?desplazamiento-numero:desplazamiento;
        ///el ternario sirve por si la suma hace que el desplazamiento supere el rango 'a-z'
            else if(ESNUMERO(*cadena))
                *cadena+=((*cadena)+desplazamientoNum)>'9'?desplazamientoNum-numeroDespl:desplazamientoNum;
            cadena++;
        }
    }
    else if(desplazamiento<0)///si se pide un desplazamiento negativo (de Z a A)
    {
        while(*cadena)
        {
            if(ESLETRA(*cadena))
                *cadena+= ((AMAYUS(*cadena)+desplazamiento)<'A')?desplazamiento+numero:desplazamiento;
            else if(ESNUMERO(*cadena))
                *cadena+=((*cadena)+desplazamientoNum)<'0'?desplazamientoNum+numeroDespl:desplazamientoNum;
            cadena++;
        }
    }
    return iniCad;
}

char* decodificarCesar(char *cadena, int desplazamiento)
{
    char *iniCad=cadena;
    int numero = ('Z'-'A'+1); ///26
    int numeroDespl = ('9'-'0'+1);
    int desplazamientoNum;
    desplazamientoNum = desplazamiento % numeroDespl;
    desplazamiento=desplazamiento%numero;
    if(desplazamiento>0)
    {
        while(*cadena)
        {
            if(ESLETRA(*cadena))
                *cadena-=((AMINUS(*cadena)-desplazamiento)<'a')?desplazamiento-numero:desplazamiento;
            else if(ESNUMERO(*cadena))
                *cadena-=((*cadena)-desplazamientoNum)<'0'?desplazamientoNum-numeroDespl:desplazamientoNum;
            cadena++;
        }
    }
    else if(ESLETRA(*cadena))
    {
        while(*cadena)
        {
            if(ESLETRA(*cadena))
                *cadena-=((AMAYUS(*cadena)-desplazamiento)>'Z')?desplazamiento+numero:desplazamiento;
            else if(ESNUMERO(*cadena))
                *cadena-=((*cadena)-desplazamientoNum)>'9'?desplazamientoNum+numeroDespl:desplazamientoNum;
            cadena++;
        }
    }
    return iniCad;
}


///

char* invertirPalabra(char* cad)
{
    char aux;
    char* ini = cad, *fin;

    while(*cad && ESLETRA(*cad))
        cad++;

    fin = cad;
    cad--;

    while(ini<cad)
    {
        aux = *ini;
        *ini = *cad;
        *cad = aux;

        ini++;
        cad--;
    }

    return fin;
}

char* proximaPalabra(char* cad)
{
    while(*cad && !(ESLETRA(*cad)&&(!ESLETRA(*(cad-1)))))
    {
        cad++;
    }

    return cad;
}

char* invertirCadena(char* cad)
{
    char* iniCad  = cad;

    while(*cad)
    {
        cad = invertirPalabra(proximaPalabra(cad));
    }

    return iniCad;
}

char* codificar(char* cad, char* codigo, int desp)
{
    char* iniCad = cad, *iniCodigo = codigo;///apunto al inicio del codigo
    int tamLetras = strlen(codigo);
    char* posUltima = codigo + tamLetras - 1;

    desp=desp%tamLetras;

    if (!desp)
        return iniCad;

    while(*cad)
    {
        codigo = iniCodigo;///

        while(*codigo && *codigo != *cad)
           codigo++; ///por cada letra de la cadena hay que chequear con todas las letras del codigo
            ///hasta encontrar una que haya sido codificada, o llegar al final


        if(*codigo == *cad)///si hay coincidencia entre la cadena y la lista de letras que se usaron para codificar
        {
            if(desp>0)
                *cad = (desp > posUltima-codigo) ? *(codigo + desp - tamLetras) : *(codigo + desp);

            else
                *cad = (-desp > codigo-iniCodigo) ? *(codigo + desp + tamLetras) : *(codigo + desp);
        }
        cad++;///siguiente letra de la cadena codificada
    }

    return iniCad;
}

void decodificar (char* cadena, FILE* pf, FILE* pfSalida, char* codigo, int despl, int tam)
{
    despl*=-1;
    while(fgets(cadena, tam, pf))
    {
        codificar(cadena, codigo, despl);
        invertirCadena(cadena);
        fprintf(pfSalida, "%s", cadena);
    }

}
