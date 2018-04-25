/*
 * GestorEstudios.cpp
 *
 *      Autor: jgarciapft
 */

#include "GestorEstudios.h"

namespace std {

GestorEstudios::GestorEstudios() {
	lEstudios = new ListaPI<Estudios*>();
}

GestorEstudios::GestorEstudios(string estudios) {
	lEstudios = new ListaPI<Estudios*>();

	vector<string> vText = splitStringToVector(estudios, DELIM);
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);
		lEstudios->insertar(new Estudios(vString[0], atoi(vString[1].c_str())));
		lEstudios->avanzar();
	}
}

GestorEstudios::~GestorEstudios() {
	Estudios* estAux;

	while(!lEstudios->finLista()){
		lEstudios->consultar(estAux);
		lEstudios->avanzar();
		delete estAux;
	}
	delete lEstudios;
}

}

void std::GestorEstudios::mostrar() {
	Estudios* estAux;

	lEstudios->moverInicio();
	while(!lEstudios->finLista()){
		lEstudios->consultar(estAux);
		lEstudios->avanzar();
		estAux->mostrar();
	}
}
