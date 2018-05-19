/**
 * @CLASE: GestorBarrio
 *
 * @brief
 * 		Clase gestora que encapsula la lista de todos los barrios cargados. Es el punto de inicio de toda
 * 			la jerarquía de datos.
 *
 * @atributo lBarrios
 * 		Lista que encapsula el gestor. Almacena todos los datos leídos del fichero \const RUTA_BARRIO.
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
	 *
	 * @pre:
	 * @post: Instancia de GestorBarrio inicializada por defecto
	 * @complejidad: O(1)
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
	 */
	~GestorBarrio();

	/**
	 * @brief
	 * 		MÉTODO INVOCATIVO. Utilizado por el Algoritmo 1 (carga de datos)
	 *
	 * @param b
	 * 		Puntero al barrio creado para ser cargado
	 *
	 * @pre:
	 * @post: Insertar por orden de llegada el barrio 'b' en la lista de barrios que encapsula el gestor sin modificación del PI
	 * @complejidad: O(1)
	 */
	void insertar(Barrio* b);
	/**
	 * @brief
	 * 		MÉTODO INVOCATIVO. Utilizado por el Algoritmo 1 (carga de datos)
	 *
	 * @param v
	 * 		Puntero a la vía creadoa para ser cargada
	 *
	 * @pre:
	 * @post: Llama a insertar en orden la vía 'v' en el gestor de vías 'gVias'
	 * @complejidad: O(n)
	 */
	void insertarVia(Via* v);
	/**
	 * @brief
	 * 		Busca asignar el dato demográfico recién creado entre todas la(s) vía(s) correspondientes entre todos los barrios.
	 * 			Utilizado por el algoritm 1 (carga de datos)
	 *
	 * @param dD
	 * 		Puntero al dato demográfico creado para ser asignado
	 *
	 * @pre:
	 * @post: Propaga por todos los barrios de la lista de barrios que encapsula el gestor el dato demográfico 'dD' para que
	 * 		comprueben si pertence a alguna de sus vías
	 * @complejidad: O(n)
	 */
	void insertarDatosDemograficos(DatosDemograficos* dD);
	void alg2(string nombreBarrio);
	void alg7(int limInf, int limSup);
	void alg8(string nombreBarrio);
	void alg9();

	/**
	 * @brief
	 * 		Muestra todos los barrios cargados y sus estructuras de datos asocidas. Se utiliza con fines de prueba
	 *
	 * @pre:
	 * @post: Muestra todos los barrios, vías en cada barrio y datos demográficos de cada vía
	 * @complejidad: O(n)
	 */
	void mostrar();
};

}

#endif /* GESTORBARRIO_H_ */
