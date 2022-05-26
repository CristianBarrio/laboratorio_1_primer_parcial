/*
 * Censista.h
 *
 *  Created on: May 20, 2022
 *      Author: Barrio Cristian
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

#include "utn.h"
#define TAM_NOMBRE 25

typedef struct
{
	int legajoCensista;
	char nombre[TAM_NOMBRE];
	int edad;
	char telefono[15];
}eCensista;

#endif /* CENSISTA_H_ */

/**
 *
 * @param censista
 */
void mostrarCensista(eCensista censista);

/**
 *
 * @param censistas
 * @param tam
 * @return
 */
int mostrarCensistas(eCensista* censistas, int tam);
