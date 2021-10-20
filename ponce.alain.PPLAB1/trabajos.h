#ifndef TRABAJOS_H_INCLUDED
#define TRABAJOS_H_INCLUDED
#include "fecha.h"
typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    eFecha fIngreso;

    int isEmpty;

}eTrabajo;

#endif // TRABAJOS_H_INCLUDED

/** \brief Indica que todas las posiciones de un array estan vacios. Esta funcion pone la bandera (isEmpty) en VERDADERA en todas las posiciones del array.
 *
 * \param lista[] eTrabajo Array de trabajos
 * \param tamTra int tamanio del array
 * \return int retorna 0 si no hay conflictos o -1 si los hay: lista = NULL o tam < 0
 *
 */
int inicializarTrabajos(eTrabajo trabajos[], int tamTra);
/** \brief Busca el primer espacio libre de la estructura eTrabajo
 *
 * \param lista[] eTrabajo array de trabajos
 * \param tamTra int tamanio del array
 * \return int retorna el indice de la primera posicion libre del array, o -1 si no hay posiciones libres
 *
 */
int buscarLibreTrabajo(eTrabajo trabajos[], int tamTra);
/** \brief Funcion utilizada para dar de alta un nuevo trabajo
 *
 * \param trabajos[] eTrabajo Array de trabajos
 * \param lista[] eMoto Array de motos
 * \param tipos[] eTipo Array de tipos
 * \param colores[] eColor Array de color
 * \param servicios[] eServicio Array de servicio
 * \param tamTra int tamanio del array
 * \param tam int tamanio del array de eMoto
 * \param tamTip int tamanio del array de eTipo
 * \param tamCol int tamanio del array de eColor
 * \param tamSer int tamanio del array de eServicio
 * \param pIdTrabajo int* puntero de ID de trabajo
 * \return int retorna 1 si no hay conflictos o 0 si hay error: punteros = NULL o tamanios < 0
 *
 */
int altaTrabajo(eTrabajo trabajos[], eMoto lista[], eTipo tipos[], eColor colores[], eServicio servicios[], int tamTra, int tam, int tamTip, int tamCol, int tamSer, int* pIdTrabajo);
/** \brief Muestra los trabajos dados de alta con su respectiva descripcion
 *
 * \param trabajos[] eTrabajo Array de trabajos
 * \param tamTra int tamanio del array
 * \param tipos[] eTipo Array de tipos
 * \param tamTip int tamanio del array de eTipo
 * \param colores[] eColor Array de color
 * \param tamCol int tamanio del array de eColor
 * \param lista[] eMoto Array de motos
 * \param tam int tamanio del array de eMoto
 * \param servicios[] eServicio  Array de servicio
 * \param tamSer int tamanio del array de eServicio
 * \return int retorna 1 si no hay confictos o 0 si hay error
 *
 */
int mostrarTrabajos(eTrabajo trabajos[], int tamTra, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eMoto lista[], int tam, eServicio servicios[], int tamSer);

/** \brief Muestra un trabajo
 *
 * \param unTrabajo eTrabajo un trabajo seleccionado por su ID
 * \param tamTra int tamanio del array
 * \param tipos[] eTipo Array de tipos
 * \param tamTip int tamanio del array de eTipo
 * \param colores[] eColor Array de color
 * \param tamCol int tamanio del array de eColor
 * \param lista[] eMoto Array de motos
 * \param tam int tamanio del array de eMoto
 * \param servicios[] eServicio  Array de servicio
 * \param tamSer int tamanio del array de eServicio
 * \return int retorna 1 si no hay confictos o 0 si hay error
 *
 */
void mostrarTrabajo(eTrabajo unTrabajo, int tamTra, eTipo tipos[], int tamTip, eColor colores[], int tamCol, eMoto lista[], int tam, eServicio servicios[], int tamSer);
