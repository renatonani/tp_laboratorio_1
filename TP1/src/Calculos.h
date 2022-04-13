/*
 * Calculos.h
 *
 *  Created on: 9 abr. 2022
 *      Author: Nani
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
/// \fn int CalcularTarjetaDebito(int)
/// \brief Calcula el valor del vuelo pagando con tarjeta de d�bito (10% de descuento).
/// \param Recibe el valor del vuelo.
/// \return Devuelve el valor del vuelo con el descuento aplicado.
int CalcularTarjetaDebito (int);

/// \fn int CalcularTarjetaCredito(int)
/// \brief Calcula el valor del vuelo pagando con tarjeta de cr�dito (25% de inter�s).
/// \param Recibe el valor del vuelo.
/// \return Devuelve el valor del vuelo con el inter�s aplicado.
int CalcularTarjetaCredito (int);

/// \fn float CalcularBitcoin(int)
/// \brief Calcula el precio del vuelo convirtiendolo a bitcoin.
/// \param Recibe el valor del vuelo.
/// \return Devuelve el valor del vuelo en bitcoins.
float CalcularBitcoin (int);

/// \fn float CalcularPrecioPorKm(int, int)
/// \brief Calcula el precio por kil�metro diviendo este primer dato por el segundo.
/// \param Recibe el valor del vuelo.
/// \param Recibe la cantidad de kil�metros.
/// \return Devuelve el precio unitario de cada kil�metro.
float CalcularPrecioPorKm (int,int);

/// \fn int CalcularDiferenciaPrecios(int, int)
/// \brief Calcula la diferencia de precio entre el valor del vuelo por Latam y el valor del vuelo por Aerolineas.
/// \param Recibe el valor del vuelo por Latam.
/// \param Recibe el valor del vuelo por Aerolineas.
/// \return Devuelve el resultado de la resta entre ambos valores.
int CalcularDiferenciaPrecios (int,int);


#endif /* CALCULOS_H_ */
