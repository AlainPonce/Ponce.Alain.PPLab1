#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipos.h"

int mostrarTipos(eTipo tipos[], int tamTip)
{
    int todoOk =0;
    printf("\n***Lista de Tipos***\n\n");
    printf("    ID    DESCRIPCION\n");

    for(int i=0; i<tamTip; i++)
    {
        mostrarTipo(tipos[i]);
        todoOk=1;
    }
    printf("\n");

    return todoOk;
}
void mostrarTipo(eTipo tipo)
{
    printf("    %d   %s\n", tipo.id, tipo.descripcion);
}
int cargarDescripcionTipo(int id, eTipo tipos[], int tamTip, char desc[])
{
    int todoOk = 0;

    if(id >= 1000 && id <= 1003 && tipos != NULL && tamTip > 0 && desc != NULL)
    {
       for(int i=0; i<tamTip; i++)
       {
           if(tipos[i].id == id)
           {
               strcpy(desc, tipos[i].descripcion);
               todoOk = 1;
               break;
           }
       }
    }
    return todoOk;
}
