/*
 * inputs.c
 *
 *  Created on: 11 jun. 2022
 *      Author: Nani
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"

int EsFlotante(char* cadena)
{
	int isDigit = -1;
	int comma = 0;
	int flagSigno = 0;
	int len = strlen(cadena);

	for(int i = 0; i < len; i++)
	{
		if((cadena[i] <=  '9' && cadena[i] >= '0') || (cadena[i] == '.' && comma == 0 && i != flagSigno) || (cadena[i] == '-' && i == 0))
		{
			if(cadena[i] == '.')
			{
				comma++;
			}
			if(cadena[i] == '-')
			{
				flagSigno++;
			}
			isDigit = 1;
		}
		else
		{
			isDigit = 0;
			break;
		}
	}

	return isDigit;
}
int PedirFlotante(float* numero, char* mensaje, char* mensajeError)
{
	int retorno = -1;
	int flagError = 0;
	char auxNumero[40];

	if(mensaje!= NULL && mensajeError != NULL && numero != NULL)
	{
		do
		{
			int isDigit = 0;

			if(flagError == 0)
			{
				printf("%s", mensaje);
				fflush(stdin);
				scanf("%40[^\n]", auxNumero);
			}
			else
			{
				printf("%s", mensajeError);
				fflush(stdin);
				scanf("%40[^\n]", auxNumero);
			}

			if((isDigit = EsFlotante(auxNumero)) == 1)
			{
				*numero = atof(auxNumero);
			}
			else
			{
				flagError = 1;
			}
		}while(retorno == -1);
	}

	return retorno;
}

void PedirCadena(char cadena[],char mensaje[])
{
	printf(mensaje);
	scanf("%s",cadena);

}
int ValidarUnaCadena(char cadena[])
{
	int retorno=1;
	int len;
	if(cadena!=NULL){
		len=strlen(cadena);
		for(int i=0;i<len;i++){
			if(!isalpha(cadena[i]))
			{
				retorno=0;
			}
		}
	}

	return retorno;
}

int ValidarTamanioUnaCadena(char cadena[], int len)
{
	int retorno = 1;
	if(cadena!=NULL)
	{
		if(strlen(cadena)>len)
		{
			printf("La cantidad de caracteres no debe ser mayor a %d\n",len);
			retorno = 0;
		}
	}
	return retorno;
}
int ValidarNumero(char numero[])
{
	int retorno=1;
	int len;
	if(numero!=NULL)
	{
		len=strlen(numero);
		for(int i=0;i<len;i++)
		{
			if(!isdigit(numero[i]))
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int PedirEntero(char mensaje[])
{
	int retorno;
	char numero[1000];
	printf(mensaje);
	scanf("%s",numero);
	while(!ValidarNumero(numero))
	{
		printf("\nERROR\n");
		printf(mensaje);
		scanf("%s",numero);
	}
	retorno=atoi(numero);
	return retorno;
}

int ValidarTipoPasajero(char tipoPasajero[])
{
	int retorno;
	retorno=1;

	if(tipoPasajero!=NULL)
	{
		if(strcmp(tipoPasajero, "FirstClass")!=0 &&
		   strcmp(tipoPasajero, "ExecutiveClass")!=0 &&
		   strcmp(tipoPasajero, "EconomyClass")!=0 )
		{
			retorno = 0;
		}
	}

	return retorno;
}

