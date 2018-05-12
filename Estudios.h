/*
 * Estudios.h
 *
 *      Autor: jgarciapft
 */

#ifndef ESTUDIOS_H_
#define ESTUDIOS_H_

#include <iostream>

namespace std {

class Estudios {
private:
	string nivEstudios;
	int nPersonas;
public:
	Estudios();
	Estudios(string nEst, int nP);
	~Estudios();

	string getNivEstudios();
	int getNPersonas();
	void incNPersonas(int nP);

	void mostrar();

	bool operator >(const Estudios& estudio);
	bool operator ==(const Estudios& estudio);
};

}

#endif /* ESTUDIOS_H_ */
