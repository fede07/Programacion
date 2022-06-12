#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED

#define ANIO_INI 1601

typedef struct{
    int dia,
        mes,
        anio;
}t_fecha;

int esBisiesto(int anio);
int validarCantD(int dia, int mes, int anio);
int validarDia(int dia, int mes);
int validarMes(int mes);
int validarFecha(t_fecha fecha);



#endif // FECHAS_H_INCLUDED
