/*
 * ArrayPassenger.c
 *
 *  Created on: 3 may. 2022
 *      Author: Nani
 */
#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "Inputs.h"
#include <string.h>
#define SIZETIPO 2

static TypePassenger listaTiposPasajeros[SIZETIPO] = {{1,"Economico"},{2, "Primera Clase"}};


Passenger PedirDatosPasajero()
{
	Passenger unPasajero;
	Passenger auxiliar;
	int validarTipoPasajero;
	int opcionTipoPasajero;
	char opcionFlycode[10];

	fflush(stdin);

	PedirCadena(unPasajero.name, "Ingrese su nombre: ");
	PedirCadena(unPasajero.lastName, "Ingrese su apellido: ");
	auxiliar.price = PedirFlotante("Ingrese el precio del vuelo: ");
	while(auxiliar.price < 1)
	{
		auxiliar.price = PedirFlotante("El precio no puede ser igual o menor a cero, vuelva a ingresar el precio: ");
	}
	unPasajero.price = auxiliar.price;

	MostrarTiposPasajeros();
	opcionTipoPasajero = PedirEntero("Ingrese el tipo de pasajero: ");
	validarTipoPasajero = ValidarTipoPasajero(opcionTipoPasajero);

	while(validarTipoPasajero == 0)
	{
		MostrarTiposPasajeros();
		opcionTipoPasajero = PedirEntero("Error, el tipo de pasajero no existe, vuelva a ingresar el tipo de pasajero: ");
		validarTipoPasajero = ValidarTipoPasajero(opcionTipoPasajero);
	}

	unPasajero.idTypePassenger = opcionTipoPasajero;

	printf("Ingrese el codigo del vuelo: ");
	scanf("%s", opcionFlycode);
	strcpy(unPasajero.flycode, opcionFlycode);

//	PedirCadena(unPasajero.flycode,"Ingrese el codigo del vuelo: ");
// 	Descarté usar el input porque no permite ingresar numeros en el codigo de vuelo, solo letras.

	auxiliar.statusFlight = PedirEntero("Ingrese el estado del vuelo: (CANCELADO (0) ACTIVO (1)): ");
	while(auxiliar.statusFlight < 0 || auxiliar.statusFlight > 1)
	{
		auxiliar.statusFlight = PedirFlotante("El estado del vuelo debe ser -1 o 0, vuelva a ingresar el estado del vuelo: ");
	}
	unPasajero.statusFlight = auxiliar.statusFlight;


	return unPasajero;
}

int ValidarTipoPasajero(int validarTipoPasajero)
{
	int retorno;

	retorno = 0;
	for(int i=0; i<SIZETIPO; i++)
	{
		if(validarTipoPasajero == listaTiposPasajeros[i].idTypePassenger)
		{
			retorno= 1;
			break;
		}
	}

	return retorno;
}

void MostrarTiposPasajeros ()
{
	for(int i=0; i<2;i++)
	{
		printf("%d. %s \n", listaTiposPasajeros[i].idTypePassenger, listaTiposPasajeros[i].descripcion);
	}
}

int initPassengers(Passenger listaPasajeros[], int tam)
{
	int resultado;
	resultado = -1;

	if (listaPasajeros != NULL || tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			listaPasajeros[i].isEmpty = 1;
			listaPasajeros[i].id=0;
			resultado = 0;
		}
	}

	return resultado;
}

int BuscarLibre(Passenger listaPasajeros[], int tam)
{
	int index;
	index = -1;


	if (listaPasajeros != NULL || tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(listaPasajeros[i].isEmpty==1)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}
int addPassenger(Passenger listaPasajeros[], int tam, int* id)
{
	int index;
	int retorno = -1;
	index = BuscarLibre(listaPasajeros, tam);

	if (listaPasajeros != NULL || tam > 0)
	{

		if(index!=-1)
		{

			listaPasajeros[index] = PedirDatosPasajero();
			listaPasajeros[index].id = *id;
			listaPasajeros[index].isEmpty = 0;
			*id = *id+1;
			retorno = 0;
		}

	}
	return retorno;
}

int findPassengerById(Passenger listaPasajeros[], int tam, int id)
{
	int retorno = -1;
	if (listaPasajeros != NULL || tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(listaPasajeros[i].isEmpty==0 && listaPasajeros[i].id == id)//lo encontró.
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int removePassenger(Passenger listaPasajeros[], int tam, int id)
{
	int retorno = -1;
	int index;
	char confirmacion;

	if (listaPasajeros != NULL || tam > 0)
	{
		index = findPassengerById(listaPasajeros, tam, id);
		if(index != -1)//lo encontró.
		{
			printf("Está seguro de que desea eliminar el pasajero? s/n: ");
			fflush(stdin);
			scanf("%c", &confirmacion);
			while(confirmacion!='s' && confirmacion!='n')
			{
				printf("Ingrese si o no: s/n: ");
				scanf("%c", &confirmacion);
			}
			if(confirmacion=='s')
			{
				listaPasajeros[index].isEmpty=1;
				retorno=0;
			}
		}

	}
	return retorno;
}

int sortPassengersByLastName(Passenger listaPasajeros[], int tam, int orden)
{
	int retorno = -1;
	Passenger auxiliar;


	if (listaPasajeros != NULL || tam > 0)
	{

		if(orden == 0)
		{
			for(int i=0; i<tam-1; i++)
			{
				for(int j= i+1; j<tam; j++)
				{
					if((strcmp(listaPasajeros[i].lastName, listaPasajeros[j].lastName)>0))
					{
						auxiliar = listaPasajeros[i];
						listaPasajeros[i] = listaPasajeros[j];
						listaPasajeros[j] = auxiliar;
						retorno = 0;
					}

					if((strcmp(listaPasajeros[i].lastName, listaPasajeros[j].lastName)==0))
					{
						if(listaPasajeros[i].idTypePassenger > listaPasajeros[j].idTypePassenger)
						{
							auxiliar = listaPasajeros[i];
							listaPasajeros[i] = listaPasajeros[j];
							listaPasajeros[j] = auxiliar;
							retorno = 0;
						}
					}
				}
			}
		}
		if(orden == 1)
		{
			for(int i=0; i<tam-1; i++)
			{
				for(int j= i+1; j<tam; j++)
				{
					if((strcmp(listaPasajeros[i].lastName, listaPasajeros[j].lastName)<0))
					{
						auxiliar = listaPasajeros[i];
						listaPasajeros[i] = listaPasajeros[j];
						listaPasajeros[j] = auxiliar;
						retorno = 0;
					}
					if((strcmp(listaPasajeros[i].lastName, listaPasajeros[j].lastName)==0))
					{
						if(listaPasajeros[i].idTypePassenger < listaPasajeros[j].idTypePassenger)
						{
							auxiliar = listaPasajeros[i];
							listaPasajeros[i] = listaPasajeros[j];
							listaPasajeros[j] = auxiliar;
							retorno = 0;
						}
					}
				}
			}
		}
	}

	return retorno;
}

void printOnePassenger (Passenger unPasajero, TypePassenger unTipo)
{
	printf("%d %-10s %-10s %4.2f %10s %10s \n",unPasajero.id ,unPasajero.lastName, unPasajero.name, unPasajero.price, unPasajero.flycode, unTipo.descripcion);
}


int printPassengers (Passenger listaPasajeros[], int tam)
{
	int retorno = 0;
	int indexTipoPasajero;



	if (listaPasajeros != NULL || tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(listaPasajeros[i].isEmpty==0)
			{
				indexTipoPasajero = EncontrarRelacionPasajeroTipo(listaPasajeros[i]);
				printOnePassenger(listaPasajeros[i], listaTiposPasajeros[indexTipoPasajero]);
				retorno =1;
			}
		}
	}

	return retorno;
}

int EncontrarRelacionPasajeroTipo(Passenger unPasajero)
{
	int retorno;
	retorno = -1;

	for(int i = 0; i<SIZETIPO; i++)
	{
		if(unPasajero.idTypePassenger == listaTiposPasajeros[i].idTypePassenger)
		{
			retorno = i;
		}
	}

	return retorno;
}
int sortPassengersByCode(Passenger listaPasajeros[], int tam, int orden)
{
	int retorno = -1;
	Passenger auxiliar;


	if (listaPasajeros != NULL || tam > 0)
	{

		if(orden == 0)
		{
			for(int i=0; i<tam-1; i++)
			{
				for(int j= i+1; j<tam; j++)
				{
					if((strcmp(listaPasajeros[i].flycode, listaPasajeros[j].flycode)>0))
					{
						auxiliar = listaPasajeros[i];
						listaPasajeros[i] = listaPasajeros[j];
						listaPasajeros[j] = auxiliar;
						retorno = 0;
					}
				}
			}
		}
		if(orden == 1)
		{
			for(int i=0; i<tam-1; i++)
			{
				for(int j= i+1; j<tam; j++)
				{
					if((strcmp(listaPasajeros[i].flycode, listaPasajeros[j].flycode)<0))
					{
						auxiliar = listaPasajeros[i];
						listaPasajeros[i] = listaPasajeros[j];
						listaPasajeros[j] = auxiliar;
						retorno = 0;
					}
				}
			}
		}
	}

	return retorno;
}

int ModificarUnPasajero(Passenger listaPasajeros[], int tam)
{
	int ID;
	int bandera;
	int opcion;
	int opcionTipoPasajero;
	int validarTipoPasajero;
	int indexPasajero;
	bandera = 0;
	Passenger auxiliar;

		printPassengers(listaPasajeros, tam);
		printf("Ingrese el ID del pasajero: ");
		scanf("%d", &ID);

		if(listaPasajeros != NULL || tam > 0)
		{
			indexPasajero = findPassengerById(listaPasajeros, tam, ID);
			if(indexPasajero != -1)//lo encontró.
			{
				do
				{
					printf("1. Modificar nombre \n");
					printf("2. Modificar apellido \n");
					printf("3. Modificar precio \n");
					printf("4. Modificar tipo de pasajero \n");
					printf("5. Modificar codigo de vuelo \n");
					printf("6. Salir.\n");
					printf("Elija una opcion: ");
					scanf("%d", &opcion);
					switch(opcion)
					{
						case 1:
							PedirCadena(listaPasajeros[indexPasajero].name, "Ingrese el nuevo nombre del pasajero: ");
							bandera=1;
						break;

						case 2:
							PedirCadena(listaPasajeros[indexPasajero].lastName, "Ingrese el nuevo apellido del pasajero: ");
							bandera=1;
							break;

						case 3:
							auxiliar.price = PedirFlotante("Ingrese el precio del vuelo: ");
							while(auxiliar.price < 1)
							{
								auxiliar.price = PedirFlotante("El precio no puede ser igual o menor a cero, vuelva a ingresar el precio: ");
							}
							listaPasajeros[indexPasajero].price = auxiliar.price;
							bandera=1;
							break;

						case 4:
							MostrarTiposPasajeros();
							opcionTipoPasajero = PedirEntero("Ingrese el tipo de pasajero: ");
							validarTipoPasajero = ValidarTipoPasajero(opcionTipoPasajero);

							while(validarTipoPasajero == 0)
							{
								MostrarTiposPasajeros();
								opcionTipoPasajero = PedirEntero("Error, el tipo de pasajero no existe, vuelva a ingresar el tipo de pasajero: ");
								validarTipoPasajero = ValidarTipoPasajero(opcionTipoPasajero);
							}
							listaPasajeros[indexPasajero].idTypePassenger = opcionTipoPasajero;
							bandera=1;
							break;

						case 5:
							PedirCadena(listaPasajeros[indexPasajero].flycode,"Ingrese el nuevo codigo del vuelo: ");
							bandera = 1;
							break;


						case 6:
							printf("Volviendo al menu principal... \n");
							break;

						default:
							printf("Ingrese una opcion valida...\n");
							break;
					}

				}while(opcion!=6);
			}

		}
	return bandera;
}

int BajaPasajero (Passenger listaPasajeros[], int tam)
{
	int retorno;
	int ID;
	retorno = -1;


	printPassengers(listaPasajeros, tam);
	printf("Ingrese el ID del pasajero: ");
	scanf("%d", &ID);

	retorno = removePassenger(listaPasajeros, tam, ID);

	return retorno;
}

int MostrarOpcionesListado()
{
	int opcion;

	printf("1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n");
	printf("2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el preciopromedio.\n");
	printf("3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’.\n");
	printf("4. Salir.\n");
	printf("Elija una opcion: ");
	scanf("%d", &opcion);

	return opcion;

}

int MostrarPasajerosOrdenadosApellido (Passenger listaPasajeros[], int tam)
{
	int orden;
	int retorno;
	retorno = -1;

	printf("Ingrese el orden con el que desea ordenar a los pasajeros: ASCENDENTE(1)(Z-A) DESCENDENTE(0)(A-Z): \n");
	scanf("%d", &orden);
	while(orden<0 || orden >1)
	{
		printf("El orden debe ser 1 o 0: ");
		scanf("%d", &orden);
	}


	retorno = sortPassengersByLastName(listaPasajeros, tam, orden);
	printPassengers(listaPasajeros, tam);

	printf("\n");

	return retorno;
}

float CalcularTotalPreciosVuelos (Passenger listaPasajeros[], int tam)
{
	float acumuladorPrecios;
	acumuladorPrecios = 0;

	for(int i = 0; i<tam; i++)
	{
		if(listaPasajeros[i].isEmpty==0)
		{
			acumuladorPrecios = acumuladorPrecios + listaPasajeros[i].price;
		}
	}

	return acumuladorPrecios;
}

int CalcularCantidadVuelos (Passenger listaPasajeros[], int tam)
{
	int contadorVuelos;
	contadorVuelos=0;

	for(int i = 0; i<tam; i++)
	{
		if(listaPasajeros[i].isEmpty==0)
		{
			contadorVuelos++;
		}
	}

	return contadorVuelos;
}

int ContarPasajerosMayorPrecioPromedio (Passenger listaPasajeros[], int tam, int precioPromedio)
{
	int contadorPasajeros;
	contadorPasajeros=0;

	for(int i=0; i<tam; i++)
	{
		if(listaPasajeros[i].isEmpty == 0 && listaPasajeros[i].price > precioPromedio)
		{
			contadorPasajeros++;
		}
	}
	return contadorPasajeros;
}

void MostrarOpcion2Listado (Passenger listaPasajeros[], int tam)
{
	float totalPrecios;
	int cantidadVuelos;
	float promedioPrecio;
	int cantidadPasajerosMayorPrecioPromedio;

	totalPrecios = CalcularTotalPreciosVuelos(listaPasajeros, tam);
	cantidadVuelos = CalcularCantidadVuelos(listaPasajeros, tam);

	promedioPrecio = totalPrecios / cantidadVuelos;
	cantidadPasajerosMayorPrecioPromedio= ContarPasajerosMayorPrecioPromedio(listaPasajeros, tam, promedioPrecio);

	printf("\nEl total de los precios de los pasajes es de %.2f\n", totalPrecios);
	printf("El precio promedio de los  pasajes es de %.2f\n", promedioPrecio);
	printf("La cantidad de pasajeros que superan el precio promedio es de %d \n\n", cantidadPasajerosMayorPrecioPromedio);

}

int MostrarOpcion3Listado (Passenger listaPasajeros[], int tam)
{
	int orden;
	int retorno;
	int indexTipo;
	retorno = -1;

	printf("Ingrese el orden con el que desea ordenar a los pasajeros: ASCENDENTE(1)(Z-A) DESCENDENTE(0)(A-Z): \n");
	scanf("%d", &orden);
	while(orden<0 || orden >1)
	{
		printf("El orden debe ser 1 o 0: ");
		scanf("%d", &orden);
	}

	retorno = sortPassengersByCode(listaPasajeros, tam, orden);

	for(int i=0; i<tam; i++)
	{
		indexTipo = EncontrarRelacionPasajeroTipo(listaPasajeros[i]);
		if(listaPasajeros[i].isEmpty == 0 && listaPasajeros[i].statusFlight == ACTIVO)
		{
			printOnePassenger(listaPasajeros[i], listaTiposPasajeros[indexTipo]);
		}

	}

	printf("\n");
	return retorno;
}

void Inicializar5Pasajeros(Passenger listaPasajeros[], int* idMain)
{
    int id[5]={1,2,3,4,5};
    char name[5][51]={"Marina", "German", "Octavio","Matias","Christian"};
    char lastName[5][51]={"Cardozo", "Scarafilo", "Villegas", "Bustamante", "Baus"};
    float price[5]={5000, 7000, 2000, 3000, 1000};
    char flycode[5][10]={"AA52","AA50","AB71","BB20","AC87"};
    int idTypePassenger[5]={2,1,1,2,1}; //Marina, espero que tengas en cuenta que te puse en primera clase, tkm.
    int statusFlight[5] = {1,1,1,0,0};
    int isEmpty[5]={0,0,0,0,0};

    for(int i=0; i<5; i++)
    {
        listaPasajeros[i].id = id[i];
        strcpy(listaPasajeros[i].name, name[i]);
        strcpy(listaPasajeros[i].lastName, lastName[i]);
        listaPasajeros[i].price = price[i];
        strcpy(listaPasajeros[i].flycode, flycode[i]);
        listaPasajeros[i].idTypePassenger = idTypePassenger[i];
        listaPasajeros[i].statusFlight = statusFlight[i];
        listaPasajeros[i].isEmpty = isEmpty[i];
    }

    *idMain = 6;

    printf("\nEl alta forzada se realizó con éxito :)\n\n");
}

