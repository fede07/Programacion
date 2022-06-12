#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ESNUMERO(x) (((x)>='0')&&((x)<='9'))
#define ESBLANCO(x) ((x)==' '||(x)=='\n'||(x)=='\t')
#define ESSIGNO(x)  (((x)=='-')||((x)=='+'))
#define ANUMERO(x)  ((x)-'0')

int cadenaAIntATOI(const char*);

int main()
{
    char *cadena1=("1234");
    char *cadena2=("-1234");
    char *cadena3=("\n1234");
    char *cadena4=("\t1234");
    char *cadena5=("\n-1234");
    char *cadena6=("\t-1234");
    char *cadena7=("  aa1234");
    char *cadena8=("  1234aaaa");
    char *cadena9=("    -123A465");
    char *cadena10=("");
    char *cadena11=("  - 1234");
    char *cadena12=("A+A1234");

    printf("\n\nCadena: *%s*", cadena1);
    printf("\nATOI: *%d*", atoi(cadena1));
    printf("\ncadenaAInt: *%d*", cadenaAIntATOI(cadena1));

    printf("\n\nCadena: *%s*", cadena2);
    printf("\nATOI: *%d*", atoi(cadena2));
    printf("\ncadenaAInt: *%d*", cadenaAIntATOI(cadena2));

    printf("\n\nCadena: *%s*", cadena3);
    printf("\nATOI: *%d*", atoi(cadena3));
    printf("\ncadenaAInt: *%d*", cadenaAIntATOI(cadena3));

    printf("\n\nCadena: *%s*", cadena4);
    printf("\nATOI: *%d*", atoi(cadena4));
    printf("\ncadenaAInt: *%d*", cadenaAIntATOI(cadena4));

    printf("\n\nCadena: *%s*", cadena5);
    printf("\nATOI: *%d*", atoi(cadena5));
    printf("\ncadenaAInt: *%d*", cadenaAIntATOI(cadena5));

    printf("\n\nCadena: *%s*", cadena6);
    printf("\nATOI: *%d*", atoi(cadena6));
    printf("\ncadenaAInt: *%d*", cadenaAIntATOI(cadena6));

    printf("\n\nCadena: *%s*", cadena7);
    printf("\nATOI: *%d*", atoi(cadena7));
    printf("\ncadenaAInt: *%d*", cadenaAIntATOI(cadena7));

    printf("\n\nCadena: *%s*", cadena8);
    printf("\nATOI: *%d*", atoi(cadena8));
    printf("\ncadenaAInt: *%d*", cadenaAIntATOI(cadena8));

    printf("\n\nCadena: *%s*", cadena9);
    printf("\nATOI: *%d*", atoi(cadena9));
    printf("\ncadenaAInt: *%d*", cadenaAIntATOI(cadena9));

    printf("\n\nCadena: *%s*", cadena10);
    printf("\nATOI: *%d*", atoi(cadena10));
    printf("\ncadenaAInt: *%d*", cadenaAIntATOI(cadena10));

    printf("\n\nCadena: *%s*", cadena11);
    printf("\nATOI: *%d*", atoi(cadena11));
    printf("\ncadenaAInt: *%d*", cadenaAIntATOI(cadena11));

    printf("\n\nCadena: *%s*", cadena12);
    printf("\nATOI: *%d*", atoi(cadena12));
    printf("\ncadenaAInt: *%d*", cadenaAIntATOI(cadena12));


    return 0;
}

int cadenaAIntATOI(const char *cadena)
{
    int valor = 0, signo=1;
    char *lectura=(char*)cadena;
    while(ESBLANCO(*lectura))
    {
        lectura++;
    }
    if(ESSIGNO(*lectura))
    {
        (*lectura=='+')?(signo=1):(signo=-1);
        lectura++;
    }
    while(ESNUMERO(*lectura))
    {
        valor*=10;
        valor+=(ANUMERO(*lectura));
        lectura++;
    }
    valor*=signo;
    return valor;
}
