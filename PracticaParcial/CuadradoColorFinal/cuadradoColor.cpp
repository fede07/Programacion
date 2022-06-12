#include "cuadradoColor.h"

Cuadrado::Cuadrado()
{
    this->lado = 1;
    this->color = "Blanco";
}

Cuadrado::Cuadrado(const Cuadrado& otro)
{
    this->setLado(otro.getLado());
    this->setColor(otro.getColor());
}

void Cuadrado::setLado(float lado)
{
    this->lado = lado;
}

float Cuadrado::getLado() const
{
    return this->lado;
}
void Cuadrado::setColor(const string& color)
{
    this->color = color;
}
const string Cuadrado::getColor() const
{
    return this->color;
}

Cuadrado& Cuadrado::operator=(float lado)
{
    this->lado = lado;

    return *this;
}

Cuadrado Cuadrado::operator++(int)
{
    Cuadrado temp(*this);
    this->lado++;
    return temp;
}

float Cuadrado::perimetro()
{
    return (this->lado)*4;
}

float Cuadrado::area()
{
    return (this->lado)*(this->lado);
}

void Cuadrado::mostrar()
{
    cout << "Color: " << this->getColor() << ", Lado: " << this->getLado() << endl;
}

ostream& operator <<(ostream& sal, const Cuadrado& otro)
{
    return sal << "Color: " << otro.getColor() << ", Lado: " << otro.getLado();
}

istream& operator >>(istream& ent, Cuadrado& otro)
{
    float lado;
    string color;

    cout << "Color: ";
    ent >> color;

    cout << "Lado: ";
    ent >> lado;

    otro.setLado(lado);
    otro.setColor(color);

    return ent;
}
