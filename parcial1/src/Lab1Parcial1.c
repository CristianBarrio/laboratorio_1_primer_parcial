/*
 ============================================================================
 Name        : Lab1Parcial1.c
 Author      : Barrio Cristian
 Version     : Finalizado1
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
#define TAM_C 3


int main(void) {
	setbuf(stdout,NULL);

	eVivienda viviendas[TAM];

	eCensista censistas[TAM_C] = {
			{100, "Ana", 34, "1203-2345"},
			{101, "Juan", 24, "4301-54678"},
			{102, "Sol", 47, "5902-37487"}
		};

	eTipo tipos[TAM_T] = {
				{1,"CASA"},
				{2,"DEPARTAMENTO"},
				{3,"CASILLA"},
				{4,"RANCHO"}
		};

	int auxId = 20000;
	char auxCalle[TAM_CALLE];
	int auxCantidadPersonas = 0;
	int auxCantidadHabitaciones = 0;
	int auxTipo = 0;

	int auxLegajoCensista = 103;

	int flagIngreso = 0;
	int continuar = 0;

	inicializarVivienda(viviendas, TAM);

	do
	{
		system("cls");

		switch(menu())
		{
			case 1:
				if(altaVivienda(viviendas, TAM, auxId, auxCalle, auxCantidadPersonas, auxCantidadHabitaciones, auxTipo, auxLegajoCensista) == 0)
				{
					printf("Alta realizada con exito.\n");
					auxId++;
					auxLegajoCensista++;
					flagIngreso = 1;
				}
				break;
			case 2:
				if(flagIngreso && modificarVivienda(viviendas, TAM, auxId, auxCalle, auxCantidadPersonas, auxCantidadHabitaciones, auxTipo, tipos, TAM_T) == 0)
				{
					printf("Modificacion realizada con exito.\n");
				}else
				{
					printf("No se pueden realizar modificaciones sin haber ingresado viviendas.\n");
				}
				break;
			case 3:
				if(flagIngreso && bajaVivienda(viviendas, TAM, auxId) == 0)
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
					mostrarViviendas(viviendas, TAM, tipos, TAM_T);
				}else
				{
					printf("No se pueden realizar informes sin haber ingresado viviendas.\n");
				}
				break;
			case 5:
				mostrarCensistas(censistas, TAM_C);
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
