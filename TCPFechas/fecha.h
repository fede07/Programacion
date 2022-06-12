#ifndef FECHA_H
#define FECHA_H

//d/m/a ->diaRel
//cantAños=añoFecha-AñoBase(1601)
//diasAñosCompl=cantAños*365+cantAños/4-cantAños/100+cantAños/400
//diaRel=diasAñosCompl+diaDelAñoFecha

//diaRel ->d/m/a
//añosComplCalc=diaRel/365
//diasAñosComplCalcañosComplCalc*365+añosComplCalc/4-añosCompCalc/100+añosComplCalc/400
//año=añoBase+AñosComplCalc
//DiaDelAño=diaRel-diasAñosComplCalc
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
