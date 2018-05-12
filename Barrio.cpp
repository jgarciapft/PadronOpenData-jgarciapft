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
	gVias = new GestorVia();									//Reserva memoria el gestor que maneja la lista de vías
}

Barrio::Barrio(string nB, string nD) {
	nombreBarrio = nB;
	nombreDistrito = nD;
	gVias = new GestorVia();									//Reserva memoria el gestor que maneja la lista de vías
}

Barrio::~Barrio() {
	delete gVias;												//Libera la memoria reservada para el gestor que maneja la lista de vías
}



string Barrio::getNombreBarrio() {
	return nombreBarrio;
}

string Barrio::getNombreDistrito() {
	return nombreDistrito;
}

void Barrio::insertarVia(Via* v) {								///@NOTA: Método invocativo
	gVias->insertarViaOrden(v);
}

void Barrio::insertarDatosDemograficos(DatosDemograficos* dD) {	///@NOTA: Método invocativo
	gVias->insertarDatosDemograficos(dD);
}

int Barrio::alg7(int limInf, int limSup) {						///@NOTA: Nombre provisional	@NOTA: Método invocativo
	return gVias->alg7(limInf, limSup);
}



void Barrio::mostrarVias() {									///@NOTA: Método invocativo
	gVias->mostrarVias();
}

void Barrio::mostrar() {
	cout << "Barrio : " << nombreBarrio << " | Distrito : " << nombreDistrito << endl;
	gVias->mostrar();
}

}

