/**
 * @CLASE: GestorLugarNacimiento
 *
 * @brief
 * 		Clase gestora que encapsula una lista de lugares de nacimiento de la población de una vía. Utilizada para
 * 			contextualizar la búsqueda/manipulación de lugares de nacimiento en una vía concreta. A partir de una cadena
 * 			con los campos de múltiples objetos 'LugarNacimiento' inicializa la lista que encapsula. Gestiona la memoria
 * 			asociada a los objetos 'LugarNacimiento' almacenados en la lista que encapsula
 *
 * @atributo lLugarNacimiento
 * 		Lista que encapsula el gestor. Almacena los lugares de nacimiento de la población de cada vía
 * 		@orden: Ninguna ordenación particular. El estado final de la lista es el orden inverso de lectura del fichero de
 * 			datos del padrón (orden alfabéticamente descendente de poblaciones, si se han guardado)
 */

#ifndef GESTORLUGARNACIMIENTO_H_
#define GESTORLUGARNACIMIENTO_H_

#include "Utils.h"
#include "listapi.h"
#include "LugarNacimiento.h"
#include <fstream>

namespace std {

class GestorLugarNacimiento {

private:
	ListaPI<LugarNacimiento*>* lLugarNacimiento;

public:
	/**
	 * @brief
	 * 		CONSTRUCTOR POR DEFECTO. Reserva memoria para la lista que encapsula
	 *
	 * @pre:
	 * @post: Instancia de GestorLugarNacimiento inicializada por defecto
	 * @complejidad: O(1)
	 */
	GestorLugarNacimiento();
	/**
	 * @brief
	 * 		CONSTRUCTOR PARAMETRIZADO. Inicializa todos los atributos de una instancia de la clase GestorLugarNacimiento
	 * 			a partir de los parámetros
	 *
	 * @param lugaresNacimiento
	 * 		Cadena 'parseada' con los campos de múltiples objetos LugarNacimiento
	 *
	 * @pre:
	 * @post: Instancia de la clase GestorLugarNacimiento inicializada paramétricamente
	 * @complejidad: O(n)
	 */
	GestorLugarNacimiento(string lugaresNacimiento);
	/**
	 * @brief
	 * 		DESTRUCTOR. Libera la memoria reservada para la lista de lugares de nacimiento y los lugares de nacimiento de la lista
	 *
	 * @pre:
	 * @post:
	 * @complejidad: O(n)
	 */
	~GestorLugarNacimiento();

	/**
	 * @brief
	 * 		Elabora una lista de las distintas provincias de nacimiento de toda la población de Cáceres. Utilizado por el Algoritmo 6
	 *
	 * @param lLugNac
	 * 		Lista en la que almacenar cada provincia como una instacia de 'LugarNacimiento'
	 *
	 * @pre:
	 * @post: Inserta/actualiza la lista de nacionalidades pasada por parámetro 'lLugNac' dependiendo de si cada provincia
	 * 			ya existía en la lista o es nueva. Por cada modificación se mantiene el orden de la lista mediante un bucle anidado
	 * 			que busca el lugar de inserción/modificación en base a la sobrecarga de operadores de la clase 'LugarNacimiento'
	 * @complejidad: O(n^2)
	 */
	void alg6(ListaPI<LugarNacimiento*>*& lLugNac);
	void alg10(ListaPI<LugarNacimiento*>*& lLugNac, string nombreProvincia);
	void alg11(ofstream& ofs);
	int alg12(string nombreProvincia);

	/**
	 * @brief
	 * 		Muestra todos los lugares de nacimiento. Se utiliza con fines de prueba
	 *
	 * @pre:
	 * @post: Llama a mostrar los atributos de cada lugar de nacimiento de la lista encapsula
	 * @complejidad: O(n)
	 */
	void mostrar();
};

}

#endif /* GESTORLUGARNACIMIENTO_H_ */
