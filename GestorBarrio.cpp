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

void GestorBarrio::insertar(Barrio* b) {
	lBarrios->insertar(b);
	lBarrios->avanzar();
}

void GestorBarrio::insertarVia(Via* v) {
	Barrio* bAux;

	lBarrios->moverInicio();
	while(!lBarrios->finLista()){
		lBarrios->consultar(bAux);
		lBarrios->avanzar();
		if(bAux->getNombreBarrio() == v->getBarrioVia())
			bAux->insertarVia(v);
	}
}

void GestorBarrio::mostrar() {
	Barrio* bAux;

	lBarrios->moverInicio();
	while(!lBarrios->finLista()){
		lBarrios->consultar(bAux);
		lBarrios->avanzar();
		cout << "Barrio : " << bAux->getNombreBarrio() << " | Distrito : " << bAux->getNombreDistrito() << endl << endl;
		cout << "***********************************************************************************************" << endl;
		bAux->mostrar();				//Muestra todas las de cada barrio, que deben de estar en orden alfabético por el nombre de la vía
		cout << "***********************************************************************************************" << endl << endl;
	}
}

}


