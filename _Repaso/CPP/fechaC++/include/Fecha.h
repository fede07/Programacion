#ifndef FECHA_H
#define FECHA_H

#include <iostream>

using namespace std;

class Fecha
{
    private:
        int dia;
        int mes;
        int anio;

        ///no se puede enviar Fecha porque todavia no esta creada
        int validaFecha(int, int, int);
        int cantDiaMesValida (int, int, int);

    public:
        Fecha();
        Fecha(int, int, int);///d,m,a
        Fecha(int);///fecha sin separaciones, hay que fragmentarla
        Fecha(const Fecha&);
        ~Fecha();

        unsigned int getdia();
        void setdia(unsigned int val);
        Fecha& getfecha();
        void setfecha(unsigned int dia, unsigned int mes, unsigned int anio);
        void getFecha(int& dia, int& mes, int& anio) const;

        Fecha operator + (int dias) const;
        Fecha& operator ++ ();///pre
        Fecha operator ++ (int);///pos
        Fecha& operator +=(int dias);


};

ostream& operator << (ostream&, const Fecha&);
istream& operator >> (istream&, Fecha&);

#endif // FECHA_H
