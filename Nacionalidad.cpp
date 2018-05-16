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



string Nacionalidad::getNacionalidad() const {
	return nacionalidad;
}

int Nacionalidad::getNPersonas() const {
	return nPersonas;
}

void Nacionalidad::incNPersonas(int nP) {						//Incrementa el atributo 'nPersonas' en 'nP'
	nPersonas += nP;
}



void Nacionalidad::mostrar() {									//Muestra toda la información del objeto 'Nacionalidad'
	cout << "Nacionalidad : " << nacionalidad << " | Personas : " << nPersonas << endl;
}



bool Nacionalidad::operator >(const Nacionalidad& nacion) {
	return nacion.nPersonas > nPersonas;						//Criterio de comparación: orden matemático de 'nPersonas'
}

bool Nacionalidad::operator ==(const Nacionalidad& nacion) {
	return nacion.nacionalidad == nacionalidad;					//Criterio de comparación: comparación lexicográfica de 'nacionalidad'
}

}

