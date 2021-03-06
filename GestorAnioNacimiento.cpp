/**
 * @CLASE: GestorAnioNacimiento
 */

#include <time.h>
#include "GestorAnioNacimiento.h"

namespace std {

GestorAnioNacimiento::GestorAnioNacimiento() {																///@NOTA: Reserva memoria para la lista de años de nacimiento que encapsula
	lAnioNacimiento = new ListaPI<AnioNacimiento*>();
}

GestorAnioNacimiento::GestorAnioNacimiento(string aniosNacimiento) {										///@NOTA: Reserva memoria para la lista de años de nacimiento que encapsula y la inicializa con un set de datos
	lAnioNacimiento = new ListaPI<AnioNacimiento*>();														//Reserva memoria para la lista de años de nacimiento que encapsula

	vector<string> vText = splitStringToVector(aniosNacimiento, DELIM);										//Delimita cada objeto 'AnioNacimiento' y lo almacena en un vector
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);														//Delimita cada campo de cada objeto 'AnioNacimiento' y lo almacena otro vector
		lAnioNacimiento->insertar(new AnioNacimiento(atoi(vString[0].c_str()), atoi(vString[1].c_str())));	//Instancia un nuevo año de nacimiento a partir del vector anterior y lo almacena en la lista que encapsula
		lAnioNacimiento->avanzar();
	}
}

GestorAnioNacimiento::~GestorAnioNacimiento() {																///@NOTA: Libera la memoria asociada a cada año de nacimiento y a la lista que los contiene
	AnioNacimiento* anNacAux;																				//Puntero auxiliar para recorrer la lista de años de nacimiento

	//Recorre secuencialmente la lista de años de nacimiento de inicio a fin
	lAnioNacimiento->moverInicio();
	while(!lAnioNacimiento->finLista()){																	//También comprueba si la lista está inicialmente vacía
		lAnioNacimiento->consultar(anNacAux);
		lAnioNacimiento->avanzar();
		delete anNacAux;																					//Libera cada objeto año de nacimiento
	}
	delete lAnioNacimiento;																					//Libera la lista de años de nacimiento
}



void GestorAnioNacimiento::alg4(ListaPI<AnioNacimiento*>*& lAnioNac) {
	bool enc = false;																						//Bandera para indicar cuando se ha encontrado la posición de la lista dónde debe insertarse/actualizarse el año de nacimiento
	AnioNacimiento* anNacAux1;																				//Puntero auxiliar para consular la lista que encapsula el gestor
	AnioNacimiento* anNacAux2;																				//Puntero auxiliar para consultar la lista pasada por parámetro 'lAnioNac'
	int anioActual;																							//Marca de clase (límite inferior) para crear cada objeto 'AnioNacimiento' y que representa al intervalo sobre el que almacena el número de personas
	time_t tiempoActual = time(NULL);																		//Obtiene el tiempo del sistema en ejecución
	tm* tiempoSis = localtime(&tiempoActual);																//Estructura para almacenar el tiempo del sistema en horas, minutos y segundos

	//Recorre secuencialmente la lista de años de nacimiento de inicio a fin1
	if(!lAnioNacimiento->estaVacia()){																		//Comprueba si el gestor contiene algún año de nacimiento
		lAnioNacimiento->moverInicio();
		if(lAnioNac->estaVacia()){																			//Maneja el caso inicial: Comprueba si la lista pasada por parámtro está vacía e inserta el primer elemento
			lAnioNacimiento->consultar(anNacAux1);
			lAnioNacimiento->avanzar();
			anioActual = tiempoSis->tm_year + 1900 - anNacAux1->getAnio();									///Calcula la edad actual @NOTA: 'tm_year' almacena los años transcurridos desde 1900, por lo que hay que sumárselos
			anioActual -= anioActual % RANGO_EDAD_ALG_4;													//Transforma la edad actual a la marca de clase que informa sobre qué intervalo representa
			lAnioNac->insertar(new AnioNacimiento(anioActual, anNacAux1->getNPersonas()));					//Crea el nuevo objeto 'AnioNacimiento' que representará cada intervalo y lo inserta en la lista pasada por parámtetro
		}

		while(!lAnioNacimiento->finLista()){																//Recorre secuencialmente la lista de años de nacimiento del gestor de inicio a fin. También comprueba si la lista está inicialmente vacía
			lAnioNacimiento->consultar(anNacAux1);
			lAnioNacimiento->avanzar();
			anioActual = tiempoSis->tm_year + 1900 - anNacAux1->getAnio();									///Calcula la edad actual. @NOTA: tm_year comienza a contar desde 1900, por lo que hay que sumárselos
			anioActual -= anioActual % RANGO_EDAD_ALG_4;													//Calculo del intervalo del año de nacimiento actual apuntado por la lista que encapsula el gestor

			lAnioNac->moverInicio();
			while (!lAnioNac->finLista() && !enc){															//Busca el lugar en el que insertar/actualizar la lista pasada por parámtetro (con el año de nacimiento actual de la lista que encapsula el gestor)
				lAnioNac->consultar(anNacAux2);
				if(anioActual <= anNacAux2->getAnio())														//Comprobación de posición a insertar. Orden matemático de 'anio' (edad actual)
					enc = true;																				//Actualiza la bandera que permite salir del bucle cuando se ha encontrado la posición del dato a procesar
				else
					lAnioNac->avanzar();																	//SOLO se avanza si no se encuentra un potencial hueco de inserción para insertar delante del dato consultado
			}
			if(anioActual == anNacAux2->getAnio())															//Se comprueba que el dato no se duplique. La condición es que las marcas de clase sean distintas
				anNacAux2->incNPersonas(anNacAux1->getNPersonas());											//Si existe se actualiza el atributo 'nPersonas' a modo de acumulador
			else																							//Si no existe se inserta un nuevo objeto. Si se modificasen los objetos ya introducidos en memoria cambiarían los datos del padrón
				lAnioNac->insertar(new AnioNacimiento(anioActual, anNacAux1->getNPersonas()));
			enc = false;																					//Reinicia la bandera de posición
		}
	}
}

int GestorAnioNacimiento::alg7(int limInf, int limSup) {
	bool fin = false;																						//Bandera para salir de la lista una vez pasado el límite inferior. El resto de datos no pertenecerán al intervalo porque la lista están ordenada ascendentemente por años de nacimiento (descendentemente por edades)
	AnioNacimiento* anNacAux;																				//Puntero auxiliar para consultar la lista de años de nacimiento que encapsula el gestor
	int anioActual = 0;																						//Almacena la conversión de año de nacimiento a edad actual. Inicialmente es 0 por si se buscan recién nacidos y asegurarse de que el bucle se ejecuta una vez
	int cont = 0;																							//Acumulador para el número de personas pertenecientes al rango de edad dado
	time_t tiempoActual = time(NULL);																		//Obtiene el tiempo del sistema en ejecución
	tm* tiempoSis = localtime(&tiempoActual);																//Estructura para almacenar el tiempo del sistema en horas, minutos y segundos

	//Recorre secuencialmente la lista de años de nacimiento de inicio a fin. También comprueba si la lista está inicialmente vacía
	lAnioNacimiento->moverInicio();
	while(!lAnioNacimiento->finLista() && !fin){															//Como los años de nacimiento están ordenados ascendentemente por año de nacimiento (descendentemente por edad), en el momento en el que la edad sea inferior al límite inferior se deja de buscar
		lAnioNacimiento->consultar(anNacAux);
		lAnioNacimiento->avanzar();
		anioActual = tiempoSis->tm_year + 1900 - anNacAux->getAnio();										///Calcula la edad actual. @NOTA: tm_year comienza a contar desde 1900, por lo que hay que sumárselos
		if(anioActual >= limInf){																			//Comprueba si la edad pertenece al rango dado. Si es menor que el límite inferior se deja de buscar
			if(anioActual <= limSup)																		//Comprueba si el año de nacimiento actual pertenece al rango indicado
				cont += anNacAux->getNPersonas();															//Actualiza el contador con el número de personas de los años de nacimiento coincidentes
		}else{
			fin = true;																						//Actualización de la bandera para dejar de buscar
		}
	}

	return cont;
}



void GestorAnioNacimiento::mostrar() {																		///@NOTA: Muestra la información de todos los años de nacimiento de la lista
	AnioNacimiento* anNacAux;																				//Puntero auxiliar para recorrer la lista de años de de nacimiento que encapsula el gestor

	//Recorre secuencialmente la lista de años de nacimiento de inicio a fin
	lAnioNacimiento->moverInicio();
	while(!lAnioNacimiento->finLista()){																	//También comprueba si la lista está vacía inicialmente
		lAnioNacimiento->consultar(anNacAux);
		lAnioNacimiento->avanzar();
		anNacAux->mostrar();																				//Llama a mostrar la información de cada año de nacimiento
	}
}

}