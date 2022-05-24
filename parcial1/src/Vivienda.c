/*
 * Vivienda.c
 *
 *  Created on: May 20, 2022
 *      Author: Barrio Cristian
 */


#include "Vivienda.h"

int inicializarVivienda(eVivienda* lista, int tam)
{
	int retorno = -1;

	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			lista[i].isEmpty = -1;
		}

		retorno = 0;
	}

	return retorno;
}

int altaVivienda(eVivienda* lista, int tam, int id, char* calle, int cantidadPersonas, int cantidadHabitaciones, int tipo, int legajoCensista)
{
	int retorno = -1;

	if(lista != NULL && tam > 0)
	{
		system("cls");
		printf("     ALTA VIVIENDA\n");
		printf("------------------------------\n");

		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == -1)
			{
				utn_getName(calle, "Ingrese la calle: ", "Calle invalida.\n");
				utn_getInt(&cantidadPersonas, "Ingrese el numero de personas de la vivienda: ", "Numero invalido.\n", 1, 9999999999999999999);
				utn_getInt(&cantidadHabitaciones, "Ingrese el numero de habitaciones de la vivienda: ", "Numero invalido.\n", 1, 9999999999999999999);
				utn_getInt(&tipo, "Ingrese el tipo de vivienda: \n"
								"Casa (1) Departamento (2) Casilla (3) Rancho (4)\n", "Tipo invalido.\n", 1, 4);

				lista[i].isEmpty = 0;
				lista[i].idVivienda = id;
				strcpy(lista[i].calle, calle);
				lista[i].cantidadPersonas = cantidadPersonas;
				lista[i].cantidadHabitaciones = cantidadHabitaciones;
				lista[i].tipoVivienda = tipo;
				lista[i].legajoCensista = legajoCensista;
				i = tam + 1;
			}
		}

		retorno = 0;
	}

	return retorno;
}

int buscarViviendaPorId(eVivienda* lista, int tam, int id)
{
	int indice = -1;

	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(!lista[i].isEmpty && lista[i].idVivienda == id)
			{
				indice = i;
				break;
			}
		}
	}

	return indice;
}

int modificarVivienda(eVivienda* lista, int tam, int id, char* calle, int cantidadPersonas, int cantidadHabitaciones, int tipo)
{
	int retorno = -1;
	int indice;
	int continuar = 0;

	if(lista != NULL && tam > 0)
	{
		system("cls");
		printf("     MODIFICAR VIVIENDA\n");
		printf("------------------------------\n");

		utn_getInt(&id, "Ingrese ID de la vivienda: ", "ID invalido.\n", 20000, 999999999999999999999);
		indice = buscarViviendaPorId(lista, tam, id);

		if(indice == -1)
		{
			printf("No existe una vivienda con ID %d.\n", id);
		}else
		{
			mostrarVivienda(lista[indice]);

			while(continuar == 0)
			{
				switch(menuModificacion())
				{
					case 1:
						utn_getName(calle, "Ingrese la calle: ", "Calle invalida.\n");
						strcpy(lista[indice].calle, calle);
						break;
					case 2:
						utn_getInt(&cantidadPersonas, "Ingrese el numero de personas de la vivienda: ", "Numero invalido.\n", 1, 9999999999999999999);
						lista[indice].cantidadPersonas = cantidadPersonas;
						break;
					case 3:
						utn_getInt(&cantidadHabitaciones, "Ingrese el numero de habitaciones de la vivienda: ", "Numero invalido.\n", 1, 9999999999999999999);
						lista[indice].cantidadHabitaciones = cantidadHabitaciones;
						break;
					case 4:
						utn_getInt(&tipo, "Ingrese el tipo de vivienda: \n"
											"Casa (1) Departamento (2) Casilla (3) Rancho (4)\n", "Tipo invalido.\n", 1, 4);
						lista[indice].tipoVivienda = tipo;
						break;
					case 5:
						continuar = 1;
						break;
					default:
						printf("\nOpcion invalida.\n");
						break;
				}
			}

			retorno = 0;
		}
	}

	return retorno;
}

int bajaVivienda(eVivienda* lista, int tam, int id)
{
	int retorno = -1;
	int indice;
	int confirmacion;

	if(lista != NULL && tam > 0)
	{
		system("cls");
		printf("     BAJA VIVIENDA\n");
		printf("------------------------------\n");

		utn_getInt(&id, "Ingrese ID de la vivienda: ", "ID invalido.\n", 20000, 999999999999999999999999);
		indice = buscarViviendaPorId(lista, tam, id);

		if(indice == -1)
		{
			printf("No existe una vivienda con ID %d.\n", id);
			confirmacion = 0;
		}else
		{
			utn_getInt(confirmacion, "Confirmar Baja? Si (1) No (0): ", "Opcion invalida.\n", 0, 1);
		}

		if(confirmacion)
		{
			lista[indice].isEmpty = 1;
			retorno = 0;
		}else
		{
			printf("Se ha cancelado la baja.\n");
		}

	}

	return retorno;
}

void mostrarVivienda(eVivienda vivienda)
{
	printf("%d%s%d%d%d%d\n", vivienda.idVivienda,
						vivienda.calle,
						vivienda.cantidadPersonas,
						vivienda.cantidadHabitaciones,
						vivienda.tipoVivienda,
						vivienda.legajoCensista);
}

int mostrarViviendas(eVivienda* lista, int tam)
{
	int retorno = -1;
	int flagVacio = 1;

	if(lista != NULL && tam > 0)
	{
		system("cls");
		printf("     VIVIENDAS\n");
		printf(" ID   CALLE   PERSONAS   HABITACIONES   TIPO   LEGAJO CENSISTA");
		printf("--------------------------------------------------------------------\n");

		for(int i = 0; i < tam; i++)
		{
			if(!lista[i].isEmpty)
			{
				mostrarVivienda(lista[i]);
				flagVacio = 0;
			}
		}

		if(flagVacio)
		{
			printf("No hay viviendas para mostrar.\n");
		}

		retorno = 0;
	}

	return retorno;
}

int ordenarViviendas(eVivienda* lista, int tam)
{
	int retorno = -1;
	eVivienda auxVivienda;

	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam - 1; i++)
		{
			for(int j = i + 1; j < tam; j++)
			{
				if((strcmp(lista[i].calle, lista[j].calle) > 0)
						|| (lista[i].cantidadPersonas > lista[j].cantidadPersonas))
				{
					auxVivienda = lista[i];
					lista[i] = lista[j];
					lista[j] = auxVivienda;
				}
			}
		}

		retorno = 0;
	}

	return retorno;
}

