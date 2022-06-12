#include "fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha(int _dia,int _mes,int _anio)
{
    dia=_dia;
    mes=_mes;
    anio=_anio;
}

Fecha::Fecha(long fecha)
{
    anio=int(fecha/10000);
    mes= int((fecha-anio*10000)/100);
    dia=int(fecha-anio*100000-mes*100);
}

void Fecha::mostrarFecha()
{
    cout<<"la fecha es: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
}
