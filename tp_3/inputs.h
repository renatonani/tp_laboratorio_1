/*
 * inputs.h
 *
 *  Created on: 11 jun. 2022
 *      Author: Nani
 */

#ifndef INPUTS_H_
#define INPUTS_H_

int EsFlotante(char* cadena);
int PedirFlotante(float* numero, char* mensaje, char* mensajeError);
void PedirCadena(char cadena[],char mensaje[]);
int ValidarNumero(char numero[]);
int PedirEntero(char mensaje[]);
int ValidarUnaCadena(char cadena[]);
int ValidarTamanioUnaCadena(char cadena[], int len);
int ValidarTipoPasajero(char tipoPasajero[]);

#endif /* INPUTS_H_ */
