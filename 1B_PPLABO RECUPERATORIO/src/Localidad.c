/*
 * Localidad.c
 *
 *  Created on: 17 nov 2021
 *      Author: Mermin
 */
#include "Localidad.h"

int localidad_inicializar(eLocalidad listaLocalidades[], int lenLocalidades)
{
	int retorno = ERROR;
	int i;

	if(listaLocalidades != NULL && listaLocalidades > 0)
	{
		for(i=0;i<lenLocalidades;i++)
		{
			listaLocalidades[i].isEmpty = LIBRE;
			retorno = FUNCIONO;
		}
	}
	return retorno;
}

int localidad_buscarPorId(eLocalidad listaLocalidades[], int lenLocalidades, int auxId, int* refIndex)
{
	int retorno = ERROR;
	int i;

	if(listaLocalidades != NULL && lenLocalidades > 0 && refIndex != NULL)
	{
		for(i=0;i<lenLocalidades;i++)
		{
			if(listaLocalidades[i].isEmpty == OCUPADO && listaLocalidades[i].idLocalidad == auxId)
			{
				*refIndex = i;
				retorno = FUNCIONO;
				break;
			}
		}
	}
	return retorno;
}

int localidad_buscarLibre(eLocalidad listaLocalidades[], int lenLocalidades, int* refIndex)
{
	int index;
	int retorno = ERROR;
	int i;

	for(i=0;i<lenLocalidades;i++)
	{
		if(listaLocalidades[i].isEmpty == LIBRE)
		{
			index = i;
			retorno = FUNCIONO;
			break;
		}
	}
	*refIndex = index;
	return retorno;
}

/*
int localidad_alta(eLocalidad listaLocalidades[], int lenLocalidades, eZona listaZonas[], int lenZonas, int IdLocalidad)
{
	int retorno = ERROR;
	int index;
	int auxIdZona;

	if(listaLocalidades != NULL && lenLocalidades > 0 && listaZonas != NULL && lenZonas > 0)
	{
		if(localidad_buscarLibre(listaLocalidades, lenLocalidades, &index) == FUNCIONO)
		{
			if(Utn_GetOnlyString(listaLocalidades[index].nombreLocalidad, LEN_CADENA, "Ingrese el nombre de su localidad: ", MENSAJE_ERROR, REINTENTOS) == FUNCIONO)
			{
				if(zona_mostrarLista(listaZonas, lenZonas) == FUNCIONO &&
					Utn_GetInt(&auxIdZona, "Ingrese el ID de la zona en la que se encuentra: ", MENSAJE_ERROR, MIN_ZONA, MAX_ZONA, REINTENTOS) == FUNCIONO)
				{
					listaLocalidades[index].idZona = auxIdZona;
					listaLocalidades[index].idLocalidad = IdLocalidad;
					listaLocalidades[index].isEmpty = OCUPADO;
					retorno = FUNCIONO;
				}
			}
		}
	}

	return retorno;
}
*/

int localidad_mostrarLista(eLocalidad listaLocalidades[], int lenLocalidades, eZona listaZonas[], int lenZonas)
{
	int retorno = ERROR;
	int i;
	int j;

	if(listaLocalidades != NULL && lenLocalidades > 0)
	{
		printf("\n/*******************************************");
		printf("\n             LISTA LOCALIDADES            \n");
		printf("\n    ID             Nombre             Zona\n");
		for(i= 0;i<lenLocalidades;i++)
		{
			if(listaLocalidades[i].isEmpty == OCUPADO)
			{
				for(j=0;j<lenZonas;j++)
				{
					if(listaLocalidades[i].idZona == listaZonas[j].idZona)
					{
						localidad_mostrarUna(listaLocalidades[i], listaZonas[j]);
						retorno = FUNCIONO;
					}
				}
			}
		}
		printf("\n*******************************************/\n");
	}

	return retorno;
}

void localidad_mostrarUna(eLocalidad unaLocalidad, eZona unaZona)
{
	printf("%5d           %10s          %7s\n",unaLocalidad.idLocalidad
								 	 	 	  ,unaLocalidad.nombreLocalidad
											  ,unaZona.nombreZona);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ZONA

int zona_buscarPorId(eZona listaZonas[], int lenZonas, int auxId, int* refIndex)
{
	int retorno = ERROR;
	int i;

	if(listaZonas != NULL && lenZonas > 0 && refIndex != NULL)
	{
		for(i=0;i<lenZonas;i++)
		{
			if(listaZonas[i].isEmpty == OCUPADO && listaZonas[i].idZona == auxId)
			{
				*refIndex = i;
				retorno = FUNCIONO;
				break;
			}
		}
	}
	return retorno;
}

int zona_mostrarLista(eZona listaZonas[], int lenZonas)
{
	int retorno = ERROR;
	int i;

	if(listaZonas != NULL && lenZonas > 0)
	{
		printf("\n/**************************");
		printf("\n        LISTA ZONAS      \n");
		printf("\n    ID             Nombre\n");
		for (i= 0;i<lenZonas;i++)
		{
			if(listaZonas[i].isEmpty == OCUPADO)
			{
				zona_mostrarUna(listaZonas[i]);
				retorno = FUNCIONO;
			}
		}
		printf("\n**************************/\n");
	}

	return retorno;
}

void zona_mostrarUna(eZona unaZona)
{
	printf("%5d           %10s\n",unaZona.idZona,
			                      unaZona.nombreZona);
}

