//#include "atoi.h"
//
//#define ESNUMERO(x) (((x)>='0')&&((x)<='9'))
//#define ESBLANCO(x) ((x)==' '||(x)=='\n'||(x)=='\t')
//#define ESSIGNO(x)  (((x)=='-')||((x)=='+'))
//#define ANUMERO(x)  ((x)-'0')
//
//int cadenaAIntATOI(const char *cadena)
//{
//    int valor = 0, signo=1;
//    char *lectura=(char*)cadena;
//    while(ESBLANCO(*lectura))
//    {
//        lectura++;
//    }
//    if(ESSIGNO(*lectura))
//    {
//        (*lectura=='+')?(signo=1):(signo=-1);
//        lectura++;
//    }
//    while(ESNUMERO(*lectura))
//    {
//        valor*=10;
//        valor+=(ANUMERO(*lectura));
//        lectura++;
//    }
//    valor*=signo;
//    return valor;
//}
