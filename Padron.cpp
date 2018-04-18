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
const char SEP = '#'; 											//Carácter separador de campos en los ficheros de datos

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
	string cad[N_CAMPOS_BARRIO];

	fEnt.open(RUTA_BARRIO.c_str(), ios::in);
	if(fEnt.is_open()){
		getline(fEnt, cad[0]); 								//Salta la cabecera
		while(!fEnt.eof()){
			getline(fEnt, cad[0], SEP); 					//Lee el nombre del barrio
			getline(fEnt, cad[1]);							//Lee el nombre del distrito
			gBarrio->insertar(new Barrio(cad[0], cad[1]));
		}
	}
	gBarrio->mostrar();										//@TEST: Muestra los barrios en el orden de inserción
}

}
