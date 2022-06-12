#ifndef PARCIAL_H_INCLUDED
#define PARCIAL_H_INCLUDED

#include <stdio.h>

#define ESLETRA(x) ((x)>='a' && (x)<='z')|| ((x)>='A' && (x)<='Z')
#define ESBLANCO(x) ((x)==' ' || x=='\n' || (x)=='\t')
#define AMAYUS(x) ((x)>='a' && (x)<='z')?((x)-('a' - 'A')):(x)
#define AMINUS(x) ((x)>='A' && (x)<='Z')?((x)+('a' - 'A')):(x)

#define MIN(x,y) ((x)<(y)?(x):(y))

#define ABS(x) ((x)<0?(x)*(-1):(x))


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

typedef struct snodo
{
    void *dato;
    unsigned tam;
    struct snodo *sig;

}t_nodo;

typedef struct
{
    t_nodo *pri;
    t_nodo *ult;
}t_cola;

///punto 1
void *memmove2 (void *s1, const void *s2, size_t n);

///punto 2
int fusionArchivos ();
char * normalizar (char *);

///primitivas cola para el punto 3
void crearCola(t_cola *cola);
int colaVacia(const t_cola *cola);
int colaLlena(const t_cola *cola, unsigned tamBy); ///es por el tamaño que ocupa la variable, como es una estructura paso la direccion para copiar la menor cantidad posible. el unsigned ocupa la misma cant q un puntero por eso lo paso por copia
int agregarEnCola(t_cola *cola, void *info, unsigned tamBy);
int sacarDeCola(t_cola *cola, void *info, unsigned tamBy);
int verPriCola(const t_cola *cola, void *info, unsigned tamBy);
void vaciarCola(t_cola *cola);
///
int elimDupl ();

///
int eliminarNult(unsigned cantidad);

///punto 5
int actualizar();



#endif // PARCIAL_H_INCLUDED
