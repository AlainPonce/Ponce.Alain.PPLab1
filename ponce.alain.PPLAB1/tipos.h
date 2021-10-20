#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[21];

}eTipo;

#endif // TIPOS_H_INCLUDED


/** \brief Muestra los tipos disponibles
 *
 * \param tipos[] eTipo array de Tipos
 * \param tamTip int tamanio de estructura
 * \return int retorna 1 si no hay conflictos o 0 si hay error
 *
 */
int mostrarTipos(eTipo tipos[], int tamTip);
/** \brief Muestra un tipo
 *
 * \param categoria eTipo array de Tipos.
 * \return void No tiene retorno, funcion para mayor orden
 *
 */
void mostrarTipo(eTipo tipo);
/** \brief Carga la descripcion vinculada al idTipo de estructura eMoto
 *
 * \param id int id ingresado del Tipo elegido
 * \param tipos[] eTipo array de Tipos
 * \param tamTip int tamanio de array de tipos
 * \param desc[] char variable utilizada para guardar la descripcion del ID del tipo
 * \return int retorna 1 si no hay conflicto o 0 si se encuentra un error
 *
 */
int cargarDescripcionTipo(int id, eTipo tipos[], int tamTip, char desc[]);
