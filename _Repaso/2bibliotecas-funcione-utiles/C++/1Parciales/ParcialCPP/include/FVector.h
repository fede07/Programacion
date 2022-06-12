#ifndef FVECTOR_H
#define FVECTOR_H
#include <iostream>
#include <vector>
#include "vecException.h"

using namespace std;

class FVector
{

    private:
        vector <float> vec;
        ///unsigned ce;

    public:
        FVector(float [],unsigned );

        bool operator == (FVector&) const;
        FVector& operator += (float);
        FVector operator -- (int);
        FVector operator / (FVector&) const;

        friend ostream& operator << (ostream&, const FVector&);
};

#endif // FVECTOR_H
