/*
 * Nacionalidad.cpp
 *
 *      Autor: jgarciapft
 */

#include "Nacionalidad.h"

namespace std {

Nacionalidad::Nacionalidad() {
	nacionalidad = "";
	nPersonas = 0;
}

Nacionalidad::Nacionalidad(string nac, int nP) {
	nacionalidad = nac;
	nPersonas = nP;
}

Nacionalidad::~Nacionalidad() {}



string Nacionalidad::getNacionalidad() {
	return nacionalidad;
}

int Nacionalidad::getNPersonas() {
	return nPersonas;
}



void Nacionalidad::mostrar() {				//Muestra toda la información del objeto 'Nacionalidad'
	cout << "Nacionalidad : " << nacionalidad << " | Personas : " << nPersonas << endl;
}

}

