#include <stdio.h>
#include <stdlib.h>
#define TAM 3

#define ESLETRA(x)  (((x)>='a'&&(x)<='z')||((x)>='A'&&(x)<='Z'))

#define ESNUMERO(x) ((x)>='0'&&(x)<='9')

#define ESMAYUS(x)  ((x)>='A'&&(x)<='Z')

#define ESMINUS(x)  ((x)>='a'&&(x)<='z')

#define AMAYUS(x)   ((x)>='a'&&(x)<='z'?(x)-32:(x)) /// Sin verificación: AMAYUS(x) (x)-('a'-'A')

#define AMINUS(x)   ((x)>='A'&&(x)<='Z'?(x)+32:(x)) /// Sin verificacion: AMINUS(x) (x)+('a'-'A')

#define ESBLANCO(X) (((X)==' ')||((X)=='\n')||((X)=='\t'))

#define ESNULL(x)   ((x)==0)

int crearLoteDePrueba(FILE** pf)
{
    int i;
    char doc[TAM][20]={"Hola mundo!\n","FUNCIONA\n","Otra cosa\n"};
    if(!*pf)
        return 0;
    for(i=0;i<TAM;i++)
    {
        fputs(doc[i],*pf);
    }
    return 1;
}

char* proximaPalabra(char *cadena, char *finalPal)
{
    char* inicioPal, finalPal;
    while(ESBLANCO(*cadena)||!(ESLETRA(*cadena)))
    {
        cadena++;
    }
    return cadena;
}

char* invertir(char* iniCad, char *finCad)
{
    while(iniCad!=finCad)
    {

    }
}
