#include "cuadrado.h"

Cuadrado::Cuadrado()
{
    this->lado = 0;
    this->color = "Holy Pepito";
}

Cuadrado::Cuadrado(const Cuadrado& otro)
{
    this->lado = otro.lado;
    this->color = otro.color;
}

void Cuadrado::setLado (const float lado)
{
    this->lado = lado;
}

void Cuadrado::setColor(const string color)
{
    this->color = color;
}

Cuadrado Cuadrado::operator++(int)
{
    Cuadrado temp(*this);
    this->lado += 1;
    return temp;
}

Cuadrado& Cuadrado::operator=(const float lado)
{
    this->setLado(lado);
    return *this;
}

float Cuadrado::perimetro()
{
    return (this->lado * 4);
}

float Cuadrado::area()
{
    return (this->lado * this->lado);
}

void Cuadrado::mostrar()
{
    cout << "Lado: " << this->lado << endl;
    cout << "Color: " << this->color << endl;
}

ostream& operator <<(ostream& salida, const Cuadrado& otro)
{
    return salida << "Lado: " << otro.lado << ", Color: " << otro.color;
}

istream& operator >>(istream& entrada, Cuadrado& otro)
{
    float lado;
    string color;

    cout << "Ingrese Lado: ";
    entrada >> lado;

    cout << "Ingrese Color: ";
    entrada >> color;

    otro.setLado(lado);
    otro.setColor(color);

    return entrada;
}
