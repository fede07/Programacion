#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

#define MIN(x,y) ((x)<(y))?(x):(y)
typedef struct
{
    unsigned cod;
    int cant;
}t_prod;





typedef struct s_nodo
{
    void * dato;
    unsigned tam;
    struct s_nodo* sig;
}t_nodo;

typedef t_nodo* t_lista;

void crearLista (t_lista *);

int insertarAlFinal (t_lista *, const void*, unsigned);
int insertarAlInicio (t_lista *, const void*, unsigned);
int instertarEnPos (t_lista *lista,void* dato, unsigned tam, unsigned pos);
int insertarOrdenado(t_lista *lista, const void *info, unsigned tamBy, int(*comp)(const void*,const void*),int duplicado);

void recorrer(t_lista*,void(*accion)(const void *));///recorre de izquierda a derecha
void recorrerFin(t_lista*,void(*accion)(const void *));///recorre de derecha a izquierda

void vaciarLista (t_lista *);
void filtrar(t_lista*,int(*fFiltro)(const void*));///el valor de comparacion se hardcodea
int eliminar (t_lista *, void * dato, unsigned);///elimina el primer nodo
int elimNult (t_lista *, unsigned);///elimina los N ultimos nodos
int elimNprim (t_lista *, unsigned);///elimina los N primeros nodos
int elimXDup (t_lista *, void *,int(*comparar)(const void *, const void *));///elimina todos los nodos iguales a X menos el primero
int elimDupOrd (t_lista *,int(*comparar)(const void *, const void *));///lista ordenada: elimina todos los duplicados dejando solo la primer aparicion de cada uno
int elimDup (t_lista * lista,int(*comparar)(const void *, const void *));///elimina todos los duplicados dejando solo la primer aparicion de cada uno
int elimYAcumOrd (t_lista * lista,int(*comparar)(const void *, const void *),void*(*acumulacion)(void *, void *));
int eliminarDuplicadosListaOrdenadaAcum (t_lista * lista,int(*comparar)(const void *, const void *), void*(*acumulacion)(void *, void *));

int buscarEnListaOrd (t_lista *, void * dato, int(*comparar)(const void *, const void *));
int buscarEnLista(t_lista * lista, void * info, int(*comparar)(const void *, const void *));
t_lista * buscarMenor (t_lista * lista, int(*comparar)(const void *, const void *));
void ordenarMenMayNodo (t_lista *, int(*comparar)(const void *, const void *));
void ordenarMenMayDato(t_lista *, int(*comparar)(const void *, const void *));

void* acumularLista(t_lista *lista,void *acum, void*(*acumulacion)(void *, void *));

///RECURSIVAS
void vaciarListaRec (t_lista * lista);
int elimNultRec (t_lista * lista, unsigned cant);
int elimNprimRec (t_lista * lista, unsigned cant);
int elimDupEnv (t_lista * lista,int(*comparar)(const void *, const void *));
int elimDupRec (void * actual, t_lista * lista, int(*comparar)(const void *, const void *));
int elimDupOrdRec(void * actual, t_lista * lista, int(*comparar)(const void *, const void *));
int elimDupOrdEnv (t_lista * lista,int(*comparar)(const void *, const void *));
int elimXnodoEnv (t_lista * lista, void *, unsigned tamBy, int(*comparar)(const void *, const void *));

void recorrerFinRec(t_lista*,void(*accion)(const void *));
void recorrerIniRec(t_lista* lista, void(*accion)(const void *));

int insertarOrdenadoRec(t_lista* lista, void* info, unsigned tamBy, int(*comparar)(const void*, const void*));
int insertarAlFinalRec(t_lista * lista, const void*info,unsigned cantBy);
int insertarEnPosRec(t_lista * lista, const void*info,unsigned cantBy, unsigned pos);

void ordenarMenMayDatoRec(t_lista *, int(*comparar)(const void *, const void *));
void ordenarMayMenDatoRec(t_lista * lista, int(*comparar)(const void *, const void *));

t_lista * buscarNodoEnListaRec(t_lista * lista, void * info, int(*comparar)(const void *, const void *));
int buscarEnListaRec(t_lista * lista, void * info, int(*comparar)(const void *, const void *));
int buscarEnListaOrdRec(t_lista * lista, void * info, int(*comparar)(const void *, const void *));
t_lista * buscarMayEnv(t_lista * lista, int(*comparar)(const void *, const void *));
t_lista * buscarMayRec (t_lista * mayor, t_lista * siguiente, int(*comparar)(const void *, const void *));
t_lista * buscarMenEnv(t_lista * lista, int(*comparar)(const void *, const void *));
t_lista * buscarMenRec (t_lista * menor, t_lista * siguiente, int(*comparar)(const void *, const void *));

int actualizarDatosRec (t_lista * lista , void * dato,int(*comparar)(const void *, const void *),void*(*acumulacion)(void *, void *));
void* acumularListaRec (t_lista*lista,void*acumulador,void*(*acumulacion)(void*,void*));
void filtrarRec (t_lista* lista,int(*fFiltro)(const void*));
void promedioCond (t_lista * lista, void * acum, void * prom, int fFiltro(const void* a),void* (*acumular)(void * acum, void *n), void (*promedio)(void * prom, const void * acum, const void * cant));
int promedioCondRec (t_lista * lista, void * acum, int fFiltro(const void* a),void* (*acumular)(void * acum, void *n));



#endif // LISTASIMPLE_H_INCLUDED


















