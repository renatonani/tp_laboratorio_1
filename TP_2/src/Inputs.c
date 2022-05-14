/*
 * Inputs.c
 *
 *  Created on: 3 may. 2022
 *      Author: Nani
 */
#include "Inputs.h"
#include "ArrayPassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



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
float PedirFlotante(char mensaje[])
{
	float retorno;
	char numero[1000];
	printf(mensaje);
	scanf("%s",numero);
	while(!ValidarNumero(numero))
	{
		printf("\nERROR\n");
		printf(mensaje);
		scanf("%s",numero);
	}
	retorno=atof(numero);
	return retorno;
}
void PedirCadena(char cadena[],char mensaje[])
{
	printf(mensaje);
	scanf("%s",cadena);
	while(!ValidarUnaCadena(cadena))
	{
		printf("\nERROR\n");
		printf(mensaje);
		scanf("%s",cadena);
	}
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


