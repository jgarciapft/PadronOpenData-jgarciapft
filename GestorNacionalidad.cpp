/*
 * GestorNacionalidad.cpp
 *
 *      Autor: jgarciapft
 */

#include "GestorNacionalidad.h"

namespace std {

GestorNacionalidad::GestorNacionalidad() {
	lNacionalidad = new ListaPI<Nacionalidad*>();
}

GestorNacionalidad::GestorNacionalidad(string nacionalidades) {
	lNacionalidad = new ListaPI<Nacionalidad*>();

	vector<string> vText = splitStringToVector(nacionalidades, DELIM);
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);
		lNacionalidad->insertar(new Nacionalidad(vString[0], atoi(vString[1].c_str())));
	}
}

GestorNacionalidad::~GestorNacionalidad() {
	Nacionalidad* nacAux;

	while(!lNacionalidad->enFin()){
		lNacionalidad->consultar(nacAux);
		delete nacAux;
		lNacionalidad->borrar();
	}
	delete lNacionalidad;
}

}
