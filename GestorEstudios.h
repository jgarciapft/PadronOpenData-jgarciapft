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
	 * @pre:
	 * @post:
	 * @complejidad: O(1)
	 *
	 * @return
	 * 		Instancia de GestorEstudios inicializada por defecto
	 */
	GestorEstudios();
	GestorEstudios(string estudios);
	~GestorEstudios();

	void alg8(ListaPI<Estudios*>*& lEstud);

	void mostrar();
};

}

#endif /* GESTORESTUDIOS_H_ */
