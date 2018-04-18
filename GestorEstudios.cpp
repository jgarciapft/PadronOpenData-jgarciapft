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
	}
}

GestorEstudios::~GestorEstudios() {
	Estudios* estAux;

	while(!lEstudios->enFin()){
		lEstudios->consultar(estAux);
		delete estAux;
		lEstudios->borrar();
	}
	delete lEstudios;
}

}
