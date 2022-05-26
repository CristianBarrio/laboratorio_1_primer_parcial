/*
 * Censista.c
 *
 *  Created on: May 20, 2022
 *      Author: Barrio Cristian
 */


#include "Censista.h"

void mostrarCensista(eCensista censista)
{
	printf(" %-8d %-8s %-6d %s\n", censista.legajoCensista,
								   censista.nombre,
								   censista.edad,
								   censista.telefono);
}

int mostrarCensistas(eCensista* censistas, int tam)
{
	int retorno = -1;
	int flagVacio = 1;

	if(censistas != NULL && tam > 0)
	{
		system("cls");
		printf("     CENSISTAS\n");
		printf(" LEGAJO\t NOMBRE\t EDAD\t TELEFONO\n");
		printf("-----------------------------------------\n");

		for(int i = 0; i < tam; i++)
		{
			mostrarCensista(censistas[i]);
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
