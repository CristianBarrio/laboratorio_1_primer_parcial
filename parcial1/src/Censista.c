/*
 * Censista.c
 *
 *  Created on: May 20, 2022
 *      Author: Barrio Cristian
 */


#include "Censista.h"

eCensista censistas[] ={
		{100, "Ana", 34, 1203-2345},
		{101, "Juan", 24, 4301-54678},
		{102, "Sol", 47, 5902-37487}
		};


void mostrarCensista(eCensista censista)
{
	printf("%d%s%d%d\n", censista.legajoCensista,
						censista.nombre,
						censista.edad,
						censista.telefono);
}

int mostrarCensistas(eCensista* lista, int tam)
{
	int retorno = -1;
	int flagVacio = 1;

	if(lista != NULL && tam > 0)
	{
		system("cls");
		printf("     CENSISTAS\n");
		printf(" LEGAJO   NOMBRE   EDAD   TELEFONO");
		printf("-------------------------------------------\n");

		for(int i = 0; i < tam; i++)
		{
			mostrarCensista(lista[i]);
			flagVacio = 0;
		}

		if(flagVacio)
		{
			printf("No hay censistas para mostrar.\n");
		}

		retorno = 0;
	}

	return retorno;
}
