#include <cmath>
#include "Recta.h"

Recta::Recta(const Punto& p1, const Punto& p2) : p1(p1), p2(p2)
{}

double Recta::operator - (const Punto& punto)
{
    double modulo;
    double raiz;
    double x1, y1, x2, y2, x0, y0;
    x1 = this->p1.getX();
    x2 = this->p2.getX();
    x0 = punto.getY();
    y1 = this->p1.getY();
    y2 = this->p2.getY();
    y0 = punto.getY();

    modulo = abs((y2-y1)*x0-(x2-x1)*y0 + x2*y1 - y2*x1);
    raiz = sqrt (pow((y2-y1),2)+pow((x2-x1),2));

//    modulo = abs( ((this->p2.getY()) - (this->p1.getY()) )*punto.getX() -  ((this->p2.getX()) - (this->p1.getX()))*punto.getY() + (this->p2.getX())*(this->p1.getY()) - (this->p2.getY())*(this->p1.getX()) );
//    raiz = sqrt( pow(((this->p2.getX()) - (this->p1.getX()),2) + pow(((this->p2.getX()) - (this->p1.getX()),2) );
    return modulo/raiz;
}

Punto Recta::operator && (const Recta& r2) const
{
///    Punto punto( (this->p1).x + (r2->p1).x,  (this->p1).y + (r2->p1).y);
///    Punto punto( this->p1.getX() + r2->p1.getX(),  this->p1.getY() + r2->p1.getY()) ;
    double x1,x2,y1,y2;
    x1 = this->p1.getX();
    x2 = r2.p1.getX();
    y1 = this->p1.getY();
    y2 = r2.p1.getY();

    x1+=x2;
    y1+=y2;

    Punto punto(x1, y1);

    return punto;
}



ostream& operator << (ostream& sal, const Recta& recta)
{
    double x1,x2,y1,y2;
    x1 = recta.p1.getX();
    x2 = recta.p2.getX();
    y1 = recta.p1.getY();
    y2 = recta.p2.getY();

    return sal << "(" << x1 << "," << y1 << ") (" << x2 << "," << y2 << ")";
}






