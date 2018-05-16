/*
 * Barrio.cpp
 *
 *      Autor: jgarciapft
 */

#include "Barrio.h"

namespace std {

Barrio::Barrio() {
	nombreBarrio = "";
	nombreDistrito = "";
	gVias = new GestorVia();									//Reserva memoria para el gestor que maneja la lista de vías
}

Barrio::Barrio(string nB, string nD) {
	nombreBarrio = nB;
	nombreDistrito = nD;
	gVias = new GestorVia();									//Reserva memoria para el gestor que maneja la lista de vías
}

Barrio::~Barrio() {
	delete gVias;												//Libera la memoria reservada para el gestor que maneja la lista de vías
}



string Barrio::getNombreBarrio() const {
	return nombreBarrio;
}

string Barrio::getNombreDistrito() const {
	return nombreDistrito;
}

void Barrio::insertarVia(Via* v) {								///@NOTA: Método invocativo
	gVias->insertarViaOrden(v);
}

void Barrio::insertarDatosDemograficos(DatosDemograficos* dD) {	///@NOTA: Método invocativo
	gVias->insertarDatosDemograficos(dD);
}

int Barrio::alg7(int limInf, int limSup) {						///@NOTA: Método invocativo
	return gVias->alg7(limInf, limSup);
}

void Barrio::alg8() {											///@NOTA: Método invocativo
	gVias->alg8();
}

void Barrio::alg9(float& pHombres, float& pMujeres) {			///@NOTA: Método invocativo
	gVias->alg9(pHombres, pMujeres);
}



void Barrio::mostrarVias() {									///@NOTA: Método invocativo
	gVias->mostrarVias();
}

void Barrio::mostrar() {
	cout << "Barrio : " << nombreBarrio << " | Distrito : " << nombreDistrito << endl;
	gVias->mostrar();											//Llama a mostrar el resto de información contenida en el barrio
}

}

