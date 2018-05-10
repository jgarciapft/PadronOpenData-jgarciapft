/*
 * AnioNacimiento.h
 *
 *      Autor: jgarciapft
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

	int getAnio();
	int getNPersonas();
	void setAnio(int _anio);
	void setNPersonas(int nP);
	void incNPersonas(int nP);

	void mostrar();
};

}

#endif /* ANIONACIMIENTO_H_ */
