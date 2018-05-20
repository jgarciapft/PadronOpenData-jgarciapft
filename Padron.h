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
	 * @pre: Se puede abrir el flujo 'fEnt' y el fichero \const RUTA_BARRIO contiene los campos necesarios para conformar
	 * 			objetos 'Barrio' en un formato correcto
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
	 * @pre: Se puede abrir el flujo 'fEnt' y el fichero \const RUTA_VIA contiene los campos necesarios para conformar objetos
	 * 		'Via' en un formato correcto
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
	 * @pre: Se puede abrir el flujo 'fEnt' y el fichero \const RUTA_PADRON contiene los campos necesarios para conformar objetos
	 * 			'DatosDemograficos' en un formato correcto
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
	 * @pre: Jerarquía de datos cargada
	 * @post: Llama a ejecutar el Algoritmo 2
	 * @complejidada: O(n)
	 */
	void alg2(string nombreBarrio);
	/**
	 * @brief
	 * 		Muestra las vías que pasan por varios barrios (si existen) y los barrios que atraviesan. Utilizado por el Algoritmo 3
	 *
	 * @pre: Jerarquía de datos cargada
	 * @post: Imprime por consola la lista de vías que atraviesan varios barrios (si existen) y los barrios que atraviesan
	 * @complejidad: O(n^2)
	 */
	void alg3();
	/**
	 * @brief
	 * 		Muestra la población de Cáceres en décadas por intervalos y con una representación gráfica aproximada a un
	 * 			histograma de frecuencias. Utilizado por el Algoritmo 4
	 *
	 * @pre: Jerarquía de datos cargada. El tiempo del sistema es posterior a al año 2016
	 * @post: Imprime por consola el número de habitantes por interválos de décadas almacenados en la lista 'lAnioNac'
	 * 		(configurable para cualquier otra amplitud a través de \const RANGO_EDAD_ALG_4)
	 * @complejidad: O(n^2)
	 */
	void alg4();
	/**
	 * @brief
	 * 		Muestra una lista ordenada descendentemente por número de habitantes de nacionalidades para todos los habitantes
	 * 			de Cáceres. Utilizado por el Algoiritmo 5
	 *
	 * @pre: Jerarquía de datos cargada
	 * @post: Imprime por consola una lista ordenada descendentemente por número de habitantes, 'lNacion' de nacionalidades
	 * 			de todos los habitantes de Cáceres recogidos en el padrón.
	 * @complejidad: O(n^2)
	 */
	void alg5();
	/**
	 * @brief
	 * 		Muestra una lista ordenada alfabéticamente descendente por provincia de nacimiento de todos los habitantes de
	 * 			Cáceres. Utilizado por el Algoritmo 6
	 *
	 * @pre: Jerarquía de datos cargada
	 * @post: Imprime por consola un la lista ordenada alfabéticamente descendente por el nombre de la provincia, 'lLugNac' de
	 * 		lugares de nacimiento de todos los habitantes de Cáceres recogidos en el padrón.
	 * @complejidad: O(n^2)
	 */
	void alg6();
	/**
	 *@brief
	 * 		MÉTODO INVOCATIVO. Utilizado por el Algoritmo 7
	 *
	 * @param limInf
	 * 		Límite inferior del rango de edad
	 * @param limSup
	 * 		Límite superior del rango de edad
	 *
	 * @pre: Jerarquía de datos cargada
	 * @post: Calcula el barrio con mayor número de habitantes para el rango [limInf, limSup] (si existe algún habitante en el
	 * 		rango). Antes comprueba que el formato del intervalo sea válido
	 * @complejidad: O(n)
	 */
	void alg7(int limInf, int limSup);
	/**
	 * @brief
	 * 		MÉTODO INVOCATIVO. Utilizado por el Algoritmo 8
	 *
	 * @param nombreBarrio
	 * 		Nombre del bario a buscar
	 *
	 * @pre: Jerarquía de datos cargada
	 * @post: Vuelca en un archivo con ruta 'NivelDeEstudios-\param nombreBarrio.txt" una lista ordenada descendentemente las distintas
	 * 			titulaciones que ostentan los habitantes de ese barrio
	 * @complejidad: O(n^2)
	 */
	void alg8(string nombreBarrio);
	/**
	 * @brief
	 * 		MÉTODO INVOCATIVO. Utilizado por el Algoritmo 9
	 *
	 * @pre: Jerarquía de datos cargada
	 * @post: Imprime por consola el barrio con mayor porcentaje de mujeres y el barrio con mayor porcentaje de hombres de Cáceres
	 * @complejidad: O(n)
	 */
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
