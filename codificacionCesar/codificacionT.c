#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ESLETRA(x) (((x)>='a' && (x)<='z' )||( (x)>='A' && (x)<='Z'))
#define ESBLANCO(x) (((x)=='\t' || (x)==' '))
#define TAM 40


///       "Carolina B. Caruso Dellisanti"
///        "Tomas Cambiasso"


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
    char* iniCad = cad, *iniLetras = codigo; //"acegiknpsuvz"
    int tamLetras = strlen(codigo);
    char* posUltima = codigo + tamLetras - 1;

    desp=desp%tamLetras;

    if (!desp)
        return iniCad;

    while(*cad)
    {
        codigo = iniLetras;

        while(*codigo && *codigo != *cad)
            codigo++;

        if(*codigo == *cad)
        {
            if(desp>0)
                *cad = (desp > posUltima-codigo) ? *(codigo + desp - tamLetras) : *(codigo + desp);

            else
                *cad = (-desp > codigo-iniLetras) ? *(codigo + desp + tamLetras) : *(codigo + desp);
        }

        cad++;
    }

    return iniCad;
}

void decodificar (char* cadena, FILE* pf, FILE* salida, char* codigo, int despl, int tam)
{
    despl*=-1;
    while(fgets(cadena, tam, pf))
    {
        codificar(cadena, codigo, despl);
        invertirCadena(cadena);
        fprintf(salida,"%s", cadena);
    }

}
