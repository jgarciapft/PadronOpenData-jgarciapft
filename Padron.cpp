/*
 * Padron.cpp
 *
 *      Autor: jgarciapft
 */

#include "Padron.h"

namespace std {

/*** DEFINCIÓN DE CONSTANTES ***/ //@NOTA: Pensar declaracion/inicializacion de constantes
const string RUTA_BARRIO = "Barrio.csv"; 						//Ruta relativa del fichero que contiene la información de los barrios
const string RUTA_VIAS = "Via.csv"; 							//Ruta relativa del fichero que contiene la información de las vías
const string RUTA_DATOS_DEMOGRAFICOS = "InformacionPadron.csv"; //Ruta relativa del fichero que contiene la informacion del padrón (Año 2016)
const int N_CAMPOS_BARRIO = 2; 									//Número de campos del fichero de datos de barrios
const int N_CAMPOS_VIA = 5;										//Número de campos del fichero de datos de vías
const int N_CAMPOS_DATOS_DEMOGRAFICOS = 7;						//Número de campos del fichero de datos de datos demográficos
const char SEP = '#'; 											//Carácter separador de campos en los ficheros de datos
const string DEF_BARRIO = "BARRIO CONTENEDOR";					//Nombre del barrio que incluirá las vías que no tienen ningún barrio asignado

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
	gBarrio->insertar(new Barrio(DEF_BARRIO, ""));			//Barrio que contendrá las vías que no tengan ningún barrio asignado
	//gBarrio->mostrar();									//@TEST: Muestra los barrios en el orden de inserción
	fEnt.close();
}

void Padron::cargarVias() {
	fstream fEnt;
	string campos[N_CAMPOS_VIA];
	Via* vAux;												//Puntero a objeto 'Via' auxiliar para almacenar la vía recién creada en la lista auxiliar y su(s) barrio(s) correspondientes

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
	gBarrio->mostrar();										//@TEST: Muestra todas las vias de todos los barrios
	fEnt.close();
}

}
