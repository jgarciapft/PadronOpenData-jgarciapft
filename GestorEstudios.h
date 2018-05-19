/**
 * @CLASE: GestorEstudios
 *
 * @brief
 * 		Clase gestora que encapsula una lista de estudios de la población de una vía. Utilizada para
 * 			contextualizar la búsqueda/manipulación de estudios en una vía concreta. A partir de una cadena
 * 			con los campos de múltiples objetos 'Estudios' inicializa la lista que encapsula. Gestiona la memoria
 * 			asociada a los objetos 'Estudios' almacenados en la lista que encapsula
 *
 * @atributo lEstudios
 * 		Lista que encapsula el gestor. Almacena los niveles de estudio de la población de cada vía
 * 		@orden: Ninguna ordenación particular. El estado final de la lista es el orden inverso de lectura del fichero de
 * 			datos del padrón
 */

#ifndef GESTORESTUDIOS_H_
#define GESTORESTUDIOS_H_

#include "Utils.h"
#include "listapi.h"
#include "Estudios.h"

namespace std {

class GestorEstudios {

private:
	ListaPI<Estudios*>* lEstudios;

private:
	void ordenarLista(ListaPI<Estudios*>*& lEstud);

public:
	/**
	 * @brief
	 * 		CONSTRUCTOR POR DEFECTO. Reserva memoria para la lista que encapsula
	 *
	 * @pre:
	 * @post: Instancia de GestorEstudios inicializada por defecto
	 * @complejidad: O(1)
	 */
	GestorEstudios();
	/**
	 * @brief
	 * 		CONSTRUCTOR PARAMETRIZADO. Inicializa todos los atributos de una instancia de la clase GestorEstudios
	 * 			a partir de los parámetros
	 *
	 * @param estudios
	 * 		Cadena 'parseada' con los campos de múltiples objetos Estudios
	 *
	 * @pre:
	 * @post: Instancia de la clase GestorEstudios inicializada paramétricamente
	 * @complejidad: O(n)
	 */
	GestorEstudios(string estudios);
	/**
	 * @brief
	 * 		DESTRUCTOR. Libera la memoria reservada para la lista de estudios y los estudios de la lista
	 *
	 * @pre:
	 * @post:
	 * @complejidad: O(n)
	 */
	~GestorEstudios();

	void alg8(ListaPI<Estudios*>*& lEstud);

	void mostrar();
};

}

#endif /* GESTORESTUDIOS_H_ */
