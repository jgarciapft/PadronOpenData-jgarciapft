/**
 * CLASE: Barrio
 *
 * @brief
 * 		Modela el concepto de 'barrio' y su comportamiento. Cada barrio es está definido por su nombre y el distrito
 * 			al que pertenece y almacena una lista gestionada de las vías que lo componen. Principalmente contiene métodos
 * 			invocativos para los algoritmos que requieren búsquedas por barrio
 *
 * @atributo nombreBarrio
 * 		Nombre del barrio
 * @atributo nombreDistrito
 * 		Nombre del distrito
 * @atributo gVias
 * 		Instancia de la clase que gestiona la lista de vías que pertenecen al barrio
 */

#ifndef BARRIO_H_
#define BARRIO_H_

#include "GestorVia.h"

namespace std {

class Barrio {

private:
	string nombreBarrio;
	string nombreDistrito;
	GestorVia* gVias;

public:
	/**
	 * @brief
	 * 		CONSTRUCTOR POR DEFECTO. Reserva memoria para 'gVias' e hace una inicialización por defecto de los atributos
	 * @pre:
	 * @post: Instancia de Barrio inicializada por defecto
	 * @complejidad: O(1)
	 */
	Barrio();
	/**
	 * @brief
	 * 		CONSTRUCTOR PARAMETRIZADO. Inicializa todos los atributos de una instancia de la clase Barrio a partir de los parámetros
	 *
	 * @param nB
	 * 		Nombre del barrio
	 * @param nD
	 * 		Nombre del distrito
	 *
	 * @pre:
	 * @post: Instancia de la clase Barrio inicializada paramétricamente
	 * @complejidad: O(1)
	 */
	Barrio(string nB, string nD);
	/**
	 * @brief
	 * 		DESTRUCTOR. Libera la memoria reservada para el gestor de vías 'gVias', por lo que se liberan en cascada las vías
	 * 			asociadas a ese gestor
	 *
	 * @pre:
	 * @post:
	 * @complejidad: O(n)
	 */
	~Barrio();

	/**
	 * GETTERS
	 */
	string getNombreBarrio() const ;
	string getNombreDistrito() const;
	/**
	 * @brief
	 * 		MÉTODO INVOCATIVO. Utilizado por el Algoritmo 1 (carga de datos)
	 *
	 * @param v
	 * 		Vía a insertar en orden en el gestor de vías 'gVias'
	 *
	 * @pre:
	 * @post: Llama a insertar la vía \param v en el gestor de vías 'gVias'
	 * @complejidad: O(n)
	 */
	void insertarVia(Via* v);
	/**
	 * @brief
	 * 		MÉTODO INVOCATIVO. Utilizado por el Algoritmo 1 (carga de datos)
	 *
	 * @param v
	 * 		Dato demográfico a insertar en alguna (o ninguna) de las vías del gestor de vías 'gVias'
	 *
	 * @pre:
	 * @post: Llama a comprobar si el dato demográfico \param dD correspone a alguna de las vías del gestor de vías 'gVias'
	 * @complejidad: O(n)
	 */
	void insertarDatosDemograficos(DatosDemograficos* dD);
	/**
	 *@brief
	 * 		MÉTODO INVOCATIVO. Utilizado por el Algoritmo 7
	 *
	 * @param limInf
	 * 		Límite inferior del rango de edad
	 * @param limSup
	 * 		Límite superior del rango de edad
	 *
	 * @pre:
	 * @post: Calcula el barrio con mayor número de habitantes para el rango [limInf, limSup] (si existe algún habitante en el
	 * 			rango)
	 * @complejidad: O(n)
	 *
	 * @return
	 * 		Número de habitantes pertenecientes al rango de edad dado en el barrio actual
	 */
	int alg7(int limInf, int limSup);
	/**
	 * @brief
	 * 		MÉTODO INVOCATIVO. Utilizado por el Algoritmo 8
	 *
	 * @pre:
	 * @post: llama a que se ejecute la funcionalidad principal del Algoritmo 8
	 * @complejidad: O(n^2)
	 */
	void alg8();
	/**
	 * @brief
	 * 		MÉTODO INVOCATIVO. Utilizado por el Algoritmo 9
	 *
	 * @pre:
	 * @post: Llama a calcular el porcentaje de hombres y de mujeres del barrio actual
	 * @complejidad: O(n)
	 */
	void alg9(float& pHombres, float& pMujeres);

	/**
	 * @brief
	 * 		MÉTODO INVOCATIVO. Se utiliza para el Algoritmo 2
	 *
	 * @pre:
	 * @post: Llama a mostrar las vías en el gestor 'gVias' del barrio, menos los datos demográficos asociados a cada vía
	 * @complejidad: O(n)
	 */
	void mostrarVias();
	/**
	 * @brief
	 * 		Muestra toda la información de cada barrio y la información cargada en el gestor de vías.
	 * 			Se utiliza con fines de prueba
	 *
	 * @pre:
	 * @post: Muestra los atributos de cada barrio, las vías del gestor 'gVias' y los datos demográficos asociados a cada vía
	 * @complejidad: O(n)
	 */
	void mostrar();
};

}

#endif /* BARRIO_H_ */
