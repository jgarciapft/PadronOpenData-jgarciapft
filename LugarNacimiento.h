/*
 * LugarNacimiento.h
 *
 *      Autor: jgarciapft
 */

#ifndef LUGARNACIMIENTO_H_
#define LUGARNACIMIENTO_H_

#include <string>

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

	bool operator >(const LugarNacimiento& lNac);
};

}

#endif /* LUGARNACIMIENTO_H_ */
