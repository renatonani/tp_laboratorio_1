/*
 * Muestrasderesultados.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Nani
 */
#include <stdio.h>
#include <stdlib.h>
#include "Calculos.h"
void MostrarValorKilometros(int kilometros)
{
	if(kilometros==0)
		{
		printf("(km=x) \n");
		}
		else
			{
			printf("(km = %d)\n",kilometros);
			}
}
void MostrarValoresVuelos(int precioAerolineas, int precioLatam)
{
	if(precioAerolineas==0)
		{
		printf("(Aerolíneas=y, Latam=z) \n");
		}
		else
			{
			printf("(Aerolíneas=%d, Latam=%d) \n",precioAerolineas,precioLatam);
			}
}

void MostrarResultadosOpcion4 (int banderaResultadosOpcion4, int debitoLatam, int creditoLatam, float bitcoinLatam, float precioPorKmLatam, int debitoAerolineas, int creditoAerolineas, float bitcoinAerolineas, float precioPorKmAerolineas, int diferenciaPrecios)
{
	if(banderaResultadosOpcion4==0)
	{
		printf("Latam:\n"
		"a) Precio con tarjeta de débito: r\n"
		"b) Precio con tarjeta de crédito: r\n"
		"c) Precio pagando con bitcoin : r\n"
		"d) Precio unitario: r\n"
		"Aerolíneas:\n"
		"a) Precio con tarjeta de débito: r\n"
		"b) Precio con tarjeta de crédito: r\n"
		"c) Precio pagando con bitcoin : r\n"
		"d) Precio unitario: r\n"
		"La diferencia de precio es: r\n\n");
	}
		else
		{
		printf("Latam:\n"
				"a) Precio con tarjeta de débito: %d\n"
				"b) Precio con tarjeta de crédito:%d\n"
				"c) Precio pagando con bitcoin : %f\n"
				"d) Precio unitario: %.2f\n"
				"Aerolíneas:\n"
				"a) Precio con tarjeta de débito: %d\n"
				"b) Precio con tarjeta de crédito: %d\n"
				"c) Precio pagando con bitcoin : %f\n"
				"d) Precio unitario: %.2f\n"
				"La diferencia de precio es: %d\n\n",debitoLatam,creditoLatam,bitcoinLatam,precioPorKmLatam,debitoAerolineas,creditoAerolineas,bitcoinAerolineas,precioPorKmAerolineas,diferenciaPrecios);
		}
}

void MostrarCargaForzada(int kilometros, int precioLatam, int precioAerolineas)
{
	int debitoAerolineas;
	int debitoLatam;;
	int creditoAerolineas;
	int creditoLatam;
	float bitcoinAerolineas;
	float bitcoinLatam;
	float precioPorKmAerolineas;
	float precioPorKmLatam;
	int diferenciaPrecios;

	debitoAerolineas = CalcularTarjetaDebito(precioAerolineas);
	debitoLatam = CalcularTarjetaDebito(precioLatam);
	creditoAerolineas = CalcularTarjetaCredito(precioAerolineas);
	creditoLatam = CalcularTarjetaCredito(precioLatam);
	bitcoinAerolineas = CalcularBitcoin(precioAerolineas);
	bitcoinLatam = CalcularBitcoin(precioLatam);
	precioPorKmAerolineas = CalcularPrecioPorKm(precioAerolineas, kilometros);
	precioPorKmLatam = CalcularPrecioPorKm(precioLatam, kilometros);
	diferenciaPrecios = CalcularDiferenciaPrecios(precioLatam, precioAerolineas);

	printf("Latam:\n"
	"a) Precio con tarjeta de débito: %d\n"
	"b) Precio con tarjeta de crédito:%d\n"
	"c) Precio pagando con bitcoin : %f\n"
	"d) Precio unitario: %.2f\n"
	"Aerolíneas:\n"
	"a) Precio con tarjeta de débito: %d\n"
	"b) Precio con tarjeta de crédito: %d\n"
	"c) Precio pagando con bitcoin : %f\n"
	"d) Precio unitario: %.2f\n"
	"La diferencia de precio es: %d\n\n",debitoLatam,creditoLatam,bitcoinLatam,precioPorKmLatam,debitoAerolineas,creditoAerolineas,bitcoinAerolineas,precioPorKmAerolineas,diferenciaPrecios);
}

