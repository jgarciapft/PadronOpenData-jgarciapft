/*
 * DatosDemograficos.cpp
 *
 *      Autor: jgarciapft
 */

#include "DatosDemograficos.h"

namespace std {

DatosDemograficos::DatosDemograficos() {											//Reserva memoria para cada gestor
	codVia = 0;
	gAnioNacimiento = new GestorAnioNacimiento();
	gLugarNacimiento = new GestorLugarNacimiento();
	gEstudios = new GestorEstudios();
	nMujeres = 0;
	nHombres = 0;
	gNacionalidad = new GestorNacionalidad();
}

DatosDemograficos::DatosDemograficos(int _codVia, string aniosNacimiento,			//Reserva memoria para cada gestor
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

DatosDemograficos::~DatosDemograficos() {											//Libera la memoria asociada a cada gestor
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

void DatosDemograficos::alg4(ListaPI<AnioNacimiento *>*& lAnioNac) {				///@NOTA: Nombre provisional
	gAnioNacimiento->alg4(lAnioNac);
}

void DatosDemograficos::alg5(ListaPI<Nacionalidad *> *&lNacion) {
	gNacionalidad->alg5(lNacion);
}

void DatosDemograficos::alg6(ListaPI<LugarNacimiento*>*& lLugNac) {					///@NOTA: Nombre provisional
	gLugarNacimiento->alg6(lLugNac);
}

void DatosDemograficos::mostrar() {													//Llama a mostrar la información de cada gestor contenido
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


