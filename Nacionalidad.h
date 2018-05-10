/*
 * Nacionalidad.h
 *
 *      Autor: jgarciapft
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

	string getNacionalidad();
	int getNPersonas();

	void mostrar();
};

}

#endif /* NACIONALIDAD_H_ */
