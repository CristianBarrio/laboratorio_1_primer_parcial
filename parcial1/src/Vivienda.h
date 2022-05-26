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

/**
 *
 * @param lista
 * @param tam
 * @return
 */
int inicializarVivienda(eVivienda* lista, int tam);

/**
 *
 * @param lista
 * @param tam
 * @param id
 * @param calle
 * @param cantidadPersonas
 * @param cantidadHabitaciones
 * @param tipo
 * @param legajoCensista
 * @return
 */
int altaVivienda(eVivienda* lista, int tam, int id, char* calle, int cantidadPersonas, int cantidadHabitaciones, int tipo, int legajoCensista);

/**
 *
 * @param lista
 * @param tam
 * @param id
 * @return
 */
int buscarViviendaPorId(eVivienda* lista, int tam, int id);

/**
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
 * @return
 */
int modificarVivienda(eVivienda* lista, int tam, int id, char* calle, int cantidadPersonas, int cantidadHabitaciones, int tipo, eTipo* tipos, int tamT);

/**
 *
 * @param lista
 * @param tam
 * @param id
 * @return
 */
int bajaVivienda(eVivienda* lista, int tam, int id);

/**
 *
 * @param vivienda
 * @param tam
 * @param tipos
 */
void mostrarVivienda(eVivienda vivienda, int tam, eTipo* tipos);

/**
 *
 * @param lista
 * @param tam
 * @param tipos
 * @param tamT
 * @return
 */
int mostrarViviendas(eVivienda* lista, int tam, eTipo* tipos, int tamT);

/**
 *
 * @param lista
 * @param tam
 * @return
 */
int ordenarViviendas(eVivienda* lista, int tam);
