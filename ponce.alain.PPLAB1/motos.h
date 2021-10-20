#include "tipos.h"
#include "colores.h"
#ifndef MOTOS_H_INCLUDED
#define MOTOS_H_INCLUDED

typedef struct
{
    int id;
    char marca[21];
    int idTipo;
    int idColor;
    int cilindrada;
    int puntaje;

    int isEmpty;

}eMoto;

#endif // MOTOS_H_INCLUDED


/** \brief Indica que todas las posiciones de un array estan vacios. Esta funcion pone la bandera (isEmpty) en VERDADERA en todas las posiciones del array.
 *
 * \param lista[] eMoto Array de clientes
 * \param tam int tamanio del array
 * \return int retorna 0 si no hay conflictos o -1 si los hay: lista = NULL o tam < 0
 *
 */
int inicializarMotos(eMoto lista[], int tam);
/** \brief Busca el primer espacio libre de la estructura eMoto
 *
 * \param lista[] eMoto array de motos
 * \param tam int tamanio del array
 * \return int retorna el indice de la primera posicion libre del array, o -1 si no hay posiciones libres
 *
 */
int buscarLibre(eMoto lista[], int tam);

/** \brief Funcion utilizada para dar de alta una nueva moto
 *
 * \param lista[] eMoto array de motos
 * \param tam int tamanio del array
 * \param pIdMoto int* puntero de ID de moto
 * \param tipos[] eTipo array de Tipos
 * \param tamTip int tamanio de array de Tipos
 * \param colores[] eColor array de Colores
 * \param tamCol int tamanio de array de Colores
 * \return int retorna 1 si no hay conflictos o 0 si hay error: punteros = NULL o tamanios < 0
 *
 */
int altaMotos(eMoto lista[], int tam, int* pIdMoto, eTipo tipos[], int tamTip, eColor colores[], int tamCol);
/** \brief Muestra las motos dadas de alta con sus respectiva descripcion
 *
 * \param lista[] eMoto array de motos
 * \param tam int tamanio del array
 * \param tipos[] eTipo array de Tipos
 * \param colores[] eColor array de Colores
 * \return int retorna 1 si no hay conflictos o 0 si hay error
 *
 */
int listarMotos(eMoto lista[], int tam, eTipo tipos[], eColor colores[]);
/** \brief Muestra una moto
 *
 * \param unaMoto eMoto moto seleccionada por su ID
 * \param tam int tamanio del array
 * \param tipos[] eTipo array de Tipos
 * \param colores[] eColor array de Colores
 * \return void No tiene retorno, funcion para mayor orden
 *
 */
void listarMoto(eMoto unaMoto, int tam, eTipo tipos[], eColor colores[]);
/** \brief Funcion utilizada para poder modificar una moto dada de alta anteriormente
 *
 * \param lista[] eMoto array de motos
 * \param tam int tamanio del array
 * \param pIdMoto int puntero de ID de moto
 * \param tipos[] eTipo array de Tipos
 * \param colores[] eColor array de Colores
 * \param tamCol int tamanio del array de Colores
 * \return int retorna 1 si no hay conflictos o 0 si hay error
 *
 */
int modificarMoto(eMoto lista[], int tam, int pIdMoto, eTipo tipos[], eColor colores[], int tamCol);
/** \brief Funcion para buscar un cliente ingresando un codigo
 *
 * \param lista[] eMoto array de motos
 * \param tam int tamanio del array
 * \param id int variable utilizada para ingresar el ID a buscar
 * \return int retorna el indice del cliente que equivale a su ID con el CODIGO, o -1 si no existe el ID ingresado
 *
 */

int buscarMotoPorCodigo(eMoto lista[], int tam, int id);
/** \brief Da de baja un cliente del array de Motos
 *
 * \param lista[] eMoto array de motos
 * \param tam int tamanio del array
 * \param id int variable utilizada para ingresar el ID a buscar
 * \param tipos[] eTipo array de Tipos
 * \param colores[] eColor array de Colores
 * \return int retorna 1 si no hay conflictos o 0 si hay error
 *
 */
int bajaMoto(eMoto lista[], int tam, int id, eTipo tipos[], eColor colores[]);
/** \brief Ordena las motos por su Tipo y por su forma predeterminada al ser identicos, por su ID
 *
 * \param lista[] eMoto array de Motos
 * \param tam int tamanio del array
 * \param tipo[] eTipo array de Tipos
 * \param tamTip int tamanio del array de Tipos
 * \return int retorna 1 si no hay conflictos o 0 si hay error
 *
 */
int ordenarMotoTipo(eMoto lista[],int tam, eTipo tipo[], int tamTip);
/** \brief Funcion utilizada para poder leer la descripcion de la Moto
 *
 * \param id int variable utilizada para ingresar el ID a buscar
 * \param lista[] eMoto array de Motos
 * \param tam int tamanio del array
 * \param desc[] char variable utilizada para guardar la descripcion del ID vinculado
 * \return int retorna 1 si no hay conflictos o 0 si hay error
 *
 */
int cargarDescripcionMoto(int id, eMoto lista[], int tam, char desc[]);

/*-----------------------------------------------------------------------------------------------------------*/

/** \brief Funcion para validar una cadena de caracteres
 *
 * \param cadena[] char Cadena de caracteres a validar
 * \return int retorna 1 si no hay conflictos o 0 si hay error
 *
 */
int validarNombre(char cadena[]);
/** \brief Funcion para validar una cadena de caracteres numericas
 *
 * \param cadena[] char Cadena de caracteres a validar
 * \return int retorna 1 si no hay conflictos o 0 si hay error
 *
 */
int validarNumero(char cadena[]);
