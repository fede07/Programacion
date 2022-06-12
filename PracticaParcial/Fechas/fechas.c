#include "fechas.h"

int esBisiesto(int anio)
{
    return((anio%4 ==0 && anio%100!=0) || anio%400==0);
}

int validarCantD(int dia, int mes, int anio)
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
        return (dia<=(28+esBisiesto(anio)));
    }
    return 1;
}

int validarDia(int dia, int mes)
{
    return (dia>=1 && dia<=31);
}

int validarMes(int mes)
{
    return (mes>=1 && mes<= 12);
}

int validarFecha(t_fecha fecha)
{
    if(fecha.anio < ANIO_INI || !validarMes(fecha.mes) || !validarDia(fecha.dia, fecha.mes))
    {
        return 0;
    }

    return validarCantD(fecha.dia, fecha.mes, fecha.anio);
}
