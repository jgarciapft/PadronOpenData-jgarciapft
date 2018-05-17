/*
 * PLACEHOLDER
 */

#ifndef PRUEBAS_H
#define PRUEBAS_H

#include "UI.h"
#include "Padron.h"
#include "timer.h"

using namespace std;

class Pruebas {

private:
	Padron p;
	ofstream salidaPruebas;

private:
	/**@PRUEBA: SOBRECARGAR DE OPERADORES
	 * CLASE : Via
	 * 		*v1   >   *v1   ->  FALSE
	 * 		*v1   >   *v2   ->  FALSE
	 * 		*v2	  >   *v1   ->  TRUE
	 *
	 * CLASE : ComparadorPtrVia
	 *		v1   operator()   v1   ->	0
	 *		v1	 operator()	  v2   ->   1
	 *		v2	 operator()   v1   ->  -1
	 *
	 * CLASE : Lugar Nacimiento
	 *		lugNac1   >=   lugNac1   ->  TRUE
	 *		lugNac1   >=   lugNac2   ->  FALSE
	 *		lugNac2   >=   lugNac1   ->  TRUE
	 *
	 *		lugNac1   ==   lugNac1   ->  TRUE
	 *		lugNac1   ==   lugNac2   ->  FALSE
	 *		lugNac1   ==   lugNac3   ->  TRUE
	 *
	 * CLASE : Estudios
	 *		est1   >   est1   ->  FALSE
	 *		est1   >   est2   ->  FALSE
	 *		est2   >   est1   ->  TRUE
	 *
	 *		est1   ==  est1   ->  TRUE
	 *		est1   ==  est2   ->  FALSE
	 *		est1   ==  est3   ->  TRUE
	 *
	 * CLASE : Nacionalidad
	 * 		nacion1   >   nacion1   ->  FALSE
	 * 		nacion1   >   nacion2   ->  FALSE
	 * 		nacion2   >   nacion1   ->  TRUE
	 * 		
	 * 		nacion1   ==  nacion1   ->  TRUE
	 *		nacion1   ==  nacion2   ->  FALSE
	 *		nacion1   ==  nacion3   ->  TRUE
	 */
	void pruebaSobrecargaOperadores();

	/**@PRUEBA: INTERFZA DE USUARIO(UI)
	 *
	 * Comprobaciones por parte del usuario:
	 * 		1. Solo se puede ejecutar un algoritmo si antes se han cargado
	 * 			los datos del padrón, de vías y de barrios (Algoritmo 1)
	 * 		2. Solo se pueden cargar una vez los datos (Algoritmo 1)
	 */
	void pruebaUI();

	/**@PRUEBA: EJECUCIÓN SECUENCIAL DE TODOS LOS ALGORITMOS DEL PROTECTO
	 *
	 * Ejecución secuencial de todos los algoritmos del proyecto con parámetros de entrada predefinidos. Consituye una
	 * 	prueba de integración entre las distintas partes del programa:
	 * 		-Muestra los tiempos de ejecución para cada algoritmo
	 * 		-Para los algoritmos con dos implementaciones, una en EDL y otra en EDNL, se ejecutan 'nRep' veces cada una
	 * 			mostrando los tiempos parciales y el tiempo promedio
	 *
	 * 	En el fichero 'ruta' del sistema de archivos en el que se ejecuta el proyecto se vuelca una tabla con los tiempos
	 * 		de ejución calculados
	 */
	void pruebaEjecucionSecuencial();
public:
	Pruebas();
	~Pruebas();

	void ejecutarPruebas();
};

#endif /* PADRONOPENDATA_JGARCIAPFT_PRUEBAS_H */
