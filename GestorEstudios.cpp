/*
 * GestorEstudios.cpp
 *
 *      Autor: jgarciapft
 */

#include "GestorEstudios.h"

namespace std {

GestorEstudios::GestorEstudios() {
	lEstudios = new ListaPI<Estudios*>();											//Reserva memoria para la lista de estudios que encapsula
}

GestorEstudios::GestorEstudios(string estudios) {
	lEstudios = new ListaPI<Estudios*>();											//Reserva memoria para la lista de estudios que encapsula

	vector<string> vText = splitStringToVector(estudios, DELIM);					//Delimita cada objeto 'Estudios' y lo almacena en un vector
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);								//Delimita cada campo de cada objeto 'Estudios' y lo almacena en otro vector
		lEstudios->insertar(new Estudios(vString[0], atoi(vString[1].c_str())));	//Instacia un nuevo objeto 'Estudios' a partir del vector anterior y lo almacena en la lista de estudios
		lEstudios->avanzar();
	}
}

GestorEstudios::~GestorEstudios() {													//Libera la memoria asociada a cada estudio y la lista que los contiene
	Estudios* estAux;																//Puntero auxiliar para consultar la lista de estudios

	//Recorre secuencialmente la lista de estudios de inicio a fin
	lEstudios->moverInicio();
	while(!lEstudios->finLista()){
		lEstudios->consultar(estAux);
		lEstudios->avanzar();
		delete estAux;																//Libera cada estudio
	}
	delete lEstudios;																//Libera la lista de estudios
}

/****************************************************************************		INTERFAZ PRIVADA	****************************************************************************/

void GestorEstudios::ordenarLista(ListaPI<Estudios *> *&lEstud) {
	bool siguiente;																	/* Bandera que compara si el dato modificado/insertado con el anterior (sabiendo que existe) antes de comprobar si el PI está en el inicio.
																					 * 		CONTROLA EL CASO DEL SEGUNDO ELEMENTO INSERTADO: al comprobar la condición del bucle no compararía el primer dato con el segundo,
																					 * 			por lo que siempre se insertaría en el inicio aunque fuese menor que el que estaba en el inicio
																					 * 		Para el resto de casos comprueba si el dato modificado/insertado es el mayor de la lista, por lo que lo coloca en el inicio
																					 * 			Si no lo es primero avanza el PI para insertar detrás del elemento del que es inmediatamente inferior*/
	Estudios* estudPI;																//Puntero auxiliar que almacena el dato insertado/modificado
	Estudios* estud;																//Puntero auxiliar para consultar la lista 'lEstud'

	if(!lEstud->enInicio()){														//CONTROLA EL CASO INICIAL: es el primer elemento a insertar, por lo que ya está ordenado
		lEstud->consultar(estudPI);													//Guarda el dato insertado/modificado (que está apuntado por el PI) para poder borrarlo y ordenarlo
		lEstud->borrar();
																					/* Como el resto de la lista está ordenada en orden descendente y se insertan/modifican los datos de tal manera que nunca tendrán menos habitantes que antes
																					 * 		solo es necesario comprobar el dato insertado/modificado con los anteriores a él. Más detenidamente:
																					 * 			+ Cuando se modifica un dato solo puede aumentar su número de habitantes, por lo que le corresponderá una posición anterior en la lista
																					 * 			+ Cuando se inserta un dato nuevo se hace al final
																					 * 		En resumen, es imposible que un dato esté entre otros dos que sean mayor que éste, y por tanto solo es necesario compararlo con los
																					 * 			datos anteriores a éste en la lista*/
		do{
			lEstud->retroceder();
			lEstud->consultar(estud);
			siguiente = *estudPI > *estud;                                          //El dato insertado/modificado es menor/mayor
		}while(siguiente && !lEstud->enInicio());
		if(!siguiente)																//Comprueba si el dato insertado/modificado es mayor que todos los de la lista
			lEstud->avanzar();														//No lo es. Hay que insertarlo detrás del PI
		lEstud->insertar(estudPI);													//Si era el mayor de todos hay que insertarlo el primero. Si no ya se ha avanzado el PI y se puede insertar detrás de éste
	}
}

/****************************************************************************		INTERFAZ PÚBLICA	****************************************************************************/

void GestorEstudios::alg8(ListaPI<Estudios*>*& lEstud) {
	bool enc = false;																//Bandera para indicar cuando se ha encontrado la posición de la lista dónde debe insertarse o actualizarse el estudio
	Estudios* estudAux1;															//Puntero auxiliar para consultar la lista de estudios que encapsula el gestor
	Estudios* estudAux2;															//Puntero auxiliar para consultar la lista de estudios pasada por parámetro

	if(!lEstudios->estaVacia()) {                                 	      			//Comprueba si el gestor contiene algun estudio
		lEstudios->moverInicio();
		if (lEstud->estaVacia()) {                                            		//Maneja el caso inicial: Comprueba si la lista pasada por parámtro está vacía e inserta el primer elemento
			lEstudios->consultar(estudAux1);
			lEstudios->avanzar();
			lEstud->insertar(new Estudios(estudAux1->getNivEstudios(), estudAux1->getNPersonas()));
		}

		while (!lEstudios->finLista()) {                 				           	//Recorre secuencialmente la lista de estudios del gestor de inicio a fin
			lEstudios->consultar(estudAux1);
			lEstudios->avanzar();
			lEstud->moverInicio();
			while (!lEstud->finLista() && !enc) {									//Busca el lugar en el que insertar/actualizar la lista pasada por parámtetro (con el estudio actual de la lista que encapsula el gestor)
				lEstud->consultar(estudAux2);
				if (*estudAux1 == *estudAux2)				                        //Comparación lexicográfica por el nivel de estudios. Comprueba si el estudio ya existe en 'lEstud'
					enc = true;                             			            //Actualiza la bandera que permite salir del bucle cuando se ha encontrado la posición del dato a procesar
				else
					lEstud->avanzar();                               				//Se avanza solo si no se encuentra un potencial hueco de inserción para insertar delante del dato consultado
			}
			if(enc)                                                                 //Se comprueba que el dato no se duplique. La condición de duplicidad es que haya 2 datos con el mismo valor para 'nivEstudios'
				estudAux2->incNPersonas(estudAux1->getNPersonas());             	//Si existe se actualiza el atributo 'nPersonas' a modo de acumulador
			else                                                                    //Si no existe se inserta un nuevo objeto. Si modificasemos los objetos ya introducidos en memoria cambiaríamos los datos del padrón
				lEstud->insertar(new Estudios(estudAux1->getNivEstudios(), estudAux1->getNPersonas()));

			ordenarLista(lEstud);													//Actualiza la lista para que mantenga su orden
			enc = false;															//Reinicia la bandera de posición
		}
	}
}



void GestorEstudios::mostrar() {													//Muestra la información de los estudios de la lista
	Estudios* estAux;																//Puntero auxiliar para consultar la lista de estudios

	//Recorre secuencialmente la lista de estudios de inicio a fin
	lEstudios->moverInicio();
	while(!lEstudios->finLista()){
		lEstudios->consultar(estAux);
		lEstudios->avanzar();
		estAux->mostrar();															//LLama a mostrar la información de cada estudio de la lista de estudios
	}
}

}


