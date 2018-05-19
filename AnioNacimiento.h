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
	AnioNacimiento();
	AnioNacimiento(int aN, int nP);
	~AnioNacimiento();

	int getAnio() const;
	int getNPersonas() const;
	void incNPersonas(int nP);

	void mostrar();
};

}

#endif /* ANIONACIMIENTO_H_ */
