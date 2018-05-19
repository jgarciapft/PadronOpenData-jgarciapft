/**
 * @CLASE: Nacionalidad
 *
 * @brief
 * 		Clase que modela el concepto de 'nacionalidad' y su comportamiento (operadores). Cada nacionalidad
 * 		está definido por el país de origen y el número de personas nacidas en ese país
 *
 * @atributo nacionalidad
 * 		País de procedencia
 * @atributo nPersonas
 * 		Número de personas que poseen la nacionalidad 'nacionalidad'
 */

#ifndef NACIONALIDAD_H_
#define NACIONALIDAD_H_

#include <iostream>

namespace std {

class Nacionalidad {

private:
	string nacionalidad;
	int nPersonas;

public:
	/**
	 * @brief
	 * 		CONSTRUCTOR POR DEFECTO. Inicializa los atributos al valor por defecto
	 *
	 * @pre:
	 * @post: Instancia de Nacionalidad inicializada por defecto
	 * @complejidad: O(1)
	 */
	Nacionalidad();
	/**
	 * @brief
	 * 		CONSTRUCTOR PARAMETRIZADO. Inicializa todos los atributos de una instancia de la clase Nacionalidad
	 * 			a partir de los parámetros
	 *
	 * @param nac
	 * 		Nacionalidad
	 * @param nP
	 * 		Número de personas que tienen la nacionalidad 'nac'
	 *
	 * @pre:
	 * @post: Instancia de la clase Nacionalidad inicializada paramétricamente
	 * @complejidad: O(1)
	 */
	Nacionalidad(string nac, int nP);
	/**
	 * @brief
	 * 		DESTRUCTOR
	 *
	 * @pre:
	 * @post:
	 * @complejidad: O(1)
	 */
	~Nacionalidad();

	string getNacionalidad() const;
	int getNPersonas() const;
	void incNPersonas(int nP);

	void mostrar();

	bool operator >(const Nacionalidad& nacion);
	bool operator ==(const Nacionalidad& nacion);
};

}

#endif /* NACIONALIDAD_H_ */
