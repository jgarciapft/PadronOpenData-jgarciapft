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
	Nacionalidad();
	Nacionalidad(string nac, int nP);
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
