#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

#define TAM 100

#define ESBLANCO(X)     ((X)==' ')
#define ESLETRA(X)      (((X)>='a' && (X)<='z')||((X)>='A' && (X)<='Z'))
#define ESMAYUS(X)      ((X)>='A' && (X)<='Z')
#define ESMINUS(X)      ((X)>='a' && (X)<='z')
#define AMAYUS(X)       ((X)>='a'&&(X)<='z'?(X)=(X)-32:(X))
#define AMINUS(X)       ((X)>='A'&&(X)<='Z'?(X)=(X)+32:(X))

#define MINIMO(x,y)       ((x)<(y)?(x):(y))

#define MOSTRAR_PROD(X)   printf("%ld %s %d/%d/%d %d %.2f\n",(X).idProducto, (X).descripcion,(X).fecUltAct.dia,(X).fecUltAct.mes,(X).fecUltAct.anio,(X).cantidad,(X).precioUnitario)

#define ESCRIB_PROD(X,Y)   fprintf((Y),"%ld %s %d/%d/%d %d %.2f\n",(X).idProducto, (X).descripcion,(X).fecUltAct.dia,(X).fecUltAct.mes,(X).fecUltAct.anio,(X).cantidad,(X).precioUnitario)

typedef struct
{
    int dia,
        mes,
        anio;
}tFecha;

typedef struct
{
    long idProducto;
    char descripcion[26];
    tFecha fecUltAct;
    int cantidad;
    float precioUnitario;
}tProducto;

typedef struct
{
    long idProducto;
    char tipoMovimiento;
    int cantidad;
}tNovedad;

typedef struct s_nodo{
    void* info;
    unsigned cantBytes;
    struct s_nodo *sig;
}t_nodo;

typedef struct{
    t_nodo *pri;
    t_nodo *ult;
}t_cola;

void crearCola(t_cola* cola);
int colaVacia(t_cola* cola);
int colaLlena(t_cola* cola, unsigned cantBytes);
int ponerEnCola(t_cola* cola, void* info, unsigned cantBytes);
int sacarDeCola(t_cola* cola, void* info, unsigned cantBytes);
int verPrim(t_cola* cola, void* info, unsigned cantBytes);

void *memmove_MIO(void *str1, const void *str2, size_t n);
char* normalizar(char* cadena);

int parseo(char* cadena, tProducto *producto);
int mergeArchs();

int eliminarDupes();

#endif // FUNCIONES_H_INCLUDED
