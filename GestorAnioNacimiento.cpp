/*
 * GestorAnioNacimiento.cpp
 *
 *      Autor: jgarciapft
 */

#include "GestorAnioNacimiento.h"

namespace std {

GestorAnioNacimiento::GestorAnioNacimiento() {
	lAnioNacimiento = new ListaPI<AnioNacimiento*>();
}

GestorAnioNacimiento::GestorAnioNacimiento(string aniosNacimiento) {
	lAnioNacimiento = new ListaPI<AnioNacimiento*>();

	vector<string> vText = splitStringToVector(aniosNacimiento, DELIM);
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);
		lAnioNacimiento->insertar(new AnioNacimiento(atoi(vString[0].c_str()), atoi(vString[1].c_str())));
	}
}

GestorAnioNacimiento::~GestorAnioNacimiento() {
	AnioNacimiento* anNacAux;

	lAnioNacimiento->moverInicio();
	while(!lAnioNacimiento->enFin()){
		lAnioNacimiento->consultar(anNacAux);
		delete anNacAux;
		lAnioNacimiento->borrar();
	}
	delete lAnioNacimiento;
}

void GestorAnioNacimiento::mostrar() {
	AnioNacimiento* anNacAux;

	lAnioNacimiento->moverInicio();
	while(!lAnioNacimiento->finLista()){
		lAnioNacimiento->consultar(anNacAux);
		lAnioNacimiento->avanzar();
		cout << "Año : " << anNacAux->getAnio() << " | Personas : " << anNacAux->getNPersonas() << endl;
	}
}

}


