#ifndef N11_H_INCLUDED
#define N11_H_INCLUDED

#define FILA 13
#define COLM 15
#define TAM 2000

#define MIN(x,y) ((x)<(y))?(x):(y)
#define ESLETRA(x) (((x)>='a' && (x)<='z') || ((x)>='A' && (x)<='Z'))

#define N printf("\n");

typedef struct
{
    char iniPila[TAM];
    unsigned tope;
}t_pila;

typedef struct
{
    char oracion[100];
    unsigned mayLong;
    unsigned cantP;
}t_verso;



void ponerEspacios(int);

///punto 1
int sinRepeticion (char *, char *);
int conRepeticion (char *, char *);

///punto 2
void llenarMatrizConsecutiva(int matriz[][COLM],int fila, int colum);
void mostrarMatriz(int matriz[][COLM], int fila, int colum);
int rotarMatriz180(int matriz[][COLM], int fila, int colum);
int mostrarTiangInfConDSec(int [][COLM], int, int);

///punto 3                ///compar para mandar la funcion
typedef int (*compar) (const t_verso, const t_verso);
int leerYordenarArchivo(FILE *, t_pila *,compar);
void * memcpy2(void *, const void *,size_t);
int comparaVerso(const t_verso, const t_verso);
void escribirArchivo (t_pila *);

unsigned contarPalabras (const char *, unsigned *);
void cargarEstructura (t_verso *);

void crearPila (t_pila *);
int ponerEnPila (t_pila *,void *,unsigned);
int verTope (const t_pila *,void *,unsigned);
int sacarDePila(t_pila *,void *,unsigned);
int pilaVacia(const t_pila *);
///int pilaLlena(const t_pila *,unsigned);
///void vaciarPila(t_pila *);

#endif // N11_H_INCLUDED
