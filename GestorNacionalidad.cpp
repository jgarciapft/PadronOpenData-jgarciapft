/*
 * GestorNacionalidad.cpp
 *
 *      Autor: jgarciapft
 */

#include "GestorNacionalidad.h"

namespace std {

GestorNacionalidad::GestorNacionalidad() {
	lNacionalidad = new ListaPI<Nacionalidad*>();											//Reserva memoria para la lista de nacionalidades que encapsula
}

GestorNacionalidad::GestorNacionalidad(string nacionalidades) {
	lNacionalidad = new ListaPI<Nacionalidad*>();											//Reserva memoria para la lista de nacionalidades que encapsula

	vector<string> vText = splitStringToVector(nacionalidades, DELIM);						//Delimita cada objeto 'Nacionalidad' y lo almacena en un vector
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);										//Delimita cada campo de cada objeto 'Nacionalidad' y lo almacena en otro vector
		lNacionalidad->insertar(new Nacionalidad(vString[0], atoi(vString[1].c_str())));	//Instacia un nuevo objeto 'Nacionalidad' a partir del vector anterior y lo almacena en la lista de nacionalidades
		lNacionalidad->avanzar();
	}
}

GestorNacionalidad::~GestorNacionalidad() {													//Libera la memoria asociada a cada nacionalidad y a la lista que las contiene
	Nacionalidad* nacAux;																	//Puntero auxiliar para consultar la lista de nacionalidades

	//Recorre secuencialmente la lista de nacionalidades de inicio a fin
	lNacionalidad->moverInicio();
	while(!lNacionalidad->finLista()){
		lNacionalidad->consultar(nacAux);
		lNacionalidad->avanzar();
		delete nacAux;																		//Libera cada nacionalidad
	}
	delete lNacionalidad;																	//Libera la lista de nacionalidades
}



void GestorNacionalidad::alg5(ListaPI<Nacionalidad *> *&lNacion) {
	bool enc = false;																		//Bandera para indicar cuando se ha encontrado la posición de la lista dónde debe insertarse o actualizarse el lugar de nacimiento
	Nacionalidad* nacionAux1;																//Puntero auxiliar para consultar la lista de lugares de nacimiento que encapsula el gestor
	Nacionalidad* nacionAux2;																//Puntero auxiliar para consultar la lista de lugares de nacimiento pasada por parámetro

	if(!lNacionalidad->estaVacia()) {                                 	      				//Comprueba si el gestor contiene alguna nacionalida
		lNacionalidad->moverInicio();
		if (lNacion->estaVacia()) {                                            				//Maneja el caso inicial: Comprueba si la lista pasada por parámtro está vacía e inserta el primer elemento
			lNacionalidad->consultar(nacionAux1);
			lNacionalidad->avanzar();
			lNacion->insertar(new Nacionalidad(nacionAux1->getNacionalidad(), nacionAux1->getNPersonas()));
		}

		while (!lNacionalidad->finLista()) {                 				           		//Recorre secuencialmente la lista de nacionaliadades del gestor de inicio a fin
			lNacionalidad->consultar(nacionAux1);
			lNacionalidad->avanzar();
			lNacion->moverInicio();
			while (!lNacion->finLista() && !enc) {											//Busca el lugar en el que insertar/actualizar la lista pasada por parámtetro (con la nacionalidad actual de la lista que encapsula el gestor)
				lNacion->consultar(nacionAux2);
				if (*nacionAux1 >= *nacionAux2)				                        	    //Comparación alfabética por la nacionalidad
					enc = true;                             			                	//Actualiza la bandera que permite salir del bucle cuando se ha encontrado la posición del dato a procesar
				else
					lNacion->avanzar();                               						//Se avanza solo si no se encuentra un potencial hueco de inserción para insertar delante del dato consultado
			}
			if (*nacionAux1 == *nacionAux2)                                 				//Se comprueba que el dato no se duplique. La condición de duplicidad es que haya 2 datos con el mismo valor para 'nacionalidad'
				nacionAux2->incNPersonas(nacionAux1->getNPersonas());       				//Si existe se actualiza el atributo 'nPersonas' a modo de acumulador
			else																			//Si no existe se inserta un nuevo objeto. Si modificasemos los objetos ya introducidos en memoria cambiaríamos los datos del padrón
				lNacion->insertar(new Nacionalidad(nacionAux1->getNacionalidad(), nacionAux1->getNPersonas()));
			enc = false;																	//Reinicia la bandera de posición
		}
}
}



void GestorNacionalidad::mostrar() {														//Muestra la información las nacionalidades de la lista
	Nacionalidad* nacAux;																	//Puntero auxiliar para consultar la lista de nacionalidades

	//Recorre secuencialmente la lista de nacionalidades de inicio a fin
	lNacionalidad->moverInicio();
	while(!lNacionalidad->finLista()){
		lNacionalidad->consultar(nacAux);
		lNacionalidad->avanzar();
		nacAux->mostrar();																	//Llama a mostrar la información de cada nacionalidad en la lista
	}
}

}

