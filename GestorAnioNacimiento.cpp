/*
 * GestorAnioNacimiento.cpp
 *
 *      Autor: jgarciapft
 */

#include "GestorAnioNacimiento.h"
#include <time.h>

namespace std {

/*** DEFINCIÓN DE CONSTANTES *** 																			TODO: Pensar declaracion/inicializacion de constantes */
extern const int RANGO_EDAD_ALG_4;																			//Amplitud del intervalo de edad que usa el algorimto 4 para agrupar los años de nacimiento de los habitantes


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

void GestorAnioNacimiento::alg4(ListaPI<AnioNacimiento*>*& lAnioNac) {										///@NOTA: Nombre provisional
	bool enc = false;																						//Bandera para indicar cuando se ha encontrado la posición de la lista dónde debe insertarse o actualizarse el año de nacimiento
	AnioNacimiento* anNacAux1;																				//Puntero auxiliar para consular la lista que encapsula el gestor
	AnioNacimiento* anNacAux2;																				//Puntero auxiliar para consultar la lista pasada por parámetro 'lAnioNac'
	int anioActual;																							//Marca de clase (límite inferior) para crear cada objeto 'AnioNacimiento' y que representa al intervalo sobre el que almacena el número de personas
	time_t tiempoActual = time(NULL);
	tm* tiempoSis = localtime(&tiempoActual);																//Estructura para almacenar el tiempo del sistema en horas, minutos y segundos

	//Recorre secuencialmente la lista de años de nacimiento de inicio a fin1
	if(!lAnioNacimiento->estaVacia()){																		//Comprueba si el gestor contiene algún año de nacimiento
		lAnioNacimiento->moverInicio();
		if(lAnioNac->estaVacia()){																			//Maneja el caso inicial: Comprueba si la lista pasada por parámtro está vacía e inserta el primer elemento
			lAnioNacimiento->consultar(anNacAux1);
			lAnioNacimiento->avanzar();
			anioActual = tiempoSis->tm_year + 1900 - anNacAux1->getAnio();									//Calcula la edad actual @NOTA: 'tm_year' almacena los años transcurridos desde 1900, por lo que hay que sumárselos
			anioActual -= anioActual % RANGO_EDAD_ALG_4;													//Transforma la edad actual a la marca de clase que informa sobre qué intervalo representa
			lAnioNac->insertar(new AnioNacimiento(anioActual, anNacAux1->getNPersonas()));					//Crea el nuevo objeto 'AnioNacimiento' que representará cada intervalo y lo inserta en la lista pasada por parámtetro
		}

		while (!lAnioNacimiento->finLista()){																//Recorre secuencialmente la lista de años de nacimiento del gestor de inicio a fin
			lAnioNacimiento->consultar(anNacAux1);
			lAnioNacimiento->avanzar();
			anioActual = tiempoSis->tm_year + 1900 - anNacAux1->getAnio();									//Calcula la edad actual. @NOTA: tm_year comienza a contar desde 1900, por lo que hay que sumárselos
			anioActual -= anioActual % RANGO_EDAD_ALG_4;													//Calculo del intervalo del año de nacimiento actual apuntado por la lista que encapsula el gestor

			lAnioNac->moverInicio();
			while (!lAnioNac->finLista() && !enc){															//Busca el lugar en el que insertar/actualizar la lista pasada por parámtetro (con el año de nacimiento actual de la lista que encapsula el gestor)
				lAnioNac->consultar(anNacAux2);
				if(anioActual <= anNacAux2->getAnio())														//Comprobación de posición a insertar
					enc = true;																				//Actualiza la bandera que permite salir del bucle cuando se ha encontrado la posición del dato a procesar
				else
					lAnioNac->avanzar();																	//Se avanza solo si no se encuentra un potencial hueco de inserción para insertar delante del dato consultado
			}
			if(anioActual == anNacAux2->getAnio())															//Se comprueba que el dato no se duplique. La condición es que las marcas de clase sean distintas
				anNacAux2->incNPersonas(anNacAux1->getNPersonas());											//Si existe se actualiza el atributo 'nPersonas' a modo de acumulador
			else																							//Si no existe se inserta un nuevo objeto. Si modificasemos los objetos ya introducidos en memoria cambiaríamos los datos del padrón
				lAnioNac->insertar(new AnioNacimiento(anioActual, anNacAux1->getNPersonas()));
			enc = false;																					//Reinicia la bandera de posición
		}
	}
}

int GestorAnioNacimiento::alg7(int limInf, int limSup) {
	bool fin = false;
	AnioNacimiento* anNacAux;																				//Puntero auxiliar para consultar la lista de años de nacimiento
	int anioActual = 0;																						//Almacena la conversión de año de nacimiento a edad. Inicialmente es 0 por si se buscan recién nacidos y asegurarse de que el bucle se ejecuta una vez
	int cont = 0;																							//Acumulador para el número de personas pertenecientes al rango de edad dado
	time_t tiempoActual = time(NULL);
	tm* tiempoSis = localtime(&tiempoActual);																//Estructura para almacenar el tiempo del sistema en horas, minutos y segundos

	//Recorre secuencialmente la lista de años de nacimiento de inicio a fin
	lAnioNacimiento->moverInicio();
	while (!lAnioNacimiento->finLista() && !fin){															//Como los años de nacimiento están ordenados ascendentemente, en el momento en el que la edad sea inferior al límite inferior se deja de buscar
		lAnioNacimiento->consultar(anNacAux);
		lAnioNacimiento->avanzar();
		anioActual = tiempoSis->tm_year + 1900 - anNacAux->getAnio();										//Calcula la edad actual. @NOTA: tm_year comienza a contar desde 1900, por lo que hay que sumárselos
		if(anioActual >= limInf){																			//Comprueba si la edad pertenece al rango dado. Si es menor que el límite inferior se deja de buscar
			if(anioActual <= limSup)
				cont += anNacAux->getNPersonas();															//Pertenece al rango indicado
		}else{
			fin = true;																						//Actualización de la bandera para dejar de buscar
		}
	}

	return cont;
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