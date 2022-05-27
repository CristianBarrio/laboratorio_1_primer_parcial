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

	if(lista != NULL && tam > 0 && legajoCensista > 0)
	{
		system("cls");
		printf("     ALTA VIVIENDA\n");
		printf("------------------------------\n");

		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == -1)
			{
				utn_getName(calle, "Ingrese la calle: ", "Calle invalida.\n");
				utn_getInt(&cantidadPersonas, "Ingrese el numero de personas de la vivienda: ", "Numero invalido.\n", 1, 999999999);
				utn_getInt(&cantidadHabitaciones, "Ingrese el numero de habitaciones de la vivienda: ", "Numero invalido.\n", 1, 999999999);
				utn_getInt(&tipo, "Ingrese el tipo de vivienda: \n"
								"Casa (1) Departamento (2) Casilla (3) Rancho (4)\n", "Tipo invalido.\n", 1, 4);
				utn_getInt(&legajoCensista, "Ingrese el censista: \n"
											"Ana (100) Juan (101) Sol (102)\n", "Censista invalido.\n", 100, 102);

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

int modificarVivienda(eVivienda* lista, int tam, int id, char* calle, int cantidadPersonas, int cantidadHabitaciones, int tipo, eTipo* tipos, int tamT, eCensista* censistas)
{
	int retorno = -1;
	int indice;
	int continuar = 0;

	if(lista != NULL && tam > 0)
	{
		system("cls");
		printf("     MODIFICAR VIVIENDA\n");
		printf("------------------------------\n");

		utn_getInt(&id, "Ingrese ID de la vivienda: ", "ID invalido.\n", 20000, 21000);
		indice = buscarViviendaPorId(lista, tam, id);

		if(indice == -1)
		{
			printf("No existe una vivienda con ID %d.\n", id);
		}else
		{
			mostrarVivienda(lista[indice], tamT, tipos, censistas[indice]);

			while(continuar == 0)
			{
				switch(menuModificacion())
				{
					case 1:
						utn_getName(calle, "Ingrese la calle: ", "Calle invalida.\n");
						strcpy(lista[indice].calle, calle);
						break;
					case 2:
						utn_getInt(&cantidadPersonas, "Ingrese el numero de personas de la vivienda: ", "Numero invalido.\n", 1, 999999999);
						lista[indice].cantidadPersonas = cantidadPersonas;
						break;
					case 3:
						utn_getInt(&cantidadHabitaciones, "Ingrese el numero de habitaciones de la vivienda: ", "Numero invalido.\n", 1, 999999999);
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

		utn_getInt(&id, "Ingrese ID de la vivienda: ", "ID invalido.\n", 20000, 21000);
		indice = buscarViviendaPorId(lista, tam, id);

		if(indice == -1)
		{
			printf("No existe una vivienda con ID %d.\n", id);
			confirmacion = 0;
		}else
		{
			utn_getInt(&confirmacion, "Confirmar Baja? Si (1) No (0): ", "Opcion invalida.\n", 0, 1);
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

void mostrarVivienda(eVivienda vivienda, int tam, eTipo* tipos, eCensista censista)
{
	char descripcionTipo[15];

	cargarDescripcionTipo(tipos, tam, vivienda.tipoVivienda, descripcionTipo);

	printf("%-6d %-10s %-16d %-13d %-12s %d %s %d %s\n", vivienda.idVivienda,
										 vivienda.calle,
										 vivienda.cantidadPersonas,
										 vivienda.cantidadHabitaciones,
										 descripcionTipo,
										 vivienda.legajoCensista,
										 censista.nombre,
										 censista.edad,
										 censista.telefono);
}

int mostrarViviendas(eVivienda* lista, int tam, eTipo* tipos, int tamT, eCensista* censistas)
{
	int retorno = -1;
	int flagVacio = 1;

	if(lista != NULL && tam > 0)
	{
		system("cls");
		printf("           VIVIENDAS\n");
		printf(" ID\t CALLE\t PERSONAS\t HABITACIONES\t TIPO\t LEGAJO CENSISTA\t NOMBRE\t EDAD\t TELEFONO\n");
		printf("-----------------------------------------------------------------------------------------------------------\n");

		for(int i = 0; i < tam; i++)
		{
			if(!lista[i].isEmpty)
			{
				mostrarVivienda(lista[i], tamT, tipos, censistas[i]);
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
				if((strcmp(lista[i].calle, lista[j].calle) < 0)
						|| (lista[i].cantidadPersonas < lista[j].cantidadPersonas))
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

int contadorCensos(eVivienda* lista, int tam)
{
	int retorno = -1;
	int contadorAna = 0;
	int contadorSol = 0;
	int contadorJuan = 0;
	int contadorMayor = 0;
	int legajo = 0;

	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			legajo = lista[i].legajoCensista;

			if(legajo == 100)
			{
				contadorAna++;
			}else if(legajo == 101)
			{
				contadorJuan++;
			}else
			{
				contadorSol++;
			}
		}

		if(contadorAna > contadorJuan && contadorAna > contadorSol)
		{
			contadorAna = contadorMayor;
			printf("El censista con mas censos realizados es: Ana\n");
		}else if(contadorJuan > contadorAna && contadorJuan > contadorSol)
		{
			contadorJuan = contadorMayor;
			printf("El censista con mas censos realizados es: Juan\n");
		}else
		{
			contadorSol = contadorMayor;
			printf("El censista con mas censos realizados es: Sol\n");
		}

		retorno = 0;
	}

	return retorno;
}


