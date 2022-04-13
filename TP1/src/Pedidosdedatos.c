/*
 * funcionestp1.c
 *
 *  Created on: 9 abr. 2022
 *      Author: Nani
 */

#include <stdio.h>
#include <stdlib.h>

int PedirKilometros (void)
{
	int kilometros;
	printf("Ingrese los kilómetros del vuelo: ");
	scanf("%d", &kilometros);

	while(kilometros < 1)
	{
		printf("La cantidad de kilometros no puede ser igual o menor a cero. Vuelva a ingresar los datos: ");
		scanf("%d", &kilometros);
	}
	return kilometros;
}

int PedirPrecioAerolineas(void)
{
	int precioAerolineas;
	printf("Precio vuelo Aerolíneas: ");
	scanf("%d", &precioAerolineas);
	while(precioAerolineas < 1)
	{
		printf("El precio no puede ser menor o igual a cero, ingrese nuevamente el precio del vuelo por Aerolíneas: ");
		scanf("%d", &precioAerolineas);
	}
	return precioAerolineas;
}

int PedirPrecioLatam(void)
{
	int precioLatam;
	printf("Precio vuelo Latam: ");
	scanf("%d", &precioLatam);
	while(precioLatam < 1)
	{
		printf("El precio no puede ser menor o igual a cero, ingrese nuevamente el precio del vuelo por Latam: ");
		scanf("%d", &precioLatam);
	}
	return precioLatam;
}
