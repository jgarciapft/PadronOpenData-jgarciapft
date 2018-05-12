/*
 * GestorBarrio.cpp
 *
 *      Autor: jgarciapft
 */

#include "GestorBarrio.h"

namespace std {

GestorBarrio::GestorBarrio() {
	lBarrios = new ListaPI<Barrio*>();										//Reserva memoria para la lista de barrios que encapsula
}

GestorBarrio::~GestorBarrio() {												//Libera la memoria asociada a cada barrio y a la lista de barrios que encapsula
	Barrio* bAux;

	//Recorre secuencialmente de inicio a fin la lista de barrios
	lBarrios->moverInicio();
	while(!lBarrios->finLista()){
		lBarrios->consultar(bAux);
		lBarrios->avanzar();
		delete bAux;														//Libera cada barrio
	}
	delete lBarrios;														//Libera la lista de barrios
}



void GestorBarrio::insertar(Barrio* b) {									//Inserta el barrio 'b' en la lista con avance del pI sin ningún criterio
	lBarrios->insertar(b);
	lBarrios->avanzar();
}

void GestorBarrio::insertarVia(Via* v) {									//Inserta la vía 'v' en el barrio que le corresponda
	bool enc = false;														//Bandera utilizada para terminar la búsqueda del barrio que le corresponde a la vía a insertar una vez haya una coincidencia
	Barrio* bAux;

	//Recorre secuencialmente de inicio a fin la lista de barrios1
	lBarrios->moverInicio();
	while(!lBarrios->finLista() && !enc){									//Puede existir la misma vía en dos barrios, pero cada tramo de vía es un objeto Via en sí. Por lo que solo corresponderá a un barrio cada tramo
		lBarrios->consultar(bAux);
		lBarrios->avanzar();
		if(bAux->getNombreBarrio() == v->getBarrioVia()){
			bAux->insertarVia(v);											//Cuando hay coincidencia de nombres de barrio le pasa a ese barrio su vía
			enc = true;														//Actualiza la bandera para salir del bucle
		}
	}
}

void GestorBarrio::insertarDatosDemograficos(DatosDemograficos* dD) {		///Inserta el dato demográfico 'dD' en su(s) vía(s) correspondiente(s)	@NOTA: Hay multiplicidad de vías para las que corresponde un dato demográfico
	Barrio* bAux;

	//Recorre secuencialmente de inicio a fin la lista de barrios
	lBarrios->moverInicio();
	while(!lBarrios->finLista()){											//Al poder haber duplicidad de vías hay que recorrer la lista entera
		lBarrios->consultar(bAux);
		lBarrios->avanzar();
		bAux->insertarDatosDemograficos(dD);								//Pasa a todos los barrios el dato demográfico a insertar para que comprueben si corresponde a alguna de sus vías
	}
}

void GestorBarrio::alg2(string nB) {										///@NOTA: Nombre provisional
	bool enc  = false;														//Bandera utilizada para terminas la búsqueda del barrio que corresponde con el parámetro 'nB'
	Barrio* bAux;															//Puntero auxiliar para recorrer la lista de barrios

	//Recorre secuencialmente de inicio a fin la lista de barrios
	lBarrios->moverInicio();
	while(!lBarrios->finLista() && !enc){
		lBarrios->consultar(bAux);
		lBarrios->avanzar();
		if(nB == bAux->getNombreBarrio()){
			bAux->mostrarVias();											//Muestra todas las vías del barrio que coincide con el parámetro 'nB'
			enc = true;														//Actualiza la bandera para salir del bucle
		}
	}
}

void GestorBarrio::alg7(int limInf, int limSup) {							///@NOTA: Nombre provisional
	Barrio* bAux;															//Puntero auxiliar para consular la lista de barrios
	Barrio* mayorBarrio = NULL;												//Puntero al barrio con mayor número de habitantes para el rango dado hasta ahora
	int nPersonasActual;													//Número de habitantes para el rango dado del barrio actual
	int mayorNPersonas = 0;													//Mayor número de habitantes para el rango dado hasta ahora

	//Recorre secuencialmente de inicio a fin la lista de barrios
	lBarrios->moverInicio();
	while(!lBarrios->finLista()){
		lBarrios->consultar(bAux);
		lBarrios->avanzar();
		nPersonasActual = bAux->alg7(limInf, limSup);						//Calcula el número de habitantes para el rango dado del barrio actual
		if(nPersonasActual > mayorNPersonas){								//Comprobación del barrio mayor hasta ahora
			mayorNPersonas = nPersonasActual;
			mayorBarrio = bAux;
		}
	}

	//Muestra la el nombre y el distrito del barrio con mayor número de habitantes para el rango dado y dicho número
	cout << "Barrio con el mayor número de habitantes para - Rango de edad (" << limInf << " , " << limSup << ")" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	if(mayorBarrio != NULL)													//Comprueba que se haya encontro alguna persona para el rango dado
		cout << "Barrio : " << mayorBarrio->getNombreBarrio() << " | Distrito : " << mayorBarrio->getNombreDistrito() <<
		 	" | Habitantes entre " << limInf << " y " << limSup << " años : " << mayorNPersonas << endl;
	else
		cout << "NO SE HA ENCONTRADO NINGÚN HABITANTES COMPRENDIDO ENTRE " << limInf << " y " << limSup << " años" << endl;
}

void GestorBarrio::mostrar() {												//Pasa la llamada a cada barrio para que muestre su contenido
	Barrio* bAux;															//Puntero auxiliar para consultar cada barrio de la lista de barrios

	//Recorre secuencialmente de inicio a fin la lista de barrios
	lBarrios->moverInicio();
	while(!lBarrios->finLista()){
		lBarrios->consultar(bAux);
		lBarrios->avanzar();
		cout << "***********************************************************************************************" << endl;
		bAux->mostrar();													//Llama a mostrar la información de cada barrio
		cout << "***********************************************************************************************" << endl << endl;
	}
}

}
