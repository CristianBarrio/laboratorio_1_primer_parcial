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
#define TAM_CALLE 25

typedef struct
{
	int idVivienda;
	char calle[TAM_CALLE];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	int isEmpty;
	eCensista legajoCensista;
}eVivienda;

#endif /* VIVIENDA_H_ */

int inicializarVivienda(eVivienda* lista, int tam);
int altaVivienda(eVivienda* lista, int tam, int id, char* calle, int cantidadPersonas, int cantidadHabitaciones, int tipo, int legajoCensista);
int buscarViviendaPorId(eVivienda* lista, int tam, int id);
int modificarVivienda(eVivienda* lista, int tam, int id, char* calle, int cantidadPersonas, int cantidadHabitaciones, int tipo);
int bajaVivienda(eVivienda* lista, int tam, int id);
void mostrarVivienda(eVivienda vivienda);
int mostrarViviendas(eVivienda* lista, int tam);
int ordenarViviendas(eVivienda* lista, int tam);
