/*
 * Calculos.c
 *
 *  Created on: 9 abr. 2022
 *      Author: Nani
 */

int CalcularTarjetaDebito (int precio)
{
	int resultado;
	resultado = precio * 0.9;
	return resultado;
}

int CalcularTarjetaCredito (int precio)
{
	int resultado;
	resultado = precio * 1.25;
	return resultado;
}

float CalcularBitcoin (int precio)
{
	float resultado;
	resultado = precio / 4606954.55;
	return resultado;
}

float CalcularPrecioPorKm (int precio, int kilometros)
{
	float resultado;
	resultado = (float)precio / kilometros;
	return resultado;
}

int CalcularDiferenciaPrecios (int precioLatam, int precioAerolineas)
{
	int resultado;
	resultado = precioLatam - precioAerolineas;
	return resultado;
}




