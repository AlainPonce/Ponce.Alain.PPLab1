#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "motos.h"
#include "tipos.h"
#include "colores.h"
#include "servicios.h"
#include "trabajos.h"

int inicializarTrabajos(eTrabajo trabajos[], int tamTra)
{
    int todoOk = -1;
    if(trabajos != NULL && tamTra > 0)
    {
        for(int i = 0; i < tamTra; i++)
        {
            trabajos[i].isEmpty = 1;
            todoOk = 0;
        }
    }

    return todoOk;
}
int buscarLibreTrabajo(eTrabajo trabajos[], int tamTra)
{
    int indice = -1;
    for(int i=0; i<tamTra; i++)
    {
        if(trabajos[i].isEmpty)
        {
            indice=i;
            break;
        }

    }
    return indice;
}
int altaTrabajo(eTrabajo trabajos[], eMoto lista[], eTipo tipos[], eColor colores[], eServicio servicios[], int tamTra, int tam, int tamTip, int tamCol, int tamSer, int* pIdTrabajo)
{
    int todoOk =0;
    int indice;
    int id;
    int idServicio;
    eTrabajo nuevoTrabajo;

    system("cls");

    if(trabajos != NULL && lista != NULL && tipos != NULL && colores != NULL && servicios != NULL && tamTra > 0 && tam > 0 && tamTip > 0 && tamCol > 0 && tamSer > 0)
    {
        printf("              ***Alta Trabajo***\n");
        indice = buscarLibreTrabajo(trabajos, tamTra);
        if(indice == -1)
        {
            printf("No hay lugar para mas alquileres");
        }
        else
        {
            listarMotos(lista,tam, tipos, colores);
            printf("\nIngrese ID: ");
            scanf("%d", &id);
            while(buscarMotoPorId(lista, tam, id) == -1)
            {
                printf("Error. Ingrese ID correctamente: ");
                scanf("%d", &id);
            }
            printf("\n");

            nuevoTrabajo.idMoto = id;

            printf("             ***Moto elegida***\n");
            printf("ID     MARCA   TIPO     COLOR   CILINDRADA    PUNTAJE\n");
            listarMoto(lista[id-1], tam, tipos, colores);

            printf("\n");

            mostrarServicios(servicios, tamSer);
            printf("Ingrese el ID del Servicio: ");
            scanf("%d", &idServicio);
            while(idServicio < 20000 || idServicio > 20004)
            {
                printf("Error. Ingrese CODIGO correctamente: ");
                scanf("%d", &idServicio);
            }

            nuevoTrabajo.idServicio = idServicio;

            printf("Ingrese dia de ingreso: ");
            scanf("%d", &nuevoTrabajo.fIngreso.dia);
            while(nuevoTrabajo.fIngreso.dia < 1 || nuevoTrabajo.fIngreso.dia > 31)
            {
                printf("Error. Ingrese dia de ingreso correctamente: ");
                scanf("%d", &nuevoTrabajo.fIngreso.dia);
            }

            printf("Ingrese mes de ingreso: ");
            scanf("%d", &nuevoTrabajo.fIngreso.mes);
            while(nuevoTrabajo.fIngreso.mes < 1 || nuevoTrabajo.fIngreso.mes >12)
            {
                printf("Error. Ingrese mes de ingreso correctamente: ");
                scanf("%d", &nuevoTrabajo.fIngreso.mes);
            }

            printf("Ingrese anio de ingreso: ");
            scanf("%d", &nuevoTrabajo.fIngreso.anio);
            while(nuevoTrabajo.fIngreso.anio < 1980 || nuevoTrabajo.fIngreso.anio >2021)
            {
                printf("Error. Ingrese anio de ingreso correctamente: ");
                scanf("%d", &nuevoTrabajo.fIngreso.anio);
            }

            nuevoTrabajo.id = *pIdTrabajo;
            (*pIdTrabajo)++;
            nuevoTrabajo.isEmpty = 0;
            trabajos[indice] = nuevoTrabajo;
            todoOk = 1;
        }
    }
    printf("\n");
    return todoOk;
}
int mostrarTrabajos(eTrabajo trabajos[], int tamTra, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eMoto lista[], int tam, eServicio servicios[], int tamSer)
{
    int flag = 1;
    int todoOk =0;
    system("cls");
    printf("         ***Listado de Trabajos***\n\n");
    printf("CODIGO  MOTO     SERVICIO       FECHA DE ALTA\n");

    for(int i=0; i<tamTra; i++)
    {
        if(trabajos[i].isEmpty == 0)
        {
          mostrarTrabajo(trabajos[i], tamTra, tipos, tamTip, colores, tamCol, lista, tam, servicios, tamSer);
          flag = 0;
          todoOk=1;
        }
    }

    if(flag)
    {
        printf("        No hay trabajos que mostrar.\n");
    }
    return todoOk;

}
void mostrarTrabajo(eTrabajo unTrabajo, int tamTra, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eMoto lista[], int tam, eServicio servicios[], int tamSer)
{
    char descripcionServicio[26];
    char descripcionMoto[21];

    if(cargarDescripcionServicio(unTrabajo.idServicio, servicios, tamSer, descripcionServicio) && cargarDescripcionMoto(unTrabajo.idMoto, lista, tam, descripcionMoto))
    {
       printf("%d   %10s   %s \t%d/%d/%d"
       , unTrabajo.id
       , descripcionMoto
       , descripcionServicio
       , unTrabajo.fIngreso.dia
       , unTrabajo.fIngreso.mes
       , unTrabajo.fIngreso.anio);

        printf("\n");
    }
}
