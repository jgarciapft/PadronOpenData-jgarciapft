/**
 * @brief
 * 		Extensión del espacio de nombres estándar 'std' con las constantes que definen el comportamiento de todas las clases
 * 			y algoritmos (excepto las pruebas) y métodos auxiliares de tratamiento de cadenas.
 */

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

/**
 * @brief
 * 		Método auxiliar de cadenas para separar todos los campos que definen una entidad
 *
 * @param text
 * 		Cadena a tratar
 * @param delim
 * 		Carácter delimitador de entidades
 *
 * @pre: La cadena pasada por parámetros no debe estar vacía
 * @post: Divide la cadena Text en subcadenas en base al delimitador 'delim'. Las distintas subcadenas son proporcionadas en un vector
 * 		Ejemplo: "1958 (5); 1988 (3)" -> |1958 (5)| 1988 (3)|
 * @complejidad: O(n)
 *
 * @return
 * 		Vector de cadenas que representan todos los campos de una entidad
 */
vector<string> splitStringToVector(string text, char delim);

/**
 * @brief
 * 		Método auxiliar de cadenas para separar cada campo que define una entidad
 *
 * @param text
 * 		Cadena a tratar con los campos de una sola entidad
 *
 * @pre:La cadena de caracteres pasada por parámetros no debe estar vacía. Text puede contener distintos valores entre paréntesis.
 * @post: Divide la cadena 'text' en subcadenas. Elimina los caracteres '(' y ')' y devuelve cada valor en una casilla del vector.
 * 		Ejemplo: "1958 (5)" -> |1958|5|
 * @complejidad: O(n)
 *
 * @return
 * 		Vector de cadenas que representa cada campo de una sola entidad
 */
vector<string> splitString(string text);

/**
 * @brief
 * 		Método auxiliar para convertir un número a cadena
 *
 * @param n
 * 		Número a convertir
 *
 * @pre:
 * @post: Devuelve una cadena con la conversión del número \param n a cadena. Utiliza un flujo de salida de cadenas para la
 * 			conversión
 * @complejidad: O(1)
 *
 * @return
 * 		Cadena con la conversión
 */
std::string int_to_string(int n);

#endif /* UTILS_H_ */
