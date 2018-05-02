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
