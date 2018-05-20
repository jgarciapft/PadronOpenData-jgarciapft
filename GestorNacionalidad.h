/**
 * @CLASE: GestorNacionalidad
 *
 * @brief
 * 		Clase gestora que encapsula una lista de nacionalidades de la población de una vía. Utilizada para
 * 			contextualizar la búsqueda/manipulación de nacionalidades en una vía concreta. A partir de una cadena
 * 			con los campos de múltiples objetos 'Nacionalidad' inicializa la lista que encapsula. Gestiona la memoria
 * 			asociada a los objetos 'Nacionalidad' almacenados en la lista que encapsula
 *
 * @atributo lNacionalidad
 * 		Lista que encapsula el gestor. Almacena las nacionalidades de la población de cada vía
 * 		@orden: Ninguna ordenación particular. El estado final de la lista es el orden inverso de lectura del fichero de
 * 			datos del padrón (orden alfabéticamente descendente de las nacionalidades)
 */

#ifndef GESTORNACIONALIDAD_H_
#define GESTORNACIONALIDAD_H_

#include "Utils.h"
#include "listapi.h"
#include "Nacionalidad.h"

namespace std {

class GestorNacionalidad {

private:
	ListaPI<Nacionalidad*>* lNacionalidad;

private:
	/**
	 * @brief
	 * 		Ordena una lista de nacionalidades descendentemente por el número de personas.
	 *
	 * @param lNacion
	 * 		Lista en la que almacenar cada nacionalidad como una instacia de 'Nacionalidad'
	 *
	 * @pre:
	 * @post: Modifica la lista pasada por parámetro 'lNacion' para mantener un orden matemático
	 * 			descendente	por el atributo 'nPersonas' de los objetos 'Nacionalidad'
	 * @complejidad: O(n)
	 */
	void ordenarLista(ListaPI<Nacionalidad*>*& lNacion);

public:
	/**
	 * @brief
	 * 		CONSTRUCTOR POR DEFECTO. Reserva memoria para la lista que encapsula
	 *
	 * @pre:
	 * @post: Instancia de GestorNacionalidad inicializada por defecto
	 * @complejidad: O(1)
	 */
	GestorNacionalidad();
	/**
	 * @brief
	 * 		CONSTRUCTOR PARAMETRIZADO. Inicializa todos los atributos de una instancia de la clase GestorNacimiento
	 * 			a partir de los parámetros
	 *
	 * @param nacionalidades
	 * 		Cadena 'parseada' con los campos de múltiples objetos Nacionalidad
	 *
	 * @pre:
	 * @post: Instancia de la clase GestorNacimiento inicializada paramétricamente
	 * @complejidad: O(n)
	 */
	GestorNacionalidad(string nacionalidades);
	/**
	 * @brief
	 * 		DESTRUCTOR. Libera la memoria reservada para la lista de nacionalidades y las nacionalidades de la lista
	 *
	 * @pre:
	 * @post:
	 * @complejidad: O(n)
	 */
	~GestorNacionalidad();

	/**
	 * @brief
	 * 		Elabora una lista de las distintas nacionalidades de toda la población de Cáceres. Utilizado por el Algoritmo 5
	 *
	 * @param lNacion
	 * 		Lista en la que almacenar cada nacionalidad como una instacia de 'Nacionalidad'
	 *
	 * @pre:
	 * @post: Inserta/actualiza la lista de nacionalidades pasada por parámetro 'lNacion' dependiendo de si cada nacionalidad
	 * 			ya existía en la lista o es nuevo. Por cada modificación se mantiene el orden de la lista mediante el método
	 * 			'GestorNacionalidad::ordenarLista'
	 * @complejidad: O(n^2)
	 */
	void alg5(ListaPI<Nacionalidad*>*& lNacion);

	/**
	 * @brief
	 * 		Muestra todas las nacionalidades. Se utiliza con fines de prueba
	 *
	 * @pre:
	 * @post: Llama a mostrar los atributos de cada nacionalidad de la lista encapsula
	 * @complejidad: O(n)
	 */
	void mostrar();
};

}

#endif /* GESTORNACIONALIDAD_H_ */
