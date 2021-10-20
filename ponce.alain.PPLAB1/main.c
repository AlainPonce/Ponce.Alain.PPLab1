#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "motos.h"
#include "tipos.h"
#include "colores.h"
#include "servicios.h"
#include "trabajos.h"

#define TAM 10
#define TAMTIP 4
#define TAMCOL 5
#define TAMSER 4
#define TAMTRA 10

int menu();

int main()
{
    int idMoto = 1;
    int idTrabajo = 1;
    int flagAlta = 0;
    char salir = 'n';

    eMoto nomina[TAM];
    inicializarMotos(nomina, TAM);

    eTrabajo tnomina[TAMTRA];
    inicializarTrabajos(tnomina, TAMTRA);

    eTipo tipos[TAMTIP] =
    {
        {1000, "Enduro      "},
        {1001, "Chopera     "},
        {1002, "Scooter     "},
        {1003, "Vintage     "},

    };

    eColor colores[TAMCOL] =
    {
        {10000, "Gris     "},
        {10001, "Negro    "},
        {10002, "Azul     "},
        {10003, "Blanco   "},
        {10004, "Rojo     "},
    };

    eServicio servicios[TAMSER] =
    {
        {20000, "Limpieza  ", 450},
        {20001, "Ajuste    ", 300},
        {20002, "Balanceo  ", 150},
        {20003, "Cadena    ", 390},
    };

    do
    {
        switch(menu())
        {
            case 'A':

                if(altaMotos(nomina, TAM, &idMoto, tipos, TAMTIP, colores, TAMCOL))
                {
                    printf("Alta Exitosa!\n\n");
                    flagAlta=1;
                }
                else
                {
                    printf("Ha ocurrido un error en el sistema.\n\n");
                }


                break;

            case 'B':
                if(flagAlta == 1 && modificarMoto(nomina, TAM, idMoto, tipos, colores, TAMCOL))
                {
                    printf("Modificacion Exitosa!\n\n");
                }
                else
                {
                    printf("\nNo se ha registrado ningun cliente o ha ocurrido un error en el sistema.\n\n");
                }

                break;

            case 'C':
                if(flagAlta == 1 && bajaMoto(nomina, TAM, idMoto, tipos, colores))
                {
                    printf("Baja Exitosa!\n\n");
                }
                else
                {
                    printf("\nNo se ha registrado ningun cliente o ha cancelado la baja.\n\n");
                }
                break;

            case 'D':
                if(flagAlta == 1)
                {
                    system("cls");
                    ordenarMotoTipo(nomina, TAM, tipos, TAMTIP);
                    listarMotos(nomina, TAM, tipos, colores);
                }
                else
                {
                    printf("\nNo se ha registrado ningun cliente o ha cancelado la baja.\n\n");
                }

                break;

            case 'E':
                mostrarTipos(tipos, TAMTIP);
                break;

            case 'F':
                mostrarColores(colores, TAMCOL);
                break;

            case 'G':
                mostrarServicios(servicios, TAMSER);
                break;

            case 'H':
                if(flagAlta == 1 && altaTrabajo(tnomina, nomina, tipos, colores, servicios, TAMTRA, TAM, TAMTIP, TAMCOL, TAMSER, &idTrabajo))
                {

                    printf("Alta Exitosa!\n\n");
                }
                else
                {
                   printf("\nNo se ha registrado ninguna Moto.\n\n");
                }

                break;

            case 'I':
                system("cls");
                mostrarTrabajos(tnomina, TAMTRA, tipos, TAMTIP, colores, TAMCOL, nomina, TAM, servicios, TAMSER);
                printf("\n");
                break;

            case 'Z':
                printf("\nConfirma salida? (s/n): ");
                fflush(stdin);
                salir=getchar();
                if(salir != 'n' && salir != 's')
                {
                    printf("\nOpcion Invalida!\n\n");
                }
                break;

            default:
            printf("Opcion Invalida!\n");

        }
        system("pause");
    }while(salir!='s');

    return 0;
}

int menu()
{
    char opcion;

    system("cls");
    printf("                 *** Service Motos ***\n\n");
    printf("  A. Alta Moto.\n");
    printf("  B. Modificar Moto.\n");
    printf("  C. Baja Moto.\n");
    printf("  D. Listar Motos.\n");
    printf("  E. Listar Tipos.\n");
    printf("  F. Listar Colores.\n");
    printf("  G. Listar Servicios.\n");
    printf("  H. Alta Trabajo.\n");
    printf("  I. Listar Trabajos.\n");

    printf("  Z. Salir.\n\n");

    printf("Ingrese opcion: ");

    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}
