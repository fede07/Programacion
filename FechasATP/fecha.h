#ifndef FECHA_H
#define FECHA_H

class Fecha
{
private:
    int dia,mes,anio;
public:
    Fecha(int,int,int);
    Fecha(long);
    void mostrarFecha();
};

#endif // FECHA_H
