#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicios.h"

int mostrarServicios(eServicio servicios[], int tamSer)
{
    int todoOk =0;
    printf("\n***Lista de Servicios***\n\n");
    printf("    ID    DESCRIPCION   PRECIO\n");

    for(int i=0; i<tamSer; i++)
    {
        mostrarServicio(servicios[i]);
        todoOk=1;
    }
    printf("\n");

    return todoOk;
}
void mostrarServicio(eServicio servicio)
{
    printf("    %d   %s    %d\n", servicio.id, servicio.descripcion, servicio.precio);
}
int cargarDescripcionServicio(int id, eServicio servicios[], int tamSer, char desc[])
{
    int todoOk = 0;

    if(id >= 20000 && id <= 20003 && servicios != NULL && tamSer > 0 && desc != NULL)
    {
       for(int i=0; i<tamSer; i++)
       {
           if(servicios[i].id == id)
           {
               strcpy(desc, servicios[i].descripcion);
               todoOk = 1;
               break;
           }
       }
    }
    return todoOk;
}
