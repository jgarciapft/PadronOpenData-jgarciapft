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

void LugarNacimiento::incNPersonas(int nP) {
	nPersonas += nP;
}

bool LugarNacimiento::operator >=(const LugarNacimiento& lugNac) { 		//@NOTA: Adecuado si solo se le da uso para el algoritmo 6
	return provinciaPais.compare(lugNac.provinciaPais) <= 0;		//Criterio de comparación: orden alfabético de 'provinciaPais'
}

bool LugarNacimiento::operator ==(const LugarNacimiento& lugNac) {		//@NOTA: Adecuado si solo se le da uso para el algoritmo 6
	return provinciaPais.compare(lugNac.provinciaPais) == 0;		//Criterio de comparación: coincidencia de cadenas carácter a carácter
}

}


