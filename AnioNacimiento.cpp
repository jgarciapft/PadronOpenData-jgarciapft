/*
 * AnioNacimiento.cpp
 *
 *      Autor: jgarciapft
 */

#include "AnioNacimiento.h"

namespace std {

AnioNacimiento::AnioNacimiento() {
	anio = 0;
	nPersonas = 0;
}

AnioNacimiento::AnioNacimiento(int aN, int nP) {
	anio = aN;
	nPersonas = nP;
}

AnioNacimiento::~AnioNacimiento() {}



int AnioNacimiento::getAnio() {
	return anio;
}

int AnioNacimiento::getNPersonas() {
	return nPersonas;
}

void AnioNacimiento::incNPersonas(int nP) {
	nPersonas += nP;
}



void AnioNacimiento::mostrar() {				//Muestra toda la información del objeto 'AnioNacimiento'
	cout << "Año : " << anio << " | Personas : " << nPersonas << endl;
}

}
