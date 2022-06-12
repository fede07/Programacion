#include "funcionesMost.h"

void mostrarArchivo(const char* nombreArch, void *info, size_t tam, void accion(void*))
{
    FILE *arch=fopen(nombreArch,"rb");
//    if(!arch){
//        return 0;
//    }
    fread(info, tam, 1, arch);
    while(!feof(arch))
    {
        accion(info);
        fread(info, tam, 1, arch);
    }
    fclose(arch);
//    return 1;
}

void mostrarEmpleado(void *info)
{
    printf("%d|%s|%s|%.2f\n",((t_novedad*)(info))->empleado.dni, ((t_novedad*)(info))->empleado.apellido,((t_novedad*)(info))->empleado.nombre,((t_novedad*)(info))->empleado.sueldo);
}
