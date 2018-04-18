/*
 * GestorBarrio.cpp
 *
 *      Autor: jgarciapft
 */

#include "GestorBarrio.h"

namespace std {

GestorBarrio::GestorBarrio() {
	lBarrios = new ListaPI<Barrio*>();
}

GestorBarrio::~GestorBarrio() {
	Barrio* bAux;

	lBarrios->moverInicio();
	while(!lBarrios->enFin()){
		lBarrios->consultar(bAux);
		delete bAux;
		lBarrios->borrar();
	}
	delete lBarrios;
}

}
