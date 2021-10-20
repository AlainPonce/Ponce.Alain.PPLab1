#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[21];

}eColor;

#endif // COLORES_H_INCLUDED


/** \brief Muestra los colores disponibles
 *
 * \param colores[] eColor array de estructura
 * \param tamCol int tamanio de estructura
 * \return int retorna 1 si no hay conflictos o 0 si hay error
 *
 */
int mostrarColores(eColor colores[], int tamCol);

/** \brief Muestra un color
 *
 * \param color eColor array de Colores
 * \return void No tiene retorno, funcion para mayor orden
 *
 */
void mostrarColor(eColor color);
/** \brief Carga la descripcion vinculada al idColor de estructura eMoto
 *
 * \param id int id ingresado del Color elegido
 * \param colores[] eColor array de Colores
 * \param tamCol int tamanio de array de colores
 * \param desc[] char variable utilizada para guardar la descripcion del ID del color
 * \return int retorna 1 si no hay conflicto o 0 si se encuentra un error
 *
 */
int cargarDescripcionColor(int id, eColor colores[], int tamCol, char desc[]);
