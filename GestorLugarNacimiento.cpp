/*
 * GestorLugarNacimiento.cpp
 *
 *      Autor: jgarciapft
 */

#include "GestorLugarNacimiento.h"

namespace std {

GestorLugarNacimiento::GestorLugarNacimiento() {
	lLugarNacimiento = new ListaPI<LugarNacimiento*>();
}

GestorLugarNacimiento::GestorLugarNacimiento(string lugaresNacimiento) {
	lLugarNacimiento = new ListaPI<LugarNacimiento*>();

	vector<string> vText = splitStringToVector(lugaresNacimiento, DELIM);
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);
		if ( vString.size()== 2)
			lLugarNacimiento->insertar(new LugarNacimiento("", vString[0], atoi(vString[1].c_str())));
		else
			lLugarNacimiento->insertar(new LugarNacimiento(vString[0], vString[1], atoi(vString[2].c_str())));
	}
}

GestorLugarNacimiento::~GestorLugarNacimiento() {
	LugarNacimiento* lNacAux;

	lLugarNacimiento->moverInicio();
	while(!lLugarNacimiento->enFin()){
		lLugarNacimiento->consultar(lNacAux);
		delete lNacAux;
		lLugarNacimiento->borrar();
	}
	delete lLugarNacimiento;
}

void GestorLugarNacimiento::mostrar() {
	LugarNacimiento* lNacAux;

	lLugarNacimiento->moverInicio();
	while(!lLugarNacimiento->finLista()){
		lLugarNacimiento->consultar(lNacAux);
		lLugarNacimiento->avanzar();
		cout << "Población : " << lNacAux->getPoblacion() << " Provincia : " << lNacAux->getProvinciaPais() << " | Personas : " << lNacAux->getNPersonas() << endl;
	}
}

}


