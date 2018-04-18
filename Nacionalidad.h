/*
 * Nacionalidad.h
 *
 *      Autor: jgarciapft
 */

#ifndef NACIONALIDAD_H_
#define NACIONALIDAD_H_

#include <string>

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
};

}

#endif /* NACIONALIDAD_H_ */
