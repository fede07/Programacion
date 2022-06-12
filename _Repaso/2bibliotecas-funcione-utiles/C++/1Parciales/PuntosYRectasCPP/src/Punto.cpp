#include "Punto.h"

Punto::Punto(double x, double y) : x(x), y(y)
{}

ostream& operator << (ostream& sal, const Punto& punto)
{
    return sal << "(" << punto.x << "," << punto.y << ")";
}

double Punto::getX () const
{
    return this->x;
}

double Punto::getY () const
{
    return this->y;
}
