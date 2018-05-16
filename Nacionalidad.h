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

	string getNacionalidad() const;
	int getNPersonas() const;
	void incNPersonas(int nP);

	void mostrar();

	bool operator >(const Nacionalidad& nacion);
	bool operator ==(const Nacionalidad& nacion);
};

}

#endif /* NACIONALIDAD_H_ */
