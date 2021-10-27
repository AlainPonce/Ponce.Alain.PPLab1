#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "motos.h"
#include "colores.h"
#include "informes.h"
#include "trabajos.h"
#include "servicios.h"

int submenu(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip, eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer)
{
    int opcion;
    int todoOk = 0;

    if(lista != NULL && tam > 0 && colores != NULL && tamCol > 0 && tipos != NULL && tamTip > 0 && trabajos != NULL && tamTra > 0 && servicios != NULL && tamSer > 0)
    {
        printf("\n                 *** Informes Motos ***\n\n");
        printf("  1. Mostrar las motos del color seleccionado por el usuario.\n");
        printf("  2. Informar el promedio de puntaje de un tipo seleccionado por el usuario.\n");
        printf("  3. Informar la o las motos de mayor cilindrada.\n");
        printf("  4. Mostrar un listado de las motos separadas por tipo.\n");
        printf("  5. Elegir un color y un tipo y contar cuantas motos hay de ese color y ese tipo.\n");
        printf("  6. Mostrar el o los colores mas elegidos por los clientes. (INCOMPLETO)\n");
        printf("  7. Pedir una moto y mostrar todos los trabajos que se le hicieron a la misma.\n");
        printf("  8. Pedir una moto e informar la suma de los importes de los servicios que se le hicieron a la misma.\n");
        printf("  9. Pedir un servicio y mostrar las motos a las que se les realizo ese servicio y la fecha.\n");
        printf("  10. Pedir una fecha y mostrar todos los servicios realizados en la misma.\n\n");

        printf("Ingrese opcion: ");

        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                if(mostrarMotosPorColor(lista, tam, colores, tamCol, tipos, tamTip))
                {
                    printf("\nFin de la lista.\n\n");
                }
                else
                {
                   printf("\nNo se ha registrado ninguna Moto.\n\n");
                }

                break;

            case 2:
                if(mostrarPromedioDePuntajesTipo(lista, tam, colores, tamCol, tipos, tamTip))
                {
                    printf("Fin de la lista.\n\n");
                }
                else
                {
                   printf("\nNo se ha registrado ninguna Moto.\n\n");
                }

                break;

            case 3:
                if(mostrarMotoMayorCilindrada(lista, tam, colores, tamCol, tipos, tamTip))
                {
                    printf("\nFin de la lista.\n\n");
                }
                else
                {
                   printf("\nNo se ha registrado ninguna Moto.\n\n");
                }

                break;

            case 4:
                if(mostrarMotosPorGrupoDeTipos(lista, tam, colores, tamCol, tipos, tamTip))
                {
                    printf("\nFin de la lista.\n\n");
                }
                else
                {
                   printf("\nNo se ha registrado ninguna Moto.\n\n");
                }

                break;

            case 5:
                if(mostrarMotosDeTipoYColor(lista, tam, colores, tamCol, tipos, tamTip))
                {
                    printf("\nFin de la lista.\n\n");
                }
                else
                {
                   printf("\nNo se ha registrado ninguna Moto.\n\n");
                }

                break;

            case 6:
                if(1)
                {
                    printf("\nFormula sin completar.\n");
                }

                break;

            case 7:
                if(mostrarTrabajosDeUnaMoto(lista, tam, colores, tamCol, tipos, tamTip, trabajos, tamTra, servicios, tamSer))
                {
                    printf("\nFin de la lista.\n\n");
                }
                else
                {
                   printf("\nNo se ha registrado ninguna Moto.\n\n");
                }

                break;

            case 8:
                if(mostrarImportesServiciosPorMoto(lista, tam, colores, tamCol, tipos, tamTip, trabajos, tamTra, servicios, tamSer))
                {
                    printf("Fin de la lista.\n\n");
                }
                else
                {
                   printf("\nNo se ha registrado ninguna Moto.\n\n");
                }

                break;

            case 9:
                if(mostrarMotosPorServicio(lista, tam, colores, tamCol, tipos, tamTip, trabajos, tamTra, servicios, tamSer))
                {
                    printf("\nFin de la lista.\n\n");
                }
                else
                {
                   printf("\nNo se ha registrado ninguna Moto.\n\n");
                }

                break;

            case 10:
                if(mostrarServicioPorFecha(lista, tam, colores, tamCol, tipos, tamTip, trabajos, tamTra, servicios, tamSer))
                {
                    printf("\nFin de la lista.\n\n");
                }
                else
                {
                   printf("No se ha registrado ninguna Moto.\n\n");
                }

                break;

            default:
            printf("Opcion Invalida!\n");
        }
        todoOk=1;
    }
    return todoOk;
}
int mostrarMotosPorColor(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip)
{
    int opcion;
    int todoOk = 0;
    int flag = 1;
    char descripcionColor[21];

    system("cls");
    printf("***Listado de Motos por COLOR***\n");
    mostrarColores(colores, tamCol);

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion < 10000 || opcion > 10004)
    {
        printf("Error. Ingrese opcion correctamente: ");
        scanf("%d", &opcion);
    }

    printf("\n             ***Listado de Motos***\n");
    printf("ID     MARCA   TIPO     COLOR   CILINDRADA    PUNTAJE\n");
    if(lista != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].idColor == opcion && lista)
            {
                listarMoto(lista[i], tam, tipos, colores);
                flag = 0;
            }
        }

        if(flag && cargarDescripcionColor(opcion, colores, tamCol, descripcionColor))
        {
            printf("No se han registrado motos del color: %s\n\n", descripcionColor);
        }
        todoOk = 1;
    }

    return todoOk;
}
int mostrarPromedioDePuntajesTipo(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip)
{
    int opcion;
    int todoOk = 0;
    int flag = 1;
    int suma = 0;
    int acumulador = 0;
    float promedio;
    char descripcionTipo[21];

    system("cls");
    printf("***Listado de Motos por TIPOS***\n");
    mostrarTipos(tipos, tamTip);
    printf("Ingrese opcion: ");

    scanf("%d", &opcion);
    while(opcion < 1000 || opcion > 1003)
    {
        printf("Error. Ingrese opcion correctamente: ");
        scanf("%d", &opcion);
    }

    printf("\n             ***Listado de Motos***\n");
    printf("ID     MARCA   TIPO     COLOR   CILINDRADA    PUNTAJE\n");
    if(lista != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].idTipo == opcion)
            {
                suma = suma + lista[i].puntaje;
                listarMoto(lista[i], tam, tipos, colores);
                acumulador++;
                flag = 0;
            }
        }

        promedio = (float) suma / acumulador;
        printf("\nEl promedio es %.2f: ", promedio);

        if(flag && cargarDescripcionTipo(opcion, tipos, tamTip, descripcionTipo))
        {
            printf("No se han registrado motos del tipo: %s\n\n", descripcionTipo);
        }
        todoOk = 1;
    }

    return todoOk;
}
int mostrarMotoMayorCilindrada(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip)
{
    int variableAComparar = 1;
    int todoOk = 0;

    system("cls");
    printf("***Listado de Motos por MAYOR CILINDRADA***\n\n");
    printf("ID     MARCA   TIPO     COLOR   CILINDRADA    PUNTAJE\n");

    if(lista != NULL && tam > 0 && colores != NULL && tamCol > 0 && tipos != NULL && tamTip > 0)
    {

        for(int i = 0; i < tam; i++)
        {
            if(lista[i].cilindrada > variableAComparar && lista[i].isEmpty == 0)
            {
                variableAComparar = lista[i].cilindrada;
            }
        }

        for(int j = 0; j < tam; j++)
        {
            if(lista[j].cilindrada == variableAComparar)
            {
                listarMoto(lista[j], tam, tipos, colores);
            }
        }
        todoOk = 1;
    }

    return todoOk;
}
int mostrarMotosPorGrupoDeTipos(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip)
{
    int todoOk=0;

    int flagEnduro=1;
    int flagChopera=1;
    int flagScooter=1;
    int flagVintage=1;

    char descripcionTipoEnduro[21];
    char descripcionTipoChopera[21];
    char descripcionTipoScooter[21];
    char descripcionTipoVintage[21];

    system("cls");
    if(lista != NULL && tam > 0 && colores != NULL && tamCol > 0 && tipos != NULL && tamTip > 0)
    {
        printf("          ***Listado de Motos POR TIPO***\n\n");
        printf("           ***Listado de Motos ENDURO***\n");
        printf("ID     MARCA   TIPO     COLOR   CILINDRADA    PUNTAJE\n");
        for(int i = 0; i<tam; i++)
        {
            if(lista[i].idTipo == 1000)
            {
                listarMoto(lista[i], tam, tipos, colores);
                flagEnduro = 0;
            }
        }
        if(flagEnduro)
        {
            cargarDescripcionTipo(1000, tipos, tamTip, descripcionTipoEnduro);
            printf("No se han registado motos de tipo: %s\n", descripcionTipoEnduro);
        }

        printf("\n           ***Listado de Motos CHOPERA***\n");
        printf("ID     MARCA   TIPO     COLOR   CILINDRADA    PUNTAJE\n");
        for(int i = 0; i<tam; i++)
        {
            if(lista[i].idTipo == 1001)
            {
                listarMoto(lista[i], tam, tipos, colores);
                flagChopera=0;
            }
        }
        if(flagChopera)
        {
            cargarDescripcionTipo(1001, tipos, tamTip, descripcionTipoChopera);
            printf("No se han registado motos de tipo: %s\n", descripcionTipoChopera);
        }

        printf("\n           ***Listado de Motos SCOOTER***\n");
        printf("ID     MARCA   TIPO     COLOR   CILINDRADA    PUNTAJE\n");
        for(int i = 0; i<tam; i++)
        {
            if(lista[i].idTipo == 1002)
            {
                listarMoto(lista[i], tam, tipos, colores);
                flagScooter=0;
            }
        }

        if(flagScooter)
        {
            cargarDescripcionTipo(1002, tipos, tamTip, descripcionTipoScooter);
            printf("No se han registado motos de tipo: %s\n", descripcionTipoScooter);
        }

        printf("\n           ***Listado de Motos VINTAGE***\n");
        printf("ID     MARCA   TIPO     COLOR   CILINDRADA    PUNTAJE\n");
        for(int i = 0; i<tam; i++)
        {
            if(lista[i].idTipo == 1003)
            {
                listarMoto(lista[i], tam, tipos, colores);
                flagVintage=0;
            }
        }
        if(flagVintage)
        {
            cargarDescripcionTipo(1003, tipos, tamTip, descripcionTipoVintage);
            printf("No se han registado motos de tipo: %s\n", descripcionTipoVintage);
        }

        todoOk=1;
    }
    return todoOk;
}
int mostrarMotosDeTipoYColor(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip)
{
    int todoOk = 0;
    int opcion;
    int opcion2;

    int contadorTipoColor = 0;

    char descripcionTipo[21];
    char descripcionColor[21];

    system("cls");
    if(lista != NULL && tam > 0 && colores != NULL && tamCol > 0 && tipos != NULL && tamTip > 0)
    {
        printf("***Listado de Motos por TIPOS***\n");
        mostrarTipos(tipos, tamTip);
        printf("Ingrese opcion: ");

        scanf("%d", &opcion);
        while(opcion < 1000 || opcion > 1003)
        {
            printf("Error. Ingrese opcion correctamente: ");
            scanf("%d", &opcion);
        }
        printf("\n");

        printf("***Listado de Motos por COLORES***\n");
        mostrarColores(colores, tamCol);
        printf("Ingrese opcion: ");

        scanf("%d", &opcion2);
        while(opcion2 < 10000 || opcion2 > 10004)
        {
            printf("Error. Ingrese opcion correctamente: ");
            scanf("%d", &opcion2);
        }

        printf("\n");

        for(int i = 0; i<tam; i++)
        {
            if(lista[i].idTipo == opcion && lista[i].idColor == opcion2)
            {
                contadorTipoColor++;
            }
        }

        if(cargarDescripcionTipo(opcion, tipos, tamTip, descripcionTipo) && cargarDescripcionColor(opcion2, colores, tamCol, descripcionColor))
        {
            printf("Cantidad de motos del tipo %s y del color %s: %d\n", descripcionTipo, descripcionColor, contadorTipoColor);
        }
        todoOk=1;
    }
    return todoOk;
}
/*int mostrarColorMasElegido(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip) //Hacer
{
    int todoOk = 0;
    int contadores[5] = {0, 0, 0, 0, 0};
    int auxContadores;


    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i<tam; i++)
        {
            switch(lista[i].idColor)
            {
                case 10000:
                    contadores[0]++;
                    break;

                case 10001:
                    contadores[1]++;
                    break;

                case 10002:
                    contadores[2]++;
                    break;

                case 10003:
                    contadores[3]++;
                    break;

                case 10004:
                    contadores[4]++;
                    break;
            }
        }

        printf("Gris: %d\n", contadores[0]);
        printf("Negro: %d\n", contadores[1]);
        printf("Blanco: %d\n", contadores[2]);
        printf("Azul: %d\n", contadores[3]);
        printf("Rojo: %d\n", contadores[4]);

        for(int i = 0; i< 5-1; i++)
        {
            for(int j = i+1; j < 5; j++)
            {
               if(contadores[i] < contadores[j])
               {
                   auxContadores = contadores[i];
                   contadores[i] = contadores[j];
                   contadores[j] = auxContadores;
               }
            }
        }
        for(int i=0; i<5; i++)
        {
            printf("Contadores: %d\n", contadores[i]);
        }
        todoOk=1;
    }
    return todoOk;
}*/
int mostrarTrabajosDeUnaMoto(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip, eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer)
{
    int id;
    int flag = 1;
    int todoOk=0;

    if(lista != NULL && tam > 0 && colores != NULL && tamCol > 0 && tipos != NULL && tamTip > 0 && trabajos != NULL && tamTra > 0 && servicios != NULL && tamSer > 0)
    {
        system("cls");
        printf("       ***Informe Trabajos de una Moto***\n");
        listarMotos(lista, tam, tipos, colores);
        printf("\nIngrese ID: ");
        scanf("%d", &id);
        while(buscarMotoPorId(lista, tam, id)== -1)
        {
            printf("Error. Ingrese CODIGO correctamente: ");
            scanf("%d", &id);
        }

        printf("\n         ***Listado de Trabajos***\n\n");
        printf("CODIGO  MOTO     SERVICIO       FECHA DE ALTA\n");
        for(int i=0; i<tamTra; i++)
        {
            if(trabajos[i].isEmpty == 0 && trabajos[i].idMoto == id)
            {
                mostrarTrabajo(trabajos[i], tamTra, tipos, tamTip, colores, tamCol, lista, tam, servicios, tamSer);

                flag = 0;
            }
        }
        todoOk=1;
        if(flag)
        {
            printf("La moto de ID: %d no registra trabajos efectuados.\n", id);
        }
    }
    return todoOk;
}
int mostrarImportesServiciosPorMoto(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip, eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer)
{
    int id;
    float total = 0;
    int flag = 1;
    int todoOk=0;

    if(lista != NULL && tam > 0 && colores != NULL && tamCol > 0 && tipos != NULL && tamTip > 0 && trabajos != NULL && tamTra > 0 && servicios != NULL && tamSer > 0)
    {
        system("cls");
        printf("  ***Informe Total Servicios de una Moto***\n");

        listarMotos(lista, tam, tipos, colores);
        printf("\nIngrese ID: ");
        scanf("%d", &id);

        while(buscarMotoPorId(lista, tam, id)== -1)
        {
            printf("Error. Ingrese CODIGO correctamente: ");
            scanf("%d", &id);
        }

        for(int i=0; i<tamTra; i++)
        {
            if(trabajos[i].isEmpty == 0 && trabajos[i].idMoto == id)
            {
                for(int j=0; j<tamSer; j++)
                {
                    if(servicios[j].id == trabajos[i].idServicio)
                    {
                        total += servicios[j].precio;
                    }
                }
                flag = 0;
                todoOk=1;
            }
        }
    }
    printf("\n");
    if(flag)
    {
        printf("La moto de ID: %d no registra servicios efectuados", id);
    }
    else
    {
        printf("Total Ingresos por servicios de moto ID %d: $%.2f", id, total);
    }
    printf("\n\n");

    return todoOk;
}
int mostrarMotosPorServicio(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip, eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer)
{
    int opcion;
    int todoOk = 0;
    int flag = 1;
    char descripcionServicio[21];

    system("cls");
    printf("***Listado de Motos por SERVICIOS***\n");
    mostrarServicios(servicios, tamSer);
    printf("Ingrese opcion: ");

    scanf("%d", &opcion);
    while(opcion < 20000 || opcion > 20003)
    {
        printf("Error. Ingrese opcion correctamente: ");
        scanf("%d", &opcion);
    }

    printf("\n             ***Listado de Motos***\n");
    printf("CODIGO  MOTO     SERVICIO       FECHA DE ALTA\n");
    if(lista != NULL && tam > 0 && colores != NULL && tamCol > 0 && tipos != NULL && tamTip > 0 && trabajos != NULL && tamTra > 0 && servicios != NULL && tamSer > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if(trabajos[i].idServicio == opcion)
            {
                mostrarTrabajo(trabajos[i], tamTra, tipos, tamTip, colores, tamCol, lista, tam, servicios, tamSer);
                flag = 0;
            }
        }

        if(flag && cargarDescripcionServicio(opcion, servicios, tamSer, descripcionServicio))
        {
            printf("No se han registrado motos del tipo: %s\n\n", descripcionServicio);
        }
        todoOk = 1;
    }

    return todoOk;
}
int mostrarServicioPorFecha(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip, eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer)
{
    eFecha fecha;
    int flag = 1;
    int cantidadDeFechas;
    int todoOk = 0;

    if(lista != NULL && tam > 0 && colores != NULL && tamCol > 0 && tipos != NULL && tamTip > 0 && trabajos != NULL && tamTra > 0 && servicios != NULL && tamSer > 0)
    {
        system("cls");
        printf("     ***Listado de Motos por fecha segun Servicio***\n");

        printf("\nIngrese fecha dd/mm/aaaa: ");
        fflush(stdin);
        cantidadDeFechas = scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
        while(cantidadDeFechas != 3)
        {
            printf("Error. Ingrese fecha dd/mm/aaaa correctamente: ");
            fflush(stdin);
            cantidadDeFechas = scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
        }
        printf("\n");
        printf("CODIGO  MARCA    SERVICIO       FECHA\n");
        for(int s=0; s<tamSer; s++)
        {
            for(int t = 0; t < tamTra; t++)
            {
                if(trabajos[t].isEmpty == 0 && servicios[s].id == trabajos[t].idServicio && comparaFechas(trabajos[t].fIngreso, fecha))
                {
                    mostrarTrabajo(trabajos[t], tamTra, tipos, tamTip, colores, tamCol, lista, tam, servicios, tamSer);
                    flag=0;
                }
            }
        }
        todoOk=1;
    }
    if(flag)
    {
        printf("No se registran trabajos en la fecha ingresada\n\n");
    }
    return todoOk;
}
