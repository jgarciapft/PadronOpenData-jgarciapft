//============================================================================
// Name        : Utils.h
// Author      : Profesores de la asignatura EDI
// Version     : Curso 17/18
// Copyright   :
// Description : Utilidades para trocear cadenas
//============================================================================

#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>

using namespace std;

/****************************************************** DEFINCIÓN DE CONSTANTES ******************************************************/

const string RUTA_BARRIO = "Barrio.csv"; 							//Ruta relativa del fichero que contiene la información de los barrios
const string RUTA_VIAS = "Via.csv"; 								//Ruta relativa del fichero que contiene la información de las vías
const string RUTA_PADRON = "InformacionPadron.csv";	 				//Ruta relativa del fichero que contiene la informacion del padrón (Año 2016)
const string RUTA_FIHCERO_PRUEBAS = "Pruebas.txt";					//Ruta relativa del fichero de volcado para la ejecución de las pruebas
const int N_CAMPOS_BARRIO = 2; 										//Número de campos del fichero de datos de barrios
const int N_CAMPOS_VIA = 5;											//Número de campos del fichero de datos de vías
const int N_CAMPOS_DATOS_DEMOGRAFICOS = 8;							//Número de campos del fichero de datos de datos demográficos (Contando el año del padron)
const char SEP = '#'; 												//Carácter separador de campos en los ficheros de datos
const char DELIM = ';';												//Carácter separador de campos para datos del fichero de información sobre el padrón
const string DEF_BARRIO = "BARRIO CONTENEDOR";						//Nombre del distrito del objeto 'Barrio' que incluye las vías que no tienen ningún barrio asignado
const string DEF_PLACEHOLDER = "";									//Nombre del distrito del objeto 'Barrio' que incluye las vías que no tienen ningún barrio asignado
const int RANGO_EDAD_ALG_4 = 10;									//Amplitud del intervalo de edad que usa el algorimto 4 para agrupar los años de nacimiento. Por defecto son décadas
const string POBLACION_TEXTO_RELLENO = "";							//Texto de relleno para el atributo 'poblacion' al crear nuevos objetos 'LugarNacimiento' aplicado al algoritmo 6
const string PROVINCIA_PAIS_TEXTO_RELLENO = "";						//Texto de relleno para el atributo 'provincia/pais' al crear nuevos objetos 'LugarNacimiento' aplicado al algoritmo 10
const char TECLA_MENU = 'm';										//Tecla para volver al menú de la interfaz del usuario

/****************************************************** DEFINCIÓN DE CONSTANTES ******************************************************/

/*
 * PRE: La cadena pasada por parámetros no debe estar vacía
 * POST: Divide la cadena Text en subcadenas en base al delimitador 'delim'. Las distintas subcadenas son proporcionadas en un vector
 * Ejemplo: "1958 (5); 1988 (3)" -> |1958 (5)| 1988 (3)|
 * COMPLEJIDAD: O(n)
 */
vector<string> splitStringToVector(string text, char delim);

/*
 * PRE:La cadena de caracteres pasada por parámetros no debe estar vacía. Text puede contener distintos valores entre par�ntesis.
 * POST: Divide la cadena 'text' en subcadenas. Elimina los caracteres '(' y ')' y devuelve cada valor en una casilla del vector.
 * Ejemplo: "1958 (5)" -> |1958|5|
 * COMPLEJIDAD: O(n)
 */
vector<string> splitString(string text);

std::string int_to_string(int n);

#endif /* UTILS_H_ */
