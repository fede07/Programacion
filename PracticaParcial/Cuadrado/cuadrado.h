#ifndef CUADRADO_H
#define CUADRADO_H

#include <iostream>

using namespace std;

class Cuadrado
{
    private:
        float lado;
        string color;

    public:
        Cuadrado();
        Cuadrado(const Cuadrado& otro);
        void setLado (const float lado);
        void setColor(const string color);

        Cuadrado operator++(int);
        Cuadrado& operator=(const float lado);

        float perimetro();
        float area();
        void mostrar();

        friend ostream& operator << (ostream& salida, const Cuadrado& otro);
        friend istream& operator >> (istream& entrada, Cuadrado& otro);

};

#endif // CUADRADO_H
