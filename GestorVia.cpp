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

void GestorVia::insertarViaOrden(Via* v) { //@PREGUNTA: prima más la legibilidad que el rendimiento?
	bool enc = false;
	Via* vAux;

	lVias->moverInicio();
	while(!lVias->finLista() && !enc){
		lVias->consultar(vAux);
		if(*v > *vAux)
			enc = true;
		else
			lVias->avanzar();				//Solo avanzo si no he encontrado el hueco dónde insertar porque quiero insertar delante del pI
	}
	lVias->insertar(v);						//Quedan manejados los casos: 1.Primer elemento de la lista, 2. Último elemento de la lista
	lVias->avanzar();
}

void GestorVia::mostrar() {
	Via* vAux;

	lVias->moverInicio();
	while(!lVias->finLista()){
		lVias->consultar(vAux);
		cout << "Via : " << vAux->getNombreVia() << " | Barrio : " << vAux->getBarrioVia() << " Longitud : " <<
				vAux->getLongitudVia() << " Tipo : " << vAux->getTipoVia() << " Codigo : " << vAux->getCodVia() << endl;
	}
}

}


