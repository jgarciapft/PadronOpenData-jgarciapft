/**
 * @CLASE: GestorVia
 *
 * @brief
 * 		Clase gestora que encapsula la lista de las vías que pertenecen a un barrio. Utilizada para
 * 			contextualizar la búsqueda/manipulación de datos en un barrio concreto
 *
 * @atributo lVias
 * 		Lista que encapsula el gestor. Almacena las vías que pertenecen a un barrio.
 * 		@orden: Ordenación alfabéticamente descendente. Facilita el volcado de las vías que pertenecen
 * 			a un barrio en orden alfabético (Algoritmo 3)
 */

#ifndef GESTORVIA_H_
#define GESTORVIA_H_

#include "Via.h"

namespace std {

class GestorVia {

private:
	ListaPI<Via*>* lVias;

public:
	/**
	 * @brief
	 * 		CONSTRUCTOR POR DEFECTO. Reserva memoria para la lista que encapsula
	 * @pre:
	 * @post: Instancia de GestorVia inicializada por defecto
	 * @complejidad: O(1)
	 */
	GestorVia();
	/**
	 * @brief
	 * 		DESTRUCTOR. Libera la memoria reservada para la lista de vías que encapsula y las vías de la lista
	 *
	 * @pre:
	 * @post:
	 * @complejidad: O(n)
	 */
	~GestorVia();

	void insertarViaOrden(Via* v);
	void insertarDatosDemograficos(DatosDemograficos* dD);
	int alg7(int limInf, int limSup);
	void alg8();
	void alg9(float& pHombres, float& pMujeres);

	/**
	 * @brief
	 * 		Muestra la información de cada vía en la lista que encapsula. Se utiliza para el Algoritmo 2
	 *
	 * @pre:
	 * @post: Muestra las vías de la lista que encapsula, menos los datos demográficos asociados a cada vía
	 * @complejidad: O(n)
	 */
	void mostrarVias();
	/**
	 * @brief
	 * 		Muestra toda la información de cada barrio y la información cargada en el gestor de vías.
	 * 			Se utiliza con fines de prueba
	 *
	 * @pre:
	 * @post: Muestra los atributos de cada vía y los datos demográficos asociados a cada vía
	 * @complejidad: O(n)
	 */
	void mostrar();
};

}

#endif /* GESTORVIA_H_ */
