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



string LugarNacimiento::getPoblacion() const {
	return poblacion;
}

string LugarNacimiento::getProvinciaPais() const {
	return provinciaPais;
}

int LugarNacimiento::getNPersonas() const {
	return nPersonas;
}

void LugarNacimiento::incNPersonas(int nP) {							//Incrementa el atributo 'nPersonas' en 'nP'
	nPersonas += nP;
}



void LugarNacimiento::mostrar() {										//Muestra toda la información del objeto 'LugarNacimiento'
	cout << "Población : " << poblacion << " | Provincia/Pais : " << provinciaPais << " | Personas : " << nPersonas << endl;
}



bool LugarNacimiento::operator >=(const LugarNacimiento& lugNac) {
	return provinciaPais.compare(lugNac.provinciaPais) <= 0;			//Criterio de comparación: orden alfabético de 'provinciaPais'
}

bool LugarNacimiento::operator ==(const LugarNacimiento& lugNac) {
	return provinciaPais == lugNac.provinciaPais;						//Criterio de comparación: orden lexicográfico de 'provinciaPais'
}

}

