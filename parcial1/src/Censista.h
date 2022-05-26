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

/** Muestra los datos pertenecientes a un censista
 *
 * @param censista eCensista
 */
void mostrarCensista(eCensista censista);

/** Muestra los datos pertenecientes a todos los censistas del array
 *
 * @param censistas eCensista* lista de censistas
 * @param tam int tamaño del array de censistas
 * @return retorno devuelve -1 si hubo un error, de lo contrario 0
 */
int mostrarCensistas(eCensista* censistas, int tam);
