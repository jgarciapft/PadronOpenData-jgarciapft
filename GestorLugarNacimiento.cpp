/*
 * GestorLugarNacimiento.cpp
 *
 *      Autor: jgarciapft
 */

#include "GestorLugarNacimiento.h"

namespace std {

/*** DEFINCIÓN DE CONSTANTES ***/
const string POBLACION_TEXTO_RELLENO = "";				//Texto de relleno para 'poblacion' al crear nuevos objetos 'LugarNacimiento' aplicado al algoritmo 6

GestorLugarNacimiento::GestorLugarNacimiento() {
	lLugarNacimiento = new ListaPI<LugarNacimiento*>();
}

GestorLugarNacimiento::GestorLugarNacimiento(string lugaresNacimiento) {
	lLugarNacimiento = new ListaPI<LugarNacimiento*>();

	vector<string> vText = splitStringToVector(lugaresNacimiento, DELIM);
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);
		if ( vString.size()== 2){
			lLugarNacimiento->insertar(new LugarNacimiento(POBLACION_TEXTO_RELLENO, vString[0], atoi(vString[1].c_str())));
		}else{
			lLugarNacimiento->insertar(new LugarNacimiento(vString[0], vString[1], atoi(vString[2].c_str())));
		}
		lLugarNacimiento->avanzar();
	}
}

GestorLugarNacimiento::~GestorLugarNacimiento() {
	LugarNacimiento* lugNacAux;

	lLugarNacimiento->moverInicio();
	while(!lLugarNacimiento->enFin()){
		lLugarNacimiento->consultar(lugNacAux);
		delete lugNacAux;
		lLugarNacimiento->borrar();
	}
	delete lLugarNacimiento;
}

void GestorLugarNacimiento::insertarOrden(LugarNacimiento* lugNac) {										//@NOTA: Adecuado solo para el algoritmo 6
	bool enc = false;
	LugarNacimiento* lugNacAux;

	if(!lLugarNacimiento->estaVacia()){
		lLugarNacimiento->moverInicio();
		while(!lLugarNacimiento->finLista() && !enc){
			lLugarNacimiento->consultar(lugNacAux);
			if(*lugNac >= *lugNacAux)
				enc = true;
			else
				lLugarNacimiento->avanzar();																								//Se avanza solo si no se encuentra un potencial hueco de inserción para insertar delante del dato consultado
		}
		if(*lugNac == *lugNacAux)																											//Se comprueba que el dato no se duplique. La condición de duplicidad es que haya 2 datos con el mismo valor para 'provinciaPais'
			lugNacAux->incNPersonas(lugNac->getNPersonas());																				//Si existe se actualiza el atributo 'nPersonas' a modo de acumulador
		else
			lLugarNacimiento->insertar(new LugarNacimiento(POBLACION_TEXTO_RELLENO, lugNac->getProvinciaPais(), lugNac->getNPersonas()));	//Si no existe, se inserta un nuevo objeto. Si modificasemos los objetos ya introducimos en memoria cambiaríamos los datos del padrón
	}else{
		lLugarNacimiento->insertar(new LugarNacimiento(POBLACION_TEXTO_RELLENO, lugNac->getProvinciaPais(), lugNac->getNPersonas()));		//Controla el caso de que la lista esté vacía inicialmente
	}
}

void GestorLugarNacimiento::alg6(GestorLugarNacimiento*& gLugNacimiento) {									//@NOTA: Nombre provisional
	LugarNacimiento* lugNacAux;

	lLugarNacimiento->moverInicio();
	while(!lLugarNacimiento->finLista()){
		lLugarNacimiento->consultar(lugNacAux);
		lLugarNacimiento->avanzar();
		if(lugNacAux->getPoblacion() != "")																	//Comprueba que el lugar de nacimiento no sea extranjero
			gLugNacimiento->insertarOrden(lugNacAux);
	}
}

void GestorLugarNacimiento::mostrar() {
	LugarNacimiento* lugNacAux;

	lLugarNacimiento->moverInicio();
	while(!lLugarNacimiento->finLista()){
		lLugarNacimiento->consultar(lugNacAux);
		lLugarNacimiento->avanzar();
		cout << "Población : " << lugNacAux->getPoblacion() << " | Provincia/Pais : " << lugNacAux->getProvinciaPais() << " | Personas : " << lugNacAux->getNPersonas() << endl;
	}
}

}


