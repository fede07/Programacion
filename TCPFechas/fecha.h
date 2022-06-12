#ifndef FECHA_H
#define FECHA_H

//d/m/a ->diaRel
//cantA�os=a�oFecha-A�oBase(1601)
//diasA�osCompl=cantA�os*365+cantA�os/4-cantA�os/100+cantA�os/400
//diaRel=diasA�osCompl+diaDelA�oFecha

//diaRel ->d/m/a
//a�osComplCalc=diaRel/365
//diasA�osComplCalca�osComplCalc*365+a�osComplCalc/4-a�osCompCalc/100+a�osComplCalc/400
//a�o=a�oBase+A�osComplCalc
//DiaDelA�o=diaRel-diasA�osComplCalc
class Fecha
{
private:
    unsigned long diaRel;

    static const int acumMesBis[13];
    static const int acumMesNBis[13];

    static int diaDelAnio(int dia,int mes,int anio);
    static int esBis(int anio);
    static void diaDelAnioADiaMes(int,int,int*,int*);

public:
    Fecha();
    Fecha(int dia,int mes,int anio);

    Fecha sumarDias(int dias) const;

    void getDMA(int*d,int*m,int*a)const;
};

#endif // FECHA_H
