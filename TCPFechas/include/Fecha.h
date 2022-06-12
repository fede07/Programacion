#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    public:
        Fecha();
        Fecha(int dia, int mes, int anio);
        Fecha sumarDias (int dias) const;
        int getDiaRel() const;
        int setDiaRel()

    private:
        unsigned long diaRel;
};

#endif // FECHA_H
