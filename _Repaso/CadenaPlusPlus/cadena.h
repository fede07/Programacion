#ifndef CADENA_H
#define CADENA_H

#include <iostream>
#include <string.h>

using namespace std;

class Cadena
{
    private:
        char* cadena;
        Cadena(char*);

    public:
        Cadena();
        Cadena(const char*);
        Cadena(const Cadena&);
        unsigned longitud();

        Cadena& operator = (const Cadena& otraCad);
        friend Cadena operator + (const Cadena& cad1, const Cadena& cad2);
        friend ostream& operator <<(ostream& salida, const Cadena& cadena);
        friend istream& operator >>(istream& entrada, const Cadena& cadena);
};

#endif // CADENA_H
