/*
 * Muestrasdeesultados.h
 *
 *  Created on: 10 abr. 2022
 *      Author: Nani
 */

#ifndef MUESTRASDERESULTADOS_H_
#define MUESTRASDERESULTADOS_H_
/// \fn void MostrarValorKilometros(int)
/// \brief Identifica si hay un valor ingresado para los kil�metros para determinar si es necesario mostrar "x" o dicho valor ingresado.
/// \param Recibe el valor de la variable kil�metros.
void MostrarValorKilometros(int);

/// \fn void MostrarValoresVuelos(int, int)
/// \brief Identifica si hay valores ingresados para los vuelos para determinar si es necesario mostrar "z" e "y" o dichos valores ingresado.
/// \param Recibe el valor del vuelo por Aerol�neas.
/// \param Recibe el valor del vuelo por Latam.
void MostrarValoresVuelos(int, int);

/// \fn void MostrarResultadosOpcion4(int, int, int, float, float, int, int, float, float, int)
/// \brief Determina en base al valor de una bandera si es necesario mostrar los valores de los c�lculos realizados en la opci�n 3 como "r" o dichos valores calculados.
/// \param Recibe el valor de la bandera.
/// \param Recibe el valor del vuelo por Latam con tarjeta de d�bido.
/// \param Recibe el valor del vuelo por Latam con tarjeta de cr�dito.
/// \param Recibe el valor del vuelo por Latam en Bitcoins.
/// \param Recibe el valor unitario por kil�metro por Latam.
/// \param Recibe el valor del vuelo por Aerol�neas con tarjeta de d�bido.
/// \param Recibe el valor del vuelo por Aerol�neas con tarjeta de cr�dito.
/// \param Recibe el valor del vuelo por Aerol�neas en Bitcoins.
/// \param Recibe el valor unitario por kil�metro por Aerol�neas.
/// \param Recibe el valor de la diferencia de precio entre el vuelo por Latam y por Aerol�neas.
void MostrarResultadosOpcion4 (int,int,int,float,float,int,int,float,float,int);

/// \fn void MostrarCargaForzada(int, int, int)
/// \brief Muestra los resultados de los c�lculos en base a valores determinados para los kil�metros y para ambos vuelos.
/// \param Recibe el valor de la variable kil�metros (7090).
/// \param Recibe el valor del vuelo por Aerol�neas (162965).
/// \param Recibe el valor del vuelo por Latam (159339).
void MostrarCargaForzada(int,int,int);


#endif /* MUESTRASDERESULTADOS_H_ */
