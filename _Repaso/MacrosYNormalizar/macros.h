#ifndef MACROS_H_INCLUDED
#define MACROS_H_INCLUDED

#define FACTORIAL(X,Y)  (Y)=1;\
                        int i;\
                        for(i=1;i<=X;i++)\
                        {\
                            (Y)*=i;\
                        };\

#define ABS(X)          (((X)<0)?((X)-=((X)*2)):(X))

#define PARTEENTERA(X,Y)        ((Y)=((int)(X)))

#define PARTEDECIMAL(X,Y)       (((X)>0)?((Y)=((X)-((int)(X))):((X)+(int)(X))))

#define ESNUMERO(x) ((x)>='0'&&(x)<='9')

#define ESMAYUS(x)  ((x)>='A'&&(x)<='Z')

#define ESMINUS(x)  ((x)>='a'&&(x)<='z')

#define ESLETRA(x)  (ESMINUS(x) || ESMAYUS(x))

#define AMAYUS(x)   ((x)>='a'&&(x)<='z'?(x)-32:(x)) /// Sin verificación: AMAYUS(x) (x)-('a'-'A')

#define AMINUS(x)   ((x)>='A'&&(x)<='Z'?(x)+32:(x)) /// Sin verificacion: AMINUS(x) (x)+('a'-'A')

#define ESBLANCO(x) (((x)==' ')||((x)=='\n')||((x)=='\t'))

#define ESNULL(x)   ((x)==0)

#endif // MACROS_H_INCLUDED
