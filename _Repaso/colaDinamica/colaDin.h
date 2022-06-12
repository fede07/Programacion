#ifndef COLADIN_H_INCLUDED
#define COLADIN_H_INCLUDED

typedef struct s_nodo{
    void* dato;
    unsigned tambyte;
    struct s_nodo* sig;
}t_nodo;

typedef struct{
    t_nodo* pri;
    t_nodo* ult;
}t_cola;

void crearCola (t_cola *cola);
int colaVacia(const t_cola *cola);
int colaLlena(const t_cola *cola, unsigned tamBytes);
int ponerEnCola(t_cola* cola, void* dato, unsigned tamBytes);
int sacarDeCola(t_cola* cola, void* dato, unsigned tamBytes);
void vaciarCola(t_cola* cola);
int verPrim(const t_cola* cola, void* dato, unsigned tamBytes);

#endif // COLADIN_H_INCLUDED
