#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int i = 0;
	int r = 0;

	char idStr[50];
	int id;
	char nombreStr[50];
	char apellidoStr[50];
	char precioStr[50];
	char tipoPasajeroStr[50];
	char codigoVueloStr[50];
	char estadoVueloStr[50];
	char lectura[400];

	Passenger* this;

	if(pFile == NULL)
	{
	return -1;
	}

	fscanf(pFile,"%[^\n]",lectura);

	while(!feof(pFile))
	{
		r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",idStr,nombreStr,apellidoStr,precioStr,codigoVueloStr,tipoPasajeroStr,estadoVueloStr);

		if(r==7)
		{
			id = atoi(idStr);
			this = Passenger_newParametros(id, nombreStr, apellidoStr, precioStr, tipoPasajeroStr, codigoVueloStr, estadoVueloStr);

			if(this!=NULL)
			{
				ll_add(pArrayListPassenger, this);
				i++;
			}
		}
	}

    return i;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

	Passenger* this;
	int retorno = 0;
	int i=0;
	if(pFile!=NULL && pArrayListPassenger != NULL)
	{
		while(!feof(pFile))
		{
			this = Passenger_new();
			fread(this, sizeof(Passenger),1, pFile);
			if(feof(pFile))
			{
				break;
			}

			if(this!=NULL)
			{
				ll_add(pArrayListPassenger, this);
				i++;
			}
		}
		retorno = i;
	}


    return retorno;
}
