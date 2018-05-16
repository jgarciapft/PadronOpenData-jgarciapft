/*
 * GestorLugarNacimiento.h
 *
 *      Autor: jgarciapft
 */

#ifndef GESTORLUGARNACIMIENTO_H_
#define GESTORLUGARNACIMIENTO_H_

#include "Utils.h"
#include "listapi.h"
#include "LugarNacimiento.h"
#include <fstream>

namespace std {

class GestorLugarNacimiento {

private:
	ListaPI<LugarNacimiento*>* lLugarNacimiento;

public:
	GestorLugarNacimiento();
	GestorLugarNacimiento(string lugaresNacimiento);
	~GestorLugarNacimiento();

	void alg6(ListaPI<LugarNacimiento*>*& lLugNac);
	void alg10(ListaPI<LugarNacimiento*>*& lLugNac, string nombreProvincia);
	void alg11(ofstream& ofs);
	int alg12(string nombreProvincia);

	void mostrar();
};

}

#endif /* GESTORLUGARNACIMIENTO_H_ */
