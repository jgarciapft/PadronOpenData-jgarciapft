/*
 * GestorEstudios.cpp
 *
 *      Autor: jgarciapft
 */

#include "GestorEstudios.h"

namespace std {

GestorEstudios::GestorEstudios() {
	lEstudios = new ListaPI<Estudios*>();											//Reserva memoria para la lista de estudios que encapsula
}

GestorEstudios::GestorEstudios(string estudios) {
	lEstudios = new ListaPI<Estudios*>();											//Reserva memoria para la lista de estudios que encapsula

	vector<string> vText = splitStringToVector(estudios, DELIM);					//Delimita cada objeto 'Estudios' y lo almacena en un vector
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);								//Delimita cada campo de cada objeto 'Estudios' y lo almacena en otro vector
		lEstudios->insertar(new Estudios(vString[0], atoi(vString[1].c_str())));	//Instacia un nuevo objeto 'Estudios' a partir del vector anterior y lo almacena en la lista de estudios
		lEstudios->avanzar();
	}
}

GestorEstudios::~GestorEstudios() {													//Libera la memoria asociada a cada estudio y la lista que los contiene
	Estudios* estAux;																//Puntero auxiliar para consultar la lista de estudios

	//Recorre secuencialmente la lista de estudios de inicio a fin
	lEstudios->moverInicio();
	while(!lEstudios->finLista()){
		lEstudios->consultar(estAux);
		lEstudios->avanzar();
		delete estAux;																//Libera cada estudio
	}
	delete lEstudios;																//Libera la lista de estudios
}

}

void std::GestorEstudios::mostrar() {												//Muestra la información de los estudios de la lista
	Estudios* estAux;																//Puntero auxiliar para consultar la lista de estudios

	//Recorre secuencialmente la lista de estudios de inicio a fin
	lEstudios->moverInicio();
	while(!lEstudios->finLista()){
		lEstudios->consultar(estAux);
		lEstudios->avanzar();
		estAux->mostrar();															//LLama a mostrar la información de cada estudio de la lista de estudios
	}
}
