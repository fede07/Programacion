#define FACTORIAL(X,Y)  (Y)=1;\
                        int i;\
                        for(i=1;i<=X;i++)\
                        {\
                            (Y)*=i;\
                        };\

#define ABS(X)          if(X<0)\   (X<0)?X-=X*2:X

#define PARTEENTERA(X,Y)        Y=(int)X;

#define PARTEDECIMAL(X,Y)       X>0?Y=X-(int)X:X+(int)X

#define ESLETRA(x) (x>='a'&&x<='z')||(x>='A'&&x<='Z')?1:0

#define ESNUMERO(x) x>='0'&&x<='9'?1:0

#define ESMAYUS(x) x>='A'&&x<='Z'?1:0

#define ESMINUS(x) x>='a'&&x<='z'?1:0

#define AMAYUS(x) (x)>='a'&&(x)<='z'?(x)-('a'-'A'):(x) /// Sin verificación: AMAYUS(x) (x)-('a'-'A')

#define AMINUS(x) (x)>='A'&&(x)<='Z'?(x)+('a'-'A'):(x) /// Sin verificacion: AMINUS(x) (x)+('a'-'A')

#define ESBLANCO(x) x==' '?1:0

#define ESNULL(x) x==0?1:0

char* borrarEspaciosExtra(char* escritura)
{
    char *inicioCad=escritura, *lectura=escritura;
    while(*lectura)
    {
        while(ESBLANCO(*lectura))
        {
            lectura++;
        }
        while(!(ESBLANCO(*lectura)) && !(ESNULL(*lectura)))
        {
            *escritura = *lectura;
            escritura++;
            lectura++;
        }
        if(!(ESNULL(*lectura)))
        {
            *escritura=' ';
            escritura++;
        }
    }
    if(ESBLANCO(*(escritura-1)))
        escritura--;
    *escritura='\0';
    return inicioCad;
}

char* primerLetraDeCadaMayus(char* escritura)
{
    char *inicioCad=escritura, *lectura=escritura;
    while(*lectura)
    {
        while(*lectura==' ')
        {
            lectura++;
        }
        *lectura=AMAYUS(*lectura);
        while(*lectura!=' ' && *lectura!='\0')
        {
            *escritura = *lectura;
            escritura++;
            lectura++;
            *lectura=AMINUS(*lectura);
        }
        if(*lectura!='\0')
        {
            *escritura=' ';
            escritura++;
        }
    }
    if(*(escritura-1)==' ')
        escritura--;
    *escritura='\0';
    return inicioCad;
}

char* primerLetraMayus(char* escritura)
{
    char *inicioCad=escritura, *lectura=escritura;

    while(*lectura==' ')
    {
        lectura++;
    }

    *lectura=AMAYUS(*lectura);
    *escritura=*lectura;
    escritura++;
    lectura++;
    while(*lectura)
    {
        while(ESBLANCO(*lectura))
        {
            lectura++;
        }
        while(!(ESBLANCO(*lectura)) && !(ESNULL(*lectura)))
        {
            *lectura=AMINUS(*lectura);
            *escritura = *lectura;
            escritura++;
            lectura++;

        }
        if(!ESNULL(*lectura))
        {
            *escritura=' ';
            escritura++;
        }
    }
    if(ESBLANCO(*(escritura-1)))
        escritura--;
    *escritura='\0';
    return inicioCad;
}
