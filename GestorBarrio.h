/**
 * @CLASE: GestorBarrio
 *
 * @brief
 * 		Clase gestora que encapsula la lista de todos los barrios cargados. Es el punto de inicio de toda
 * 			la jerarquía de datos.
 *
 * @atributo lBarrios
 * 		Lista que encapsula el gestor. Almacena todos los datos leídos del fichero \constante RUTA_BARRIO.
 * 		@orden: Ninguna ordenación particular. El estado final de la lista es el orden inverso al orden
 * 		de lectura del fichero de barrios
 */

#ifndef GESTORBARRIO_H_
#define GESTORBARRIO_H_

#include "Barrio.h"

namespace std {

class GestorBarrio {

private:
	ListaPI<Barrio*>* lBarrios;

public:
	/**
	 * @brief
	 * 		CONSTRUCTOR POR DEFECTO. Reserva memoria para la lista que encapsula
	 * @pre:
	 * @post:
	 * @complejidad: O(1)
	 *
	 * @return
	 * 		Instancia de GestorBarrio inicializada por defecto
	 */
	GestorBarrio();
	/**
	 * @brief
	 * 		DESTRUCTOR. Libera la memoria reservada para la lista de barrios que encapsula y los barrios de la lista.
	 * 		En cascada las vías asociadas a cada barrio.
	 *
	 * @pre:
	 * @post:
	 * @complejidad: O(n)
	 *
	 * @return
	 */
	~GestorBarrio();

	void insertar(Barrio* b);
	void insertarVia(Via* v);
	void insertarDatosDemograficos(DatosDemograficos* dD);
	void alg2(string nombreBarrio);
	void alg7(int limInf, int limSup);
	void alg8(string nombreBarrio);
	void alg9();

	void mostrar();
};

}

#endif /* GESTORBARRIO_H_ */
