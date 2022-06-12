#ifndef CODIFICACIONT_H_INCLUDED
#define CODIFICACIONT_H_INCLUDED

char* invertirPalabra(char* cad);
char* proximaPalabra(char* cad);
char* invertirCadena(char* cad);
char* codificar(char* cad, char* codigo, int desp);
void decodificar (char* cadena, FILE* pf, FILE* salida, char* codigo, int despl, int tam);

#endif // CODIFICACIONT_H_INCLUDED
