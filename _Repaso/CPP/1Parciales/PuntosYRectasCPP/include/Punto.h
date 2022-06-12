#ifndef PUNTO_H
#define PUNTO_H
#include <iostream>

using namespace std;

class Punto
{
    private:
        double x;
        double y;

    public:
        Punto(double x = 0, double y = 0);

        double getX () const;
        double getY () const;

        friend ostream& operator << (ostream&, const Punto&);
};



#endif // PUNTO_H
