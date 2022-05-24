/*
 ============================================================================
 Name        : Lab1Parcial1.c
 Author      : Barrio Cristian
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Vivienda.h"
#include "Censista.h"

#define TAM 1000

int main(void) {
	setbuf(stdout,NULL);

	eVivienda viviendas[TAM];
	eCensista censistas[TAM];
	int auxId = 20000;
	char auxCalle[TAM_CALLE];
	int auxCantidadPersonas=0;
	int auxCantidadHabitaciones=0;
	int auxTipo=0;
	int auxLegajoCensista = 0;

	int flagIngreso = 0;
	int continuar = 0;

	inicializarVivienda(viviendas, TAM);

	do
	{
		system("cls");

		switch(menu())
		{
			case 1:
				if(altaVivienda(viviendas, TAM, auxId, auxCalle, auxCantidadPersonas, auxCantidadHabitaciones, auxTipo, auxLegajoCensista))
				{
					printf("Alta realizada con exito.\n");
					auxId++;
					auxLegajoCensista++;
					flagIngreso = 1;
				}
				break;
			case 2:
				if(flagIngreso && modificarVivienda(viviendas, TAM, auxId, auxCalle, auxCantidadPersonas, auxCantidadHabitaciones, auxTipo))
				{
					printf("Modificacion realizada con exito.\n");
				}else
				{
					printf("No se pueden realizar modificaciones sin haber ingresado viviendas.\n");
				}
				break;
			case 3:
				if(flagIngreso && bajaVivienda(viviendas, TAM, auxId))
				{
					printf("Baja realizada con exito.\n");
				}else
				{
					printf("No se puede realizar la baja sin haber ingresado viviendas.\n");
				}
				break;
			case 4:
				if(flagIngreso)
				{
					ordenarViviendas(viviendas, TAM);
					mostrarViviendas(viviendas, TAM);
				}else
				{
					printf("No se pueden realizar informes sin haber ingresado viviendas.\n");
				}
				break;
			case 5:
				mostrarCensistas(censistas, TAM);
				break;
			case 6:
				continuar = 1;
				break;
			default:
				break;
		}
		system("pause");
	}while(continuar == 0);

	return EXIT_SUCCESS;
}
