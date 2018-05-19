/**
 * @CLASE: LugarNacimiento
 *
 * @brief
 * 		Clase que modela el concepto de 'lugar de nacimiento' y su comportamiento (operadores). Cada año de nacimiento
 * 		está definido por el año de nacimiento y el número de personas nacidas ese año
 *
 * @atributo poblacion
 * 		Población de nacimiento
 * @atributo provinciaPais
 * 		Si la nacionalidad es española, representa la provincia de nacimiento; pero si es extranjera representa
 * 			el país de origen
 * @atributo nPersonas
 * 		Número de personas que nacieron la población 'poblacion'
 */

#ifndef LUGARNACIMIENTO_H_
#define LUGARNACIMIENTO_H_

#include <iostream>

namespace std {

class LugarNacimiento {

private:
	string poblacion;
	string provinciaPais;
	int nPersonas;

public:
	/**
	 * @brief
	 * 		CONSTRUCTOR POR DEFECTO. Inicializa los atributos al valor por defecto
	 *
	 * @pre:
	 * @post: Instancia de LugarNacimiento inicializada por defecto
	 * @complejidad: O(1)
	 */
	LugarNacimiento();
	/**
	 * @brief
	 * 		CONSTRUCTOR PARAMETRIZADO. Inicializa todos los atributos de una instancia de la clase LugarNacimiento
	 * 			a partir de los parámetros
	 *
	 * @param pobl
	 * 		Población de nacimiento
	 * @param provP
	 * 		Si la nacionalidad es española, representa la provincia de nacimiento. Si la nacionalidad es extranjera
	 * 			representa el país de origen
	 * @param nP
	 * 		Número de personas nacidas en la población 'pobl'
	 *
	 * @pre:
	 * @post: Instancia de la clase LugarNacimiento inicializada paramétricamente
	 * @complejidad: O(1)
	 */
	LugarNacimiento(string pobl, string provP, int nP);
	/**
	 * @brief
	 * 		DESTRUCTOR
	 *
	 * @pre:
	 * @post:
	 * @complejidad: O(1)
	 */
	~LugarNacimiento();

	string getPoblacion() const;
	string getProvinciaPais() const;
	int getNPersonas() const;
	void incNPersonas(int nP);

	void mostrar();

	bool operator >=(const LugarNacimiento& lugNac);
	bool operator ==(const LugarNacimiento& lugNac);
};

}

#endif /* LUGARNACIMIENTO_H_ */
