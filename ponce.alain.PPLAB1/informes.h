#include "trabajos.h"
#include "servicios.h"
#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED
/** \brief Muestra submenu de Informes
 *
 * \param lista[] eMoto Array de Motos
 * \param tam int tamanio del array
 * \param colores[] eColor Array de Colores
 * \param tamCol int tamanio del array de colores
 * \param tipos[] eTipo Array de Tipos
 * \param tamTip int tamanio del array de tipos
 * \param trabajos[] eTrabajo Array de trabajos
 * \param tamTra int tamanio del array
 * \param servicios[] eServicio Array de servicios
 * \param tamSer int tamanio del array
 * \return int retorna 1 si no existen conflictos o 0 si algun array es NULO o tamanio menor a 0.
 *
 */
int submenu(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip, eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer);
/** \brief Muestra las motos de un color especifico seleccionado por el usuario
 *
 * \param lista[] eMoto Array de motos
 * \param tam int tamanio del array
 * \param colores[] eColor Array de colores
 * \param tamCol int tamanio del array de colores
 * \param tipos[] eTipo Array de tipos
 * \param tamTip int tamanio del array de tipos
 * \return int retorna 1 si no existen conflictos o 0 si algun array es NULO o tamanio menor a 0.
 *
 */
int mostrarMotosPorColor(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip);
/** \brief Muestra el promedio de puntaje de un tipo de motos seleccionado por el usuario.
 *
 * \param lista[] eMoto Array de motos
 * \param tam int tamanio del array
 * \param colores[] eColor Array de colores
 * \param tamCol int tamanio del array de colores
 * \param tipos[] eTipo Array de tipos
 * \param tamTip int tamanio del array de tipos
 * \return int retorna 1 si no existen conflictos o 0 si algun array es NULO o tamanio menor a 0.
 *
 */
int mostrarPromedioDePuntajesTipo(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip);
/** \brief Muestra las motos registradas de mayor cilindrada
 *
 * \param lista[] eMoto Array de motos
 * \param tam int tamanio del array
 * \param colores[] eColor Array de colores
 * \param tamCol int tamanio del array de colores
 * \param tipos[] eTipo Array de tipos
 * \param tamTip int tamanio del array de tipos
 * \return int retorna 1 si no existen conflictos o 0 si algun array es NULO o tamanio menor a 0.
 *
 */
int mostrarMotoMayorCilindrada(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip);
/** \brief Muestra un listado completo de las motos separadas por su tipo
 *
 * \param lista[] eMoto Array de motos
 * \param tam int tamanio del array
 * \param colores[] eColor Array de colores
 * \param tamCol int tamanio del array de colores
 * \param tipos[] eTipo Array de tipos
 * \param tamTip int tamanio del array de tipos
 * \return int retorna 1 si no existen conflictos o 0 si algun array es NULO o tamanio menor a 0.
 *
 */
int mostrarMotosPorGrupoDeTipos(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip);
/** \brief Muestra las motos seleccionadas por el usuario segun su tipo y color
 *
 * \param lista[] eMoto Array de motos
 * \param tam int tamanio del array
 * \param colores[] eColor Array de colores
 * \param tamCol int tamanio del array de colores
 * \param tipos[] eTipo Array de tipos
 * \param tamTip int tamanio del array de tipos
 * \return int retorna 1 si no existen conflictos o 0 si algun array es NULO o tamanio menor a 0.
 *
 */
int mostrarMotosDeTipoYColor(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip);
//int mostrarColorMasElegido(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip);
/** \brief Muestra los trabajos efectuados de una moto seleccionada por el usuario
 *
 * \param lista[] eMoto Array de motos
 * \param tam int tamanio del array
 * \param colores[] eColor Array de colores
 * \param tamCol int tamanio del array de colores
 * \param tipos[] eTipo Array de tipos
 * \param tamTip int tamanio del array de tipos
 * \param trabajos[] eTrabajo Array de trabajos
 * \param tamTra int tamanio del array de trabajos
 * \param servicios[] eServicio Array de servicios
 * \param tamSer int tamanio del array de servicios
 * \return int retorna 1 si no existen conflictos o 0 si algun array es NULO o tamanio menor a 0.
 *
 */
int mostrarTrabajosDeUnaMoto(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip, eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer);
/** \brief Muestra la suma de los precios de los servicios efectuados en una moto.
 *
 * \param lista[] eMoto Array de motos.
 * \param tam int tamanio del array.
 * \param colores[] eColor Array de colores.
 * \param tamCol int tamanio del array de colores.
 * \param tipos[] eTipo Array de tipos.
 * \param tamTip int tamanio del array de tipos.
 * \param trabajos[] eTrabajo Array de trabajos.
 * \param tamTra int tamanio del array de trabajos.
 * \param servicios[] eServicio Array de servicios.
 * \param tamSer int tamanio del array de servicios.
 * \return int retorna 1 si no existen conflictos o 0 si algun array es NULO o tamanio menor a 0.
 *
 */
int mostrarImportesServiciosPorMoto(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip, eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer);
/** \brief Muestra las motos a las que se les realio un servicio seleccionado por el usuario y su fecha
 *
 * \param lista[] eMoto Array de motos.
 * \param tam int tamanio del array.
 * \param colores[] eColor Array de colores.
 * \param tamCol int tamanio del array de colores.
 * \param tipos[] eTipo Array de tipos.
 * \param tamTip int tamanio del array de tipos.
 * \param trabajos[] eTrabajo Array de trabajos.
 * \param tamTra int tamanio del array de trabajos.
 * \param servicios[] eServicio Array de servicios.
 * \param tamSer int tamanio del array de servicios.
 * \return int retorna 1 si no existen conflictos o 0 si algun array es NULO o tamanio menor a 0.
 *
 */
int mostrarMotosPorServicio(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip, eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer);
/** \brief Muestra los servicios efectuados en una fecha ingresada por el usuario.
 *
 * \param lista[] eMoto Array de motos.
 * \param tam int tamanio del array.
 * \param colores[] eColor Array de colores.
 * \param tamCol int tamanio del array de colores.
 * \param tipos[] eTipo Array de tipos.
 * \param tamTip int tamanio del array de tipos.
 * \param trabajos[] eTrabajo Array de trabajos.
 * \param tamTra int tamanio del array de trabajos.
 * \param servicios[] eServicio Array de servicios.
 * \param tamSer int tamanio del array de servicios.
 * \return int retorna 1 si no existen conflictos o 0 si algun array es NULO o tamanio menor a 0.
 *
 */
int mostrarServicioPorFecha(eMoto lista[], int tam, eColor colores[], int tamCol, eTipo tipos[], int tamTip, eTrabajo trabajos[], int tamTra, eServicio servicios[], int tamSer);
