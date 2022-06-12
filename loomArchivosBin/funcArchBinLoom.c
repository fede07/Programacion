#include "funcArchBinLoom.h"

void crearArchivos()
{
    t_alumno alumno[TAMALU]=
    {
        {123333,"Fernandez","Juana",2.50},
        {123365,"Garcia","Jose",2},
        {456666,"Garcia","Jose",1.5},///este no es empleado
        {456798,"Gonzalez","Maria",9},
        {789999,"Gonzalez","Maria",3},
        {666548,"Hernandez","Pepa",8.5},///este no es empleado
        {998775,"Hernandez","Pepe",3},///este no es empleado
        {484897,"Illidian","Antoni",4},///este no es empleado
        {000000,"Lopez","Francisco",5},
        {111222,"Rodriguez","Luis",8},
        {321321,"Rodriguez","Martin",9},
        {654789,"Tortuga","Pepito",10},
        {889648,"Werez","Martin",8},
        {999854,"Zar","Pepita",7}
    };
    t_empleado empleado[TAMEMP]=
    {
        {123333,"Fernandez","Juana",250},
        {458922,"Fernandez","Juana",300},
        {456666,"Garcia","Jose",200},
        {456798,"Gonzalez","Maria",100},
        {789999,"Gonzalez","Maria",300},
        {998845,"Hernandez","Federico",450},
        {445618,"Jeliz","Pepito",999},///este no es alumno
        {000000,"Lopez","Francisco",500},
        {414880,"Martinez","Marito",15},
        {111222,"Rodriguez","Luis",800},
        {321321,"Rodriguez","Martin",1100},
        {654789,"Tortuga","Pepito",1300},
        {995587,"Tortuga","Pepito",10},
        {889648,"Werez","Nicolas",0},
        {999854,"Zar","Pepita",1200},
        {698541,"Zar","Pepito",750}
    };
    int i;
    FILE *archEmpl, *archAlum;

    archEmpl=fopen("empleados.bin", "wb");
    if(!archEmpl)
    {
        printf("NO SE PUDO CREAR EMPLEADOS.BIN");
        exit(100);
    }

    archAlum=fopen("estudiantes.bin","wb");

    if(!archAlum)
    {
        printf("NO SE PUDO CREAR ESTUDIANTES.BIN");
        fclose(archEmpl);
        exit(101);
    }

    for(i=0; i<TAMALU; i++)
    {
        fwrite(&alumno[i],sizeof(t_alumno),1,archAlum);
    }

    for(i=0; i<TAMEMP; i++)
    {
        fwrite(&empleado[i],sizeof(t_empleado),1,archEmpl);
    }

    fclose(archAlum);
    fclose(archEmpl);
}

void actualizarArch(FILE* archAlum, FILE* archEmpl, FILE* archUpdate)
{
    t_empleado empleado;
    t_alumno alumno;

    fread(&alumno, sizeof(t_alumno),1,archAlum);
    fread(&empleado, sizeof(t_empleado),1,archEmpl);

    while(!feof(archAlum) && !feof(archEmpl))
    {
        if(alumno.dni==empleado.dni)
        {
            if(alumno.promedio>=7)
            {
                empleado.sueldo*=AUMENTO;
            }
        }
        if(strcmp(alumno.apellido, empleado.apellido))

        }

}
