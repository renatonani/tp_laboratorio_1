/*
 * ArrayPassenger.h
 *
 *  Created on: 3 may. 2022
 *      Author: Nani
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#define CANCELADO 0
#define ACTIVO 1


struct
{
	int idTypePassenger;
	char descripcion[30];
}typedef TypePassenger;

struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int idTypePassenger;
	int statusFlight;
	int isEmpty;
}typedef Passenger;
/// @fn int ValidarTipoPasajero(int)
/// @brief La función se encarga de validar que exista el id ingresado de un tipo de pasajero dentro del array de tipos de pasajeros.
///
/// @param validarTipoPasajero Recibe un id a comparar con los ids guardados dentro del array de tipo de pasajeros;
/// @return Retorna 0 si el id de tipo de pasajero no existe o 1 si el id de tipo de pasajero SI existe.
int ValidarTipoPasajero(int validarTipoPasajero);

/// @fn int initPassengers(Passenger[], int)
/// @brief La función se encarga de iniciar el campo isEmpty de todo el array de listaPasajeros en 1, indicando que estas posiciones del vector estan vacías.
///
/// @param listaPasajeros Recibe el array de tipo Passenger a recorrer.
/// @param tam Recibe el tamaño de dicho array.
/// @return Devuelve 0 si el campo isEmpty de todos los elementos del vector fue cambiado a 1 o devuelve 1 si esto no pudo realizarse.
int initPassengers(Passenger listaPasajeros[], int tam);

/// @fn Passenger CargarUnPasajero()
/// @brief Se encarga de crear una variable de tipo Passenger y pedir los datos para rellenarla con los mismos.
///
/// @return La funcion devuelve la variable de tipo Passenger con los datos cargados.
Passenger PedirDatosPasajero();

/// @fn int addPassenger(Passenger[], int)
/// @brief La funcion encuentra un espacio libre en el array de pasajeros en el cual cargar uno de ellos con sus datos completos.
///
/// @param listaPasajeros Recibe un array de tipo Passenger.
/// @param tam Recibe el tamaño de dicho array.
/// @return La función devuelve 0 si la carga en el array se realizó con éxito o -1 caso contrario.
/// (ACLARACIÓN: Al utilizar una funcion que encuentra un espacio libre y devuelve dicha posicion, me hubiese gustado utilizar este valor de retorno para informar
/// en qué posición se realizó la carga, pero no estaba seguro si hacerlo ya que en la consigna la documentacion de la funcion decia que debía devolver 0 o -1)
int addPassenger(Passenger listaPasajeros[], int tam, int* id);

/// @fn int findPassengerById(Passenger[], int, int)
/// @brief Encuenta un pasajero en el array de pasajeros utilizando como parametros de busqueda su id
///
/// @param listaPasajeros
/// @param tam
/// @param id
/// @return En caso de encontrar dicho pasajero retorna la posicion en la que se encuentra el mismo, en caso de que la id ingresada no exista, devuelve -1.
int findPassengerById(Passenger listaPasajeros[], int tam, int id);

/// @fn int removePassenger(Passenger[], int, int)
/// @brief Elimina de manera lógica (isEmpty Flag en 1) un pasajero recibiendo como parámetro su Id.
///
/// @param listaPasajeros
/// @param tam
/// @param id
/// @return Retorna 0 si el pasajero fue eliminado correctamente o -1 caso contrario.
int removePassenger(Passenger listaPasajeros[], int tam, int id);

/// @fn int sortPassengersByName(Passenger[], int, int)
/// @brief Ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o descendente.
///
/// @param listaPasajeros
/// @param tam
/// @param orden
/// @return Retorna 0 si los pasajeros fueron ordenados satisfactoriamente o -1 caso contrario.
int sortPassengersByLastName(Passenger listaPasajeros[], int tam, int orden);

/// @fn int sortPassengersByCode(Passenger[], int, int)
/// @brief Ordena el array de pasajeros por código de vuelo de manera ascendente o descendente.
///
/// @param listaPasajeros
/// @param tam
/// @param orden
/// @return Retorna 0 si los pasajeros fueron ordenados satisfactoriamente o -1 caso contrario.
int sortPassengersByCode(Passenger listaPasajeros[], int tam, int orden);

/// @fn void printOnePassenger(Passenger, TypePassenger)
/// @brief Muestra los datos de un pasajero.
///
/// @param unPasajero
/// @param unTipo
void printOnePassenger (Passenger unPasajero, TypePassenger unTipo);

/// @fn int printPassengers(Passenger[], int)
/// @brief Muestra todos los pasajeros existentes con sus respectivos datos.
///
/// @param listaPasajeros
/// @param tam
/// @return Retorna 0 si los pasajeros fueron mostrados o -1 caso contrario;
int printPassengers (Passenger listaPasajeros[], int tam);

/// @fn int ModificarUnPasajero(Passenger[], int)
/// @brief Permite modificar lo datos de un pasajero luego de comprobar la ID del mismo existe.
///
/// @param listaPasajeros
/// @param tam
/// @return Devuelve 1 si al menos un dato del pasajero ingresado fue modifcado, en caso de no realizar ninguna modificacion, la funcion devuelve 0.
int ModificarUnPasajero(Passenger listaPasajeros[], int tam);

/// @fn void MostrarTiposPasajeros()
/// @brief Muestra los tipos de pasajeros existentes.
///
void MostrarTiposPasajeros ();

/// @fn int BajaPasajero(Passenger[], int)
/// @brief La funcion pide el ID del pasajero a eliminar y si el mismo existe, lo elimina cambiando el estado de la variable isEmpty a 1.
///
/// @param listaPasajeros
/// @param tam
/// @return Devuelve 0 si el pasajero fue eliminado o -1 caso contrario;
int BajaPasajero (Passenger listaPasajeros[], int tam);

/// @fn int EncontrarRelacionPasajeroTipo(Passenger)
/// @brief Se encarga de comparar la idTypePassenger de un pasajero con las ids existentes en el array de tipos de pasajeros para encontrar cuál es el tipo de pasajero.
///
/// @param unPasajero
/// @return Devuelve la posicion en la que se encuentra el id del tipo de pasajero o -1 en caso de que no exista.
int EncontrarRelacionPasajeroTipo(Passenger unPasajero);

/// @fn int MostrarOpcionesListado()
/// @brief Muestra las opciones del listado del case 4 del menu principal.
///
/// @return Devuelve la opcion seleccionada por el usuario.
int MostrarOpcionesListado();

/// @fn int ContarPasajerosMayorPrecioPromedio(Passenger[], int, int)
/// @brief Cuenta cuántos pasajeros tienen un precio mayor al precio promedio de todos los vuelos existentes.
///
/// @param listaPasajeros
/// @param tam
/// @param precioPromedio
/// @return Devuelve la cantidad de pasajeros que cumplen con la condición.
int ContarPasajerosMayorPrecioPromedio (Passenger listaPasajeros[], int tam, int precioPromedio);

/// @fn int CalcularCantidadVuelos(Passenger[], int)
/// @brief Cuenta la cantidad de vuelos que existen teniendo en cuenta que el estado de la variable isEmpty sea 0.
///
/// @param listaPasajeros
/// @param tam
/// @return Devuelve la cantidad de vuelos existentes.
int CalcularCantidadVuelos (Passenger listaPasajeros[], int tam);

/// @fn float CalcularTotalPreciosVuelos(Passenger[], int)
/// @brief Suma los precios de todos los vuelos existentes.
///
/// @param listaPasajeros
/// @param tam
/// @return Devuelve el valor de la suma de todos los precios de los vuelos existentes.
float CalcularTotalPreciosVuelos (Passenger listaPasajeros[], int tam);

/// @fn void MostrarOpcion2Listado(Passenger[], int)
/// @brief Muestra Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.
///
/// @param listaPasajeros
/// @param tam
void MostrarOpcion2Listado (Passenger listaPasajeros[], int tam);

/// @fn int MostrarPasajerosOrdenadosApellido(Passenger[], int)
/// @brief Muestra el listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.
///
/// @param listaPasajeros
/// @param tam
/// @return Devuelve 0 si los pasajeros fueron ordenados correctamente o -1 si no pudo realizarse.
int MostrarPasajerosOrdenadosApellido (Passenger listaPasajeros[], int tam);

/// @fn int MostrarOpcion3Listado(Passenger[], int)
/// @brief Muestra el listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’.
///
/// @param listaPasajeros
/// @param tam
/// @return Devuelve 0 si los pasajeros fueron ordenados correctamente o -1 si no pudo realizarse.
int MostrarOpcion3Listado (Passenger listaPasajeros[], int tam);

/// @fn void Inicializar5Pasajeros(Passenger[])
/// @brief La funcion realiza un alta forzada con los datos de 5 pasajeros.
///
/// @param listaPasajeros
void Inicializar5Pasajeros(Passenger listaPasajeros[], int* id);





#endif /* ARRAYPASSENGER_H_ */
