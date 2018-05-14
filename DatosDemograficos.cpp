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

void DatosDemograficos::alg4(ListaPI<AnioNacimiento *>*& lAnioNac) {				///@NOTA: Nombre provisional	@NOTA: Método invocativo
	gAnioNacimiento->alg4(lAnioNac);
}

void DatosDemograficos::alg5(ListaPI<Nacionalidad*>*& lNacion) {					///@NOTA: Nombre provisional	@NOTA: Método invocativo
	gNacionalidad->alg5(lNacion);
}

void DatosDemograficos::alg6(ListaPI<LugarNacimiento*>*& lLugNac) {					///@NOTA: Nombre provisional	@NOTA: Método invocativo
	gLugarNacimiento->alg6(lLugNac);
}

int DatosDemograficos::alg7(int limInf, int limSup) {								///@NOTA: Nombre provisional	@NOTA: Método invocativo
	return gAnioNacimiento->alg7(limInf, limSup);
}

void DatosDemograficos::alg8(ListaPI<Estudios*>*& lEstud) {							///@NOTA: Nombre provisional	@NOTA: Método invocativo
	gEstudios->alg8(lEstud);
}

void DatosDemograficos::alg10(ListaPI<LugarNacimiento*>*& lLugNac, string nombreProvincia) {	///@NOTA: Nombre provisional	@NOTA: Método invocativo
	gLugarNacimiento->alg10(lLugNac, nombreProvincia);
}

void DatosDemograficos::alg11(ofstream& ofs) {										///@NOTA: Nombre provisional	@NOTA: Método invocativo
	gLugarNacimiento->alg11(ofs);
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


