#ifndef FECHA_H
#define FECHA_H

#include <iostream>

#define ANIO_INI 1601

using namespace std;

class Fecha
{
    private:
        unsigned int dia;
        unsigned int mes;
        unsigned int anio;

        int esBisiesto(unsigned int anio);
        int validarCantD(unsigned int dia, unsigned int mes, unsigned int anio);
        int validarDia(unsigned int dia, unsigned int mes);
        int validarMes(unsigned int mes);
        int validarFecha(unsigned int dia, unsigned int mes, unsigned int anio);

    public:
        Fecha();
        Fecha(unsigned, unsigned, unsigned);
        Fecha(unsigned);
        Fecha(const Fecha&);

        ~Fecha();

        unsigned getDia();
        void setDia(int _dia);
        unsigned int getMes();
        void setMes(int _mes);
        unsigned int getAnio();
        void setAnio(int _anio);
        void setDia(unsigned int _dia);
        Fecha& getFecha();
        void setFecha(unsigned int _dia, unsigned int _mes, unsigned int _anio);
        void getFecha(unsigned *dia, unsigned *mes, unsigned *anio) const;


        Fecha operator + (int dias) const;
        Fecha& operator++(); //PRE
        Fecha operator ++ (int);//POS
        Fecha operator += (int dias);
};

ostream& operator << (ostream& salida, const Fecha& fecha);
istream& operator >> (istream& entrada, Fecha& fecha);

#endif // FECHA_H
