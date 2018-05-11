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

void Nacionalidad::incNPersonas(int nP) {						//Incrementa el atributo 'nPersonas'. Utilizado por el algoritmo 5
	nPersonas += nP;
}



void Nacionalidad::mostrar() {									//Muestra toda la información del objeto 'Nacionalidad'
	cout << "Nacionalidad : " << nacionalidad << " | Personas : " << nPersonas << endl;
}

bool Nacionalidad::operator >(const Nacionalidad& nacion) {		///@NOTA: Adecuado si solo se le da uso para el algoritmo 5
	return nPersonas > nacion.nPersonas;						//Criterio de comparación: orden matemático de 'nPersonas'
}

bool Nacionalidad::operator ==(const Nacionalidad& nacion) {	///@NOTA: Adecuado si solo se le da uso para el algoritmo 5
	return nacionalidad == nacion.nacionalidad;					//Criterio de comparación: orden alfabético de 'nacionalidad'
}

}

