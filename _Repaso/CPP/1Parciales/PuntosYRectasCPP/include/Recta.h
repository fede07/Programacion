#ifndef RECTA_H
#define RECTA_H

#include "Punto.h"

class Recta
{
    private:
        Punto p1;
        Punto p2;

    public:
        Recta(const Punto&, const Punto&);

        double operator - (const Punto&);
        Punto operator && (const Recta&) const;
        friend ostream& operator << (ostream&, const Recta&);
};

#endif // RECTA_H
