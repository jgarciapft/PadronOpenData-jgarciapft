/*
 * GestorLugarNacimiento.cpp
 *
 *      Autor: jgarciapft
 */

#include "GestorLugarNacimiento.h"

namespace std {

/*** DEFINCIÓN DE CONSTANTES ***/
const string POBLACION_TEXTO_RELLENO = "";										//Texto de relleno para el atributo 'poblacion' al crear nuevos objetos 'LugarNacimiento' aplicado al algoritmo 6

GestorLugarNacimiento::GestorLugarNacimiento() {
	lLugarNacimiento = new ListaPI<LugarNacimiento*>();							//Reserva memoria para la lista de lugares de nacimiento que encapsula
}

GestorLugarNacimiento::GestorLugarNacimiento(string lugaresNacimiento) {
	lLugarNacimiento = new ListaPI<LugarNacimiento*>();							//Reserva memoria para la lista de lugares de nacimiento que encapsula

	vector<string> vText = splitStringToVector(lugaresNacimiento, DELIM);		//Delimita cada objeto 'Lugar de nacimiento' y lo almacena en un vector
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);							//Delimita cada campo de cada objeto 'Lugar de nacimiento' y lo almacena en otro vector
		//Dependiendo de si el lugar de nacimiento es extranjero o nacional el último vector tendrá una longitud distinta porque para extranjeros no se almacena la población
		//Instancia un nuevo lugar de nacimiento y lo almacena en la lista dependiendo de estas condiciones
		if ( vString.size()== 2){												//Es extranjero
			//La población se rellna con un texto alternativo de relleno definido en una constante
			lLugarNacimiento->insertar(new LugarNacimiento(POBLACION_TEXTO_RELLENO, vString[0], atoi(vString[1].c_str())));
		}else{																	//Es nacional
			lLugarNacimiento->insertar(new LugarNacimiento(vString[0], vString[1], atoi(vString[2].c_str())));
		}
		lLugarNacimiento->avanzar();
	}
}

GestorLugarNacimiento::~GestorLugarNacimiento() {								//Libera la memoria asociada a cada lugar de nacimiento y a la lista que los contiene
	LugarNacimiento* lugNacAux;													//Puntero auxiliar para recorrer la lista de lugares de nacimiento

	//Recorre secuencialmente la lista de lugares de nacimiento de inicio a fin
	lLugarNacimiento->moverInicio();
	while(!lLugarNacimiento->finLista()){
		lLugarNacimiento->consultar(lugNacAux);
		lLugarNacimiento->avanzar();
		delete lugNacAux;
	}
	delete lLugarNacimiento;													//Libera la lista de lugares de nacimiento
}

/*
 * ***********************************************************		MÉTODOS PRIVADOS	*********************************************************************
 */

void GestorLugarNacimiento::insertarOrden(LugarNacimiento* lugNac) {			///@NOTA: Adecuado solo para el algoritmo 6
	bool enc = false;															//Bandera para indicar cuando se ha encontrado la posición de la lista dónde debe insertarse o actualizarse el lugar de nacimiento
	LugarNacimiento* lugNacAux;													//Puntero auxiliar para consultar la lista de lugares de nacimiento

	if(!lLugarNacimiento->estaVacia()){											//Comprueba si es la primera vez que se accede a la lista. Hay que insertar el lugar de nacimiento seguro
		lLugarNacimiento->moverInicio();
		while(!lLugarNacimiento->finLista() && !enc){							//Recorre secuencialmente la lista de lugares de nacimiento de inicio a fin
			lLugarNacimiento->consultar(lugNacAux);
			if(*lugNac >= *lugNacAux)											//Comparación alfabética por la provincia/país
				enc = true;														//Actualiza la bandera que permite salir del bucle cuando se ha encontrado la posición del dato a procesar
			else
				lLugarNacimiento->avanzar();									//Se avanza solo si no se encuentra un potencial hueco de inserción para insertar delante del dato consultado
		}
		if(*lugNac == *lugNacAux)												//Se comprueba que el dato no se duplique. La condición de duplicidad es que haya 2 datos con el mismo valor para 'provinciaPais'
			lugNacAux->incNPersonas(lugNac->getNPersonas());					//Si existe se actualiza el atributo 'nPersonas' a modo de acumulador
		else
			lLugarNacimiento->insertar(new LugarNacimiento(POBLACION_TEXTO_RELLENO, lugNac->getProvinciaPais(), lugNac->getNPersonas()));	//Si no existe, se inserta un nuevo objeto. Si modificasemos los objetos ya introducimos en memoria cambiaríamos los datos del padrón
	}else{
		lLugarNacimiento->insertar(new LugarNacimiento(POBLACION_TEXTO_RELLENO, lugNac->getProvinciaPais(), lugNac->getNPersonas()));		//Controla el caso de que la lista esté vacía inicialmente
	}
}

/*
 * ***********************************************************		MÉTODOS PÚBLICOS	*********************************************************************
 */

void GestorLugarNacimiento::alg6(GestorLugarNacimiento*& gLugNacimiento) {		///@NOTA: Nombre provisional
}

void GestorLugarNacimiento::mostrarAlg6() {										//Muestra la lista procesada por el algoritmo 6 como resultado
	LugarNacimiento* lugNacAux;													//Puntero auxiliar para consultar la lista de lugares de Nacimiento

	//Recorre secuencialmente la lista de lugares de nacimiento de inicio a fin
	lLugarNacimiento->moverInicio();
	while(!lLugarNacimiento->finLista()){
		lLugarNacimiento->consultar(lugNacAux);
		lLugarNacimiento->avanzar();
		cout << lugNacAux->getProvinciaPais() << " (" << lugNacAux->getNPersonas() << ")" << endl;
	}
}

void GestorLugarNacimiento::mostrar() {											//Muestra la información de cada lugar de nacimiento
	LugarNacimiento* lugNacAux;													//Puntero auxiliar para consultar la lista de lugares de nacimiento

	//Recorre secuencialmente la lista de lugares de nacimiento de inicio a fin
	lLugarNacimiento->moverInicio();
	while(!lLugarNacimiento->finLista()){
		lLugarNacimiento->consultar(lugNacAux);
		lLugarNacimiento->avanzar();
		lugNacAux->mostrar();													//Llama a mostrar todos los datos de cada objeto 'LugarNacimiento'
	}
}

}

