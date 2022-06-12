#include "FVector.h"

/**

vec.size() DEVUELVE EL NUMERO EXACTO DE ELEMENTOS
PARA USAR ce COMO INDICE [ce] HAY QUE RESTARLE 1

REVISAR CONSTS SI HAY ERRORES EN LOS OPERADORES << >>

**/


FVector::FVector(float vec[],unsigned ce)
{
    for(unsigned i = 0; i < ce; i++)
    {
        this->vec.push_back(vec[i]);
    }
}

bool FVector::operator == (FVector& otro) const
{
    unsigned ce = otro.vec.size();

    if(ce != this->vec.size())
    {
        return 0;
    }

    while(ce && this->vec[ce-1]==otro.vec[ce-1])
    {
        ce--;
    }

    if(ce)
    {///se encontro un elemento diferente
        return 0;
    }

    return 1;
}

FVector& FVector::operator += (float num)
{
    unsigned i;
    for (i=0; i < this->vec.size(); i++)
    {
        this->vec[i] += num;
    }

    return *this;
}

FVector FVector::operator -- (int)
{
    FVector tempVec = *this;
    unsigned i;
    for (i=0; i < this->vec.size(); i++)
    {
        this->vec[i] --;
    }

    return tempVec;
}

FVector FVector::operator / (FVector& otro) const
{
    FVector tempVec = *this;
    unsigned ce = otro.vec.size();

    if(ce != this->vec.size())
    {
        throw vecException("no aplica a vectores de diferente longitud...");
    }

    while (ce && otro.vec[ce-1]!=0)
    {
        tempVec.vec[ce-1] = this->vec[ce-1]/otro.vec[ce-1];
        ce--;
    }

    if(ce)
    {
        throw vecException("no se puede dividir por 0...");
    }

    return tempVec;
}

ostream& operator << (ostream& sal , const FVector& otro)
{
    int ce = otro.vec.size();
    int i;

    sal << "{";
    for(i=0; i<ce-1; i++)
    {

        sal << otro.vec[i] << ", ";
    }
    return sal << otro.vec[i] << "}";
}








