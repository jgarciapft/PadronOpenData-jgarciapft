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



string Estudios::getNivEstudios() const {
	return nivEstudios;
}

int Estudios::getNPersonas() const {
	return nPersonas;
}

void Estudios::incNPersonas(int nP) {						//Incrementa el atributo 'nPersonas' en 'nP'
	nPersonas += nP;
}



void Estudios::mostrar() {									//Muestra toda la información del objeto 'Estudios'
	cout << "Nivel de estudios : " << nivEstudios << " | Personas : " << nPersonas << endl;
}



bool Estudios::operator >(const Estudios& estudio) {
	return nPersonas > estudio.nPersonas;					//Criterio de comparación: orden matemático de 'nPersonas'
}

bool Estudios::operator==(const Estudios &estudio) {
	return nivEstudios == estudio.nivEstudios;				//Criterio de comparación: comparación lexicográfica de 'nivEsudios'
}

}

