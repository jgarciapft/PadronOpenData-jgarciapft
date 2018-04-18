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
using namespace std;

const char DELIM = ';';

/*
 * PRE: La cadena pasada por parámetros no debe estar vacía
 * POST: Divide la cadena Text en subcadenas en base al delimitador 'delim'. Las distintas subcadenas son proporcionadas en un vector
 * Ejemplo: "1958 (5); 1988 (3)" -> |1958 (5)| 1988 (3)|
 * COMPLEJIDAD: O(n)
 */
vector<string> splitStringToVector(string text, char delim);

/*
 * PRE:La cadena de caracteres pasada por parámetros no debe estar vacáa. Text puede contener distintos valores entre par�ntesis.
 * POST: Divide la cadena 'text' en subcadenas. Elimina los caracteres '(' y ')' y devuelve cada valor en una casilla del vector.
 * Ejemplo: "1958 (5)" -> |1958|5|
 * COMPLEJIDAD: O(n)
 */
vector<string> splitString(string text);




#endif /* UTILS_H_ */

