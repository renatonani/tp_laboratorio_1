/*
 ============================================================================
 Name        : TP_2.c
 Author      : Renato Nani Divisi�n 1C.
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "Inputs.h"
#define TAM 2001

int main(void)
{

	setbuf(stdout, NULL);

	int iniciarPasajeros;
	int opcion;
	int confirmacionAlta;
	int confirmacionModificar;
	int confirmacionBaja;
	int opcionListado;
	int confirmacionListado1;
	int confirmacionListado3;

	Passenger listaPasajeros[TAM];
	iniciarPasajeros = initPassengers(listaPasajeros, TAM);

	if(iniciarPasajeros == 0)
	{
		printf("El programa se inici� correctamente.\n");
	}
	else
	{
		printf("Ocurri� un error al iniciar el programa\n");
	}

//	Passenger unPasajero = {1000,"Pedro","Garcia",2500,"AA11",1,1,0};
//	printOnePassenger(unPasajero);
	do
	{
		printf("1. ALTAS\n");
		printf("2. MODIFICAR\n");
		printf("3. BAJAS\n");
		printf("4. INFORMAR\n");
		printf("5. ALTA FORZADA\n");
		printf("6. SALIR\n");
		printf("Elija una opcion: ");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:
				confirmacionAlta = addPassenger(listaPasajeros, TAM);
				if(confirmacionAlta == 0)
				{
					printf("La carga se realiz� con �xito.\n");
				}
				else
				{
					printf("Ocurri� un error al realizar la carga.\n");
				}

				break;

			case 2:
				if(confirmacionAlta==0)
				{
					confirmacionModificar = ModificarUnPasajero(listaPasajeros, TAM);
					if(confirmacionModificar == 1)
					{
						printf("Se guardaron correctamente los cambios.\n");
					}
					else
					{
						printf("No se realizaron cambios.\n");
					}
				}
				else
				{
					printf("Se debe realizar al menos un alta :( \n");
				}

				break;

			case 3:
				if(confirmacionAlta==0)
				{
					confirmacionBaja = BajaPasajero(listaPasajeros, TAM);
					if(confirmacionBaja == 0)
					{
						printf("La baja se realiz� con �xito.\n");
					}
					else
					{
						printf("Ocurri� un error al realizar la baja.\n");
					}
				}
				else
				{
					printf("Se debe realizar al menos un alta :( \n");
				}

				break;

			case 4:
				if(confirmacionAlta==0)
				{
					do
					{
					opcionListado = MostrarOpcionesListado();
					switch(opcionListado)
					{
						case 1:

							confirmacionListado1 = MostrarPasajerosOrdenadosApellido(listaPasajeros, TAM);
							if(confirmacionListado1!=0)
							{
								printf("Ocurri� un error al realizar el listado\n");
							}
							break;

						case 2:
							MostrarOpcion2Listado(listaPasajeros, TAM);
							break;

						case 3:
							confirmacionListado3 = MostrarOpcion3Listado(listaPasajeros, TAM);
							if(confirmacionListado3!=0)
							{
								printf("Ocurri� un error al realizar el listado\n");
							}
							break;

						case 4:
							printf("Saliendo...\n");
							break;

						default:

							printf("Introduzca una opci�n v�lida\n");
							break;

					}
					}while(opcionListado!=4);
				}
				else
				{
					printf("Se debe realizar al menos un alta :( \n");
				}


				break;

			case 5:
				Inicializar5Pasajeros(listaPasajeros);
				confirmacionAlta=0;
				break;

			case 6:
				printf("Saliendo...");
				break;

			default:
			printf("Introduzca una opcion valida\n");

		}
	}while(opcion != 6);


	return EXIT_SUCCESS;
}
