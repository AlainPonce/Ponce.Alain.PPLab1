#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "motos.h"
#include "tipos.h"
#include "colores.h"

int inicializarMotos(eMoto lista[], int tam)
{
    int todoOk = -1;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
            todoOk = 0;
        }
    }

    return todoOk;
}
int buscarLibre(eMoto lista[], int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(lista[i].isEmpty)
        {
            indice=i;
            break;
        }

    }
    return indice;
}
int altaMotos(eMoto lista[], int tam, int* pIdMoto, eTipo tipos[], int tamTip, eColor colores[], int tamCol)
{
    int todoOk = 0;
    eMoto nuevaMoto;
    int indice;

    system("cls");
    printf("      ***Alta Motos***\n\n");
    printf("ID: %d\n", *pIdMoto);
    printf("\n");

    if(lista != NULL && tam > 0 && pIdMoto != NULL && tipos != NULL && tamTip > 0 && colores != NULL && tamCol > 0)
    {
        indice = buscarLibre(lista, tam);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema.\n");
        }
        else
        {
            printf("Ingrese marca: ");
            fflush(stdin);
            gets(nuevaMoto.marca);
            while(strlen(nuevaMoto.marca) > 21 || validarNombre(nuevaMoto.marca) == 0)
            {
                printf("Error. Ingrese marca correctamente: ");
                fflush(stdin);
                gets(nuevaMoto.marca);
            }

            mostrarTipos(tipos, tamTip);
            printf("Ingrese ID de TIPO: ");
            fflush(stdin);
            scanf("%d", &nuevaMoto.idTipo);
            while(nuevaMoto.idTipo < 1000 || nuevaMoto.idTipo > 1003)
            {
                printf("Error. Ingrese ID de Tipo correctamente: ");
                fflush(stdin);
                scanf("%d", &nuevaMoto.idTipo);
            }

            mostrarColores(colores, tamCol);
            printf("Ingrese ID de color: ");
            fflush(stdin);
            scanf("%d", &nuevaMoto.idColor);
            while(nuevaMoto.idColor < 10000 || nuevaMoto.idColor> 10004)
            {
                printf("Error. Ingrese ID de Color correctamente: ");
                fflush(stdin);
                scanf("%d", &nuevaMoto.idColor);
            }

            printf("Ingrese cilindrada (50, 125, 500, 600 ,750): ");
            fflush(stdin);
            scanf("%d", &nuevaMoto.cilindrada);
            while(nuevaMoto.cilindrada != 50 && nuevaMoto.cilindrada != 125 && nuevaMoto.cilindrada != 500 && nuevaMoto.cilindrada != 600 && nuevaMoto.cilindrada != 750)
            {
                printf("Error. Ingrese cilindrada correctamente (50, 125, 500, 600 ,750): ");
                fflush(stdin);
                scanf("%d", &nuevaMoto.cilindrada);
            }

            printf("Ingrese puntaje (1 a 10): ");
            fflush(stdin);
            scanf("%d", &nuevaMoto.puntaje);
            while(nuevaMoto.puntaje < 1 || nuevaMoto.puntaje > 10 )
            {
                printf("Error. Ingrese puntaje correctamente (1 a 10): ");
                fflush(stdin);
                scanf("%d", &nuevaMoto.puntaje);
            }

            printf("\n");

            nuevaMoto.id = *pIdMoto;
            *pIdMoto = *pIdMoto +1;
            nuevaMoto.isEmpty = 0;

            lista[indice] = nuevaMoto;
            todoOk = 1;
        }
    }
    return todoOk;
}
int listarMotos(eMoto lista[], int tam, eTipo tipos[], eColor colores[])
{
    int flag = 1;
    int todoOk =0;

    printf("             ***Listado de Motos***\n\n");
    printf("ID     MARCA   TIPO     COLOR   CILINDRADA    PUNTAJE\n");

    for(int i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == 0)
        {
          listarMoto(lista[i], tam, tipos, colores);
          flag = 0;
          todoOk=1;
        }
    }

    if(flag)
    {
        printf("        No hay motos que mostrar.\n");
    }

    return todoOk;
}
void listarMoto(eMoto unaMoto, int tam, eTipo tipos[], eColor colores[])
{
    char descripcionTipo[21];
    char descripcionColor[21];

    if(cargarDescripcionTipo(unaMoto.idTipo, tipos, tam, descripcionTipo) && cargarDescripcionColor(unaMoto.idColor, colores, tam, descripcionColor))
    {
        printf("%d  %10s  %s\t%s\t%d\t\t%d"
        , unaMoto.id
        , unaMoto.marca
        , descripcionTipo
        , descripcionColor
        , unaMoto.cilindrada
        , unaMoto.puntaje);

        printf("\n");
    }
}
int modificarMoto(eMoto lista[], int tam, int pIdMoto, eTipo tipos[], eColor colores[], int tamCol)
{
    int todoOk=0;
    int indice;
    int opcion;

    system("cls");
    printf("              ***Modificar Moto***\n");
    listarMotos(lista,tam, tipos, colores);
    printf("\n");
    printf("Ingrese ID: ");
    scanf("%d", &pIdMoto);

    printf("\n");

    indice = buscarMotoPorId(lista, tam, pIdMoto);
    if(lista != NULL && tam>0 && pIdMoto !=0 && tipos != NULL && colores != NULL && tamCol > 0)
    {
        if(indice == -1)
        {
            printf("No hay ninguna moto registrada con el ID ingresado: %d.\n\n", pIdMoto);
        }
        else
        {

            printf("            ***Moto elegida***\n");
            printf("ID    MARCA    TIPO       COLOR     CILINDRADA    PUNTAJE\n");
            listarMoto(lista[indice], tam, tipos, colores);

            printf("\n");

            printf("Que desea modificar?\n\n");

            printf("1. Color\n");
            printf("2. Puntaje\n\n");

            printf("Opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);
            while(opcion<1 || opcion>2)
            {
                printf("Error. Ingrese Opcion correctamente: ");
                fflush(stdin);
                scanf("%d", &opcion);
            }
            printf("\n");

            switch(opcion)
            {
                case 1:

                    mostrarColores(colores, tamCol);
                    printf("Ingrese ID de color: ");
                    fflush(stdin);
                    scanf("%d", &lista[indice].idColor);
                    while(lista[indice].idColor < 10000 || lista[indice].idColor > 10004)
                    {
                        printf("Error. Ingrese ID de Color correctamente: ");
                        fflush(stdin);
                        scanf("%d", &lista[indice].idColor);
                    }

                    break;

                case 2:
                    printf("Ingrese nuevo puntaje (1 a 10): ");
                    fflush(stdin);
                    scanf("%d", &lista[indice].puntaje);
                    while(lista[indice].puntaje < 1 || lista[indice].puntaje > 10)
                    {
                        printf("Error. Ingrese nuevo puntaje correctamente (1 a 10): ");
                        fflush(stdin);
                        scanf("%d", &lista[indice].puntaje);
                    }

                    break;
            }
            todoOk=1;
            printf("\n");
        }
    }
    return todoOk;
}
int bajaMoto(eMoto lista[], int tam, int id, eTipo tipos[], eColor colores[])
{
    int todoOk=0;
    int indice;
    char confirma;

    system("cls");
    printf("           ***Baja de Cliente***\n");
    listarMotos(lista, tam, tipos, colores);
    printf("\n");
    printf("Ingrese ID: ");
    scanf("%d", &id);

    printf("\n");

    indice = buscarMotoPorId(lista, tam, id);
    if(lista != NULL && tam > 0 && id > 0 && tipos != NULL && colores != NULL)
    {
        if(indice == -1)
        {
            printf("No hay ningun cliente registrado con el ID ingresado: %d.\n\n", id);
        }
        else
        {
            printf("           ***Moto elegida***\n");
            printf("ID    MARCA    TIPO       COLOR     CILINDRADA\n");
            listarMoto(lista[indice], tam, tipos, colores);
            printf("\n");
            printf("Confirma baja? s/n: ");
            fflush(stdin);
            scanf("%c", &confirma);
            printf("\n");

            if(confirma == 's')
            {
                lista[indice].isEmpty = 1;
                todoOk=1;
            }
        }
    }
    return todoOk;
}
int ordenarMotoTipo(eMoto lista[],int tam, eTipo tipo[], int tamTip) //VER
{
    int todoOk=0;
    eMoto auxMoto;

    char descripcionTipo[21];
    char descripcionTipo2[21];

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(cargarDescripcionTipo(lista[i].idTipo, tipo, tamTip, descripcionTipo) && cargarDescripcionTipo(lista[j].idTipo, tipo, tamTip, descripcionTipo2))
            {
                if(strcmp(descripcionTipo, descripcionTipo2)>0)
                {
                    auxMoto = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxMoto;
                    todoOk=1;
                }
            }
        }
    }
    return todoOk;
}
int cargarDescripcionMoto(int id, eMoto lista[], int tam, char desc[])
{
    int todoOk = 0;

    if(id >= 1 && lista != NULL && tam > 0 && desc != NULL)
    {
       for(int i=0; i<tam; i++)
       {
           if(lista[i].id == id)
           {
               strcpy(desc, lista[i].marca);
               todoOk = 1;
               break;
           }
       }
    }
    return todoOk;
}
int buscarMotoPorId(eMoto lista[], int tam, int id)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(lista[i].id == id && lista[i].isEmpty == 0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int validarNombre(char cadena[])
{
    for(int i = 0; i < strlen(cadena); i++)
    {
        if((cadena[i] >= 65 && cadena[i]<= 90) || (cadena[i] >= 97 && cadena[i] <= 122))
        {
            return 1;
        }
    }
    return 0;
}
int validarNumero(char numero[])
{
    for(int i = 0; i < strlen(numero); i++)
    {
        if(isdigit(numero[i]))
        {
            return 1;
        }
    }

    return 0;
}
