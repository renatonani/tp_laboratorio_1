/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#define FIRSTCLASS 1
#define EXECUTIVECLASS 2
#define ECONOMYCLASS 3
Passenger* Passenger_new()
{
	Passenger* this = NULL;

	this = (Passenger*) malloc(sizeof(Passenger));

	return this;
}

Passenger* Passenger_newParametros(int id, char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr)
{
	Passenger* this = NULL;

	int tipoPasajero;
	float precio;

	this = Passenger_new();
	precio = atof(precioStr);

	if(strcmp(tipoPasajeroStr, "FirstClass") == 0)
	{
		tipoPasajero = FIRSTCLASS; //(1)
	}
	else
	{
		if(strcmp(tipoPasajeroStr, "ExecutiveClass") == 0)
		{
			tipoPasajero = EXECUTIVECLASS; //(2)
		}
		else
		{
			if(strcmp(tipoPasajeroStr, "EconomyClass") == 0)
			{
				tipoPasajero = ECONOMYCLASS; //(3)
			}

		}
	}

	if(this != NULL)
	{
		if(Passenger_setId(this, id) == -1 ||
		   Passenger_setNombre(this, nombreStr) == -1||
		   Passenger_setApellido(this, apellidoStr) == -1||
		   Passenger_setPrecio(this, precio) == -1||
		   Passenger_setTipoPasajero(this, tipoPasajero) == -1||
		   Passenger_setCodigoVuelo(this, codigoVueloStr) == -1||
		   Passenger_setEstadoVuelo(this, estadoVueloStr) == -1)
		{
			Passenger_delete(this);
			this = NULL;
		}
	}

	return this;
}



void Passenger_delete(Passenger* this)
{
	if(this!=NULL)
	{
		free(this);
		this = NULL;
	}
}

int Passenger_setId(Passenger* this,int id)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}
int Passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;
	if(this!= NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this!=NULL && apellido!=NULL)
	{
		strcpy(this->apellido, apellido);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this!=NULL && apellido!=NULL)
	{
		strcpy(apellido, this->apellido);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = -1;
	if(this!=NULL && estadoVuelo!=NULL)
	{
		strcpy(this->estadoVuelo, estadoVuelo);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = -1;
	if(this!=NULL && estadoVuelo!=NULL)
	{
		strcpy(estadoVuelo, this->estadoVuelo);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = 0;
		this->tipoPasajero = tipoPasajero;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero != NULL)
	{
		retorno = 0;
		*tipoPasajero = this->tipoPasajero;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = 0;
		this->precio = precio;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		retorno = 0;
		*precio = this->precio;
	}
	return retorno;
}

int Passenger_CompareByStatusFlight(void* p1, void* p2)
{
	char primerEstado[50];
	char segundoEstado[50];
	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;
	int comparacion;

	Passenger_getCodigoVuelo(pasajero1, primerEstado);
	Passenger_getCodigoVuelo(pasajero2, segundoEstado);

	if(strcmp(primerEstado, segundoEstado)==0)
	{
		comparacion = 0;
	}
	else
	{
		if(strcmp(primerEstado, segundoEstado)>0)
		{
			comparacion =1;
		}
		else
		{
			comparacion =-1;
		}
	}

	return comparacion;
}

int Passenger_CompareByPrice(void* p1, void* p2)
{

	Passenger* pasajero1;
	Passenger* pasajero2;
	int comparacion;
	comparacion = 0;

	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	float precio1;
	float precio2;

	Passenger_getPrecio(pasajero1, &precio1);
	Passenger_getPrecio(pasajero2, &precio2);

	if(precio1 > precio2)
	{
		comparacion = 1;
	}
	else
	{
		if(precio1 < precio2)
		{
			comparacion = -1;
		}
	}
	return comparacion;

}
int Passenger_CompareByTypePassenger(void* p1, void* p2)
{

	Passenger* pasajero1;
	Passenger* pasajero2;
	int comparacion;
	comparacion = 0;

	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	int tipoPasajero1;
	int tipoPasajero2;

	Passenger_getTipoPasajero(pasajero1, &tipoPasajero1);
	Passenger_getTipoPasajero(pasajero2, &tipoPasajero2);

	if(tipoPasajero1 > tipoPasajero2)
	{
		comparacion = 1;
	}
	else
	{
		if(tipoPasajero1 < tipoPasajero2)
		{
			comparacion = -1;
		}
	}
	return comparacion;

}
int Passenger_CompareByFlyCode(void* p1, void* p2)
{
	char primerCodigo[50];
	char segundoCodigo[50];
	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;
	int comparacion;

	Passenger_getCodigoVuelo(pasajero1, primerCodigo);
	Passenger_getCodigoVuelo(pasajero2, segundoCodigo);

	if(strcmp(primerCodigo, segundoCodigo)==0)
	{
		comparacion = 0;
	}
	else
	{
		if(strcmp(primerCodigo, segundoCodigo)>0)
		{
			comparacion =1;
		}
		else
		{
			comparacion =-1;
		}
	}

	return comparacion;

}
int Passenger_CompareByLastName(void* p1, void* p2)
{
	char primerApellido[50];
	char segundoApellido[50];
	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;
	int comparacion;

	Passenger_getApellido(pasajero1, primerApellido);
	Passenger_getApellido(pasajero2, segundoApellido);

	if(strcmp(primerApellido, segundoApellido)==0)
	{
		comparacion = 0;
	}
	else
	{
		if(strcmp(primerApellido, segundoApellido)>0)
		{
			comparacion =1;
		}
		else
		{
			comparacion =-1;
		}
	}

	return comparacion;

}
int Passenger_CompareByName(void* p1, void* p2)
{
	char primerNombre[50];
	char segundoNombre[50];
	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;
	int comparacion;

	Passenger_getNombre(pasajero1, primerNombre);
	Passenger_getNombre(pasajero2, segundoNombre);

	if(strcmp(primerNombre, segundoNombre)==0)
	{
		comparacion = 0;
	}
	else
	{
		if(strcmp(primerNombre, segundoNombre)>0)
		{
			comparacion =1;
		}
		else
		{
			comparacion =-1;
		}
	}

	return comparacion;

}
int Passenger_CompareById(void* p1, void* p2)
{

	Passenger* pasajero1;
	Passenger* pasajero2;
	int comparacion;
	comparacion = 0;

	pasajero1 = (Passenger*) p1;
	pasajero2 = (Passenger*) p2;

	int id1;
	int id2;

	Passenger_getId(pasajero1, &id1);
	Passenger_getId(pasajero2, &id2);

	if(id1 > id2)
	{
		comparacion = 1;
	}
	else
	{
		if(id1 < id2)
		{
			comparacion = -1;
		}
	}
	return comparacion;

}
int Passenger_tipoIntToStr(char* tipoPasajeroStr, int* tipoPasajero)
{
	int retorno = 0;

	if(tipoPasajeroStr != NULL && tipoPasajero != NULL)
	{
		if(*tipoPasajero == 1)
		{
			strcpy(tipoPasajeroStr, "FirstClass");
			retorno = 1;
		}
		else
		{
			if(*tipoPasajero == 2)
			{
				strcpy(tipoPasajeroStr, "ExecutiveClass");
				retorno = 1;
			}
			else
			{
				if(*tipoPasajero == 3)
				{
					strcpy(tipoPasajeroStr, "EconomyClass");
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}
void Passenger_PrintOne(Passenger* this)
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[8];
	char estadoVuelo[30];
	char tipoPasajeroStr[50];

	Passenger_getId(this, &id);
	Passenger_getNombre(this, nombre);
	Passenger_getApellido(this, apellido);
	Passenger_getPrecio(this, &precio);
	Passenger_getTipoPasajero(this, &tipoPasajero);
	Passenger_getCodigoVuelo(this, codigoVuelo);
	Passenger_getEstadoVuelo(this, estadoVuelo);

	Passenger_tipoIntToStr(tipoPasajeroStr, &tipoPasajero);
	printf("%8d %20s %20s %13.2f %17s %13s %13s\n", id, nombre, apellido, precio, tipoPasajeroStr, codigoVuelo, estadoVuelo);


}
