#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED

///devuelve positivo si la primer cadena es mayor, 0 si es igual, negativo si es menor
int mi_strcmp (const char *, const char*);
///copia s2 en s1 incluyendo el caracter nulo (pisa s1)
char * mi_strcpy(char *, const char *);
///agrega s2 a lo de s1, poniendo el primer valor en el \0
char *mi_strcat(char*,const char *);
///dice cuantos caracteres tiene la cadena sin contar el nulo
int mi_strlen(const char *);
///convierte una letra a mayuscula, si recibe otro caracter no le hace nada
int mi_toupper(char);
///convierte una letra a minuscula, si recibe otro caracter no le hace nada
int mi_tolower(char);
///propia de c++? convierte toda la cadena a mayuscula
char * mi_strupr (char *);
///propia de c++? convierte toda la cadena a minuscula
char * mi_strlwr (char *);
///devuelve la posicion de la primera ocurrencia de c, sino devuelve un NULL
char *mi_strchr(char *, int );
///devuelva la ultima ocurrencia de c, sino devuelve NULL
char * mi_strrchr (char *str, int c);
///busca s2 en s1, y devuelve esa posicion
char *mi_strstr(const char *,const char *);

int sinRepeticion (char *, char *);
int conRepeticion (char *, char *);

int esAnagrama (const char * cadena1, const char * cadena2);
int hayLetras (const char * cadena);
int buscarCaracter (char letra, char * copia);



#endif // CADENAS_H_INCLUDED
