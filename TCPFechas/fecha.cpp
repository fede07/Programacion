#include "fecha.h"
#define ANIO_BASE 1601
const int Fecha::acumMesNBis[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
const int Fecha::acumMesBis[] = {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
Fecha::Fecha()
{
    this->diaRel=1;
}

Fecha::Fecha(int dia,int mes, int anio)
{
    int cantAnios=anio-ANIO_BASE;
    int diasAniosCompl=cantAnios*365+cantAnios/4-cantAnios/100+cantAnios/400;
    this->diaRel=diasAniosCompl+diaDelAnio(dia,mes,anio);
}
Fecha Fecha::sumarDias(int dias) const
{
    Fecha fSuma(*this);
    fSuma.diaRel+=dias;
    return fSuma;
}
void Fecha::getDMA(int*d,int*m,int*a)const{
    int aniosComplCalc=this->diaRel/365;
    unsigned long diasAniosComplCalc=aniosComplCalc*365+aniosComplCalc/4-aniosComplCalc/100+aniosComplCalc/400;
    while(diasAniosComplCalc>=this->diaRel)
    {
        aniosComplCalc--;
        diasAniosComplCalc=aniosComplCalc*365+aniosComplCalc/4-aniosComplCalc/100+aniosComplCalc/400;
    }
int anio=ANIO_BASE+aniosComplCalc;
*a=anio;
int diaDelAnio=this->diaRel-diasAniosComplCalc;
diaDelAnioADiaMes(diaDelAnio,anio,d,m);
}
/*********** Funciones miembro (metodos) privadas ********/
int Fecha::diaDelAnio(int dia,int mes,int anio){
    return (esBis(anio)? acumMesBis[mes]:acumMesNBis[mes])+dia;
}
int Fecha::esBis(int anio){
    return (anio%4==0&&anio%100!=0)||anio%400==0;
}
void Fecha::diaDelAnioADiaMes(int diaDelAnio,int anio,int* d,int* m){
    const int* acumMes=esBis(anio)?acumMesBis:acumMesNBis;
    int mes=2;
    while(mes<=12&&diaDelAnio>acumMes[mes])
        mes++;
    mes--;
    *m=mes;
    *d=diaDelAnio-acumMes[mes];
}
