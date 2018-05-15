/*
 * LugarNacimiento.h
 *
 *      Autor: jgarciapft
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
	LugarNacimiento();
	LugarNacimiento(string pobl, string provP, int nP);
	~LugarNacimiento();

	string getPoblacion();
	string getProvinciaPais();
	int getNPersonas();
	void incNPersonas(int nP);

	void mostrar();

	bool operator >=(const LugarNacimiento& lugNac);
	bool operator ==(const LugarNacimiento& lugNac);
};

}

#endif /* LUGARNACIMIENTO_H_ */
