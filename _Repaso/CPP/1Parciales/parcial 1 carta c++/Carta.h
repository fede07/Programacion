#ifndef CARTA_H
#define CARTA_H
#include <iostream>
#include <string.h>

/**

Destinatario, Provincia y Precio. Donde Destinatario
y Provincia son atributos dinámicos y Precio es un atributo float
**/
using namespace std;
class Carta
{
    private:
        string destinario;
        string provincia;
        float precio;
    public:
        Carta ();
        Carta(const string, const string, float);
        Carta (Carta&);

        void actualizarPrecio(float);
        void setPrecio(float);
        string getDest();
        string getProv();
        float getPrecio();

        Carta& operator += (const float);
        Carta& operator = (const Carta&);
        Carta& operator ++ ();
        Carta operator ++ (int);

        friend ostream& operator << (ostream&, const Carta&);
        friend istream& operator >> (istream&, Carta&);
};




#endif // CARTA_H









