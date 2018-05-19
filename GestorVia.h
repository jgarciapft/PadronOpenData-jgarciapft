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
	 * @post:
	 * @complejidad: O(1)
	 *
	 * @return
	 * 		Instancia de GestorVia inicializada por defecto
	 */
	GestorVia();
	~GestorVia();

	void insertarViaOrden(Via* v);
	void insertarDatosDemograficos(DatosDemograficos* dD);
	int alg7(int limInf, int limSup);
	void alg8();
	void alg9(float& pHombres, float& pMujeres);

	void mostrarVias();
	void mostrar();
};

}

#endif /* GESTORVIA_H_ */
