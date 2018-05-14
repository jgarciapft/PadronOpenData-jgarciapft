/*
 * GestorVia.cpp
 *
 *      Autor: jgarciapft
 */

#include "GestorVia.h"

namespace std {

GestorVia::GestorVia() {
	lVias = new ListaPI<Via*>();									//Reserva memoria para la lista de vías que encapsula
}

GestorVia::~GestorVia() {											//Libera la memoria asociada a cada vía y a la lista de vías que encapsula
	Via* vAux;														//Puntero auxiliar para consultar la lista de vías

	//Recorre secuencialmente de inicio a fin la lista de vías
	lVias->moverInicio();
	while(!lVias->finLista()){
		lVias->consultar(vAux);
		lVias->avanzar();
		delete vAux;												//Libera cada vía
	}
	delete lVias;													//Libera la lista de vías
}



void GestorVia::insertarViaOrden(Via* v) {
	bool enc = false;												//Bandera para indicar cuándo se ha encontrado la posición de la lista en la que insertar la vía
	Via* vAux;														//Puntero auxiliar para consultar la lista de vías

	//Recorre secuencialmente de inicio a fin la lista de vías
	lVias->moverInicio();
	while(!lVias->finLista() && !enc){
		lVias->consultar(vAux);
		if(*v > *vAux)
			enc = true;												//Actualiza la bandera que controla la salida del bucle cuando la vía a insertar es alfabéticamente mayor que la vía apuntada
		else
			lVias->avanzar();										//Solo avanzo si no se ha encontrado el hueco dónde insertar porque la vía se inserta delante del pI
	}
	lVias->insertar(v);												//Quedan manejados los casos: 1.Primer elemento de la lista, 2. Último elemento de la lista
	lVias->avanzar();
}

void GestorVia::insertarDatosDemograficos(DatosDemograficos* dD) {	//Busca si el dato demográfico pasado por parámetro 'dD' corresponde a alguna vía de esta lista y lo une a ella
	bool enc = false;												//Bandera para indicar cuando se ha encotrado (si se encuentra) la vía la que corresponde el parámetro 'dD'
	Via* vAux;														//Puntero auxiliar para consultar la lista de vías

	//Recorre secuencialmente de inicio a fin la lista de vías
	lVias->moverInicio();
	while(!lVias->finLista() && !enc){								//Cada vía es única en su barrio, y cada código de vía es único por vía, es decir, solo hay una vía con el mismo código por barrio
		lVias->consultar(vAux);
		lVias->avanzar();
		if(vAux->getCodVia() == dD->getCodVia()){
			vAux->setDatosDemograficos(dD);							//Se ha encontrado una vía cuyo código coincide con el del dato demográfico 'dD' y se une a esa vía
			enc = true;												//Actualiza la bandea que controla la salida del bucle cuando se encuentra la vía a la que pertenece el dato demográfico a unir
		}
	}
}

int GestorVia::alg7(int limInf, int limSup) {						///@NOTA: Nombre provisional
	Via* vAux;														//Puntero auxiliar para consultar la lista de vías
	int cont = 0;													//Acumulador para la suma del número de habitantes pertenecientes al rango dado por vía

	//Recorre secuencialmente de inicio a fin la lista de vías
	lVias->moverInicio();
	while (!lVias->finLista()){										//Comprueba que la lista contenga alguna vía
		lVias->consultar(vAux);
		lVias->avanzar();
		cont += vAux->alg7(limInf, limSup);							//Suma los habitantes que pertenecen al rango dado por cada vía a los que ya habían antes
	}

	return cont;
}

void GestorVia::alg8() {											///@NOTA: Nombre provisional
	ListaPI<Estudios*> *lEstud = new ListaPI<Estudios*>();			/* Lista en la que se almacenan los resultados del algoritmo. Cada nivel de estudios con el numero total de habitantes
 																	 * es representada por un objeto 'Estudios':
																	 *		El nivel se almacena en el atributo 'nivEstudios' y el número de personas en 'nPersonas' */
	ofstream ofs;													//Flujo de salida para volcar en un fichero los resultados del algoritmo
	string ruta = "NivelDeEstudios-";								//Ruta del fichero en el que se almacenan los resultados del algoritmo
	string extension  = ".txt";										//Extensión del fichero donde se vuelcan los resultados del algoritmo
	Via* vAux;														//Puntero auxiliar para consultar la lista de vías
	Estudios* estudAux;												//Puntero auxiliar para consultar la lista de 'lEstud'

	//Recorre secuencialmente de inicio a fin la lista de vías
	lVias->moverInicio();
	while (!lVias->finLista()){										//Comprueba que la lista contenga alguna vía
		lVias->consultar(vAux);
		lVias->avanzar();
		vAux->alg8(lEstud);											//Rellena la lista 'lEstud' con los datos de cada vía
	}

	//Vuelca a un fichero los resultados del algoritmo una vez completado
	ruta += vAux->getBarrioVia() + extension;						//Conforma la ruta del fichero
	ofs.open(ruta.c_str(), ios::app);								//Modo de apertura : adjutar. Añade a continuación de los contenidos previos los resultados de esta ejecución
	if(ofs.is_open()){												//Comprueba si se ha abierto el fichero correctamente
		if(!lEstud->estaVacia()){									//Comprueba si está vacía porque no se haya encontrado ningún dato que insertar
			ofs << endl << endl << "Nivel de estudios de los habitantes del barrio - " << vAux->getBarrioVia() << endl;
			ofs << "-----------------------------------------------------------------------------------------------" << endl;
			lEstud->moverInicio();
			while (!lEstud->finLista()){
				lEstud->consultar(estudAux);
				lEstud->avanzar();
				ofs << estudAux->getNivEstudios() << " (" << estudAux->getNPersonas() << ")" << endl;
			}
		}else{
			cout << "EL BARRIO ESTÁ VACÍO" << endl;					//Si está vacía lo indica por consola al usuario
		}
	}else{
		cout << "ERROR AL CREAR EL FICHERO PARA VOLCAR LOS RESULTADOS" << endl;
	}
	ofs.close();													//Cierra el flujo

	//Libera la memoria asociada a los nuevos estudios creados por el algoritmo 8
	lEstud->moverInicio();
	while(!lEstud->finLista()){										//Recorre secuencialmente la lista de estudios de inicio a fin
		lEstud->consultar(estudAux);
		lEstud->avanzar();
		delete estudAux;											//Libera cada estudio de la lista
	}
	delete lEstud;													//Libera la lista
}

void GestorVia::alg9(float& pHombres, float& pMujeres) {			///@NOTA: Nombre provisional
	Via* vAux;														//Puntero auxiliar para consultar la lista de vías que encapsula el gestor
	float nHombres = 0;												//Acumulador del número de hombres para el barrio que contiene este gestor de vías
	float nMujeres = 0;												//Acumulador del número de mujeres para el barrio que contiene este gestor de vías

	//Recorre secuencialmente de inicio a fin la lista de vías
	lVias->moverInicio();
	while (!lVias->finLista()){
		lVias->consultar(vAux);
		lVias->avanzar();
		vAux->alg9(nHombres, nMujeres);								//Por cada vía suma el número de hombres y mujeres de la actual a los anteriores
	}

	if(nHombres != 0){												//Comprueba que se hayan actualizado los acumuladores. Si están a 0 es porque no había ninguna via en la lista y hay que evitar una división por 0
		pHombres = nHombres / (nHombres + nMujeres);
		pMujeres = 1 - pHombres;									//'pHombres' y 'pMujeres' son mutuamente excluyentes y representan al total de la población
	}
}



void GestorVia::mostrarVias() {										//Muestra todas las vías de la lista. Utilizado por el algorimto 2
	Via* vAux;														//Puntero auxiliar para consultar la lista de vías

	//Recorre secuencialmente de inicio a fin la lista de vías
	lVias->moverInicio();
	while(!lVias->finLista()){
		lVias->consultar(vAux);
		lVias->avanzar();
		cout << "Via : " << vAux->getNombreVia() << " | Barrio : " << vAux->getBarrioVia() << " | Longitud : " <<
				vAux->getLongitudVia() << " | (m) Tipo : " << vAux->getTipoVia() << " | Codigo : " << vAux->getCodVia() << endl;
	}
}

void GestorVia::mostrar() {											//Llama a mostrar la información de cada vía
	Via* vAux;														//Puntero auxiliar para consultar la lista de vías

	//Recorre secuencialmente de inicio a fin la lista de vías
	lVias->moverInicio();
	while(!lVias->finLista()){
		lVias->consultar(vAux);
		lVias->avanzar();
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		vAux->mostrar();											//Muestra todos los datos de cada vía
		cout << "-----------------------------------------------------------------------------------------------" << endl;
	}
}

}

