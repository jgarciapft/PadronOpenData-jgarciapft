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

GestorVia::GestorVia(ListaPI<Via*>* lV) {						//@NOTA: No se avanza 'lVias' para que al usarla en 'alg3' ya esté en el inicio
	lVias = new ListaPI<Via*>();

	Via* vAux;

	lV->moverInicio();
	while(!lV->finLista()){
		lVias->consultar(vAux);
		lVias->avanzar();
		lVias->insertar(new Via(vAux->getLongitudVia(),vAux->getNombreVia(), vAux->getLongitudVia(),
				vAux->getTipoVia(), vAux->getCodVia()));
	}
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

void GestorVia::insertarViaOrden(Via* v) { 							//@PREGUNTA: prima más la legibilidad que el rendimiento?
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

void GestorVia::insertarDatosDemograficos(DatosDemograficos* dD) {
	bool enc = false;
	Via* vAux;

	lVias->moverInicio();
	while(!lVias->finLista() && !enc){		//Cada vía es única en su barrio, y cada código de vía es único en cada vía. Paramos cuando coincidan los codigos o se acabe la lista
		lVias->consultar(vAux);
		lVias->avanzar();
		if(vAux->getCodVia() == dD->getCodVia()){
			vAux->setDatosDemograficos(dD);
			enc = true;
		}
	}
}

void GestorVia::alg3() {
	bool primerRes = true;
	Via* vAux1;
	Via* vAux2;								//@PREGUNTA: Por qué no puedo declarar las dos vías auxiliares en la misma línea?

	while(!lVias->finLista()){
		lVias->consultar(vAux1);
		lVias->avanzar();
		while(!lVias->finLista()){
			lVias->consultar(vAux2);
			if(vAux1->getNombreVia() == vAux2->getNombreVia()){
				if(primerRes){
					primerRes = false;
					cout << "Vía : " << vAux1->getNombreVia() << endl;
					cout << "***********************************************************************************************" << endl;
					cout << "Barrios que atraviesa :" << endl << endl;
					cout << vAux1->getBarrioVia() << endl;
				}
				cout << vAux2->getBarrioVia() << endl;
				lVias->borrar();
				delete vAux2;
			}
			lVias->avanzar();
		}
		while(vAux1 != vAux2){
			//TODO Recolocar el PI en vAux1
		}
	}
}

void GestorVia::mostrarVias() {
	Via* vAux;

	lVias->moverInicio();
	while(!lVias->finLista()){
		lVias->consultar(vAux);
		lVias->avanzar();
		cout << "Via : " << vAux->getNombreVia() << " | Barrio : " << vAux->getBarrioVia() << " | Longitud : " <<
				vAux->getLongitudVia() << " | (m) Tipo : " << vAux->getTipoVia() << " | Codigo : " << vAux->getCodVia() << endl;
	}
}

void GestorVia::mostrar() {
	Via* vAux;

	lVias->moverInicio();
	while(!lVias->finLista()){
		lVias->consultar(vAux);
		lVias->avanzar();
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		vAux->mostrar();					//Muestra todos los datos demograficos de cada vía
		cout << "-----------------------------------------------------------------------------------------------" << endl;
	}
}

}



