/*
 * DatosDemograficos.cpp
 *
 *      Autor: jgarciapft
 */

#include "DatosDemograficos.h"

namespace std {

DatosDemograficos::DatosDemograficos() {
	codVia = 0;
	gAnioNacimiento = new GestorAnioNacimiento();
	gLugarNacimiento = new GestorLugarNacimiento();
	gEstudios = new GestorEstudios();
	nMujeres = 0;
	nHombres = 0;
	gNacionalidad = new GestorNacionalidad();
}

DatosDemograficos::DatosDemograficos(int _codVia, string aniosNacimiento,
		string lugaresNacimiento, string estudios, int _nMujeres, int _nHombres,
		string nacionalidades) {
	codVia = _codVia;
	gAnioNacimiento = new GestorAnioNacimiento(aniosNacimiento);
	gLugarNacimiento = new GestorLugarNacimiento(lugaresNacimiento);
	gEstudios = new GestorEstudios(estudios);
	nMujeres = _nMujeres;
	nHombres = _nHombres;
	gNacionalidad = new GestorNacionalidad(nacionalidades);
}

DatosDemograficos::~DatosDemograficos() {
	delete gAnioNacimiento;
	delete gLugarNacimiento;
	delete gEstudios;
	delete gNacionalidad;
}

int DatosDemograficos::getCodVia() {
	return codVia;
}

int DatosDemograficos::getNMujeres() {
	return nMujeres;
}

int DatosDemograficos::getNHombres() {
	return nHombres;
}

void DatosDemograficos::alg6(GestorLugarNacimiento*& gLugNacimiento) {				//@NOTA: Nombre provisional
	gLugarNacimiento->alg6(gLugNacimiento);
}

void DatosDemograficos::mostrar() {
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	gAnioNacimiento->mostrar();
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	gLugarNacimiento->mostrar();
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	gEstudios->mostrar();
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	gNacionalidad->mostrar();
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

}


