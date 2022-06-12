#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}t_fecha;

int validaFecha(t_fecha);///fecha completa
int validaMes (int);///solo el mes
int validaDia (int);///valida solo que este en el rango 1 31

int esBisiesto (int);///solo el año
int cantDiaMesValida (t_fecha);


#endif // FECHAS_H_INCLUDED
