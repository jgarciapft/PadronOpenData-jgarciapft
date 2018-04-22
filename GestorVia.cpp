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

GestorVia::GestorVia(ListaPI<Via*>* lV) {	//@NOTA: No se avanza 'lVias' para optimizar el constructor. En 'alg3' se mueve el pI al inicio
	lVias = new ListaPI<Via*>();

	Via* vAux;

	lV->moverInicio();
	while(!lV->finLista()){
		lV->consultar(vAux);
		lV->avanzar();
		lVias->insertar(new Via(vAux->getBarrioVia(),vAux->getNombreVia(), vAux->getLongitudVia(),
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

void GestorVia::insertarViaOrden(Via* v) { 	//@PREGUNTA: prima más la legibilidad que el rendimiento?
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

void GestorVia::alg3() {					//@NOTA: Nombre provisional
	bool primerRes = true;
	Via* vAux1;
	Via* vAux2;								//@PREGUNTA: Por qué no puedo declarar las dos vías auxiliares en la misma línea?

	lVias->moverInicio();
	while(!lVias->finLista()){				//Bucle externo : avance secuencial de cada vía de la lista
		lVias->consultar(vAux1);
		lVias->avanzar();
		while(!lVias->finLista()){			//Bucle interno: por cada vía seleccionada en el bucle exterior, se comprueban todas las vías siguientes secuencialmente
			lVias->consultar(vAux2);
			if(vAux1->getNombreVia() == vAux2->getNombreVia()){
				if(primerRes){				//Bandera que controla cuándo se ha producido la primera coincidencia para controlar las líneas de '*' que indican los barrios por los que pasa cada vía repetida
					cout << "Vía : " << vAux1->getNombreVia() << endl;
					cout << "***********************************************************************************************" << endl;
					cout << "Barrios que atraviesa :" << endl << endl;
					cout << vAux1->getBarrioVia() << endl;
					primerRes = false;
				}
				cout << vAux2->getBarrioVia() << endl;
				lVias->borrar();			//Para evitar volver a tratar la misma vía se elimina de la lista auxiliar. @NOTA: Solo se libera la memoria asociada al nodo de la lista
				delete vAux2;				//Se libera la memoria asociada con la vía a eliminar de la lista
			}else{
					lVias->avanzar();		//Como al borrar un nodo se avanza automáticamente el pI solo si no hay coincidencia se avanza
			}
		}
		if(!primerRes)						//La bandera también indica si ha habido coincidencia de vías, así controla la línea de control
			cout << "***********************************************************************************************" << endl << endl;
		lVias->moverInicio();
		/*El uso de la estructura 'do while' se justifica porque al final de cada ejecución del bucle interno el pI siempre apuntará a NULL
		 *		porque hay que recorrer el resto de la lista entera, no podemos suponer el número de barrios por los que pasará una vía.
		 *		Moviendo el pI al inicio y consultándolo antes de hacer la comprobación nos libra de comprobar la certeza de que 'vAux1' nunca será NULL
		 */
		do{									//Reposiciona el pI dónde apuntaba previamente 'vAux1' para no volver a procesar desde el inicio de la lista y nunca acabar
			lVias->consultar(vAux2);
			lVias->avanzar();
		}while(vAux1 != vAux2);				//Solo es necesario comparar cuando los punteros apuntan al mismo sitio, no es necesario explorar la información de las vías
		primerRes = true;					//Hay que reiniciar la bandera por cada vía procesada, si no ha habido ninguna no tendrá efecto.
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



