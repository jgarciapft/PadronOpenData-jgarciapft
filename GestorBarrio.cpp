/**
 * @CLASE: GestorBarrio
 */

#include "GestorBarrio.h"

namespace std {

GestorBarrio::GestorBarrio() {
	lBarrios = new ListaPI<Barrio*>();										///@NOTA: Reserva memoria para la lista de barrios que encapsula
}

GestorBarrio::~GestorBarrio() {												///@NOTA: Libera la memoria asociada a cada barrio y a la lista de barrios que encapsula
	Barrio* bAux;

	//Recorre secuencialmente de inicio a fin la lista de barrios
	lBarrios->moverInicio();
	while(!lBarrios->finLista()){											//También comprueba si la lista está vacía inicialmente
		lBarrios->consultar(bAux);
		lBarrios->avanzar();
		delete bAux;														//Libera cada barrio
	}
	delete lBarrios;														//Libera la lista de barrios
}



void GestorBarrio::insertar(Barrio* b) {									///@NOTA: Método invocativo
	lBarrios->insertar(b);													//Inserta el barrio 'b' en la lista sin ningún criterio
}

void GestorBarrio::insertarVia(Via* v) {									///@NOTA: Inserta la vía 'v' en el barrio que le corresponda con orden alfabético descendente
	bool enc = false;														//Bandera utilizada para terminar la búsqueda del barrio que le corresponde a la vía a insertar una vez haya una coincidencia
	Barrio* bAux;															//Puntero auxiliar para consultar la lista de barrios que encapsula el gestor

	//Recorre secuencialmente de inicio a fin la lista de barrios. También comprueba si está vacía inicialmente
	lBarrios->moverInicio();
	while(!lBarrios->finLista() && !enc){									//Puede existir la misma vía en dos barrios, pero cada tramo de vía es un objeto 'Via' en sí. Por lo que solo le corresponderá a un barrio cada tramo
		lBarrios->consultar(bAux);
		lBarrios->avanzar();
		if(bAux->getNombreBarrio() == v->getBarrioVia()){					//Comprueba si coincide el nombre del barrio al que pertenece la vía y el nombre barrio apuntado
			bAux->insertarVia(v);											//Cuando hay coincidencia de nombres de barrio la vía es pasada al gestor de vías para su inserción en orden
			enc = true;														//Actualiza la bandera para salir del bucle
		}
	}
}

void GestorBarrio::insertarDatosDemograficos(DatºosDemograficos* dD) {		///@NOTA: Inserta el dato demográfico 'dD' en su(s) vía(s) correspondiente(s)	@NOTA: Hay multiplicidad de vías para las que corresponde un dato demográfico
	Barrio* bAux;															//Puntero auxiliar para consultar la lista de barrios que encapsula el gestor

	//Recorre secuencialmente de inicio a fin la lista de barrios
	lBarrios->moverInicio();
	while(!lBarrios->finLista()){											//Al poder haber duplicidad de vías hay que recorrer la lista entera. También comprueba si la lista está vacía inicialmente
		lBarrios->consultar(bAux);
		lBarrios->avanzar();
		bAux->insertarDatosDemograficos(dD);								//Pasa a todos los barrios el dato demográfico a insertar para que comprueben si corresponde a alguna de sus vías
	}
}

void GestorBarrio::alg2(string nombreBarrio) {
	bool enc  = false;														//Bandera utilizada para comprobar si se ha econtrado el barrio dado
	Barrio* bAux;															//Puntero auxiliar para recorrer la lista de barrios

	//Recorre secuencialmente de inicio a fin la lista de barrios
	lBarrios->moverInicio();
	while(!lBarrios->finLista() && !enc){									//Cada barrio es único en la lista de barrios. La búsqueda se termina en la primera coincidencia. También comprueba si la lista está vacía inicialmente
		lBarrios->consultar(bAux);
		lBarrios->avanzar();
		if(nombreBarrio == bAux->getNombreBarrio()){						//Comprueba si coincide el nombre del barrio al que pertenece la vía y el nombre barrio apuntado
			bAux->mostrarVias();											//Muestra todas las vías del barrio que coincide con el parámetro 'nombreBarrio'
			enc = true;														//Actualiza la bandera para salir del bucle
		}
	}
	if(!enc){																//Sino se encuentra el barrio dado se indica al usuario por consola
		cout << "NO SE HA ENCONTRADO NINGÚN BARRIO CON EL NOMBRE (" << nombreBarrio << ")" << endl;
	}
}

void GestorBarrio::alg7(int limInf, int limSup) {
	Barrio* bAux;															//Puntero auxiliar para consular la lista de barrios
	Barrio* mayorBarrio = NULL;												//Puntero al barrio con mayor número de habitantes para el rango dado hasta ahora
	int nPersonasActual;													//Número de habitantes para el rango dado del barrio actual
	int mayorNPersonas = 0;													//Mayor número de habitantes para el rango dado hasta ahora

	//Recorre secuencialmente de inicio a fin la lista de barrios
	lBarrios->moverInicio();
	while(!lBarrios->finLista()){											//También comprueba si la lista está vacía inicialmente
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
	else																	//
		cout << "NO SE HA ENCONTRADO NINGÚN HABITANTE COMPRENDIDO ENTRE " << limInf << " y " << limSup << " años" << endl;
}

void GestorBarrio::alg8(string nombreBarrio) {
	bool enc = false;														//Bandera para salir del bucle una vez encontrado el barrio buscado (si existe)
	Barrio* bAux;															//Puntero auxiliar para consultar la lista de barrios

	//Recorre secuencialmente de inicio a fin la lista de barrios
	lBarrios->moverInicio();
	while(!lBarrios->finLista() && !enc){									//Cada barrio es único en la lista. En el momento en el que se encuentre se para de buscar
		lBarrios->consultar(bAux);
		lBarrios->avanzar();
		if(bAux->getNombreBarrio() == nombreBarrio)							//Comprueba si es el barrio buscado
			enc = true;														//Actualiza la bandera
	}
	if(enc)																	//Comprueba si se ha encontrado el barrio en la lista de barrios
		bAux->alg8();														//Una vez encontrado el barrio al algoritmo no le hace falta el nombre de éste
	else																	//Si no se ha encontrado se indica por consola al usuario
		cout << "NO SE HA ENCONTRADO EL BARRIO " << nombreBarrio << endl;
}

void GestorBarrio::alg9() {
	Barrio* bAux;															//Puntero auxiliar para consultar la lista de barrios que encapulsa el gestor
	Barrio* barrioPHombres = NULL;											//Puntero al barrio que contiene el mayor porcentaje de hombres hasta ahora
	Barrio* barrioPMujeres = NULL;											//Puntero al barrio que contiene el mayor porentaje de mujeres hasta ahora
	float pHombres;															//Porcentaje de hombres de cada barrio
	float pMujeres;															//Porcentaje de mujeres de cada barrio
	float mayorPHombres = 0;												//Mayor porcentaje de hombres hasta ahora
	float mayorPMujeres = 0;												//Mayor porcentaje de mujeres hasta ahora

	//Recorre secuencialmente de inicio a fin la lista de barrios
	lBarrios->moverInicio();
	while(!lBarrios->finLista()){											//También comprueba si la lista está vacía inicialmente
		lBarrios->consultar(bAux);
		lBarrios->avanzar();
		bAux->alg9(pHombres, pMujeres);										//Calcula los porcentajes de hombres y mujeres del barrio actual
		if(pHombres > mayorPHombres){										//Compara el mayor porcentaje de hombres hasta ahora con el barrio actual y actualiza las variables si procede
			mayorPHombres = pHombres;										//Actualiza el mayor porcentaje de hombres hasta ahora
			barrioPHombres = bAux;
		}
		if(pMujeres > mayorPMujeres){										//Compara el mayor porcentaje de mujeres hasta ahora con el barrio actual y actualiza las variables si procede
			mayorPMujeres = pMujeres;										//Actualiza el mayor porcentaje de mujeres hasta ahora
			barrioPMujeres = bAux;
		}
	}

	//Muetra los resultados del algoritmo
	if(barrioPHombres != NULL){												//Comprueba si hay algún hombre entre la población
		cout << "Barrio con el mayor porcentaje de HOMBRES - PORCENTAJE (%) : " << mayorPHombres * 100 << "%" << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << "Barrio : " << barrioPHombres->getNombreBarrio() << " | Distrito : " << barrioPHombres->getNombreDistrito() << endl << endl;
	}else{
		cout << "NO HAY NINGÚN HOMBRE ENTRE LA POBLACIÓN" << endl;			//Si no hay ningún hombre se indica al usuario por consola
	}
	if(barrioPMujeres != NULL){												//Comprueba si hay alguna mujer entre la población
		cout << "Barrio con el mayor porcentaje de MUJERES - PORCENTAJE (%) : " << mayorPMujeres * 100 << "%" << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << "Barrio : " << barrioPMujeres->getNombreBarrio() << " | Distrito : " << barrioPMujeres->getNombreDistrito() << endl;
	}else{
		cout << "NO HAY NINGÚN HOMBRE ENTRE LA POBLACIÓN" << endl;			//Si no hay ninguna mujer se indica al usuario por consola
	}
}



void GestorBarrio::mostrar() {												//Pasa la llamada a cada barrio para que muestre su contenido
	Barrio* bAux;															//Puntero auxiliar para consultar la lista de barrios que encapsula el gestor

	//Recorre secuencialmente de inicio a fin la lista de barrios
	lBarrios->moverInicio();
	while(!lBarrios->finLista()){											//También comprueba si la lista está vacía inicialmente
		lBarrios->consultar(bAux);
		lBarrios->avanzar();
		cout << "***********************************************************************************************" << endl;
		bAux->mostrar();													//Llama a mostrar la información de cada barrio
		cout << "***********************************************************************************************" << endl << endl;
	}
}

}
