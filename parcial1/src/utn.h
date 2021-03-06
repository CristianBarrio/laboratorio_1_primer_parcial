/*
 * utn.h
 *
 *  Created on: May 20, 2022
 *      Author: Barrio Cristian
 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#endif /* UTN_H_ */

/** Pide una cadena y cambia el ultimo elemento de '\n' a \0'
 *
 * @param cadena char*
 * @param longitud int tama?o de la cadena
 * @return retorno devuelve -1 si hubo un error, de lo contrario 0
 */
int myGets(char* cadena, int longitud);

/** Recibe una cadena y devuelve 1 si el texto solo esta compuesto por numeros
 *
 * @param pResultado int*
 * @return retorno devuelve -1 si hubo un error, de lo contrario 0
 */
int getInt(int* pResultado);

/** Recorre la cadena para verificar que todos sus elementos sean numericos
 *
 * @param cadena char*
 * @return retorno devuelve -1 si hubo un error, de lo contrario 0
 */
int esNumerica(char* cadena);

/** Recibe un texto convertido a entero, imprime un mensaje y un mensaje de error
 *
 * @param pResultado int* puntero al entero recibido
 * @param mensaje char* mensaje solicitando el entero
 * @param mensajeError char* mensaje en caso de ingresar un entero incorrecto
 * @param minimo int valor minimo a ingresar
 * @param maximo int valor maximo a ingresar
 * @return retorno devuelve -1 si hubo un error, de lo contrario 0
 */
int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);

/** Pide un texto, lo almacena como cadena, valida y lo convierte a numero
 *
 * @param pResultado
 * @return retorno devuelve -1 si hubo un error, de lo contrario 0
 */
int getFloat(float* pResultado);

/**
 * @param pResultado float* puntero al flotante recibido
 * @param mensaje char* mensaje solicitando el flotante
 * @param mensajeError char* mensaje en caso de ingresar un flotante incorrecto
 * @param minimo float valor minimo a ingresar
 * @param maximo float valor maximo a ingresar
 * @return retorno devuelve -1 si hubo un error, de lo contrario 0
 */
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo);

/** recibe un texto y valida que sea solo compuesto por caracteres
 *
 * @param cadena char* cadena de caracteres ingresada
 * @param mensaje char* mensaje solicitando la cadena
 * @param mensajeError char* mensaje en caso de ingresar una cadena incorrecta
 * @return retorno devuelve -1 si hubo un error, de lo contrario 0
 */
int utn_getName(char* cadena, char* mensaje, char* mensajeError);

/** Menu de opciones del ABM
 *
 * @return opcion seleccionada del menu
 */
int menu();

/** Menu de opciones de la modificacion de viviendas
 *
 * @return opcion seleccionada del menu
 */
int menuModificacion();
