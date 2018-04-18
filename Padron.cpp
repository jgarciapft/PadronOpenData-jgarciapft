/*
 * Padron.cpp
 *
 *      Autor: jgarciapft
 */

#include "Padron.h"

namespace std {

Padron::Padron() {
	gBarrio = new GestorBarrio();
	lDatDemograficos = new ListaPI<DatosDemograficos*>();
	lVias = new ListaPI<Via*>();
}

Padron::~Padron() {
	delete lDatDemograficos;
	delete lVias;
}

}
