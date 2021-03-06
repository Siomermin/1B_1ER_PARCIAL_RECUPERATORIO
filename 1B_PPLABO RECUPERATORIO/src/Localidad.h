/*
 * Localidad.h
 *
 *  Created on: 17 nov 2021
 *      Author: Mermin
 */
/*
1) Agregar la entidad Localidad.
2) Refactorizar las funciones que considere necesarias para que utilicen la nueva entidad.
3) Agregar los siguientes informes:
a) Cliente con m?s pedidos pendientes.
b) Cliente con m?s pedidos completados.
Nota 1: Se deber?n desarrollar bibliotecas por cada entidad las cuales contendr?n las funciones (Alta, Baja, Modificar, etc.).
Los informes deber?n estar en una biblioteca aparte.
Nota 2: El c?digo deber? tener comentarios con la documentaci?n de cada una de las funciones y respetar las reglas de estilo
de la c?tedra.*/

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_
#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

typedef struct
{
	int idZona;
	char nombreZona[LEN_CADENA];
	int isEmpty;
}eZona;

typedef struct
{
	int idLocalidad;
	char nombreLocalidad[LEN_CADENA];
	int isEmpty;
	int idZona;
}eLocalidad;

/// \fn int localidad_inicializar(eLocalidad[], int)
/// \brief Inicializa los campos isEmpty del array de localides en LIBRE(1).
/// \param listaLocalidades eLocalidad array de localidades.
/// \param lenLocalidades lenLocalidades int tama?o del array de localidades.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int localidad_inicializar(eLocalidad listaLocalidades[], int lenLocalidades);

/// \fn int localidad_buscarPorId(eLocalidad[], int, int, int*)
/// \brief Busca una localidad por el id que llega por parametro, si la localidad pertenece al array devuelve su posicion o index por referencia.
/// \param listaLocalidades eLocalidad array de localidades.
/// \param lenLocalidades lenLocalidades int tama?o del array de localidades.
/// \param auxId int ID a buscar.
/// \param refIndex int* Posicion en la que se encuentra la localidad.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int localidad_buscarPorId(eLocalidad listaLocalidades[], int lenLocalidades, int auxId, int* refIndex);

//int localidad_alta(eLocalidad listaLocalidades[], int lenLocalidades, eZona listaZonas[], int lenZonas, int IdLocalidad); La agregue para dar una opcion mas, igualmente habria que modificar mas cosas.

/// \fn int localidad_mostrarLista(eLocalidad[], int)
/// \brief Recorre el array de localidades y si encuentra una con el campo isEmpty OCUPADO, llama a la funcion "localidad_mostrarUna" y muestra la lista de localidades.
/// \param listaLocalidades eLocalidad array de localidades.
/// \param lenLocalidades lenLocalidades int tama?o del array de localidades.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int localidad_mostrarLista(eLocalidad listaLocalidades[], int lenLocalidades, eZona listaZonas[], int lenZonas);

/// \fn void localidad_mostrarUna(eLocalidad)
/// \brief Muestra los campos de una localidad que le llega por parametro.
/// \param unaLocalidad eLocalidad una localidad.
void localidad_mostrarUna(eLocalidad unaLocalidad, eZona unaZona);

/// \fn int zona_buscarPorId(eZona[], int, int, int*)
/// \brief Busca una zona por el id que llega por parametro, si la zona pertenece al array devuelve su posicion o index por referencia.
/// \param listaZonas eZona array de zonas.
/// \param lenZonas int tama?o del array de zonas.
/// \param auxId int ID a buscar.
/// \param refIndex int* Posicion en la que se encuentra la zona.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int zona_buscarPorId(eZona listaZonas[], int lenZonas, int auxId, int* refIndex);

/// \fn int zona_mostrarLista(eZona[], int)
/// \brief Recorre el array de zonas y si encuentra una con el campo isEmpty OCUPADO, llama a la funcion "zona_mostrarUna" y muestra la lista de zonas.
/// \param listaZonas eZona array de zonas.
/// \param lenZonas int tama?o del array de zonas.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int zona_mostrarLista(eZona listaZonas[], int lenZonas);

/// \fn void zona_mostrarUna(eZona)
/// \brief  Muestra los campos de una zona que le llega por parametro.
/// \param unaZona eZona una zona.
void zona_mostrarUna(eZona unaZona);


#endif /* LOCALIDAD_H_ */

