#include "fechas.h"

int validaFecha(t_fecha fecha)
{
    if(fecha.anio<1601 || !validaMes(fecha.mes) || !validaDia(fecha.dia))///si llega aca el anio es valido
    {
        return 0;
    }

    return cantDiaMesValida(fecha);
}

int validaMes(int mes)
{
    return (mes>=1 && mes<=12);
}

int validaDia(int dia)
{
    return (dia>=1 && dia<=31);
}

int cantDiaMesValida (t_fecha fecha)
{
    switch(fecha.mes)
    {
        case 4:
        case 6:
        case 9:
        case 11:
            if(fecha.dia>30)
                return 0;
            break;

        case 2:
            if(fecha.dia>(28+esBisiesto(fecha.anio)))
            {
                return 0;
            }
            break;
    }

    return 1;
}

int esBisiesto(int anio)
{
    return ((anio%4==0 && anio%100!=0) || anio%400==0);
}
