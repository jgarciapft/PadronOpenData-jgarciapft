/*
 * GestorVia.cpp
 *
 *      Autor: jgarciapft
 */

#include "GestorVia.h"

namespace std {

GestorVia::GestorVia() {
	lVias = new ListaPI<Via*>();
}

GestorVia::~GestorVia() {
	Via* vAux;

	lVias->moverInicio();
	while(!lVias->enFin()){
		lVias->consultar(vAux);
		delete vAux;
		lVias->borrar();
	}
	delete lVias;
}

}
