/*
 * Vivienda.h
 *
 *  Created on: May 20, 2022
 *      Author: Barrio Cristian
 */

#ifndef VIVIENDA_H_
#define VIVIENDA_H_

#include "utn.h"
#include "Censista.h"
#include "Tipo.h"
#define TAM_CALLE 25

typedef struct
{
	int idVivienda;
	char calle[TAM_CALLE];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int legajoCensista;
	int isEmpty;
}eVivienda;

#endif /* VIVIENDA_H_ */

/** Indica que todas las posiciones del array estan vacias
 *
 * @param lista eVivienda* array de viviendas
 * @param tam int tamaño del array
 * @return retorno devuelve -1 si hubo un error, de lo contrario 0
 */
int inicializarVivienda(eVivienda* lista, int tam);

/** Agrega una vivienda al primer espacio vacio del array de viviendas
 *
 * @param lista eVivienda* array de viviendas
 * @param tam int tamaño del array
 * @param id int ID correspondiente a cada vivienda
 * @param calle char* calle correspodiente a cada vivienda
 * @param cantidadPersonas int numero de habitantes de cada vivienda
 * @param cantidadHabitaciones int numero de habitaciones de cada vivienda
 * @param tipo int numero de tipo de vivienda
 * @param legajoCensista int legajo correspondiente al censista de cada vivienda
 * @return retorno devuelve -1 si hubo un error, de lo contrario 0
 */
int altaVivienda(eVivienda* lista, int tam, int id, char* calle, int cantidadPersonas, int cantidadHabitaciones, int tipo, int legajoCensista);

/** Busca una vivienda por su ID en el array de viviendas
 *
 * @param lista eVivienda* array de viviendas
 * @param tam int tamaño del array
 * @param id int ID correspondiente a cada vivienda
 * @return indice int devuelve una posicion libre o -1 si hubo un problema
 */
int buscarViviendaPorId(eVivienda* lista, int tam, int id);

/** Permite modificar alguno de los datos correspondientes a una vivienda
 *
 * @param lista eVivienda* array de viviendas
 * @param tam int tamaño del array
 * @param id int ID correspondiente a cada vivienda
 * @param calle char* calle correspodiente a cada vivienda
 * @param cantidadPersonas int numero de habitantes de cada vivienda
 * @param cantidadHabitaciones int numero de habitaciones de cada vivienda
 * @param tipo int numero de tipo de vivienda
 * @param tipos eTipo* array de tipos de viviendas
 * @param tamT int tamaño del array de tipos
 * @return retorno devuelve -1 si hubo un error, de lo contrario 0
 */
int modificarVivienda(eVivienda* lista, int tam, int id, char* calle, int cantidadPersonas, int cantidadHabitaciones, int tipo, eTipo* tipos, int tamT);

/** Permite dar de baja una vivienda, vaciando su posicion en el array
 *
 * @param lista eVivienda* array de viviendas
 * @param tam int tamaño del array
 * @param id int ID correspondiente a cada vivienda
 * @return retorno devuelve -1 si hubo un error, de lo contrario 0
 */
int bajaVivienda(eVivienda* lista, int tam, int id);

/** Informa los datos pertenecientes a una vivienda
 *
 * @param vivienda eVivienda variable correspondiente a una vivienda
 * @param tam int tamaño del array de tipos
 * @param tipos eTipo* array de tipos
 */
void mostrarVivienda(eVivienda vivienda, int tam, eTipo* tipos);

/** Informa los datos pertenecientes a todas las viviendas del array
 *
 * @param lista eVivienda* array de viviendas
 * @param tam int tamaño del array
 * @param tipos eTipo* array de tipos de viviendas
 * @param tamT int tamaño del array de tipos
 * @return retorno devuelve -1 si hubo un error, de lo contrario 0
 */
int mostrarViviendas(eVivienda* lista, int tam, eTipo* tipos, int tamT);

/** Ordena a las viviendas por calle y ante igualdad de calle, por la cantidad de habitantes, de mayor a menor
 *
 * @param lista eVivienda* array de viviendas
 * @param tam int tamaño del array
 * @return retorno devuelve -1 si hubo un error, de lo contrario 0
 */
int ordenarViviendas(eVivienda* lista, int tam);
