#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED

char* aMayusculaString(char*);
char* aMinusculaString(char*);
char* copiarString(char*, const char*);
char* concatenarString(char*, const char*);
int compararString (const char*, const char*);
int compararStringIg (const char*, const char*);
unsigned longitudString (const char*);
int aMayuscula(int ch);
int aMinuscula(int ch);
char* primerAparicionEnString(char*, int);
char* primerAparicionDeStringEnString(const char *,const char*);
char* ultimaAparicionEnString(const char*, int);

int encontrada(char*, char*);
char* buscarSubCadena(char*,char*);

void* memcpy_MI(void*, const void*, size_t);


#endif // CADENA_H_INCLUDED
