#ifndef CESAR_H_INCLUDED
#define CESAR_H_INCLUDED

char* codificarACesar(char *cadena, int desplazamiento);
char* decodificarCesar(char *cadena, int desplazamiento);
void decodificar (char* cadena, FILE* pf, FILE* pfSalida, char* codigo, int despl, int tam);
char* codificar(char* cad, char* codigo, int desp);
char* invertirCadena(char* cad);
char* proximaPalabra(char* cad);
char* invertirPalabra(char* cad);

#endif // CESAR_H_INCLUDED
