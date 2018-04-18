/*
 * Estudios.h
 *
 *      Autor: jgarciapft
 */

#ifndef ESTUDIOS_H_
#define ESTUDIOS_H_

#include <string>

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
};

}

#endif /* ESTUDIOS_H_ */
