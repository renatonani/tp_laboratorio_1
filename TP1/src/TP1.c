/*
 ============================================================================
Renato Nani.
DNI: 45065450
División C.
Trabajo Práctico N° 1.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Pedidosdedatos.h"
#include "Calculos.h"
#include "Muestrasderesultados.h"

int main(void)
{
	setbuf(stdout,NULL);
	int kilometros;
	int precioAerolineas;
	int precioLatam;
	int banderaResultadosOpcion4;
	int banderaCargaKilometros;
	int banderaCargaPrecios;
	int banderaCostosCalculados;
	int debitoAerolineas;
	int debitoLatam;
	int creditoAerolineas;
	int creditoLatam;
	float bitcoinAerolineas;
	float bitcoinLatam;
	float precioPorKmAerolineas;
	float precioPorKmLatam;
	int diferenciaPrecios;
	int opcion;
	char seguir;
	seguir = 's';
	kilometros = 0;
	precioAerolineas = 0;
	banderaCargaKilometros = 0;//determina si ya fueron ingresados los kilometros o no.
	banderaCargaPrecios = 0;//determina si ya fueron ingresados los precios de los vuelos.
	banderaCostosCalculados = 0;//determina si ya fueron calculados los costos al ingresar la opcion 3
	banderaResultadosOpcion4 = 0;//determina si existen resultados para mostrar en el menú.
//Aclaración: El sistema permite ingresar primero los precios de los vuelos y luego los kilometros ya que su orden no tiene relevancia, pero no avanzar a la opción 3 sin antes haber seleccionado ambas opciones.
	do
		{
			printf("1. Ingresar Kilómetros: ");
			MostrarValorKilometros(kilometros);
			printf("2. Ingresar Precio de Vuelos: ");
			MostrarValoresVuelos(precioAerolineas,precioLatam);
			printf("3. Calcular todos los costos: \n"
					"a) Tarjeta de débito (descuento 10 porciento)\n"
					"b) Tarjeta de crédito (interés 25 porciento)\n"
					"c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n"
					"d) Mostrar precio por km (precio unitario)\n"
					"e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");
			printf("4. Informar Resultados\n");
			MostrarResultadosOpcion4(banderaResultadosOpcion4,debitoLatam,creditoLatam,bitcoinLatam,precioPorKmLatam,debitoAerolineas,creditoAerolineas,bitcoinAerolineas,precioPorKmAerolineas,diferenciaPrecios);
			printf("5. Carga forzada de datos\n");
			printf("6. Salir.\n");
			printf("Elija una opcion: ");
			scanf("%d", &opcion);
			switch(opcion)
			{
				case 1:

					kilometros = PedirKilometros();
					banderaCargaKilometros=1;

					break;
				case 2:

					precioAerolineas = PedirPrecioAerolineas();
					precioLatam = PedirPrecioLatam();
					banderaCargaPrecios=1;

					break;
				case 3:
					if(banderaCargaKilometros == 0 || banderaCargaPrecios == 0)
					{
						printf("Faltan cargar datos antes de poder calcular los costos :(\n");
						break;
					}
					debitoAerolineas = CalcularTarjetaDebito(precioAerolineas);
					debitoLatam = CalcularTarjetaDebito(precioLatam);
					creditoAerolineas = CalcularTarjetaCredito(precioAerolineas);
					creditoLatam = CalcularTarjetaCredito(precioLatam);
					bitcoinAerolineas = CalcularBitcoin(precioAerolineas);
					bitcoinLatam = CalcularBitcoin(precioLatam);
					precioPorKmAerolineas = CalcularPrecioPorKm(precioAerolineas, kilometros);
					precioPorKmLatam = CalcularPrecioPorKm(precioLatam, kilometros);
					diferenciaPrecios = CalcularDiferenciaPrecios(precioLatam, precioAerolineas);
					printf("Costos calculados exitosamente :)\n");
					banderaCostosCalculados=1;

					break;
				case 4:
					if(banderaCostosCalculados==0)
					{
						printf("Se deben calcular los costos antes de mostrar los resultados\n");
							break;
					}
					MostrarResultadosOpcion4(banderaResultadosOpcion4,debitoLatam,creditoLatam,bitcoinLatam,precioPorKmLatam,debitoAerolineas,creditoAerolineas,bitcoinAerolineas,precioPorKmAerolineas,diferenciaPrecios);
					banderaResultadosOpcion4=1;
					break;
				case 5:

					kilometros=7090;
					precioAerolineas=162965;
					precioLatam=159339;

					MostrarCargaForzada(kilometros, precioAerolineas, precioLatam);

					break;

				case 6:
					printf("Gracias por usar nuestra app...");
					seguir = 'n';
					break;
				default:
					printf("Opción incorrecta...\n");
					break;
			}//fin del switch

		} while(seguir == 's');

	return EXIT_SUCCESS;
}//fin de la función
