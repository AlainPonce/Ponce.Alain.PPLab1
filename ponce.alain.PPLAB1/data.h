#include "motos.h"
#include "trabajos.h"
#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED



#endif // DATA_H_INCLUDED
/** \brief Dataware para ingresar ejemplos de Motos
 *
 * \param lista[] eMoto Array de motos
 * \param tam int tamanio del array
 * \param cantidadMotos int cantidad de espacio a ocupar en el array
 * \param pId int* puntero al ID de motos
 * \return int retorna 1 si no existen conflictos o 0 si algun array es NULO o tamanio menor a 0.
 *
 */
int dataMotos(eMoto lista[], int tam, int cantidadMotos, int* pId);
/** \brief Dataware para ingresar ejemplos de Trabajos
 *
 * \param trabajos[] eTrabajo array de Trabajos
 * \param tamTra int tamanio del array de trabajos
 * \param cantidadTrabajos int cantidad de espacio a ocupar en el array
 * \param pIdTra int* puntero al ID de trabajos
 * \return int retorna 1 si no existen conflictos o 0 si algun array es NULO o tamanio menor a 0.
 *
 */
int dataTrabajos(eTrabajo trabajos[], int tamTra, int cantidadTrabajos, int* pIdTra);
