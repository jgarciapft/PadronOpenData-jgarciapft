/*
 * AnioNacimiento.cpp
 *
 *  Created on: 14 abr. 2018
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

}
