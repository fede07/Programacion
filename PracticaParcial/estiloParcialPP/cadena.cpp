#include "cadena.h"

Cadena::Cadena()
{
    this->cadena = new char[1];
    this->cadena[0]='\0';
}

Cadena::Cadena(const char * nueCad)
{
    this->cadena = new char[strlen(nueCad)+1];
    strcpy(this->cadena, nueCad);
}

Cadena::Cadena(const Cadena& nueCad)
{
    this->cadena = new char[strlen(nueCad.cadena)+1];
    strcpy(this->cadena, nueCad.cadena);
}

unsigned Cadena::longitud()
{
    return strlen(this->cadena);
}

Cadena::Cadena(char* nueCad)
{
    this->cadena = nueCad;
}


Cadena& Cadena::operator =(const Cadena& otraCad)
{
    if(strlen(this->cadena)!= strlen(otraCad.cadena))
    {
        delete [] this->cadena;
        this->cadena = new char [strlen(otraCad.cadena)+1];
    }

    strcpy(this->cadena, otraCad.cadena);

    return *this;
}

Cadena operator + (const Cadena& cad1, const Cadena& cad2)
{
    char * cadTemp = new char[strlen(cad1.cadena) + strlen(cad2.cadena) + 1];
    strcpy(cadTemp, cad1.cadena);
    strcat(cadTemp, cad2.cadena);

    return Cadena(cadTemp);
}

ostream& operator <<(ostream& salida, const Cadena& cadena)
{
    return salida<<cadena.cadena;
}

istream& operator >>(istream& entrada, const Cadena& cadena)
{
    entrada>>cadena.cadena;

    return entrada;
}
