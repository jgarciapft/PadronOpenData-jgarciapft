/*
 * Padron.cpp
 *
 *      Autor: jgarciapft
 */

#include "Padron.h"

namespace std {

/*** DEFINCIÓN DE CONSTANTES *** @NOTA: Pensar declaracion/inicializacion de constantes */
const string RUTA_BARRIO = "Barrio.csv"; 						//Ruta relativa del fichero que contiene la información de los barrios
const string RUTA_VIAS = "Via.csv"; 							//Ruta relativa del fichero que contiene la información de las vías
const string RUTA_DATOS_DEMOGRAFICOS = "InformacionPadron.csv"; //Ruta relativa del fichero que contiene la informacion del padrón (Año 2016)
const int N_CAMPOS_BARRIO = 2; 									//Número de campos del fichero de datos de barrios
const int N_CAMPOS_VIA = 5;										//Número de campos del fichero de datos de vías
const int N_CAMPOS_DATOS_DEMOGRAFICOS = 7;						//Número de campos del fichero de datos de datos demográficos
const char SEP = '#'; 											//Carácter separador de campos en los ficheros de datos
const string DEF_BARRIO = "BARRIO CONTENEDOR";					//Nombre del distrito del objeto barrio que incluirá las vías que no tienen ningún barrio asignado

Padron::Padron() {
	gBarrio = new GestorBarrio();
	lDatDemograficos = new ListaPI<DatosDemograficos*>();
	lVias = new ListaPI<Via*>();
}

Padron::~Padron() {
	delete lDatDemograficos;
	delete lVias;
}

void Padron::cargarBarrios() {
	fstream fEnt;
	string campos[N_CAMPOS_BARRIO];

	fEnt.open(RUTA_BARRIO.c_str(), ios::in);
	if(fEnt.is_open()){
		getline(fEnt, campos[0]); 							//Salta la cabecera
		while(!fEnt.eof()){
			getline(fEnt, campos[0], SEP); 					//Lee el nombre del barrio
			getline(fEnt, campos[1]);						//Lee el nombre del distrito
			if(!fEnt.eof())									//Doble comprobación del FINAL DE FICHERO
				gBarrio->insertar(new Barrio(campos[0], campos[1]));
		}
	}
	gBarrio->insertar(new Barrio("", DEF_BARRIO));			//Barrio que contendrá las vías que no tengan ningún barrio asignado

	fEnt.close();
}

void Padron::cargarVias() {
	fstream fEnt;
	string campos[N_CAMPOS_VIA];
	Via* vAux;												//Puntero a objeto 'Via' auxiliar para almacenar la vía recién creada en la lista auxiliar y en su(s) barrio(s) correspondientes

	fEnt.open(RUTA_VIAS.c_str());
	if(fEnt.is_open()){
		getline(fEnt, campos[0]); 							//Salta la cabecera
		while(!fEnt.eof()){
			for(int i=0; i<N_CAMPOS_VIA-1; i++){			//Lee todos los campos de cada vía menos el último
				getline(fEnt, campos[i], SEP);
			}
			getline(fEnt, campos[4]);						//Lee el último campo
			if(!fEnt.eof()){								//Doble comprobación del FINAL DE FICHERO
				vAux = new Via(campos[0], campos[1], atof(campos[2].c_str()), campos[3], atoi(campos[4].c_str()));
				lVias->insertar(vAux);						//Insertar la via recien creada en la lista auxiliar de todas las vías
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
	DatosDemograficos* dD;										//Puntero a objeto 'DatosDemograficos' auxiliar para almacenar el dato recién creado en la lista auxiliar y en su vía correspondiente

	fEnt.open(RUTA_DATOS_DEMOGRAFICOS.c_str(), ios::in);
	if(fEnt.is_open()){
		getline(fEnt, campos[0]); 								//Salta la cabecera
		while(!fEnt.eof()){
			for(int i=0; i<N_CAMPOS_DATOS_DEMOGRAFICOS-1; i++){	//Lee todos los campos de cada dato menos el último
				getline(fEnt, campos[i], SEP);
			}
			getline(fEnt, campos[6]);							//Lee el último campo
			if(!fEnt.eof()){									//Doble comprobación del FINAL DE FICHERO
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

void Padron::alg2(string nB) {												//@NOTA: Nombre provisional
	gBarrio->alg2(nB);
}

void Padron::alg6() {														//@NOTA: Nombre provisional
	GestorLugarNacimiento* gLugNacimiento = new GestorLugarNacimiento();	//Gestor auxiliar para manejar la lista ordenada de provincias
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
}

void Padron::mostrarEstructura() {											//@TEST: Muestra toda la estructura de datos cargada y las estructuras auxiliares
	Via* vAux;
	DatosDemograficos* dD;

	gBarrio->mostrar();														//@TEST: Muestra toda la estructura de datos cargada

	cout << "LISTA DE VÍAS AUXILIAR" << endl << endl;						//@TEST: Muestra la lista auxiliar de todas las vías
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
