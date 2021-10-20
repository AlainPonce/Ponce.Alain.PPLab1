#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[26];
    int precio;
    //int isEmpty;

}eServicio;

#endif // SERVICIOS_H_INCLUDED

/** \brief Muestra los servicios disponibles
 *
 * \param servicios[] eServicio array de estructura
 * \param tamSer int tamanio de estructura
 * \return int retorna 1 si no hay conflictos o 0 si hay error
 *
 */
int mostrarServicios(eServicio servicios[], int tamSer);

/** \brief Muestra un servicio
 *
 * \param servicio eServucui array de Servicios
 * \return void No tiene retorno, funcion para mayor orden
 *
 */
void mostrarServicio(eServicio servicio);
/** \brief Carga la descripcion vinculada al idServicio de estructura eTrabajo
 *
 * \param id int id ingresado del Servicio elegido
 * \param servicios[] eServicio array de Servicios
 * \param tamSer int tamanio de array de servicios
 * \param desc[] char variable utilizada para guardar la descripcion del ID del servicio
 * \return int retorna 1 si no hay conflicto o 0 si se encuentra un error
 *
 */
int cargarDescripcionServicio(int id, eServicio servicios[], int tamSer, char desc[]);
