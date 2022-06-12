#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int evaluarExpresion(char *cad)
{
    t_pila pila;
    crearPila(&pila);
    char valor;

    while(*cad)
    {
        if((*cad == '{') || (*cad =='[') || (*cad == '('))
        {
            ponerEnPila(&pila, cad, sizeof(*cad));
            verTope(&pila,&valor,sizeof(char));
            printf("%c",valor);
        }
        else if ((*cad == '}') || (*cad ==']') || (*cad == ')'))
        {
            if(sacarDePila(&pila, &valor, sizeof(valor)))
            {
                if((valor == '{' && *cad!='}') || (valor == '[' && *cad!=']') || (valor == '(' && *cad!=')'))
                {
                    vaciarPila(&pila);
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
        cad++;
    }

    if(!pilaVacia(&pila))
    {
        vaciarPila(&pila);
        return 0;
    }

    return 1;
}

char sumar (char valorPila1, char valorPila2, char * acarreo)
{
    char suma;
    suma = valorPila1 + valorPila2 - '0' + *acarreo;
    if(suma > '9')
    {
        suma -= 10;
        *acarreo = 1;
    }
    else
    {
        *acarreo = 0;
    }
    return suma;
}

void numExtra (t_pila * p, char * acarreo, t_pila * res)
{
    char valor;
    char suma;
    while(pilaVacia(p)==0 )
    {
        sacarDePila(p,&valor,sizeof(char));

        suma = sumar(valor,'0',acarreo);

        ponerEnPila(res,&suma,sizeof(char));
    }
}

///asumimos que las cadenas contienen SOLO numeros
char * sumarNGrandes (char * n1, char * n2, char * resultado)
{
    t_pila pilaN1;
    t_pila pilaN2;
    t_pila pilaRes;

    char valorPila1;
    char valorPila2;
    char suma;
    char acarreo = 0;
    char * iniRes = resultado;

    crearPila(&pilaN1);///creo las pilas
    crearPila(&pilaN2);
    crearPila(&pilaRes);

    while(*n1)///apilo los valores
    {
        ponerEnPila(&pilaN1,n1,sizeof(char));
        n1++;
    }
    while(*n2)
    {
        ponerEnPila(&pilaN2,n2,sizeof(char));
        n2++;
    }

    ///mientras no esten vacias
    while(pilaVacia(&pilaN1)==0 && pilaVacia(&pilaN2)==0)
    {
        sacarDePila(&pilaN1,&valorPila1,sizeof(char));
        sacarDePila(&pilaN2,&valorPila2,sizeof(char));

        suma = sumar(valorPila1,valorPila2,&acarreo);

        ponerEnPila(&pilaRes,&suma,sizeof(char));
    }

    numExtra (&pilaN1,&acarreo,&pilaRes);

    numExtra (&pilaN2,&acarreo,&pilaRes);

    if(acarreo == 1)
    {
     ///   acarreo = '1';/// sin esto aparece pepito
        ponerEnPila(&pilaRes,&acarreo,sizeof(char));
    }

    while(!pilaVacia(&pilaRes))
    {
        sacarDePila(&pilaRes,resultado,sizeof(char));
        resultado++;
    }

    (*resultado)='\0';

    return iniRes;
}

int main()
{
//    char cadena[30]="{x+[2+n]+[5*w(2+x)]}";
//    if(evaluarExpresion(cadena))
//        printf("holi");

    char numero1[TAM]="9";
    char numero2[TAM]="1";
    char resultado[TAM+1];

    printf("<%s>",sumarNGrandes(numero1,numero2,resultado));

    return 0;
}
