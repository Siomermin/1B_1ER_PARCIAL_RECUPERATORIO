/*
 * Informes.h
 *
 *  Created on: 18 nov 2021
 *      Author: Mermin
 */

#ifndef INFORMES_H_
#define INFORMES_H_
//#include "Cliente.h"
#include "Pedido.h"
//#include "localidad.h"

/// \fn int pedido_imprimirProcesados(ePedido[], int, eCliente[], int, ePago[], int)
/// \brief Recorre la lista de clientes y llama a la funcion "pedido_buscarYMostrarProcesados" que relaciona el cliente con su pedido y lo muestra.
/// \param listaPedidos ePedido array de pedidos
/// \param lenPedidos int tamaño del array de pedidos
/// \param listaClientes eCliente array de clientes.
/// \param lenClientes int tamaño del array de clientes.
/// \param listaPagos ePago array de pagos.
/// \param lenPagos int tamaño del array de pagos.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int pedido_imprimirProcesados(ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes, ePago listaPagos[], int lenPagos);

/// \fn int pedido_buscarYMostrarProcesados(ePedido[], int, eCliente, ePago[], int)
/// \brief Recorre la lista de pedidos y si se relaciona con el cliente que llega por parametro y es de estado PROCESADO, se imprime por pantalla.
/// \param listaPedidos ePedido array de pedidos
/// \param lenPedidos int tamaño del array de pedidos
/// \param unCliente eCliente un cliente.
/// \param listaPagos ePago array de pagos.
/// \param lenPagos int tamaño del array de pagos.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int pedido_buscarYMostrarProcesados(ePedido listaPedidos[], int lenPedidos, eCliente unCliente, ePago listaPagos[], int lenPagos);

/// \fn int informe_pedidosPendientePorLocalidad(ePedido[], int, eCliente[], int, eLocalidad[], int)
/// \brief Muestra la lista de las localidades y usuario elije una por su ID, luego recorre el array de clientes para asociar esta localidad que con el cliente corrrespondiente,
///        si es asi, llama a la funcion "contador_porEstado" que recorre el array de pedidos y cuenta la cantidad de pedidos en estado PENDIENTE.
/// \param listaPedidos ePedido array de pedidos.
/// \param lenPedidos int tamaño del array de pedidos.
/// \param listaClientes eCliente array de clientes.
/// \param lenClientes int tamaño del array de clientes.
/// \param listaLocalidades eLocalidad array de localidades.
/// \param lenLocalidades int tamaño del array de localidades.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int informe_pedidosPendientePorLocalidad(ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes, eLocalidad listaLocalidades[], int lenLocalidades, eZona listaZonas[], int lenZonas);

/// \fn int informe_promedioKilosPolipropeno(ePedido[], int, eCliente[], int, ePago[], int)
/// \brief Imprime la lista de pedidos procesados y el usuario puede elegir el ID del cliente a calcular promedio,
///        luego recorre la lista de pedidos en busca de los pedidos del el cliente elegido y calcula el promedio de PP.
/// \param listaPedidos ePedido array de pedidos.
/// \param lenPedidos int tamaño del array de pedidos.
/// \param listaClientes eCliente array de clientes.
/// \param lenClientes int tamaño del array de clientes.
/// \param listaPagos ePagos array de pagos.
/// \param lenPagos  int tamaño del array de pagos.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int informe_promedioKilosPolipropeno(ePedido listaPedidos[], int lenPedidos, eCliente listaClientes[], int lenClientes, ePago listaPagos[], int lenPagos);

/// \fn int informe_clienteMasPedidosPendientes(eCliente[], int, ePedido[], int, eLocalidad[], int)
/// \brief Busca el maximo de los pedidos pendientes, cuando lo encuentra, vuelve a contar la cantidad de pedidos por cliente y los que son iguales al maximo los imprime en pantalla.
/// \param listaClientes eCliente array de pedidos.
/// \param lenClientes int tamaño del array de clientes.
/// \param listaPedidos  ePedido array de pedidos.
/// \param lenPedidos int tamaño del array de clientes.
/// \param listaLocalidades eLocalidad array de localidades.
/// \param lenLocalidades int tamaño del array de localidades.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int informe_clienteMasPedidosPendientes(eCliente listaClientes[], int lenClientes, ePedido listaPedidos[], int lenPedidos, eLocalidad listaLocalidades[], int lenLocalidades);

/// \fn int maximo_clienteMasPedidosPorEstado(eCliente[], int, ePedido[], int, int, int*)
/// \brief Recorre la lista de clientes y calcula la maxima cantidad de pedidos por estado ( PENDIENTE O PROCESADO ), luego retorna el maximo por parametro.
/// \param listaClientes eCliente array de pedidos.
/// \param lenClientes int tamaño del array de clientes.
/// \param listaPedidos ePedido array de pedidos.
/// \param lenPedidos int tamaño del array de pedidos.
/// \param estadoPedido int PENDIENTE O PROCESADO.
/// \param cantidadMaxPedidos int maxima cantidad de pedidos.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int maximo_clienteMasPedidosPorEstado(eCliente listaClientes[], int lenClientes, ePedido listaPedidos[], int lenPedidos, int estadoPedido, int* cantidadMaxPedidos);

/// \fn int informe_clienteMasPedidosProcesados(eCliente[], int, ePedido[], int, eLocalidad[], int)
/// \brief Busca el maximo de los pedidos procesados, cuando lo encuentra, vuelve a contar la cantidad de pedidos por cliente y los que son iguales al maximo los imprime en pantalla.
/// \param listaClientes eCliente array de clientes.
/// \param lenClientes int tamaño del array de clientes.
/// \param listaPedidos ePedido array de pedidos.
/// \param lenPedidos int tamaño del array de clientes.
/// \param listaLocalidades eLocalidad array de localidades.
/// \param lenLocalidades int tamaño del array de localidades.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int informe_clienteMasPedidosProcesados(eCliente listaClientes[], int lenClientes, ePedido listaPedidos[], int lenPedidos, eLocalidad listaLocalidades[], int lenLocalidades);

/// \fn int contador_porEstado(eCliente, ePedido[], int, int*, int)
/// \brief  Cuenta la cantidad de pedidos por estado de un cliente.
/// \param unCliente eCliente un cliente.
/// \param listaPedidos ePedido array de pedidos.
/// \param lenPedidos int tamaño del array de pedidos.
/// \param contador contador de pedidos
/// \param estadoPedido  int PENDIENTE O PROCESADO.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int contador_porEstado(eCliente unCliente, ePedido listaPedidos[], int lenPedidos, int* contador, int estadoPedido);

/// \fn int promedio_pagosLiquidadosPorZona(eCliente[], int, ePedido[], int, eLocalidad[], int, ePago[], int, eZona[], int)
/// \brief Calcula el promedio de pagos liquidados de la zona que el usuario elija.
/// Primero recorre la lista de localidades, contando la cantidad de localidades que cumplen con la condición.
/// Luego recorre la lista de pedidos , en busca del index, de los que les pertenece los barrios y zona.
/// Y por último recorre la lista de pagos, acumulando la cantidad de dinero liquidado. Después imprime el promedio por pantalla.
/// \param listaClientes eCliente array de clientes.
/// \param lenClientes int tamaño del array de clientes.
/// \param listaPedidos  ePedido array de pedidos.
/// \param lenPedidos int tamaño del array de pedidos.
/// \param listaLocalidades  eLocalidad array de localidades.
/// \param lenLocalidades int tamaño del array de localidades.
/// \param listaPagos ePago array de pagos.
/// \param lenPagos int tamaño del array de pagos.
/// \param listaZonas eZona array de zonas.
/// \param lenZonas int tamaño del array de zonas.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int promedio_pagosLiquidadosPorZona(eCliente listaClientes[], int lenClientes, ePedido listaPedidos[], int lenPedidos, eLocalidad listaLocalidades[], int lenLocalidades, ePago listaPagos[], int lenPagos, eZona listaZonas[], int lenZonas);

/// \fn int informe_contadorClientePorZona(eLocalidad[], int, eCliente, eZona[], int, int*)
/// \brief Muestra la lista de zonas y el usuario elige la cual quiere que se calcule el promedio. Si es un ID correcto se matchea con su localidad y se cuenta la cantidad de clientes que pertenecen a esa zona.
/// \param listaLocalidades eLocalidad array de localidades.
/// \param lenLocalidades int tamaño del array de localidades.
/// \param unCliente eCliente un cliente.
/// \param listaZonas eZona array de zonas.
/// \param lenZonas int tamaño del array de zonas.
/// \param contadorLocalidades int contador de clientes en la zona especificada.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int informe_contadorClientePorZona(eLocalidad listaLocalidades[], int lenLocalidades, eCliente unCliente, eZona listaZonas[], int lenZonas, int* contadorLocalidades);

/// \fn int informe_pedidoClientePorZona(ePedido[], int, eCliente, int*)
/// \brief Se recorre la lista de pedidos buscando matchear con el o los clientes encontrados en la funcion "informe_contadorClientePorZona" y asi devolver su index.
/// \param listaPedidos ePedido array de pedidos.
/// \param lenPedidos int tamaño del array de pedidos.
/// \param unCliente eCliente un cliente.
/// \param indexPedido int index donde se encuentra el pedido.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int informe_pedidoClientePorZona(ePedido listaPedidos[], int lenPedidos, eCliente unCliente, int* indexPedido);

/// \fn int informe_acumuladorPagosEnZonaSur(ePago[], int, ePedido, float*)
/// \brief Recorre la lista de pagos y acumula la cantidad de dinero liquidado, si es asi lo devuelve por parametro.
/// \param listaPagos listaPagos ePago array de pagos.
/// \param lenPagos enPagos int tamaño del array de pagos.
/// \param unPedido ePedido un pedido.
/// \param acumuladorDineroLiquidado float acumulador del dinero liquidado.
/// \return ERROR(-1) si hubo un error o FUNCIONO(0) si todo estuvo bien.
int informe_acumuladorPagosPorZona(ePago listaPagos[], int lenPagos, ePedido unPedido, float* acumuladorDineroLiquidado);

#endif /* INFORMES_H_ */
