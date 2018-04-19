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

bool LugarNacimiento::operator >(const LugarNacimiento& lNac) {
	bool res = false;

	if(provinciaPais.compare(lNac.provinciaPais) == -1){				//Primer criterio de comparación: orden alfabético de 'provinciaPais'
		res = true;
	}else if(provinciaPais.compare(lNac.provinciaPais) == 0){
		if(poblacion.compare(lNac.poblacion) == -1){					//Segundo criterio de comparación: orden alfabético de 'poblacion'
			res = true;
		}
	}

	return res;
}

}


