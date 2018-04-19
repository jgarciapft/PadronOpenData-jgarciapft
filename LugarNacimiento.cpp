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

bool LugarNacimiento::operator >=(const LugarNacimiento& lNac) { 		//@NOTA: Adecuado si solo se le da uso para el algoritmo 6
	bool res = false;

	if(provinciaPais.compare(lNac.provinciaPais) <= 0)					//Criterio de comparación: orden alfabético de 'provinciaPais'
		res = true;

	return res;
}

bool LugarNacimiento::operator ==(const LugarNacimiento& lNac) {		//@NOTA: Adecuado si solo se le da uso para el algoritmo 6
	return !bool(provinciaPais.compare(lNac.provinciaPais));			//Criterio de comparación: coincidencia de cadenas carácter a carácter
}

}


