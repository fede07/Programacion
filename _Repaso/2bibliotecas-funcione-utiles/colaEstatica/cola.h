#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#define TAM_COLA 24
#define MIN(x,y) ((x)<(y)?(x):(y))

typedef struct
{
    char vec[TAM_COLA];
    unsigned pri;
    unsigned ult;
    unsigned tamDisponible;
}t_cola;


void crearCola(t_cola *cola);
int colaVacia(const t_cola *cola);
int colaLlena(const t_cola *cola, unsigned tamBy); ///es por el tamaño que ocupa la variable, como es una estructura paso la direccion para copiar la menor cantidad posible. el unsigned ocupa la misma cant q un puntero por eso lo paso por copia
int ponerEnCola(t_cola *cola, void *info, unsigned tamBy);
int sacarDeCola(t_cola *cola, void *info, unsigned tamBy);
void vaciarCola(t_cola *cola);
int verPriCola(const t_cola *cola, void *info, unsigned tamBy);

#endif // COLA_H_INCLUDED
