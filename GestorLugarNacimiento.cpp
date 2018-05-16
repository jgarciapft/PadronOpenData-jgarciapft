/*
 * GestorLugarNacimiento.cpp
 *
 *      Autor: jgarciapft
 */

#include "GestorLugarNacimiento.h"

namespace std {

GestorLugarNacimiento::GestorLugarNacimiento() {								///@NOTA: Reserva memoria para la lista de lugares de nacimiento que encapsula
	lLugarNacimiento = new ListaPI<LugarNacimiento*>();
}

GestorLugarNacimiento::GestorLugarNacimiento(string lugaresNacimiento) {		///@Reserva memoria para la lista de lugares de nacimiento que encapsula y la inicializa con un set de datos
	lLugarNacimiento = new ListaPI<LugarNacimiento*>();

	vector<string> vText = splitStringToVector(lugaresNacimiento, DELIM);		//Delimita cada objeto 'Lugar de nacimiento' y lo almacena en un vector
	for(int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);							/*Delimita cada campo de cada objeto 'Lugar de nacimiento' y lo almacena en otro vector
																					* Dependiendo de si el lugar de nacimiento es extranjero o nacional el último vector tendrá una longitud distinta porque para extranjeros no se almacena la población
																					* Instancia un nuevo lugar de nacimiento y lo almacena en la lista dependiendo de estas condiciones*/
		if(vString.size()== 2){													//Comprueba si la nacionalidad es extranjera
			//La población se rellna con un texto alternativo de relleno definido en una constante
			lLugarNacimiento->insertar(new LugarNacimiento(POBLACION_TEXTO_RELLENO, vString[0], atoi(vString[1].c_str())));
		}else{																	//Sino el lugar de nacimiento es nacional
			lLugarNacimiento->insertar(new LugarNacimiento(vString[0], vString[1], atoi(vString[2].c_str())));
		}
		lLugarNacimiento->avanzar();
	}
}

GestorLugarNacimiento::~GestorLugarNacimiento() {								///@NOTA: Libera la memoria asociada a cada lugar de nacimiento y a la lista que los contiene
	LugarNacimiento* lugNacAux;													//Puntero auxiliar para recorrer la lista de lugares de nacimiento que encapsula el gestor

	//Recorre secuencialmente la lista de lugares de nacimiento de inicio a fin
	lLugarNacimiento->moverInicio();
	while(!lLugarNacimiento->finLista()){
		lLugarNacimiento->consultar(lugNacAux);
		lLugarNacimiento->avanzar();
		delete lugNacAux;														//Libera cada lugar de nacimiento
	}
	delete lLugarNacimiento;													//Libera la lista de lugares de nacimiento
}



void GestorLugarNacimiento::alg6(ListaPI<LugarNacimiento *> *&lLugNac) {
	bool enc = false;															//Bandera para indicar cuando se ha encontrado la posición de la lista dónde debe insertarse/actualizarse el lugar de nacimiento
	LugarNacimiento* lugNacAux1;												//Puntero auxiliar para consultar la lista de lugares de nacimiento que encapsula el gestor
	LugarNacimiento* lugNacAux2;												//Puntero auxiliar para consultar la lista de lugares de nacimiento pasada por parámetro

	if(!lLugarNacimiento->estaVacia()) {                                        //Comprueba si el gestor contiene algún lugar de nacimiento
		lLugarNacimiento->moverInicio();
		if (lLugNac->estaVacia()) {                                             //Maneja el caso inicial: Comprueba si la lista pasada por parámtro está vacía e inserta el primer elemento si procede
			do {																//Comprueba que el primer LUGAR DE NACIMIENTO a insertar NO SEA EXTRANJERO y busca uno que sea nacional
				lLugarNacimiento->consultar(lugNacAux1);
				lLugarNacimiento->avanzar();
			} while(lugNacAux1->getPoblacion() == POBLACION_TEXTO_RELLENO && !lLugarNacimiento->finLista());
			if(!lLugarNacimiento->finLista()){									//Comprueba si la lista solo contenía nacionalidades extranjeras y no hay ninguna más que insertar
				lLugNac->insertar(new LugarNacimiento(POBLACION_TEXTO_RELLENO, lugNacAux1->getProvinciaPais(), lugNacAux1->getNPersonas()));
			}
		}

		//Recorre secuencialmente la lista de lugares de nacimiento del gestor de inicio a fin. También comprueba que no esté inicialmente vacía
		while (!lLugarNacimiento->finLista()) {                            		//Cada lugar de nacimiento es único en la lista. Cuando se encuentra el potenical hueco en el que insertar/actualizar se para de modificar la lista
			lLugarNacimiento->consultar(lugNacAux1);
			lLugarNacimiento->avanzar();
			if(lugNacAux1->getPoblacion() != POBLACION_TEXTO_RELLENO){			//Comprueba que la nacionalidad no sea extranjera
				lLugNac->moverInicio();
				while (!lLugNac->finLista() && !enc) {							//Busca el lugar en el que insertar/actualizar la lista pasada por parámtetro (con el lugar de nacimiento actual de la lista que encapsula el gestor)
					lLugNac->consultar(lugNacAux2);
					if (*lugNacAux1 >= *lugNacAux2)                             //Comparación alfabética por la provincia/país
						enc = true;                                             //Actualiza la bandera que permite salir del bucle cuando se ha encontrado la posición del dato a procesar
					else
						lLugNac->avanzar();                               		//SOLO se avanza si no se encuentra un potencial hueco de inserción para insertar delante del dato consultado
				}
				if(*lugNacAux1 == *lugNacAux2)                                  //Se comprueba que el dato no se duplique. La condición de duplicidad es que haya 2 datos con el mismo valor para 'provinciaPais'
					lugNacAux2->incNPersonas(lugNacAux1->getNPersonas());       //Si existe se actualiza el atributo 'nPersonas' a modo de acumulador
				else															//Si no existe se inserta un nuevo objeto. Si modificasemos los objetos ya introducidos en memoria cambiaríamos los datos del padrón
					lLugNac->insertar(new LugarNacimiento(POBLACION_TEXTO_RELLENO, lugNacAux1->getProvinciaPais(), lugNacAux1->getNPersonas()));
				enc = false;													//Reinicia la bandera de posición
			}
		}
	}
}

void GestorLugarNacimiento::alg10(ListaPI<LugarNacimiento*>*& lLugNac, string nombreProvincia) {
	bool enc = false;															//Bandera para salir del bucle que compara si la población encontrada para la provincia dada está ya en la lista 'lLugNac'
	LugarNacimiento* lugNacAux1;												//Puntero auxiliar para consultar la lista de lugares de nacimiento que encapsula el gestor
	LugarNacimiento* lugNacAux2;												//Puntero auxiliar para consultar la lista de lugares de nacimiento pasada por parámetro 'lLugNac'

	//Recorre secuencialmente la lista de lugares de nacimiento del gestor de inicio a fin
	lLugarNacimiento->moverInicio();
	while(!lLugarNacimiento->finLista()){										//También comprueba si la lista está vacía inicialmente
		lLugarNacimiento->consultar(lugNacAux1);
		lLugarNacimiento->avanzar();
		if(lugNacAux1->getProvinciaPais() == nombreProvincia){					//Compara si la provincia del elemento actual coincide con la buscada
			lLugNac->moverInicio();
			while (!lLugNac->finLista() && !enc){								//Recorre secuencialmente la lista de lugares de nacimiento pasada por parámetro 'lLugNac' o hasta que encuentra una coincidencia de población ya incluida
				lLugNac->consultar(lugNacAux2);
				lLugNac->avanzar();
				if(lugNacAux1->getPoblacion() == lugNacAux2->getPoblacion())	//Comprueba si ya existía la población actual
					enc = true;
			}
			if(enc)																//Comprueba si ha habido coincidencia de población. Actualiza el dato ya existente con los nuevos habitantes
				lugNacAux2->incNPersonas(lugNacAux1->getNPersonas());
			else																//Sino inserta un nuevo lugar de nacimiento con los datos actuales
				lLugNac->insertar(new LugarNacimiento(lugNacAux1->getPoblacion(), PROVINCIA_PAIS_TEXTO_RELLENO, lugNacAux1->getNPersonas()));
			enc = false;														//Reinicia la bandera
		}
	}
}

void GestorLugarNacimiento::alg11(ofstream& ofs) {
	LugarNacimiento* lugNacAux;													//Puntero auxiliar para consultar la lista de lugares de nacimiento que encapsula el gestor

	//Recorre secuencialmente la lista de lugares de nacimiento del gestor de inicio a fin
	lLugarNacimiento->moverInicio();
	while(!lLugarNacimiento->finLista()){										//También comprueba si la lista está vacía inicialmente
		lLugarNacimiento->consultar(lugNacAux);
		lLugarNacimiento->avanzar();
		ofs << lugNacAux->getPoblacion() << ", " << lugNacAux->getProvinciaPais() << " (" << lugNacAux->getNPersonas() << ") " << endl;	//Escribe cada lugar de nacimiento presente en la lista al ficehro de volcado
	}
}

int GestorLugarNacimiento::alg12(string& nombreProvincia) {
	int cont = 0;																//Acumulador del número de habitantes de la lista que encapsula el gestor que pertenecen a la provincia dada
	LugarNacimiento* lugNacAux;													//Puntero auxiliar para consultar la lista de lugares de nacimiento que encapsula el gestor

	//Recorre secuencialmente la lista de lugares de nacimiento del gestor de inicio a fin
	lLugarNacimiento->moverInicio();
	while(!lLugarNacimiento->finLista()){										//También comprueba si la lista está inicialmente vacía
		lLugarNacimiento->consultar(lugNacAux);
		lLugarNacimiento->avanzar();
		if(lugNacAux->getPoblacion() != POBLACION_TEXTO_RELLENO){				//Comprueba que la nacionalidad no sea extranjera, indicado por la cadena POBLACION_TEXTO_RELLENO en el atributo 'poblacion'
			if(lugNacAux->getProvinciaPais() == nombreProvincia)				//Comprueba si es la provincia buscada
				cont += lugNacAux->getNPersonas();								//Actualiza el acumulador con el número de personas de los lugares de nacimiento coincidentes
		}
	}

	return cont;
}



void GestorLugarNacimiento::mostrar() {											///@NOTA: Muestra la información de cada lugar de nacimiento
	LugarNacimiento* lugNacAux;													//Puntero auxiliar para consultar la lista de lugares de nacimiento que encapsula el gestor

	//Recorre secuencialmente la lista de lugares de nacimiento de inicio a fin
	lLugarNacimiento->moverInicio();
	while(!lLugarNacimiento->finLista()){										//También comprueba si la lista está vacía inicialmente
		lLugarNacimiento->consultar(lugNacAux);
		lLugarNacimiento->avanzar();
		lugNacAux->mostrar();													//Llama a mostrar todos los datos de cada objeto 'LugarNacimiento'
	}
}

}

