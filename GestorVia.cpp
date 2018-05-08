/*
 * GestorVia.cpp
 *
 *      Autor: jgarciapft
 */

#include "GestorVia.h"

namespace std {

GestorVia::GestorVia() {
	lVias = new ListaPI<Via*>();									//Reserva memoria para la lista de vías que encapsula
}

GestorVia::~GestorVia() {											//Libera la memoria asociada a cada vía y a la lista de vías que encapsula
	Via* vAux;														//Puntero auxiliar para consultar la lista de vías

	//Recorre secuencialmente de inicio a fin la lista de vías
	lVias->moverInicio();
	while(!lVias->finLista()){
		lVias->consultar(vAux);
		lVias->avanzar();
		delete vAux;												//Libera cada vía
	}
	delete lVias;													//Libera la lista de vías
}



void GestorVia::insertarViaOrden(Via* v) { 							///@PREGUNTA: prima más la legibilidad que el rendimiento?
	bool enc = false;												//Bandera para indicar cuándo se ha encontrado la posición de la lista en la que insertar la vía
	Via* vAux;														//Puntero auxiliar para consultar la lista de vías

	//Recorre secuencialmente de inicio a fin la lista de vías
	lVias->moverInicio();
	while(!lVias->finLista() && !enc){
		lVias->consultar(vAux);
		if(*v > *vAux)
			enc = true;												//Actualiza la bandera que controla la salida del bucle cuando la vía a insertar es alfabéticamente mayor que la vía apuntada
		else
			lVias->avanzar();										//Solo avanzo si no se ha encontrado el hueco dónde insertar porque la vía se inserta delante del pI
	}
	lVias->insertar(v);												//Quedan manejados los casos: 1.Primer elemento de la lista, 2. Último elemento de la lista
	lVias->avanzar();
}

void GestorVia::insertarDatosDemograficos(DatosDemograficos* dD) {	//Busca si el dato demográfico pasado por parámetro 'dD' corresponde a alguna vía de esta lista y lo une a ella
	bool enc = false;												//Bandera para indicar cuando se ha encotrado (si se encuentra) la vía la que corresponde el parámetro 'dD'
	Via* vAux;														//Puntero auxiliar para consultar la lista de vías

	//Recorre secuencialmente de inicio a fin la lista de vías
	lVias->moverInicio();
	while(!lVias->finLista() && !enc){								//Cada vía es única en su barrio, y cada código de vía es único por vía, es decir, solo hay una vía con el mismo código por barrio
		lVias->consultar(vAux);
		lVias->avanzar();
		if(vAux->getCodVia() == dD->getCodVia()){
			vAux->setDatosDemograficos(dD);							//Se ha encontrado una vía cuyo código coincide con el del dato demográfico 'dD' y se une a esa vía
			enc = true;												//Actualiza la bandea que controla la salida del bucle cuando se encuentra la vía a la que pertenece el dato demográfico a unir
		}
	}
}

void GestorVia::mostrarVias() {										//Muestra todas las vías de la lista. Utilizado por el algorimto 2
	Via* vAux;														//Puntero auxiliar para consultar la lista de vías

	//Recorre secuencialmente de inicio a fin la lista de vías
	lVias->moverInicio();
	while(!lVias->finLista()){
		lVias->consultar(vAux);
		lVias->avanzar();
		cout << "Via : " << vAux->getNombreVia() << " | Barrio : " << vAux->getBarrioVia() << " | Longitud : " <<
				vAux->getLongitudVia() << " | (m) Tipo : " << vAux->getTipoVia() << " | Codigo : " << vAux->getCodVia() << endl;
	}
}

void GestorVia::mostrar() {											//Llama a mostrar la información de cada vía
	Via* vAux;														//Puntero auxiliar para consultar la lista de vías

	//Recorre secuencialmente de inicio a fin la lista de vías
	lVias->moverInicio();
	while(!lVias->finLista()){
		lVias->consultar(vAux);
		lVias->avanzar();
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		vAux->mostrar();											//Muestra todos los datos de cada vía
		cout << "-----------------------------------------------------------------------------------------------" << endl;
	}
}

}

