#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "colores.h"

int mostrarColores(eColor colores[], int tamCol)
{
    int todoOk =0;
    printf("\n***Lista de Colores***\n\n");
    printf("    ID    NOMBRE COLOR\n");

    for(int i=0; i<tamCol; i++)
    {
        mostrarColor(colores[i]);
        todoOk=1;
    }
    printf("\n");

    return todoOk;
}
void mostrarColor(eColor color)
{
    printf("    %d   %s\n", color.id, color.nombreColor);
}
int cargarDescripcionColor(int id, eColor colores[], int tamCol, char desc[])
{
    int todoOk = 0;

    if(id >= 10000 && id <= 10004 && colores != NULL && tamCol > 0 && desc != NULL)
    {
       for(int i=0; i<tamCol; i++)
       {
           if(colores[i].id == id)
           {
               strcpy(desc, colores[i].nombreColor);
               todoOk = 1;
               break;
           }
       }
    }
    return todoOk;
}
