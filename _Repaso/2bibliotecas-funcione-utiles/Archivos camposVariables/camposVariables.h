#ifndef CAMPOSNOVARIABLES_H_INCLUDED
#define CAMPOSNOVARIABLES_H_INCLUDED

#define TODO_OK 1
#define ERROR_ARCH 0
#define TAM 9
#define LARGO 38

typedef struct{
char nyap[30];
int dni;
char estado;
float puntuacion;
}t_animo;

int crearLote();
int abrirArchivo(FILE **,char *,char *);
int parseo(char *,t_animo *);

#endif // CAMPOSNOVARIABLES_H_INCLUDED
