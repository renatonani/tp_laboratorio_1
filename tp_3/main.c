#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto). y
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero y
     6. Listar pasajeros y
     7. Ordenar pasajeros y
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto). y
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option;
    int banderaGuardadoArchivo;
    banderaGuardadoArchivo=0;
    int cantidadCargados;
    int cantidadGuardados;
    int confirmacion;

//Aclaraciones: Utilicé un archivo txt para el case 2 y 9 pero los datos se encuentran de igual forma guardados en modo binario.

    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
    			"2. Cargar los datos de los pasajeros desde el archivo datos.txt (modo binario).\n"
				"3. Alta de pasajero.\n"
				"4. Modificar datos de pasajero.\n"
				"5. Baja de pasajero.\n"
				"6. Listar pasajeros.\n"
				"7. Ordenar pasajeros.\n"
				"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
				"9. Guardar los datos de los pasajeros en el archivo datos.txt (modo binario).\n"
				"10. Salir.\n"
    			"Elija una opcion: ");
    	scanf("%d",&option);


        switch(option)
        {
            case 1:
                cantidadCargados = controller_loadFromText("data.csv",listaPasajeros);
                printf("\nSe cargaron %d pasajeros.\n\n", cantidadCargados);
                break;
            case 2:
            	cantidadCargados = controller_loadFromBinary("datos.txt", listaPasajeros);
            	printf("\nSe cargaron %d pasajeros.\n\n", cantidadCargados);
            	break;
            case 3:
            	confirmacion = controller_addPassenger(listaPasajeros);
            	if(confirmacion == 1)
				{
					printf("\nSe agregó correctamente al pasajero.\n\n");
				}
				else
				{
					printf("\nOcurrió un error al intentar agregar el pasajero.\n\n");
				}
				break;
            case 4:
            	confirmacion = controller_editPassenger(listaPasajeros);
            	if(confirmacion == 1)
            	{
            		printf("\nSe guardaron correctamente los cambios.\n\n");
            	}
            	else
            	{
            		printf("\nNo se realizaron cambios.\n\n");
            	}
				break;
            case 5:
            	confirmacion = controller_removePassenger(listaPasajeros);
            	if(confirmacion == 1)
            	{
            		printf("\nSe eliminó correctamente al pasajero.\n\n");
            	}
            	else
            	{
            		printf("\nOcurrió un error al intentar eliminar el pasajero.\n\n");
            	}

				break;
            case 6:
            	confirmacion = controller_ListPassenger(listaPasajeros);
            	if(confirmacion==0)
            	{
            		printf("\nNo hay pasajeros para listar.\n\n");
            	}
				break;
            case 7:
            	confirmacion = controller_sortPassenger(listaPasajeros);
            	if(confirmacion==0)
            	{
            		printf("\nNo se realizo ningun ordenamiento.\n\n");
            	}
            	else
            	{
            		if(confirmacion==-1)
            		{
            			printf("\nNo hay pasajeros para ordenar.\n\n");
            		}
            	}
				break;
            case 8:
            	cantidadGuardados = controller_saveAsText("data.csv", listaPasajeros);
            	if(cantidadGuardados != 0)
            	{
            		printf("\nSe guardaron %d pasajeros.\n\n", cantidadGuardados);
            		banderaGuardadoArchivo=1;
            	}
            	else
            	{
            		printf("\nOcurrio un error al intentar guardar pasajeros.\n\n");
            	}
                break;
            case 9:
            	cantidadGuardados = controller_saveAsBinary("datos.txt", listaPasajeros);
            	if(cantidadGuardados!=0)
            	{
            		printf("\nSe guardaron %d pasajeros.\n\n", cantidadGuardados);
            		banderaGuardadoArchivo=1;
            	}
            	else
				{
					printf("\nOcurrio un error al intentar guardar pasajeros.\n\n");
				}

            	banderaGuardadoArchivo=1;
                break;

            case 10:
            	if(banderaGuardadoArchivo == 1)
				{
            		printf("\nSaliendo...\n");
				}
            	else
            	{
            		printf("\nSe debe realizar un guardado de archivo antes de poder salir.\n\n");
            		option=0;
            	}
                break;

            default:
				printf("Elija una opcion valida.\n");
				break;
        }
    }while(option != 10);
    return 0;
}

