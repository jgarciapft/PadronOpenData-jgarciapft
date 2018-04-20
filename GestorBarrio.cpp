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
	while(!lBarrios->finLista()){				//Puede existir la misma vía en dos barrios. Hay que recorrer la lista de barrios entera
		lBarrios->consultar(bAux);
		lBarrios->avanzar();
		if(bAux->getNombreBarrio() == v->getBarrioVia())
			bAux->insertarVia(v);
	}
}

void GestorBarrio::insertarDatosDemograficos(DatosDemograficos* dD) {
	Barrio* bAux;

	lBarrios->moverInicio();
	while(!lBarrios->finLista()){				//Al poder haber duplicidad de vías hay que recorrer la lista de barrios entera y pasarles el dato
		lBarrios->consultar(bAux);
		lBarrios->avanzar();
		bAux->insertarDatosDemograficos(dD);
	}
}

void GestorBarrio::alg2(string nB) {			//@NOTA: Nombre provisional
	bool enc  = false;
	Barrio* bAux;

	lBarrios->moverInicio();
	while(!lBarrios->finLista() && !enc){
		lBarrios->consultar(bAux);
		lBarrios->avanzar();
		if(nB == bAux->getNombreBarrio()){
			bAux->mostrarVias();
			enc = true;
		}
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
		bAux->mostrar();					//Muestra todas las de cada barrio, que deben de estar en orden alfabético por el nombre de la vía
		cout << "***********************************************************************************************" << endl << endl;
	}
}

}
