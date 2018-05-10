/*
 * GestorAnioNacimiento.cpp
 *
 *      Autor: jgarciapft
 */

#include "GestorAnioNacimiento.h"

namespace std {

GestorAnioNacimiento::GestorAnioNacimiento() {
	lAnioNacimiento = new ListaPI<AnioNacimiento*>();														//Reserva memoria para la lista de años de nacimiento que encapsula
}

GestorAnioNacimiento::GestorAnioNacimiento(string aniosNacimiento) {
	lAnioNacimiento = new ListaPI<AnioNacimiento*>();														//Reserva memoria para la lista de años de nacimiento que encapsula

	vector<string> vText = splitStringToVector(aniosNacimiento, DELIM);										//Delimita cada objeto 'AnioNacimiento' y lo almacena en un vector
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);														//Delimita cada campo de cada objeto 'AnioNacimiento' y lo almacena otro vector
		lAnioNacimiento->insertar(new AnioNacimiento(atoi(vString[0].c_str()), atoi(vString[1].c_str())));	//Instancia un nuevo año de nacimiento a partir del vector anterior y lo almacena en la lista
		lAnioNacimiento->avanzar();
	}
}

GestorAnioNacimiento::~GestorAnioNacimiento() {																//Libera la memoria asociada a cada año de nacimiento y a la lista que los contiene
	AnioNacimiento* anNacAux;																				//Puntero auxiliar para recorrer la lista de años de nacimiento

	//Recorre secuencialmente la lista de años de nacimiento de inicio a fin
	lAnioNacimiento->moverInicio();
	while(!lAnioNacimiento->finLista()){
		lAnioNacimiento->consultar(anNacAux);
		lAnioNacimiento->avanzar();
		delete anNacAux;																					//Libera cada objeto año de nacimiento
	}
	delete lAnioNacimiento;																					//Libera la lista de años de nacimiento
}

void GestorAnioNacimiento::alg4(ListaPI<AnioNacimiento*>*& lAnio) {
}



void GestorAnioNacimiento::mostrar() {																		//Muestra la información de todos los años de nacimiento de la lista
	AnioNacimiento* anNacAux;																				//Puntero auxiliar para recorrer la lista de años de de nacimiento

	//Recorre secuencialmente la lista de años de nacimiento de inicio a fin
	lAnioNacimiento->moverInicio();
	while(!lAnioNacimiento->finLista()){
		lAnioNacimiento->consultar(anNacAux);
		lAnioNacimiento->avanzar();
		anNacAux->mostrar();																				//Llama a mostrar la información de cada año de nacimiento
	}
}

}