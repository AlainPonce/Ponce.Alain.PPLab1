#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fecha.h"
#include "data.h"
#include "motos.h"

char marcaMotos[8][21] = {"Toyota", "Zanella", "Motomel", "Toyota", "Yamaha", "Yamaha", "Gilera", "Suzuki"};
int idTipos[8] = {1000, 1003, 1000, 1001, 1002, 1002, 1003, 1001};
int idColores[8] = {10000, 10003, 10004, 10000, 10003, 10001, 10001, 10000};
int cilindradas[8] = {750, 50, 125, 125, 50, 600, 500, 600};
int puntajes[8] = {2, 5, 8, 2, 5, 9, 2, 6};

int idServicios[8] = {20001, 20000, 20001, 20003, 20002, 20002, 20000, 20001};
int idMotos[8] = {1, 2, 3, 4, 5, 6 , 7, 8};
eFecha fecha[8] = {{10,5,2021}, {15,5,2021}, {18,5,2021}, {25,5,2021}, {30,5,2021}, {12,6,2021}, {20,6,2021}, {28,6,2021}};

int dataMotos(eMoto lista[], int tam, int cantidadMotos, int* pId)
{
    int todoOk = 0;
    if(lista != NULL && tam > 0 && cantidadMotos >= 0 && pId > 0)
    {
        for(int i = 0; i < cantidadMotos; i++)
        {
            lista[i].id = *pId;
            (*pId)++;
            strcpy(lista[i].marca, marcaMotos[i]);
            lista[i].idTipo = idTipos[i];
            lista[i].idColor = idColores[i];
            lista[i].cilindrada = cilindradas[i];
            lista[i].puntaje = puntajes[i];
            lista[i].isEmpty = 0;
        }
        todoOk=1;
    }
    return todoOk;
}

int dataTrabajos(eTrabajo trabajos[], int tamTra, int cantidadTrabajos, int* pIdTra)
{
    int todoOk = 0;
    if(trabajos != NULL && tamTra > 0 && cantidadTrabajos >= 0 && pIdTra > 0)
    {
        for(int i = 0; i < cantidadTrabajos; i++)
        {
            trabajos[i].id = *pIdTra;
            (*pIdTra)++;
            trabajos[i].idServicio = idServicios[i];
            trabajos[i].idMoto = idMotos[i];
            trabajos[i].fIngreso = fecha[i];
            trabajos[i].isEmpty = 0;
        }
        todoOk=1;
    }
    return todoOk;
}
