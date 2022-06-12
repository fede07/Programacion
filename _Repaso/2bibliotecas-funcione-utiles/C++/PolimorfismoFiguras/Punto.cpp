#include <math.h>

#include "Punto.h"

                ///seria similar a this->x = x
Punto::Punto(double x, double y): x(x), y(y)
{}

///calcula la distancia entre dos coordenadas
double Punto::operator -(const Punto& otro) const
{
	double catetoX = this->x - otro.x;
	double catetoY = this->y - otro.y;
	return sqrt(catetoX * catetoX + catetoY * catetoY);
}
