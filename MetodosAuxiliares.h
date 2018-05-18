/*
 * PLACEHOLDER
 */

#ifndef METODOSAUXILIARES_H_
#define METODOSAUXILIARES_H_

#include "Padron.h"

namespace pruebas {

class MetodosAuxiliares {

public:
	MetodosAuxiliares();
	~MetodosAuxiliares();

	/**@TEST: Implementación de prueba del método GestorNacionalidad::ordenarLista y GestorEstudios::ordenarLista
	 *
	 * @param lNacion
	 * 		Simula la lista encapsulada 'lNacionalidad' y 'lEstudios' del gestor GestorNacionalidad y GestorEstudios
	 */
	static void ordenarLista(ListaPI<Nacionalidad*>*& lNacion);

	/**@TEST: Implementación de prueba del método GestorBarrio::insertarVia
	 *
	 * @param v
	 * 		Vía a buscar en la lista de barrios \param lBarrios
	 * @param lBarrios
	 * 		Simula la lista de barrios encapsulada del gestor GestorBarrio
	 * @return
	 * 		Devuelve si la vía pertence a algún barrio de la lista \param lBarrios
	 */
	static bool insertarVia(Via* v, ListaPI<Barrio*>& lBarrios);
};

}

#endif /* METODOSAUXILIARES_H_ */
