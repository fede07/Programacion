#include "fecha.h"
#include "fechaexception.h"

Fecha::Fecha()
{
    this->dia = 1;
    this->mes = 1;
    this->anio = ANIO_INI;
}

Fecha::Fecha(unsigned _dia, unsigned _mes, unsigned _anio)
{
    setFecha(_dia, _mes, _anio);
}

Fecha::Fecha(unsigned fechaLarga)
{
    this->dia = fechaLarga/1000000;
    this->mes = (fechaLarga%1000000)/10000;
    this->anio = fechaLarga%1000000;
}

Fecha::Fecha(const Fecha& fecha)
{
    setFecha(fecha.dia, fecha.mes, fecha.anio);
}
Fecha::~Fecha()
{
    //dtor
}

int Fecha::esBisiesto(unsigned int anio)
{
    return((anio%4 ==0 && anio%100!=0) || anio%400==0);
}

int Fecha::validarCantD(unsigned int dia, unsigned int mes, unsigned int anio)
{
    switch(dia)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        return dia<=30;
        break;
    case 2:
        return ((int)dia<=(28+esBisiesto(anio)));
    }
    return 1;
}

int Fecha::validarDia(unsigned int dia, unsigned int mes)
{
    return (dia>=1 && dia<=31);
}

int Fecha::validarMes(unsigned int mes)
{
    return (mes>=1 && mes<= 12);
}

int Fecha::validarFecha(unsigned int dia, unsigned int mes, unsigned int anio)
{
    if(anio < ANIO_INI || !validarMes(mes) || !validarDia(dia, mes))
    {
        return 0;
    }

    return validarCantD(dia, mes, anio);
}

unsigned Fecha::getDia()
{
    return this->dia;
}

void Fecha::setDia(unsigned int _dia)
{
    this->dia = _dia;
}

Fecha& Fecha::getFecha()
{
    return *this;
}

void Fecha::setFecha(unsigned int _dia, unsigned int _mes, unsigned int _anio)
{
    if(!validarFecha(_dia, _mes,_anio))
    {
        throw FechaException("Fecha Invalida");
    }
    this->dia = _dia;
    this->mes = _mes;
    this->anio = _anio;
}

void Fecha::getFecha(unsigned *dia, unsigned *mes, unsigned *anio) const
{
    *dia= this->dia;
    *mes = this->mes;
    *anio = this->anio;
}

///SOBRECARGA OPERADORES

Fecha Fecha::operator + (int dia) const
{
    Fecha tempFecha(*this);
    tempFecha.dia+=dia;
    return tempFecha;
}

Fecha& Fecha::operator++() //PRE
{
    ++this->dia;
    return *this;
}
Fecha Fecha::operator ++ (int)//POS
{
    Fecha tempFecha(*this);
    this->dia++;
    return tempFecha;

}

Fecha Fecha::operator += (int dias)
{
    Fecha tempFecha(*this);
    this->dia+=dias;
    return *this;
}

ostream& operator << (ostream& salida, const Fecha& fecha)
{
    unsigned dia, mes, anio;
    fecha.getFecha(&dia, &mes, &anio);
    return salida <<dia<<'/'<<mes<<'/'<<anio;
}
istream& operator >> (istream& entrada, Fecha& fecha)
{
    int dia, mes, anio;
    entrada>>dia>>mes>>anio;
    fecha.setFecha(dia,mes,anio);

    return entrada;
}
