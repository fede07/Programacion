#include "Fecha.h"
#include "FechaException.h"

#define DIAVALIDO(x) ((x)>=1 && (x)<=31)
#define MESVALIDO(x) ((x)>=1 && (x)<=12)
#define ANIOVALIDO(x) ((x)>=1601)
#define ESBISIESTO(x) (((x)%4==0 && (x)%100!=0) || (x)%400==0)

Fecha::Fecha()
{
    this->dia=1;
    this->mes=1;
    this->anio=1601;
}

Fecha::Fecha(int dia, int mes, int anio)
{
    this->setfecha(dia,mes,anio);
}

Fecha::Fecha(int fechaLarga)
{
    int dia, mes, anio;///las necesito para probar el throwExc antes de asignar valores
    dia = fechaLarga/1000000;
    mes = (fechaLarga%1000000)/10000;
    anio = fechaLarga%10000;

    if(!validaFecha(dia,mes,anio))
        throw FechaException("La fecha es invalida");

    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

Fecha::Fecha(const Fecha& fecha)
{
    this->setfecha(fecha.dia,fecha.mes,fecha.anio);
}

Fecha::~Fecha()
{
    //dtor
}

unsigned int Fecha::getdia()
{
    return this->dia;
}

void Fecha::setdia(unsigned int dia)
{
    if(!DIAVALIDO(dia))
        throw FechaException("La fecha es invalida");
    this->dia = dia;
}

Fecha& Fecha::getfecha()
{
    return *this;
}

void Fecha::setfecha(unsigned int dia, unsigned int mes, unsigned int anio)
{
    if(!validaFecha(dia,mes,anio))
        throw FechaException("La fecha es invalida");

    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

void Fecha::getFecha(int& dia, int& mes, int& anio) const
{
    dia=this->dia;
    mes=this->mes;
    anio=this->anio;
}

int Fecha::cantDiaMesValida (int dia, int mes, int anio)
{
    switch(mes)
    {
        case 4:
        case 6:
        case 9:
        case 11:
            if(dia>30)
                return 0;
            break;

        case 2:
            if(dia>(28+ESBISIESTO(anio)))
            {
                return 0;
            }
            break;
    }

    return 1;
}

int Fecha::validaFecha(int dia, int mes, int anio)
{
    if(!DIAVALIDO(dia) || !MESVALIDO(mes) || !ANIOVALIDO(anio))
    {
        return 0;
    }

    return cantDiaMesValida(dia,mes,anio);
}

///sobrecarga operadores
Fecha Fecha::operator + (int dias) const
{
    Fecha tempFecha(*this);///creo un objeto nuevo
    tempFecha.dia += dias;
    return tempFecha;
}

Fecha& Fecha::operator ++ ()///pre
{
    ++this->dia;
    return *this;
}

Fecha Fecha::operator ++ (int)///pos
{
    Fecha tempFecha(*this);
    this->dia++;
    return tempFecha;
}

Fecha& Fecha::operator +=(int dias)
{
    this->dia+=dias;
    return *this;
}

ostream& operator << (ostream& sal, const Fecha& fecha)
{
    int dia, mes, anio;
    fecha.getFecha(dia, mes, anio);
    return sal << dia << "/" << mes << '/' << anio;
}

istream& operator >> (istream& ent, Fecha& fecha)
{
    int dia, mes, anio;
    ent >> dia >> mes >> anio;
    fecha.setfecha(dia,mes,anio);

    return ent;
}






















