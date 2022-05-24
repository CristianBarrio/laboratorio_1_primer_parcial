/*
 * Censista.h
 *
 *  Created on: May 20, 2022
 *      Author: Barrio Cristian
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

#include "utn.h"
#define TAM_NOMBRE 51

typedef struct
{
	int legajoCensista;
	char nombre[51];
	int edad;
	int telefono;
}eCensista;

#endif /* CENSISTA_H_ */

void mostrarCensista(eCensista censista);
int mostrarCensistas(eCensista* lista, int tam);
