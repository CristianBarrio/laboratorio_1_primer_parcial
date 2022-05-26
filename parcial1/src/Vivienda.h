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
 * @param lista
 * @param tam
 * @param id
 * @param calle
 * @param cantidadPersonas
 * @param cantidadHabitaciones
 * @param tipo
 * @param legajoCensista
 * @return retorno devuelve -1 si hubo un error, de lo contrario 0
 */
int altaVivienda(eVivienda* lista, int tam, int id, char* calle, int cantidadPersonas, int cantidadHabitaciones, int tipo, int legajoCensista);

/** Busca una vivienda por su ID en el array de viviendas
 *
 * @param lista
 * @param tam
 * @param id
 * @return indice int devuelve una posicion libre o -1 si hubo un problema
 */
int buscarViviendaPorId(eVivienda* lista, int tam, int id);

/** Permite modificar alguno de los datos correspondientes a una vivienda
 *
 * @param lista
 * @param tam
 * @param id
 * @param calle
 * @param cantidadPersonas
 * @param cantidadHabitaciones
 * @param tipo
 * @param tipos
 * @param tamT
 * @return retorno devuelve -1 si hubo un error, de lo contrario 0
 */
int modificarVivienda(eVivienda* lista, int tam, int id, char* calle, int cantidadPersonas, int cantidadHabitaciones, int tipo, eTipo* tipos, int tamT);

/** Permite dar de baja una vivienda, vaciando su posicion en el array
 *
 * @param lista
 * @param tam
 * @param id
 * @return retorno devuelve -1 si hubo un error, de lo contrario 0
 */
int bajaVivienda(eVivienda* lista, int tam, int id);

/** Informa los datos pertenecientes a una vivienda
 *
 * @param vivienda
 * @param tam
 * @param tipos
 */
void mostrarVivienda(eVivienda vivienda, int tam, eTipo* tipos);

/** Informa los datos pertenecientes a todas las viviendas del array
 *
 * @param lista
 * @param tam
 * @param tipos
 * @param tamT
 * @return retorno devuelve -1 si hubo un error, de lo contrario 0
 */
int mostrarViviendas(eVivienda* lista, int tam, eTipo* tipos, int tamT);

/** Ordena a las viviendas por calle y ante igualdad de calle, por la cantidad de habitantes, de mayor a menor
 *
 * @param lista
 * @param tam
 * @return retorno devuelve -1 si hubo un error, de lo contrario 0
 */
int ordenarViviendas(eVivienda* lista, int tam);
