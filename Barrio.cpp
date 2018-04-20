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
	gVias = new GestorVia();
}

Barrio::Barrio(string nB, string nD) {
	nombreBarrio = nB;
	nombreDistrito = nD;
	gVias = new GestorVia();
}

Barrio::~Barrio() {
	delete gVias;
}

string Barrio::getNombreBarrio() {
	return nombreBarrio;
}

string Barrio::getNombreDistrito() {
	return nombreDistrito;
}

void Barrio::insertarVia(Via* v) {
	gVias->insertarViaOrden(v);
}

void Barrio::insertarDatosDemograficos(DatosDemograficos* dD) {
	gVias->insertarDatosDemograficos(dD);
}

void Barrio::mostrarVias() {
	gVias->mostrarVias();
}

void Barrio::mostrar() {
	gVias->mostrar();
}

}

