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

void Estudios::incNPersonas(int nP) {
	nPersonas += nP;
}



void Estudios::mostrar() {									//Muestra toda la información del objeto 'Estudios'
	cout << "Nivel de estudios : " << nivEstudios << " | Personas : " << nPersonas << endl;
}



bool Estudios::operator >(const Estudios& estudio) {		///@NOTA: Adecuado si solo se le da uso para el algoritmo 8
	return nPersonas > estudio.nPersonas;					//Criterio de comparación: orden matemático de 'nPersonas'
}

bool Estudios::operator==(const Estudios &estudio) {		///@NOTA: Adecuado si solo se le da uso para el algoritmo 8
	return nivEstudios == estudio.nivEstudios;				//Criterio de comparación: comparación lexicográfica de 'nivEsudios'
}

}

