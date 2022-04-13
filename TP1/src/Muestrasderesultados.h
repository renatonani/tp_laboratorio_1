/*
 * Muestrasdeesultados.h
 *
 *  Created on: 10 abr. 2022
 *      Author: Nani
 */

#ifndef MUESTRASDERESULTADOS_H_
#define MUESTRASDERESULTADOS_H_
/// \fn void MostrarValorKilometros(int)
/// \brief Identifica si hay un valor ingresado para los kilómetros para determinar si es necesario mostrar "x" o dicho valor ingresado.
/// \param Recibe el valor de la variable kilómetros.
void MostrarValorKilometros(int);

/// \fn void MostrarValoresVuelos(int, int)
/// \brief Identifica si hay valores ingresados para los vuelos para determinar si es necesario mostrar "z" e "y" o dichos valores ingresado.
/// \param Recibe el valor del vuelo por Aerolíneas.
/// \param Recibe el valor del vuelo por Latam.
void MostrarValoresVuelos(int, int);

/// \fn void MostrarResultadosOpcion4(int, int, int, float, float, int, int, float, float, int)
/// \brief Determina en base al valor de una bandera si es necesario mostrar los valores de los cálculos realizados en la opción 3 como "r" o dichos valores calculados.
/// \param Recibe el valor de la bandera.
/// \param Recibe el valor del vuelo por Latam con tarjeta de débido.
/// \param Recibe el valor del vuelo por Latam con tarjeta de crédito.
/// \param Recibe el valor del vuelo por Latam en Bitcoins.
/// \param Recibe el valor unitario por kilómetro por Latam.
/// \param Recibe el valor del vuelo por Aerolíneas con tarjeta de débido.
/// \param Recibe el valor del vuelo por Aerolíneas con tarjeta de crédito.
/// \param Recibe el valor del vuelo por Aerolíneas en Bitcoins.
/// \param Recibe el valor unitario por kilómetro por Aerolíneas.
/// \param Recibe el valor de la diferencia de precio entre el vuelo por Latam y por Aerolíneas.
void MostrarResultadosOpcion4 (int,int,int,float,float,int,int,float,float,int);

/// \fn void MostrarCargaForzada(int, int, int)
/// \brief Muestra los resultados de los cálculos en base a valores determinados para los kilómetros y para ambos vuelos.
/// \param Recibe el valor de la variable kilómetros (7090).
/// \param Recibe el valor del vuelo por Aerolíneas (162965).
/// \param Recibe el valor del vuelo por Latam (159339).
void MostrarCargaForzada(int,int,int);


#endif /* MUESTRASDERESULTADOS_H_ */
