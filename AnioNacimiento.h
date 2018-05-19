/**
 * @CLASE: AnioNacimiento
 *
 * @brief
 * 		Clase que modela el concepto de 'año de nacimiento' y su comportamiento (operadores). Cada año de nacimiento está
 * 			definido por el año de nacimiento y el número de personas nacidas ese año
 *
 * @atributo anio
 * 		Año de nacimiento
 * @atributo nPersonas
 * 		Número de personas que nacieron en el año 'anio'
 */

#ifndef ANIONACIMIENTO_H_
#define ANIONACIMIENTO_H_

#include <iostream>

namespace std {

class AnioNacimiento {

private:
	int anio;
	int nPersonas;

public:
	/**
	 * @brief
	 * 		CONSTRUCTOR POR DEFECTO. Inicializa los atributos al valor por defecto
	 *
	 * @pre:
	 * @post: Instancia de AnioNacimiento inicializada por defecto
	 * @complejidad: O(1)
	 */
	AnioNacimiento();
	/**
	 * @brief
	 * 		CONSTRUCTOR PARAMETRIZADO. Inicializa todos los atributos de una instancia de la clase AnioNacimiento
	 * 			a partir de los parámetros
	 *
	 * @param aN
	 * 		Año de nacimiento
	 * @param nP
	 * 		Número de personas que nacieron en el año 'aN'
	 *
	 * @pre:
	 * @post: Instancia de la clase AnioNacimiento inicializada paramétricamente
	 * @complejidad: O(1)
	 */
	AnioNacimiento(int aN, int nP);
	/**
	 * @brief
	 * 		DESTRUCTOR
	 *
	 * @pre:
	 * @post:
	 * @complejidad: O(1)
	 */
	~AnioNacimiento();

	int getAnio() const;
	int getNPersonas() const;
	void incNPersonas(int nP);

	/**
	 * @brief
	 * 		Muestra la información de cada año de nacimiento. Se utiliza con fines de prueba
	 *
	 * @pre:
	 * @post: Muestra los atributos de cada objeto 'AnioNacimiento'
	 * @complejidad: O(1)
	 */
	void mostrar();
};

}

#endif /* ANIONACIMIENTO_H_ */
