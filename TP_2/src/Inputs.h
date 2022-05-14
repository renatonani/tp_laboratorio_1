/*
 * Inputs.h
 *
 *  Created on: 3 may. 2022
 *      Author: Nani
 */

#ifndef INPUTS_H_
#define INPUTS_H_
#include "ArrayPassenger.h"


/// @brief Se encarga de pedir un numero y validar que el mismo sea un entero.
///
/// @param mensaje Recibe un mensaje que se imprimirá al momento de pedir el entero.
/// @return Devuelve un numero entero.
int PedirEntero(char mensaje[]);

/// @brief Se encarga de validar que un dato ingresado sea un entero y no una caracter/es
///
/// @param numero Recibe una cadena que posiblemente contenga un numero.
/// @return Devuelve 0 si se trata de digitos o 1 si se trata de una cadena con unicamente caracter/es.
int ValidarNumero(char numero[]);

/// @brief Se encarga de pedir un numero y validar que el mismo sea un flotante.
///
/// @param mensaje Recibe un mensaje que se imprimirá al momento de pedir el flotante.
/// @return Devuelve un numero flotante.
float PedirFlotante(char mensaje[]);

/// @brief Se encarga de pedir una cadena de caracteres y validar que no se trate de numeros.
///
/// @param cadena Recibe un array de caracteres donde se guardará la cadena pedida.
/// @param mensaje Recibe un mensaje que se mostrará al momento de pedir la cadena.
void PedirCadena(char cadena[],char mensaje[]);

/// @brief Se encarga de validar que una cadena sea de texto o caracteres y no de numeros.
///
/// @param cadena Recibe la cadena a validar.
/// @return Devuelve 0 si se trata de texto o 1 si se trata de numeros.
int ValidarUnaCadena(char cadena[]);



#endif /* INPUTS_H_ */
