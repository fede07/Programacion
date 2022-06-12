#ifndef MACROS_H_INCLUDED
#define MACROS_H_INCLUDED

#include <math.h>

#define ABS(x) (x<0)?(x*(-1)):x

#define PARTE_ENTERA(x,y) y=(int)x

#define PARTE_DECIMAL(x) (x)>0?(x)-(int)x:((int)(x)-(x))*(-1)

#define REDONDEO(x,y,z) float x1=x;\
                        int i;\
                        z=(int)(x);\
                        x1-=(int)(x1);\
                        printf("\n\nPreCiclo: x1: %f z: %f\n", x1, z);\
                        for(i=0;i<y;i++)\
                            {(x1)=(x1)*10;\
                            (z)+=(int)x1*pow(0.1,i+1);\
                             printf("\nCiclo: %d, asignacion z= %f+ %f * %f", i, z, x1, pow(0.1,i+1));\
                            (x1)-=(int)(x1);}\
                        if((x1)>=0,5)\
                            (z)+=pow(0.1,y)


#define ESLETRA(x) x>='a'&&x<='z'||x>='A'&&x<='Z'?1:0

#define ESNUMERO(x) x>='0'&&x<='9'?1:0

#define ESMAYUS(x) x>='A'&&x<='Z'?1:0

#define ESMINUS(x) x>='a'&&x<='z'

#define AMAYUS(x) ESMINUS(x)?((x)=(x)-('a'-'A')):(x)

#define AMINUS(x) x>='A'&&x<='Z'?((x)=(x)+('a'-'A')):(x)

#define ESBLANCO(x) x==' '?1:0

#define ESNULL(x) x==0?1:0

#endif // MACROS_H_INCLUDED
