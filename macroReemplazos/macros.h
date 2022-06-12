#ifndef MACROS_H_INCLUDED
#define MACROS_H_INCLUDED

#define ESLETRA(x)  (((x)>='a'&&(x)<='z')||((x)>='A'&&(x)<='Z'))

#define ESNUMERO(x) ((x)>='0'&&(x)<='9')

#define ESMAYUS(x)  ((x)>='A'&&(x)<='Z')

#define ESMINUS(x)  ((x)>='a'&&(x)<='z')

#define AMAYUS(x)   ((x)>='a'&&(x)<='z'?(x)-32:(x)) /// Sin verificación: AMAYUS(x) (x)-('a'-'A')

#define AMINUS(x)   ((x)>='A'&&(x)<='Z'?(x)+32:(x)) /// Sin verificacion: AMINUS(x) (x)+('a'-'A')

#define ESBLANCO(X) (((X)==' ')||((X)=='\n')||((X)=='\t'))

#define ESNULL(x)   ((x)==0)

#endif // MACROS_H_INCLUDED
