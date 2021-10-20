#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

#endif // FECHA_H_INCLUDED

/** \brief Compara una primera fecha contra una segunda para ser ejecutada segun una condicion
 *
 * \param f1 eFecha fecha numero 1
 * \param f2 eFecha fecha numero 2
 * \return int retorna 1 si las fechas coindicen o 0 si son diferentes
 *
 */
int comparaFechas(eFecha f1, eFecha f2);
