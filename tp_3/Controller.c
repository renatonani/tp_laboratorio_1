#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "inputs.h"

int controller_getLastID(char* path, int* id)
{
	int retorno;
	FILE* pArchivo;
	retorno=0;

	pArchivo = fopen(path, "rb");
	if(pArchivo != NULL && id !=NULL)
	{
		fread(id, sizeof(int), 1, pArchivo);
		retorno = 1;
	}

	fclose(pArchivo);

	return retorno;
}
int controller_saveLastID(char* path, int* id)
{
	FILE* pArchivo;
	int retorno;
	retorno=0;

	pArchivo = fopen(path,"wb");
	if(pArchivo != NULL && id !=NULL)
	{
		fwrite(id, sizeof(int), 1, pArchivo);
		retorno = 1;
	}

	fclose(pArchivo);

	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int cantidadCargados;
	cantidadCargados = -1;

	if(path!= NULL && pArrayListPassenger!=NULL)
	{
		pArchivo = fopen(path,"r");
		cantidadCargados = parser_PassengerFromText(pArchivo, pArrayListPassenger);
		fclose(pArchivo);
	}

    return cantidadCargados;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int cantidadCargados;
	cantidadCargados = -1;

	if(path!= NULL && pArrayListPassenger!=NULL)
	{
		pArchivo = fopen(path,"rb");
		cantidadCargados = parser_PassengerFromBinary(pArchivo, pArrayListPassenger);
		fclose(pArchivo);
	}

	return cantidadCargados;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{

	Passenger* this;

	int id;
	char nombreStr[50];
	char apellidoStr[50];
	char precioStr[50];
	float precio;
	char tipoPasajeroStr[50];
	char codigoVueloStr[50];
	char estadoVueloStr[50];
	int validarDato;
	int retorno;
	retorno = 0;

	if(pArrayListPassenger != NULL)
	{

		PedirCadena(nombreStr, "Ingrese el nombre del pasajero: ");
		validarDato = ValidarUnaCadena(nombreStr);
		while(validarDato == 0)
		{
			PedirCadena(nombreStr, "Error, el nombre no puede contener numeros, ingrese el nombre del pasajero nuevamente: ");
			validarDato = ValidarUnaCadena(nombreStr);
		}

		PedirCadena(apellidoStr, "Ingrese el apellido del pasajero: ");
		validarDato = ValidarUnaCadena(apellidoStr);
		while(validarDato == 0)
		{
			PedirCadena(apellidoStr, "Error, el apellido no puede contener numeros, ingrese el nombre del pasajero nuevamente: ");
			validarDato = ValidarUnaCadena(apellidoStr);
		}


		PedirCadena(precioStr,"Ingrese el precio del vuelo: ");
		validarDato = EsFlotante(precioStr);
		precio = atof(precioStr);
		while(validarDato==0 || precio<=0)
		{
			PedirCadena(precioStr,"Error, ingrese el precio del vuelo nuevamente: ");
			validarDato = EsFlotante(precioStr);
			precio = atof(precioStr);
		}

		PedirCadena(tipoPasajeroStr, "Ingrese el tipo de pasajero ('FirstClass' // 'ExecutiveClass' // 'EconomyClass'): ");
		validarDato = ValidarTipoPasajero(tipoPasajeroStr);

		while(validarDato==0)
		{
			PedirCadena(tipoPasajeroStr, "Error, ingrese el tipo de pasajero nuevamente: ");
			validarDato = ValidarTipoPasajero(tipoPasajeroStr);
		}

		PedirCadena(codigoVueloStr, "Ingrese el codigo de vuelo: ");
		validarDato = ValidarTamanioUnaCadena(codigoVueloStr, 7);
		while(validarDato==0)
		{
			PedirCadena(codigoVueloStr, "Error, ingrese el codigo de vuelo nuevamente: ");
			validarDato = ValidarTamanioUnaCadena(codigoVueloStr, 7);
		}

		PedirCadena(estadoVueloStr, "Ingrese el estado del vuelo: ");
		validarDato = ValidarUnaCadena(estadoVueloStr);
		while(validarDato == 0)
		{
			PedirCadena(estadoVueloStr, "Error, el estado de vuelo no puede contener numeros, ingrese el estado de vuelo nuevamente: ");
			validarDato = ValidarUnaCadena(estadoVueloStr);
		}
		if(controller_getLastID("id.txt", &id) == 1)
		{
			id++;
			this = Passenger_newParametros(id, nombreStr, apellidoStr, precioStr, tipoPasajeroStr, codigoVueloStr, estadoVueloStr);
		}

		if(this != NULL)
		{
//			if(controller_saveLastID("id.txt", &id) == 1)
			{
				ll_add(pArrayListPassenger, this);
				retorno = 1;
			}
		}
	}
    return retorno;
}
/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int cantidad;
	int retorno;
	retorno = 0;
	cantidad = ll_len(pArrayListPassenger);

	Passenger* this;
	if(cantidad>0)
	{
		printf("\n%8s %20s %20s %13s %17s %13s %13s\n\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "TIPOPASAJERO", "CODIGOVUELO", "ESTADOVUELO");
		for(int i=0; i<cantidad; i++)
		{
			this = (Passenger*)ll_get(pArrayListPassenger, i);
			Passenger_PrintOne(this);
		}
		printf("\nSe listaron %d pasajeros\n\n",cantidad);
		retorno = 1;
	}
    return retorno;
}
/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int id;
	int idIngresada;
	int cantidad;
	int retorno = 0;
	int opcion;
	char nombreStr[50];
	char apellidoStr[50];
	char precioStr[50];
	float precio;
	int tipoPasajero;
	char codigoVueloStr[50];
	char estadoVueloStr[50];
	int validarDato;

	Passenger* this;

	if(pArrayListPassenger != NULL)
	{
		cantidad = ll_len(pArrayListPassenger);
		controller_ListPassenger(pArrayListPassenger);
		idIngresada = PedirEntero("Ingrese el id del pasajero a modificar: ");

		for(int i=0; i<cantidad; i++)
		{
			this = (Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_getId(this, &id);
			if(id == idIngresada)
			{
				do
				{
					printf("1. Modificar nombre \n");
					printf("2. Modificar apellido \n");
					printf("3. Modificar precio \n");
					printf("4. Modificar tipo de pasajero \n");
					printf("5. Modificar codigo de vuelo \n");
					printf("6. Modificar estado del vuelo \n");
					printf("7. Salir.\n");
					opcion= PedirEntero("Elija una opcion: ");
					switch(opcion)
					{
						case 1:
							PedirCadena(nombreStr, "Ingrese el nuevo nombre del pasajero: ");
							validarDato = ValidarUnaCadena(nombreStr);
							while(validarDato == 0)
							{
								PedirCadena(nombreStr, "Error, el nombre no puede contener numeros, ingrese el nombre del pasajero nuevamente: ");
								validarDato = ValidarUnaCadena(nombreStr);
							}
							Passenger_setNombre(this, nombreStr);
							retorno = 1;
							break;
						case 2:
							PedirCadena(apellidoStr, "Ingrese el apellido del pasajero: ");
							validarDato = ValidarUnaCadena(apellidoStr);
							while(validarDato == 0)
							{
								PedirCadena(apellidoStr, "Error, el apellido no puede contener numeros, ingrese el nombre del pasajero nuevamente: ");
								validarDato = ValidarUnaCadena(apellidoStr);
							}
							Passenger_setApellido(this, apellidoStr);
							retorno = 1;
							break;
						case 3:
							PedirCadena(precioStr,"Ingrese el nuevo precio del vuelo: ");
							validarDato = EsFlotante(precioStr);
							precio = atof(precioStr);
							while(validarDato==0 || precio<=0)
							{
								PedirCadena(precioStr,"Error, ingrese el precio del vuelo nuevamente: ");
								validarDato = EsFlotante(precioStr);
								precio = atof(precioStr);
							}

							Passenger_setPrecio(this, precio);
							retorno = 1;
							break;
						case 4:
							tipoPasajero = PedirEntero("Escoja uno de los siguientes numeros para definir el tipo de pasajero: (1) FirstClass / (2) ExecutiveClass / (3) EconomyClass ");

							while(tipoPasajero != 1 && tipoPasajero !=2 && tipoPasajero != 3)
							{
								tipoPasajero = PedirEntero("El tipo de pasajero debe ser 1, 2 o 3");
							}
							Passenger_setTipoPasajero(this, tipoPasajero);
							retorno = 1;
							break;
						case 5:
							PedirCadena(codigoVueloStr, "Ingrese el nuevo codigo de vuelo: ");
							validarDato = ValidarTamanioUnaCadena(codigoVueloStr, 7);
							while(validarDato==0)
							{
								PedirCadena(codigoVueloStr, "Error, ingrese el codigo de vuelo nuevamente: ");
								validarDato = ValidarTamanioUnaCadena(codigoVueloStr, 7);
							}
							Passenger_setCodigoVuelo(this, codigoVueloStr);
							retorno = 1;
							break;
						case 6:
							PedirCadena(estadoVueloStr, "Ingrese el nuevo estado del vuelo: ");
							validarDato = ValidarUnaCadena(estadoVueloStr);
							while(validarDato == 0)
							{
								PedirCadena(estadoVueloStr, "Error, el estado de vuelo no puede contener numeros, ingrese el estado de vuelo nuevamente: ");
								validarDato = ValidarUnaCadena(estadoVueloStr);
							}
							Passenger_setEstadoVuelo(this, estadoVueloStr);
							retorno = 1;
							break;
						case 7:
							printf("Saliendo...\n");
							break;
						default:
							printf("Elija una opcion valida.\n");
							break;
					}

				}while(opcion!=7);
			}
		}
	}
	return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int idIngresado;
	int id;
	int cantidad;
	int retorno = 0;
	char confirmacion;
	Passenger* this;

	if(pArrayListPassenger != NULL)
	{
		cantidad = ll_len(pArrayListPassenger);
		controller_ListPassenger(pArrayListPassenger);
		idIngresado = PedirEntero("Ingrese el id del pasajero a eliminar: ");

		for(int i=0; i<cantidad; i++)
		{
			this = (Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_getId(this, &id);
			if(id == idIngresado)
			{
				printf("Está seguro de que desea eliminar el pasajero? s/n: ");
				fflush(stdin);
				scanf("%c", &confirmacion);

				while(confirmacion!='s' && confirmacion!='n')
				{
					printf("Ingrese si o no: s/n: ");
					fflush(stdin);
					scanf("%c", &confirmacion);
				}

				if(confirmacion=='s')
				{
					ll_remove(pArrayListPassenger, i);
					retorno = 1;
					break;
				}

			}
		}
	}
    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int opcion;
	int orden;
	int retorno;
	int cantidad;
	cantidad = ll_len(pArrayListPassenger);
	retorno = 0;

	if(cantidad == 0)
	{
		return -1;
	}
	if(pArrayListPassenger != NULL)
	{
		do
		{
		printf("Elija el criterio de ordenamiento:\n"
				"1. Ordenamiento por id.\n"
				"2. Ordenamiento por nombre.\n"
				"3. Ordenamiento por apellido.\n"
				"4. Ordenamiento por precio.\n"
				"5. Ordenamiento por codigo de vuelo.\n"
				"6. Ordenamiento por tipo de pasajero.\n"
				"7. Ordenamiento por estado de vuelo.\n"
				"8. Salir.");
		scanf("%d", &opcion);

		if(opcion!=8)
		{
			printf("Elija el orden con el que desea ordenar: \n"
					"1. de la A a la Z\n"
					"2. de la Z a la A\n"
					"3. Salir.\n");
			scanf("%d",&orden);

			while(orden !=1 && orden !=2 && orden !=3)
			{
				printf("Elija el orden con el que desea ordenar: \n"
						"1. de la A a la Z\n"
						"2. de la Z a la A\n"
						"3. Salir.\n");
				scanf("%d",&orden);
			}
		}

		switch(opcion)
		{
			case 1:
				ll_sort(pArrayListPassenger, Passenger_CompareById, orden);
				printf("Se ordenó por ID.\n");
				retorno = 1;
				break;
			case 2:
				printf("Esto llevara algunos segundos..");
				ll_sort(pArrayListPassenger, Passenger_CompareByName, orden);
				printf("Se ordenó por nombre.\n");
				retorno = 1;
				break;
			case 3:
				printf("Esto llevara algunos segundos..");
				ll_sort(pArrayListPassenger, Passenger_CompareByLastName, orden);
				printf("Se ordenó por apellido.\n");
				retorno = 1;
				break;
			case 4:
				ll_sort(pArrayListPassenger, Passenger_CompareByPrice, orden);
				printf("Se ordenó por precio.\n");
				retorno = 1;
				break;
			case 5:
				printf("Esto llevara algunos segundos..");
				ll_sort(pArrayListPassenger, Passenger_CompareByFlyCode, orden);
				printf("Se ordenó por codigo de vuelo.\n");
				retorno = 1;
				break;
			case 6:
				ll_sort(pArrayListPassenger, Passenger_CompareByTypePassenger, orden);
				printf("Se ordenó por tipo de pasajero.\n");
				retorno = 1;
				break;
			case 7:
				printf("Esto llevara algunos segundos..");
				ll_sort(pArrayListPassenger, Passenger_CompareByStatusFlight, orden);
				printf("Se ordenó por tipo de estado de vuelo.\n");
				retorno = 1;
				break;
			case 8:
				printf("Saliendo...\n");
				break;
			default:
				printf("Elija una opcion valida.\n");
				break;
		}
		}
		while(opcion!=8);
	}

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	int retorno;
	retorno = 0;
	Passenger* this;
	int cantidad;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[8];
	char estadoVuelo[30];
	char tipoPasajeroStr[50];
	int p = 0;

	if(pArrayListPassenger != NULL && path != NULL)
	{
		pArchivo = fopen(path,"w");
		cantidad = ll_len(pArrayListPassenger);
		fprintf(pArchivo, "id,nombre,apellido,precio,tipopasajero,codigovuelo,estadovuelo\n");
		for(int i=0; i<cantidad; i++)
		{
			this = (Passenger*)ll_get(pArrayListPassenger, i);

			Passenger_getId(this, &id);
			Passenger_getNombre(this, nombre);
			Passenger_getApellido(this, apellido);
			Passenger_getPrecio(this, &precio);
			Passenger_getTipoPasajero(this, &tipoPasajero);
			Passenger_getCodigoVuelo(this, codigoVuelo) ;
			Passenger_getEstadoVuelo(this, estadoVuelo);

			if(this != NULL)
			{
			Passenger_tipoIntToStr(tipoPasajeroStr, &tipoPasajero);
			fprintf(pArchivo, "%d,%s,%s,%.2f,%s,%s,%s\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajeroStr, estadoVuelo);
			p++;
			}
		}
	}
	fclose(pArchivo);
	if(p==cantidad)
	{
		retorno = p;
	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pArchivo;
	Passenger* this;
	int retorno;
	int cantidad;
	int p = 0;
	retorno = 0;

	pArchivo = fopen(path,"wb");

	if(pArrayListPassenger!=NULL)
	{
		cantidad = ll_len(pArrayListPassenger);

		for(int i=0; i<cantidad;i++)
		{
			this=(Passenger*)ll_get(pArrayListPassenger, i);
			fwrite(this, sizeof(Passenger),1, pArchivo);
			p++;
		}

	}
	fclose(pArchivo);
	if(p==cantidad)
	{
		retorno = p;
	}
    return retorno;
}



