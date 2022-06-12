#ifndef COLAESTATICA_H_INCLUDED
#define COLAESTATICA_H_INCLUDED

#define TAM_COLA 24

#define MIN(x,y) ((x)<=(y)?(x):(y))

typedef struct{
    char iniCola[TAM_COLA];
    unsigned pri;
    unsigned ult;
    unsigned tamDisp;
}t_cola;

void crearCola (t_cola *cola);
int colaVacia(const t_cola *cola);
int colaLlena(const t_cola *cola, unsigned cantBytes);
int ponerEnCola(t_cola* cola, void* dato, unsigned cantBytes);
int sacarDeCola(t_cola* cola, void* dato, unsigned cantBytes);
void vaciarCola(t_cola* cola);
int verPrim(const t_cola* cola, void* dato, unsigned cantBytes);

#endif // COLAESTATICA_H_INCLUDED
