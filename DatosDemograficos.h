/**
 * @CLASE: DatosDemograficos
 *
 * @brief
 * 		Clase interfaz de los datos del padrón para cada vía. Provee de métodos invocativos para explorar de forma
 * 			jerárquica y ordenada cada categoría de datos: años y lugares de nacimiento, estudios y nacionalidades.
 * 			Pasa a cada clase gestora una cadena con los campos de múltiples objetos a almacenar y gestiona la memoria asociada
 * 			a ellos
 *
 * @atributo codVia
 * 		Código númerico en el rango de [0, NUMERO DE VIAS]. Relaciona cada vía con un set de datos demográficos leídos del
 * 			archivo del padrón. Cada código es único para cada vía y es compartido por todos los tramos de vías (objetos 'Via' también) que
 * 			pertenecen a distintos barrios con el mismo nombre de vía
 * @atributo gAnioNacimiento
 * 		Instancia de la clase gestora de años de nacimiento
 * @atributo gLugarNacimiento
 * 		Instancia de la clase gestora de lugares de nacimiento
 * @atributo gEstudios
 * 		Instancia de la clase gestora de los estudios de la población
 * @atributo nMujeres
 * 		Número de mujeres de cada vía
 * @atributo nhombres
 * 		Número de hombres de cada via
 * @atributo gNacionalidad
 * 		Instancia de la clase gestora de nacionalidades
 */

#ifndef DATOSDEMOGRAFICOS_H_
#define DATOSDEMOGRAFICOS_H_

#include "GestorAnioNacimiento.h"
#include "GestorLugarNacimiento.h"
#include "GestorEstudios.h"
#include "GestorNacionalidad.h"

namespace std {

class DatosDemograficos {

private:
	int codVia;
	GestorAnioNacimiento* gAnioNacimiento;
	GestorLugarNacimiento* gLugarNacimiento;
	GestorEstudios* gEstudios;
	int nMujeres;
	int nHombres;
	GestorNacionalidad* gNacionalidad;

public:
	/**
	 * @brief
	 * 		CONSTRUCTOR POR DEFECTO. Reserva memoria para los gestores de datos del padrón e inicializa por defecto
	 * 			el resto de atributos
	 *
	 * @pre:
	 * @post: Instancia de DatosDemograficos inicializada por defecto
	 * @complejidad: O(1)
	 */
	DatosDemograficos();
	/**
	 * @brief
	 * 		CONSTRUCTOR PARAMETRIZADO. Inicializa todos los atributos de una instancia de la clase DatosDemograficos
	 * 			a partir de los parámetros
	 *
	 * @param _codVia
	 * 		Código de la vía a la que pertenece la instancia
	 * @param aniosNacimiento
	 * 		Cadena 'parseada' con los campos de múltiples objetos AnioNacimiento
	 * @param lugaresNacimiento
	 * 		Cadena 'parseada' con los campos de múltiples objetos LugarNacimiento
	 * @param estudios
	 * 		Cadena 'parseada' con los campos de múltiples objetos Estudios3
	 * @param _nMujeres
	 * 		Número de mujeres en la vía a la que pertenece la instancia
	 * @param _nHombres
	 *  	Número de hombres en la vía a la que pertenece la instancia
	 * @param nacionalidades
	 * 		Cadena 'parseada' con los campos de múltiples objetos Nacionalidad
	 *
	 * @pre:
	 * @post: Instancia de la clase DatosDemograficos inicializada paramétricamente
	 * @complejidad: O(n)
	 */
	DatosDemograficos(int _codVia, string aniosNacimiento, string lugaresNacimiento, string estudios, int _nMujeres,
			int _nHombres, string nacionalidades);
	/**
	 * @brief
	 * 		DESTRUCTOR. Libera la memoria reservada para los gestores de datos del padrón: 'gAnioNacimiento',
	 * 			'gLugarNacimiento', 'gEstudios' y 'gNacionalidad'
	 *
	 * @pre:
	 * @post:
	 * @complejidad: O(n)
	 */
	~DatosDemograficos();

	/**
	 * GETTERS
	 */
	int getCodVia() const;
	int getNMujeres() const;
	int getNHombres() const;
	/**
	 * @brief
	 * 		MÉTODO INVOCATIVO. Utilizado por el Algoritmo 4
	 *
	 * @param lAnioNac
	 * 		Lista en la que almacenar cada rango de edad como una instacia de 'AnioNacimiento'
	 *
	 * @pre:
	 * @post: Llama a modificar la lista pasada por parámetro 'lAnioNac'
	 * @complejidad: O(n^2)
	 */
	void alg4(ListaPI<AnioNacimiento*>*& lAnioNac);
	/**
	 * @brief
	 * 		MÉTODO INVOCATIVO. Utilizado por el Algoritmo 5
	 *
	 * @param lNacion
	 * 		Lista en la que almacenar cada nacionalidad como una instancia de 'Nacionalidad
	 *
	 * @pre:
	 * @post: Llama a modificar la lista pasada por parámetro 'lNacion'
	 * @complejidad: O(n^2)
	 */
	void alg5(ListaPI<Nacionalidad*>*& lNacion);
	/**
	 * @brief
	 * 		MÉTODO INVOCATIVO. Utilizado por el Algoritmo 6
	 *
	 * @param lLugNac
	 * 		Lista en la que almacenar cada lugar de nacimiento como una instancia de 'LugarNacimiento'
	 *
	 * @pre:
	 * @post: Llama a modificar la lista pasada por parámetro 'lLugNac'
	 * @complejidad: O(n^2)
	 */
	void alg6(ListaPI<LugarNacimiento*>*& lLugNac);
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
	 * @post: Llama a calcular el número de habitantes pertencientes al rango de edad dado
	 * @complejidad: O(n)
	 */
	int alg7(int limInf, int limSup);
	/**
	 * @brief
	 * 		MÉTODO INVOCATIVO. Utilizado por el Algoritmo 8
	 *
	 * @param lEstud
	 * 		Lista ordenada de objetos 'Estudios' con el resultado del algoritmo
	 *
	 * @pre:
	 * @post: Llama a modificar la lista de resultados
	 * @complejidad: O(n^2)
	 */
	void alg8(ListaPI<Estudios*>*& lEstud);
	void alg10(ListaPI<LugarNacimiento*>*& lLugNac, string nombreProvincia);
	void alg11(ofstream& ofs);
	int alg12(string nombreProvincia);

	/**
	 * @brief
	 * 		Muestra toda la información de cada vía asocidada. Se utiliza con fines de prueba
	 *
	 * @pre:
	 * @post: Llama a mostrar los datos del padrón almacenados en cada gestor: 'gAnioNacimiento',
	 * 		'gLugNacimiento', 'gEstudios', 'gNacionalidad' y muestra por consola el resto de atributos
	 * @complejidad: O(n)
	 */
	void mostrar();
};

}

#endif /* DATOSDEMOSGRAFICOS_H_ */
