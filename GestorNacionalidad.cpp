/**
 * @CLASE: GestorNacionalidad
 */

#include "GestorNacionalidad.h"

namespace std {

GestorNacionalidad::GestorNacionalidad() {													///@NOTA:_Reserva memoria para la lista de nacionalidades que encapsula
	lNacionalidad = new ListaPI<Nacionalidad*>();
}

GestorNacionalidad::GestorNacionalidad(string nacionalidades) {								///@NOTA: Reserva memoria para la lista de nacionalidades que encapsula
	lNacionalidad = new ListaPI<Nacionalidad*>();

	vector<string> vText = splitStringToVector(nacionalidades, DELIM);						//Delimita cada objeto 'Nacionalidad' y lo almacena en un vector
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);										//Delimita cada campo de cada objeto 'Nacionalidad' y lo almacena en otro vector
		lNacionalidad->insertar(new Nacionalidad(vString[0], atoi(vString[1].c_str())));	//Instacia un nuevo objeto 'Nacionalidad' a partir del vector anterior y lo almacena en la lista de nacionalidades
		lNacionalidad->avanzar();
	}
}

GestorNacionalidad::~GestorNacionalidad() {													///@NOTA: Libera la memoria asociada a cada nacionalidad y a la lista que las contiene
	Nacionalidad* nacAux;																	//Puntero auxiliar para consultar la lista de nacionalidades que encapsula el gestor

	//Recorre secuencialmente la lista de nacionalidades de inicio a fin
	lNacionalidad->moverInicio();
	while(!lNacionalidad->finLista()){														//También comprueba si la lista está inicialmente vacía
		lNacionalidad->consultar(nacAux);
		lNacionalidad->avanzar();
		delete nacAux;																		//Libera cada nacionalidad
	}
	delete lNacionalidad;																	//Libera la lista de nacionalidades
}

/****************************************************************************		INTERFAZ PRIVADA	****************************************************************************/

void GestorNacionalidad::ordenarLista(ListaPI<Nacionalidad*>*& lNacion) {
	bool siguiente;																			/* Bandera que compara si el dato modificado/insertado con el anterior (sabiendo que existe) antes de comprobar si el PI está en el inicio.
																							 * 		CONTROLA EL CASO DEL SEGUNDO ELEMENTO INSERTADO: al comprobar la condición del bucle no compararía el primer dato con el segundo,
																							 * 			por lo que siempre se insertaría en el inicio aunque fuese menor que el que estaba en el inicio
																							 * 		Para el resto de casos comprueba si el dato modificado/insertado es el mayor de la lista, por lo que lo coloca en el inicio
																							 * 			Si no lo es primero avanza el PI para insertar detrás del elemento del que es inmediatamente inferior*/
	Nacionalidad* nacionPI;																	//Puntero auxiliar que almacena el dato insertado/modificado
	Nacionalidad* nacion;																	//Puntero auxiliar para consultar la lista 'lNacion'

	if(!lNacion->enInicio()){																//CONTROLA EL CASO INICIAL: es el primer elemento a insertar, por lo que ya está ordenado
		lNacion->consultar(nacionPI);														//Guarda el dato insertado/modificado (que está apuntado por el PI) para poder borrarlo y ordenarlo
		lNacion->borrar();
																							/* Como el resto de la lista está ordenada en orden descendente y se insertan/modifican los datos de tal manera que nunca tendrán menos habitantes que antes
																							 * 		solo es necesario comprobar el dato insertado/modificado con los anteriores a él. Más detenidamente:
																							 * 			+ Cuando se modifica un dato solo puede aumentar su número de habitantes, por lo que le corresponderá una posición anterior en la lista
																							 * 			+ Cuando se inserta un dato nuevo se hace al final
																							 * 		En resumen, es imposible que un dato esté entre otros dos que sean mayor que éste, y por tanto solo es necesario compararlo con los
																							 * 			datos anteriores a éste en la lista*/
		do{
			lNacion->retroceder();
			lNacion->consultar(nacion);
			siguiente = *nacionPI > *nacion;                                                //Indica si el dato insertado/modificado es menor/mayor
		}while(siguiente && !lNacion->enInicio());
		if(!siguiente)																		//Comprueba si el dato insertado/modificado es mayor que todos los de la lista
			lNacion->avanzar();																//No lo es. Hay que insertarlo detrás del PI
		lNacion->insertar(nacionPI);														//Si era el mayor de todos se inserta el primero. Si no ya se ha avanzado el PI y se puede insertar detrás de éste
	}
}

/****************************************************************************		INTERFAZ PÚBLICA	****************************************************************************/

void GestorNacionalidad::alg5(ListaPI<Nacionalidad*>*& lNacion) {
	bool enc = false;																		//Bandera para indicar cuando se ha encontrado la posición de la lista dónde debe insertarse/actualizarse el lugar de nacimiento
	Nacionalidad* nacionAux1;																//Puntero auxiliar para consultar la lista de lugares de nacimiento que encapsula el gestor
	Nacionalidad* nacionAux2;																//Puntero auxiliar para consultar la lista de lugares de nacimiento pasada por parámetro

	if(!lNacionalidad->estaVacia()) {                                 	      				//Comprueba si el gestor contiene alguna nacionalidad
		lNacionalidad->moverInicio();
		if (lNacion->estaVacia()) {                                            				//Maneja el caso inicial: Comprueba si la lista pasada por parámtro está vacía e inserta el primer elemento
			lNacionalidad->consultar(nacionAux1);
			lNacionalidad->avanzar();
			lNacion->insertar(new Nacionalidad(nacionAux1->getNacionalidad(), nacionAux1->getNPersonas()));
		}

		//Recorre secuencialmente la lista de nacionaliadades del gestor de inicio a fin
		while (!lNacionalidad->finLista()) {                 				           		//También comprueba si la lista está inicialmente vacía
			lNacionalidad->consultar(nacionAux1);
			lNacionalidad->avanzar();
			lNacion->moverInicio();
			while (!lNacion->finLista() && !enc) {											//Busca el lugar en el que insertar/actualizar la lista pasada por parámtetro (con la nacionalidad actual de la lista que encapsula el gestor)
				lNacion->consultar(nacionAux2);
				if (*nacionAux1 == *nacionAux2)				                        	    //Comparación lexicográfica por la nacionalidad. Comprueba si la nacionalidad ya existe en 'lNacion'
					enc = true;                             			                	//Actualiza la bandera que permite salir del bucle cuando se ha encontrado la posición del dato a procesar
				else
					lNacion->avanzar();                               						//SOLO se avanza si no se encuentra un potencial hueco de inserción para insertar delante del dato consultado
			}
			if(enc)                                                                         //Se comprueba que el dato no se duplique. La condición de duplicidad es que haya 2 datos con el mismo valor para 'nacionalidad'
				nacionAux2->incNPersonas(nacionAux1->getNPersonas());             		    //Si existe se actualiza el atributo 'nPersonas' a modo de acumulador con el número de personas de la nacionalidad coincidente
			else                                                                            //Si no existe se inserta un nuevo objeto. Si se modificasen los objetos ya introducidos en memoria se modificarían los datos del padrón
				lNacion->insertar(new Nacionalidad(nacionAux1->getNacionalidad(), nacionAux1->getNPersonas()));

			ordenarLista(lNacion);															//Actualiza la lista para que mantenga su orden
			enc = false;																	//Reinicia la bandera de posición
		}
	}
}



void GestorNacionalidad::mostrar() {														///@NOTA: Muestra la información las nacionalidades de la lista
	Nacionalidad* nacAux;																	//Puntero auxiliar para consultar la lista de nacionalidades que encapsula el gestor

	//Recorre secuencialmente la lista de nacionalidades de inicio a fin
	lNacionalidad->moverInicio();
	while(!lNacionalidad->finLista()){														//También comprueba si la lista está inicialmente vacía
		lNacionalidad->consultar(nacAux);
		lNacionalidad->avanzar();
		nacAux->mostrar();																	//Llama a mostrar la información de cada nacionalidad en la lista
	}
}

}

