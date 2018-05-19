/**
 * @CLASE: Padron
 *
 * @brief
 * 		Almacena la jerarquia de la estructura de datos y provee una interfaz a la clase UI para ejecutar los algoritmos
 * 			del proyecto a partir de la entrada del usuario por la entrada estandar (cin). También maneja la reserva/liberación de la
 * 			memoria asociada a toda la estructura
 *
 * @atributo gBarrio
 * 		Instancia de la clase gestora de la lista de barrios 'GestorBarrio' y, por tanto, de toda la jerarquía de datos
 * @atributo lVias
 * 		Lista de vías auxiliar para almacenar todas las vías creadas a partir de los ficheros de datos
 * @atributo aVias
 * 		ABB de vías auxiliar para almacenar para la implementación de los algoritmos 11 y 12 en su versión EDNL.
 * 			No se garantiza el balanceado del árbol.
 * @atributo lDatDemograficos
 * 		Lista de datos demográficos auxiliar para almacenar todos los datos demográficos creados.
 * 		También se usa para liberar la memoria asociada. Como una vía puede estar compuesta de varios tramos,
 * 			y cada tramo es un objeto 'Via' en sí que apunta a los datos demográficos de todos los tramos,
 * 			ocurre que varios objetos apuntan a un mismo objeto, lo que puede ocasionar la doble liberación de punteros
 */

#ifndef PADRON_H_
#define PADRON_H_

#include "GestorBarrio.h"
#include "arbol.h"

namespace std {

class Padron {

private:
	GestorBarrio* gBarrio;
	ListaPI<Via*>* lVias;
	Arbol<Via*, ComparadorPtrVia>* aVias;
	ListaPI<DatosDemograficos*>* lDatDemograficos;

private:
	void alg11(Arbol<Via*, ComparadorPtrVia>* aVias, string nombreVia, ofstream& ofs, bool& enc);
	Arbol<Via*, ComparadorPtrVia>* alg12(Arbol<Via*, ComparadorPtrVia>* aVias, string raiz);
	int filtroInOrden(Arbol<Via*, ComparadorPtrVia>* aVias, string raiz, string nombreProvincia);

public:
	/**
	 * @brief
	 * 		CONSTRUCTOR POR DEFECTO. Reserva espacio para 'gBarrio', 'lVias', 'aVias' y 'lDatDemograficos'
	 *
	 * @pre:
	 * @post: Instancia de Padron inicializada por defecto
	 * @complejidad: O(1)
	 */
	Padron();
	/**
	 * @brief
	 * 		DESTRUCTOR. Libera la memoria reservada para toda la jerarquía de datos en cascada.
	 * 			Los datos demográficos se liberan a partir de la lista 'lDatDemograficos'
	 * 			Las raices de los nodos del ABB 'aVias' ya han sido liberadas, solo se liberan
	 * 				los nodos del ABB 'aVias'
	 *
	 * @pre:
	 * @post:
	 * @complejidad: O(n)
	 */
	~Padron();

	/**
	 * @brief
	 * 		Lee los datos de los barrios del fichero \const RUTA_BARRIO, crea las instancias de objetos 'Barrio'
	 * 			y las carga en la jerarquía de datos
	 *
	 * @pre: El fichero \const RUTA_BARRIO contiene los campos necesarios para conformar objetos 'Barrio' en un formato
	 * 		correcto
	 * @post: Se cargan en 'gBarrios' los barrios creados
	 * @complejidad: O(n)
	 *
	 * @return
	 * 		TRUE  ->  Si se pudo acceder a \const RUTA_BARRIO
	 * 		FALSE ->  Si no se pudo acceder a \const RUTA_BARRIO
	 */
	bool cargarBarrios();
	/**
	 * @brief
	 * 		Lee los datos de las vías del fichero \const RUTA_VIA, crea las instancias de objetos 'Via'
	 * 			y las carga en la jerarquía de datos, en la lista auxiliar de vías y en el ABB auxiliar de vías
	 *
	 * @pre: El fichero \const RUTA_VIA contiene los campos necesarios para conformar objetos 'Via' en un formato
	 * 		correcto
	 * @post: Se cargan en los gestores 'gVias' de los barrios del gestor 'gBarrios' las vías según el nombre del
	 * 		del barrio al que pertenecen
	 * @complejidad: O(n^2)
	 *
	 * @return
	 * 		TRUE  ->  Si se pudo acceder a \const RUTA_VIA
	 * 		FALSE ->  Si no se pudo acceder a \const RUTA_VIA
	 */
	bool cargarVias();
	/**
	 * @brief
	 * 		Lee los datos del padrón del fichero \const RUTA_PADRON, crea las instancias de objetos 'DatosDemografioos'
	 * 			y las carga en la jerarquía de datos y en la lista auxiliar de datos demográficos
	 *
	 * @pre: El fichero \const RUTA_PADRON contiene los campos necesarios para conformar objetos 'DatosDemograficos' en un
	 * 		formato correcto
	 * @post: Se asignan las instancias de DatosDemograficos a los punteros de vías de toda la estructura de datos (incluidas
	 * 		las estructuras auxiliares) según el código de vía
	 * @complejidad: O(n)
	 *
	 * @return
	 * 		TRUE  ->  Si se pudo acceder a \const RUTA_PADRON
	 * 		FALSE ->  Si no se pudo acceder a \const RUTA_PADRON
	 */
	bool cargarDatosDemograficos();
	/**
	 * @brief
	 * 		MÉTODO INVOCATIVO. Utilizado por el Algoritmo 2
	 *
	 * @param nombreBarrio
	 * 		Nombre del barrio utilizar por el Algoritmo 2
	 *
	 * @pre:
	 * @post: Llama a ejecutar el Algoritmo 2
	 * @complejidada: O(n)
	 */
	void alg2(string nombreBarrio);
	void alg3();
	void alg4();
	void alg5();
	void alg6();
	void alg7(int limInf, int limSup);
	void alg8(string nombreBarrio);
	void alg9();
	void alg10(string nombreProvincia);
	void alg11_EDL(string nombreVia);
	void alg11_EDNL(string nombreVia);
	void alg12_EDL(string raiz, string nombreProvincia);
	void alg12_EDNL(string raiz, string nombreProvincia);

	/**
	 * @brief
	 * 		Muestra toda la información procesada y cargada. Se utiliza con fines de prueba
	 *
	 * @pre:
	 * @post: Muestra toda la jerarquía de datos cargada y las estructuras auxiliares
	 * @complejidad: O(n)
	 */
	void mostrarEstructura();
};

}

#endif /* PADRON_H_ */
