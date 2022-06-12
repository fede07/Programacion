#ifndef CUADRADOCOLOR_H
#define CUADRADOCOLOR_H

#include <iostream>
#include <string>

using namespace std;

class Cuadrado
{
    private:

        float lado;
        string color;

    public:
        Cuadrado();
        Cuadrado(const Cuadrado& otro);

        void setLado(float lado);
        float getLado() const;
        void setColor(const string& color);
        const string getColor() const;

        float perimetro();
        float area();
        void mostrar();

        Cuadrado operator++(int);
        Cuadrado& operator=(float lado);

        friend ostream& operator<< (ostream& sal, const Cuadrado& otro);
        friend istream& operator>> (istream& ent, Cuadrado& otro);

};

#endif // CUADRADOCOLOR_H
