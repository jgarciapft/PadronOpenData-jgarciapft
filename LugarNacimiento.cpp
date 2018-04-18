/*
 * LugarNacimiento.cpp
 *
 *      Autor: jgarciapft
 */

#include "LugarNacimiento.h"

namespace std {

LugarNacimiento::LugarNacimiento() {
	poblacion = "";
	provinciaPais = "";
	nPersonas = 0;
}

LugarNacimiento::LugarNacimiento(string pobl, string provP, int nP) {
	poblacion = pobl;
	provinciaPais = provP;
	nPersonas = nP;
}

LugarNacimiento::~LugarNacimiento() {}

string LugarNacimiento::getPoblacion() {
	return poblacion;
}

string LugarNacimiento::getProvinciaPais() {
	return provinciaPais;
}

int LugarNacimiento::getNPersonas() {
	return nPersonas;
}

}
