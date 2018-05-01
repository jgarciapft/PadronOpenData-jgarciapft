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
	while(!lBarrios->finLista()){
		lBarrios->consultar(bAux);
		lBarrios->avanzar();
		delete bAux;
	}
	delete lBarrios;
}

void GestorBarrio::insertar(Barrio* b) {
	lBarrios->insertar(b);
	lBarrios->avanzar();
}

void GestorBarrio::insertarVia(Via* v) {
	bool enc = false;
	Barrio* bAux;

	lBarrios->moverInicio();
	while(!lBarrios->finLista() && !enc){									//Puede existir la misma vía en dos barrios, pero cada tramo de vía es un objeto en sí. Por lo que solo corresponderá a un barrio cada tramo
		lBarrios->consultar(bAux);
		lBarrios->avanzar();
		if(bAux->getNombreBarrio() == v->getBarrioVia()){
			bAux->insertarVia(v);
			enc = true;
		}
	}
}

void GestorBarrio::insertarDatosDemograficos(DatosDemograficos* dD) {
	Barrio* bAux;

	lBarrios->moverInicio();
	while(!lBarrios->finLista()){											//Al poder haber duplicidad de vías hay que recorrer la lista de barrios entera
		lBarrios->consultar(bAux);
		lBarrios->avanzar();
		bAux->insertarDatosDemograficos(dD);
	}
}

void GestorBarrio::alg2(string nB) {										//@NOTA: Nombre provisional
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
		cout << "***********************************************************************************************" << endl;
		bAux->mostrar();													//Muestra todas las de cada barrio, que deben de estar en orden alfabético por el nombre de la vía
		cout << "***********************************************************************************************" << endl << endl;
	}
}

}
