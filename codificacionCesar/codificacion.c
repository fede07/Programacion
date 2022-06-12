#include "codificacion.h"
#include <stdio.h>

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
    char *iniCad=cadena;
    int numero = ('Z'-'A'+1); ///26
    desplazamiento=desplazamiento%numero;
    if(desplazamiento>0)
    {
        while(*cadena)
        {
            if(ESLETRA(*cadena))
                *cadena+=((AMINUS(*cadena)+desplazamiento)>'z')?desplazamiento-numero:desplazamiento;
            cadena++;
        }
    }
    else if(desplazamiento<0)
    {
        while(*cadena)
        {
            if(ESLETRA(*cadena))
                *cadena+= ((AMAYUS(*cadena)+desplazamiento)<'A')?desplazamiento+numero:desplazamiento;
            cadena++;
        }
    }
    return iniCad;
}

char* decodificarCesar(char *cadena, int desplazamiento)
{
    char *iniCad=cadena;
    int numero = ('Z'-'A'+1); ///26
    desplazamiento=desplazamiento%numero;
    if(desplazamiento>0)
    {
        while(*cadena)
        {
            if(ESLETRA(*cadena))
                *cadena-=((AMINUS(*cadena)-desplazamiento)<'a')?desplazamiento-numero:desplazamiento;
            cadena++;
        }
    }
    else if(ESLETRA(*cadena))
    {
        while(*cadena)
        {
            if(ESLETRA(*cadena))
                *cadena-=((AMAYUS(*cadena)-desplazamiento)>'Z')?desplazamiento+numero:desplazamiento;
            cadena++;
        }
    }
    return iniCad;
}

//char* codificarACesarCondicionado(char *cadena, int desplazamiento)
//{
//    ///TAM = 5
//    char *iniCad=cadena;
//    char codigo[TAM+1]={"aeiou"};
//    int numero = TAM;
//    desplazamiento=desplazamiento%numero;
//    if(desplazamiento>0)
//    {
//        while(*cadena)
//        {
//            if(*cadena == letra)///Hay que hacer una funcion
//                *cadena+=((AMINUS(*cadena)+desplazamiento)>'z')?desplazamiento-numero:desplazamiento;
//            cadena++;
//        }
//    }
//    else if(desplazamiento<0)
//    {
//        while(*cadena)
//        {
//            if(*cadena == letra)
//                *cadena+= ((AMAYUS(*cadena)+desplazamiento)<'A')?desplazamiento+numero:desplazamiento;
//            cadena++;
//        }
//    }
//    return iniCad;
//}
//
//char* decodificarCesarCondicionado(char *cadena,char letra, int desplazamiento)
//{
//    char *iniCad=cadena;
//    char codigo[6]={"aeiou"};
//    int numero = ('Z'-'A'+1); ///26
//    desplazamiento=desplazamiento%numero;
//    if(desplazamiento>0)
//    {
//        while(*cadena)
//        {
//            if(*cadena==letra)
//                *cadena-=((AMINUS(*cadena)-desplazamiento)<'a')?desplazamiento-numero:desplazamiento;
//            cadena++;
//        }
//    }
//    else if(desplazamiento<0)
//    {
//        while(*cadena)
//        {
//            if(*cadena ==letra)
//                *cadena-=((AMAYUS(*cadena)-desplazamiento)>'Z')?desplazamiento+numero:desplazamiento;
//            cadena++;
//        }
//    }
//    return iniCad;
//}
