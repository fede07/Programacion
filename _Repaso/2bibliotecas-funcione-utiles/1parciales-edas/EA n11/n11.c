#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "n11.h"

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


///punto 2

void llenarMatrizConsecutiva(int matriz[][COLM],int fila, int colum)
{
    int i,j, contador=1;
    for(i=0; i<fila; i++)
        for(j=0; j<colum; j++)
        {
            matriz[i][j]=contador;
            contador++;
        }
}

void mostrarMatriz(int matriz[][COLM], int fila, int colum)
{
    int i,j;
    for(i=0; i<fila; i++)
    {
        for(j=0; j<colum; j++)
            printf("%d\t",matriz[i][j]);
        printf("\n");
    }
}

int rotarMatriz180(int matriz[][COLM], int fila, int colum)
{
    int i,j, temp,mitad=fila/2;
    for(i=0; i<mitad; i++) //si no funciono AGREGALE LA MITAD GEGE
    {
        for(j=0; j<colum; j++)
        {
            temp=matriz[i][j];
            matriz[i][j]=matriz[fila-i-1][colum-j-1];
            matriz[fila-i-1][colum-j-1]=temp;
        }
    }
    if(fila%2==1)
    {
        for(j=0; j<colum-j-1; j++)
        {
            temp=matriz[mitad][j];
            matriz[mitad][j]=matriz[mitad][colum-j-1];
            matriz[mitad][colum-j-1]=temp;
        }
    }
    return 1;
}

int mostrarTiangInfConDSec(int matriz[][COLM], int fila, int columna)
{
    int i, j, menor;
    ///if(fila==columna)

    menor = fila<columna?fila:columna;

    for(i=0; i<menor; i++)
    {
        ponerEspacios(menor-i-1);
        for(j=columna-i-1; j<columna; j++)
        {
            printf("%d\t",matriz[i][j]);
        }
        printf("\n");
    }

    if(i<fila)
    {
        for(i=i; i<fila; i++)
        {
            for(j=0; j<columna; j++)
                printf("%d\t",matriz[i][j]);
            printf("\n");
        }
    }

    ///else return 0;

    return 1;
}

void ponerEspacios(int cant)
{
    int veces=0;
    while(veces<cant&&cant!=0)
    {
        printf("\t");
        veces++;
    }
}



///punto 3
int leerYordenarArchivo(FILE * lect, t_pila * pila, compar cmp)
{
    t_pila pilaTemp;
    t_verso verso;///este es el leido del archivo
    t_verso versoTope;///este se usa para ver el tope o sacado de la pila
    crearPila(&pilaTemp);

    ///primero cantidad de palabras, despues palabra mas larga
    while(fgets(verso.oracion,sizeof(verso.oracion),lect))
    {
        cargarEstructura (&verso);
        if((pilaVacia(pila) || cmp(verso,versoTope)>0) && !pilaVacia(&pilaTemp))
        {
            while(!pilaVacia(pila) && cmp(verso,versoTope)>0)
            {
                sacarDePila(pila,&versoTope,sizeof(t_verso));
                ponerEnPila(&pilaTemp,&versoTope,sizeof(t_verso));
                if(!pilaVacia(pila))
                    verTope(pila,&versoTope,sizeof(t_verso));///veo el nuevo tope para comparar
            }
            ponerEnPila(pila,&verso,sizeof(t_verso));
        }
        else
        {
            verTope(&pilaTemp,&versoTope,sizeof(t_verso));
            while(!pilaVacia(&pilaTemp) && cmp(verso,versoTope)<0)
            {
                sacarDePila(&pilaTemp,&versoTope,sizeof(t_verso));
                ponerEnPila(pila,&versoTope,sizeof(t_verso));
                if(!pilaVacia(&pilaTemp))
                    verTope(&pilaTemp,&versoTope,sizeof(t_verso));
            }
            ponerEnPila(&pilaTemp,&verso,sizeof(t_verso));
        }
        if(!pilaVacia(pila))
            verTope(pila,&versoTope,sizeof(t_verso));
    }

    while(sacarDePila(&pilaTemp,&versoTope,sizeof(t_verso)))
    {
        ponerEnPila(pila,&versoTope,sizeof(t_verso));
    }

    return 1;
}

int comparaVerso(const t_verso a, const t_verso b)
{
    if(a.cantP == b.cantP)
        return a.mayLong - b.mayLong;
    return a.cantP - b.cantP;
}

void cargarEstructura (t_verso * verso)
{
    verso->cantP = contarPalabras (verso->oracion,&(verso->mayLong));
}

unsigned contarPalabras (const char * cadena, unsigned * mayLong)
{
    unsigned longAnterior=0;
    unsigned cantidadP=0;
    *mayLong = 0;

    while(*cadena)
    {
        while(ESLETRA(*cadena))
        {
            (*mayLong)++;///suma cada letra de cada palabra
            cadena++;
        }
        if(longAnterior < *mayLong)
            longAnterior = *mayLong;

        if(*mayLong != 0)///solo va a sumar palabras si encontro alguna letra
            cantidadP++;

        *mayLong = 0;
        cadena++;
    }

    *mayLong = longAnterior;

    return cantidadP;
}

void escribirArchivo (t_pila * pila)
{
    FILE * p;
    t_verso verso;
    p = fopen("resultado.txt","wt");

    if(!p)
    {
        while(sacarDePila(pila,&verso,sizeof(t_verso)))
        {
            printf("%s\n",verso.oracion);
        }
        printf("No se pudo crear el archivo");
    }
    else
    {
        while(sacarDePila(pila,&verso,sizeof(t_verso)))
        {
            ///a una oracion le falta el
            fprintf(p,"%s",verso.oracion);
        }
    }

    fclose(p);
}


void * memcpy2(void * destino, const void * origen,size_t tamanio)
{
    int i;
    void * iniDest = destino;
    for(i=0; i<tamanio; i++)
    {
        *((char*)destino) = *((char*)origen);
        destino++;
        origen++;
    }
    return iniDest;
}

void crearPila (t_pila * pila)
{
    pila->tope=TAM;
}

int ponerEnPila (t_pila * pila,void * dato,unsigned tamByte)
{
    if( (pila->tope < (sizeof(unsigned)+tamByte) ))///si no tiene espacio
        return 0;

    pila->tope-=tamByte;
    memcpy2(pila->iniPila + pila->tope, dato, tamByte);
    pila->tope-=sizeof(unsigned);
    memcpy2(pila->iniPila + pila->tope, &tamByte, sizeof(unsigned));

    return 1;
}

int verTope (const t_pila * pila,void * dato,unsigned tamByte)
{
    int tempTam;
    if(pila->tope == TAM)
        return 0;

    memcpy2(&tempTam, pila->iniPila+pila->tope, sizeof(unsigned));
    memcpy2(dato,pila->iniPila+pila->tope + sizeof(unsigned),MIN(tamByte,tempTam));

    return 1;
}

int sacarDePila(t_pila * pila,void * dato,unsigned tamByte)
{
    int tempTam;
    if(pila->tope == TAM)
        return 0;

    memcpy2(&tempTam, pila->iniPila+pila->tope, sizeof(unsigned));
    pila->tope += sizeof(unsigned);
    memcpy2(dato,pila->iniPila+pila->tope,MIN(tamByte,tempTam));
    pila->tope += tempTam;

    return 1;
}

int pilaVacia(const t_pila * pila)
{
    return pila->tope == TAM;
}

int pilaLlena(const t_pila * pila, unsigned tamByte)
{
    return pila->tope;
}


/*

void vaciarPila(t_pila *);
*/




































