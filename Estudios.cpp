/*
 * Estudios.cpp
 *
 *      Autor: jgarciapft
 */

#include "Estudios.h"

namespace std {

Estudios::Estudios() {
	nivEstudios = "";
	nPersonas = 0;
}

Estudios::Estudios(string nEst, int nP) {
	nivEstudios = nEst;
	nPersonas = nP;
}

Estudios::~Estudios() {}



string Estudios::getNivEstudios() {
	return nivEstudios;
}

int Estudios::getNPersonas() {
	return nPersonas;
}

void Estudios::mostrar() {				//Muestra toda la información del objeto 'Estudios'
	cout << "Nivel de estudios : " << nivEstudios << " | Personas : " << nPersonas << endl;
}

}

