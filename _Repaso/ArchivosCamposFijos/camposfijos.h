#ifndef CAMPOSFIJOS_H_INCLUDED
#define CAMPOSFIJOS_H_INCLUDED

#define ESBLANCO(x) ((x)==' '||(x)=='\t'||(x)=='\n')

typedef struct{
int dni;
char nyap[33];
char direccion[33];
int altura;
}t_alumno;

char * borrarBlancosExtras (char*);

int crearLote ();
int abrirArh(FILE **,char [], char []);
int dezglozamiento (char *, t_alumno *);



#endif // CAMPOSFIJOS_H_INCLUDED
