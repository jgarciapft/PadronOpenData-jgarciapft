/**
 * @CLASE: GestorAnioNacimiento
 *
 * @brief
 * 		Clase gestora que encapsula una lista de años de nacimiento de la población de una vía. Utilizada para
 * 			contextualizar la búsqueda/manipulación de años de nacimiento en una vía concreta. A partir de una cadena
 * 			con los campos de múltiples objetos 'AnioNacimiento' inicializa la lista que encapsula. Gestiona la memoria
 * 			asociada a los objetos 'AnioNacimiento' almacenados en la lista que encapsula
 *
 * @atributo lAnioNacimiento
 * 		Lista que encapsula el gestor. Almacena los años de nacimiento de la población de cada vía
 * 		@orden: Ninguna ordenación particular. El estado final de la lista es el orden inverso de lectura del fichero de
 * 			datos del padrón (orden ascendente de años de nacimiento)
 */

#ifndef GESTORANIONACIMIENTO_H_
#define GESTORANIONACIMIENTO_H_

#include "Utils.h"
#include "listapi.h"
#include "AnioNacimiento.h"

namespace std {

class GestorAnioNacimiento {

private:
	ListaPI<AnioNacimiento*> *lAnioNacimiento;

public:
	/**
	 * @brief
	 * 		CONSTRUCTOR POR DEFECTO. Reserva memoria para la lista que encapsula
	 *
	 * @pre:
	 * @post: Instancia de GestorAnioNacimiento inicializada por defecto
	 * @complejidad: O(1)
	 */
	GestorAnioNacimiento();
	/**
	 * @brief
	 * 		CONSTRUCTOR PARAMETRIZADO. Inicializa todos los atributos de una instancia de la clase GestorAnioNacimiento
	 * 			a partir de los parámetros
	 *
	 * @param aniosNacimiento
	 * 		Cadena 'parseada' con los campos de múltiples objetos AnioNacimiento
	 *
	 * @pre:
	 * @post: Instancia de la clase GestorAnioNacimiento inicializada paramétricamente
	 * @complejidad: O(n)
	 */
	GestorAnioNacimiento(string aniosNacimiento);
	/**
	 * @brief
	 * 		DESTRUCTOR. Libera la memoria reservada para la lista de años de nacimiento y los años de nacimiento de la lista
	 *
	 * @pre:
	 * @post:
	 * @complejidad: O(n)
	 */
	~GestorAnioNacimiento();

	void alg4(ListaPI<AnioNacimiento*>*& lAnioNac);
	int alg7(int limInf, int limSup);

	/**
	 * @brief
	 * 		Muestra todos los años de nacimientos. Se utiliza con fines de prueba
	 *
	 * @pre:
	 * @post: Llama a mostrar los atributos de cada año de nacimiento de la lista encapsula
	 * @complejidad: O(n)
	 */
	void mostrar();
};

}

#endif /* GESTORANIONACIMIENTO_H_ */
