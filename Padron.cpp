/*
 * Padron.cpp
 *
 *      Autor: jgarciapft
 */

#include "Padron.h"

namespace std {

/*** DEFINCIÓN DE CONSTANTES *** 										@NOTA: Pensar declaracion/inicializacion de constantes */
const string RUTA_BARRIO = "Barrio.csv"; 								//Ruta relativa del fichero que contiene la información de los barrios
const string RUTA_VIAS = "Via.csv"; 									//Ruta relativa del fichero que contiene la información de las vías
const string RUTA_DATOS_DEMOGRAFICOS = "InformacionPadron.csv";	 		//Ruta relativa del fichero que contiene la informacion del padrón (Año 2016)
const int N_CAMPOS_BARRIO = 2; 											//Número de campos del fichero de datos de barrios
const int N_CAMPOS_VIA = 5;												//Número de campos del fichero de datos de vías
const int N_CAMPOS_DATOS_DEMOGRAFICOS = 7;								//Número de campos del fichero de datos de datos demográficos
const char SEP = '#'; 													//Carácter separador de campos en los ficheros de datos
const string DEF_BARRIO = "BARRIO CONTENEDOR";							//Nombre del distrito del objeto barrio que incluirá las vías que no tienen ningún barrio asignado

Padron::Padron() {
	gBarrio = new GestorBarrio();
	lDatDemograficos = new ListaPI<DatosDemograficos*>();
	lVias = new ListaPI<Via*>();
}

Padron::~Padron() {
	delete lDatDemograficos;											//Libera los nodos de la lista de datos demográficos auxiliar, pero no los los datos demográficos
	delete lVias;														//Libera los nodos de la lista de vías auxiliar, pero no las vías
	delete gBarrio;														//Desencadena los destructores de toda la estructura de datos, liberando el espacio reservado para todos los datos
}

void Padron::cargarBarrios() {
	fstream fEnt;
	string campos[N_CAMPOS_BARRIO];

	fEnt.open(RUTA_BARRIO.c_str(), ios::in);
	if(fEnt.is_open()){
		getline(fEnt, campos[0]); 										//Salta la cabecera
		while(!fEnt.eof()){
			getline(fEnt, campos[0], SEP); 								//Lee el nombre del barrio
			getline(fEnt, campos[1]);									//Lee el nombre del distrito
			if(!fEnt.eof())												//Doble comprobación del FINAL DE FICHERO
				gBarrio->insertar(new Barrio(campos[0], campos[1]));
		}
	}
	gBarrio->insertar(new Barrio("", DEF_BARRIO));						//Barrio que contendrá las vías que no tengan ningún barrio asignado

	fEnt.close();
}

void Padron::cargarVias() {
	fstream fEnt;
	string campos[N_CAMPOS_VIA];
	Via* vAux;															//Puntero a objeto 'Via' auxiliar para almacenar la vía recién creada en la lista auxiliar y en su(s) barrio(s) correspondientes

	fEnt.open(RUTA_VIAS.c_str());
	if(fEnt.is_open()){
		getline(fEnt, campos[0]); 										//Salta la cabecera
		while(!fEnt.eof()){
			for(int i=0; i<N_CAMPOS_VIA-1; i++){						//Lee todos los campos de cada vía menos el último
				getline(fEnt, campos[i], SEP);
			}
			getline(fEnt, campos[4]);									//Lee el último campo
			if(!fEnt.eof()){											//Doble comprobación del FINAL DE FICHERO
				vAux = new Via(campos[0], campos[1], atof(campos[2].c_str()), campos[3], atoi(campos[4].c_str()));
				lVias->insertar(vAux);									//Insertar la via recien creada en la lista auxiliar de todas las vías
				lVias->avanzar();
				gBarrio->insertarVia(vAux);
			}
		}
	}

	fEnt.close();
}

void Padron::cargarDatosDemograficos() {
	fstream fEnt;
	string campos[N_CAMPOS_DATOS_DEMOGRAFICOS];
	DatosDemograficos* dD;												//Puntero a objeto 'DatosDemograficos' auxiliar para almacenar el dato recién creado en la lista auxiliar y en su vía correspondiente

	fEnt.open(RUTA_DATOS_DEMOGRAFICOS.c_str(), ios::in);
	if(fEnt.is_open()){
		getline(fEnt, campos[0]); 										//Salta la cabecera
		while(!fEnt.eof()){
			for(int i=0; i<N_CAMPOS_DATOS_DEMOGRAFICOS-1; i++){			//Lee todos los campos de cada dato menos el último
				getline(fEnt, campos[i], SEP);
			}
			getline(fEnt, campos[6]);									//Lee el último campo
			if(!fEnt.eof()){											//Doble comprobación del FINAL DE FICHERO
				dD = new DatosDemograficos(atoi(campos[0].c_str()), campos[1], campos[2], campos[3], atoi(campos[4].c_str()),
							atoi(campos[5].c_str()), campos[6]);
				lDatDemograficos->insertar(dD);
				lDatDemograficos->avanzar();
				gBarrio->insertarDatosDemograficos(dD);
			}
		}
	}

	fEnt.close();
}

void Padron::alg2(string nB) {											//@NOTA: Nombre provisional
	gBarrio->alg2(nB);
}

void Padron::alg6() {													//@NOTA: Nombre provisional
	GestorLugarNacimiento* gLugNacimiento = new GestorLugarNacimiento();//Gestor auxiliar para manejar la lista ordenada de provincias
	DatosDemograficos* dD;

	lDatDemograficos->moverInicio();
	while(!lDatDemograficos->finLista()){
		lDatDemograficos->consultar(dD);
		lDatDemograficos->avanzar();
		dD->alg6(gLugNacimiento);
	}
	gLugNacimiento->mostrarAlg6();

	delete gLugNacimiento;
}

void Padron::alg3() {
	bool primerRes = true;												//Bandera que controla la impresión de la cabecera de para una vía que atraviese varios barrios
	bool coincidencia = false;											//Bandera que verifica que no se haya procesado previamente la vía actual
	Via* vAux1;
	Via* vAux2;
	string test;
	ListaPI<string> lCoincidencias;										//Lista de vías que ya han sido procesadas

	lVias->moverInicio();
	while(!lVias->finLista()){											//Bucle externo: Lee secuencialmente todas las vías
		lVias->consultar(vAux1);
		lVias->avanzar();
		lCoincidencias.moverInicio();
		while(!lCoincidencias.finLista() && !coincidencia){				//Antes de entrar al bucle interno hay que comprobar que no hayamos procesado ya la vía
			lCoincidencias.consultar(test);
			lCoincidencias.avanzar();
			if(vAux1->getNombreVia() == test)
				coincidencia = true;
		}
		if(!coincidencia){
			while(!lVias->finLista()){									//Bucle interno: Para cada vía seleccionada por el bucle externo procesa todas las siguientes, ya que no podemos asumir el número máximo de ocurrencias
				lVias->consultar(vAux2);
				lVias->avanzar();
				if(vAux1->getNombreVia() == vAux2->getNombreVia()){
					if(primerRes){										//Imprime la cabecera de una vía que atraviesa barios barrios
						cout << "Vía : " << vAux1->getNombreVia() << endl;
						cout << "***********************************************************************************************" << endl;
						cout << "Barrios que atraviesa : " << endl << endl;
						cout << vAux1->getBarrioVia() << endl;
						lCoincidencias.insertar(vAux1->getNombreVia());	//Añade la vía a la lista de vías procesadas una sola vez, la primera vez que encuentre un duplicado
						primerRes = false;
					}
					cout << vAux2->getBarrioVia() << endl;				//Para el resto de vías simplemente imprime el nombre de su barrio
				}
			}
			if(!primerRes)												//Solo imprime el footer si ha habido alguna coincidencia
				cout << "***********************************************************************************************" << endl;
			lVias->moverInicio();
			/*El uso de la estructura 'do while' se justifica porque al final de cada ejecución del bucle interno el pI siempre apuntará a NULL
			 *		porque hay que recorrer el resto de la lista entera, no podemos suponer el número de barrios por los que pasará una vía.
			 *		Moviendo el pI al inicio y consultándolo antes de hacer la comprobación nos libra de comprobar la certeza de que 'vAux1' nunca será NULL
			 */
			do{
				lVias->consultar(vAux2);
				lVias->avanzar();
			}while(vAux1 != vAux2);
			primerRes = true; 											//Solo tiene efecto si hubo alguna coincidencia de vías
		}
		coincidencia = false;											//Solo tiene efecto si hubo alguna coincidencia con alguna vía ya tratada, y pueda volver a tratar otra vía
	}
}

void Padron::mostrarEstructura() {										//@TEST: Muestra toda la estructura de datos cargada y las estructuras auxiliares
	Via* vAux;
	DatosDemograficos* dD;

	gBarrio->mostrar();													//@TEST: Muestra toda la estructura de datos cargada

	cout << "LISTA DE VÍAS AUXILIAR" << endl;							//@TEST: Muestra la lista auxiliar de todas las vías
	cout << "***********************************************************************************************" << endl;
	lVias->moverInicio();
	while(!lVias->finLista()){
		lVias->consultar(vAux);
		lVias->avanzar();
		cout << "Via : " << vAux->getNombreVia() << " | Barrio : " << vAux->getBarrioVia() << " | Longitud : " <<
					vAux->getLongitudVia() << " | (m) Tipo : " << vAux->getTipoVia() << " | Codigo : " << vAux->getCodVia() << endl;	//@NOTA: No muestra los datos demográficos
	}
	cout << "***********************************************************************************************" << endl;

	cout << "LISTA DE DATOS DEMOGRÁFICOS AUXILIAR" << endl << endl;		//@TEST: Muestra la lista auxiliar de todos los datos demograficos auxiliares
	cout << "***********************************************************************************************" << endl;
	lDatDemograficos->moverInicio();
	while(!lDatDemograficos->finLista()){
		lDatDemograficos->consultar(dD);
		lDatDemograficos->avanzar();
		dD->mostrar();
	}
	cout << "***********************************************************************************************" << endl;

}

}
