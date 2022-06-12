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

char* todoMayus(char* escritura)
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
            *lectura=AMAYUS(*lectura);
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

char* primerPalabraMayus(char* escritura)
{
    char *inicioCad=escritura, *lectura=escritura;

    while(ESBLANCO(*lectura) && *lectura)
    {
        lectura++;
    }
    while(!(ESBLANCO(*lectura)) && *lectura)
    {
        *lectura=AMAYUS(*lectura);
        *escritura = *lectura;
        escritura++;
        lectura++;
    }

    *escritura=*lectura;
    escritura++;

    while(*lectura)
    {
        while(ESBLANCO(*lectura) && *lectura)
        {
            lectura++;
        }
        while(!(ESBLANCO(*lectura)) && *lectura)
        {
            *lectura=AMINUS(*lectura);
            *escritura = *lectura;
            escritura++;
            lectura++;

        }
        if(*lectura)
        {
            *escritura=*lectura;
            escritura++;
        }
    }
    if(ESBLANCO(*(escritura-1)))
        escritura--;
    *escritura='\0';
    return inicioCad;
}

char* apellidoIniciales(char* escritura)
{
    char *inicioCad=escritura, *lectura=escritura;

    while(ESBLANCO(*lectura) && *lectura)
    {
        lectura++;
    }
    while(!(ESBLANCO(*lectura)) && *lectura)
    {
        *lectura=AMAYUS(*lectura);
        *escritura = *lectura;
        escritura++;
        lectura++;
    }

    *escritura=' ';
    escritura++;

    while(*lectura)
    {
        while(ESBLANCO(*lectura) && *lectura)
        {
            lectura++;
        }

        if(*lectura)
        {
            *lectura=AMAYUS(*lectura);
            *escritura = *lectura;
            escritura++;
            lectura++;
            *escritura = '.';
            escritura++;
            lectura++;
        }

        while(ESLETRA(*lectura) && *lectura)
        {
            lectura++;
        }

        if(*lectura)
        {
            *escritura=*lectura;
            escritura++;
        }
    }
    if(ESBLANCO(*(escritura-1)))
        escritura--;
    *escritura='\0';
    return inicioCad;
}
