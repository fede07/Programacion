#ifndef NORMALIZA_H_INCLUDED
#define NORMALIZA_H_INCLUDED

#define ESBLANCO(x) ((x)==' ')

#define ESMAYUS(x) ((x)>='A' && (x)<='Z')

#define AMAYUS(x) (ESMINUS(x)?(x)-='a'-'A':(x))

#define ESMINUS(x) ((x)>='a'&&(x)<='z')

#define AMINUS(x) (ESMAYUS(x)?((x)+='a'-'A'):(x))

#define ESLETRA(x) (((x)>='a' && (x)<='z')||((x)>='A' && (x)<='Z'))



char * borrarBlancosExtras (char*);
char * tipoTitulo (char*);
char * tipoOracion (char*);
char * primerPalabraMayus (char*);

char * todoMayus (char*);

char * apellidoInicialesMayuscula (char*);


#endif // NORMALIZAR_H_INCLUDED
