/*
 * PLACEHOLDER
 */

#ifndef PRUEBAS_H_
#define PRUEBAS_H_

#include "ui.h"
#include "timer.h"

///@TEST: Includes de prueba de clases
#include "MetodosAuxiliares.h"

namespace pruebas{

class Pruebas {

private:
	Padron p;

public:
	ofstream salidaPruebas;

private:
	/**\@PRUEBA: Utilidades de cadenas
	 *
	 *	Invoca las pruebas ya implementadas en el proyecto base de las utilidades de cadenas
	 */
	void pruebaUtils();

	/**@PRUEBA: SOBRECARGA DE OPERADORES
	 *
	 * @CLASE : Via
	 * 		*v1   >   *v1   ->  FALSE
	 * 		*v1   >   *v2   ->  FALSE
	 * 		*v2	  >   *v1   ->  TRUE
	 *
	 * @CLASE : ComparadorPtrVia
	 *		v1   operator()   v1   ->	0
	 *		v1	 operator()	  v2   ->   1
	 *		v2	 operator()   v1   ->  -1
	 *
	 * @CLASE : Lugar Nacimiento
	 *		lugNac1   >=   lugNac1   ->  TRUE
	 *		lugNac1   >=   lugNac2   ->  FALSE
	 *		lugNac2   >=   lugNac1   ->  TRUE
	 *
	 *		lugNac1   ==   lugNac1   ->  TRUE
	 *		lugNac1   ==   lugNac2   ->  FALSE
	 *		lugNac1   ==   lugNac3   ->  TRUE
	 *
	 * @CLASE : Estudios
	 *		est1   >   est1   ->  FALSE
	 *		est1   >   est2   ->  FALSE
	 *		est2   >   est1   ->  TRUE
	 *
	 *		est1   ==  est1   ->  TRUE
	 *		est1   ==  est2   ->  FALSE
	 *		est1   ==  est3   ->  TRUE
	 *
	 * @CLASE : Nacionalidad
	 * 		nacion1   >   nacion1   ->  FALSE
	 * 		nacion1   >   nacion2   ->  FALSE
	 * 		nacion2   >   nacion1   ->  TRUE
	 *
	 * 		nacion1   ==  nacion1   ->  TRUE
	 *		nacion1   ==  nacion2   ->  FALSE
	 *		nacion1   ==  nacion3   ->  TRUE
	 */
	void pruebaSobrecargaOperadores();

	/**@PRUEBA: MÉTODOS AUXILIARES
	 *
	 *@MÉTODO : GestorNacionalidad::ordenarLista y GestorEstudios::ordenarLista
	 * 		1. lVias vacía 						  	 ->   No hace nada
	 * 		2. lVias con 1 elemento				  	 ->   No la modifica
	 * 		3. lVias con 4 elementos ordenados	  	 ->   No la modifica
	 * 		4. lVias con 5 elementos desordenados	 ->   Queda ordenada descendentemente por número de habitantes (NacionalidadE, NacionalidadA,
	 * 														NacionalidadB, NacionalidadC, NacionalidadD)
	 *
	 * @MÉTODO : GestorBarrio::insertarVia
	 * 		1. v1 está en lBarrios      ->   v1 se inserta al final de lBarrios
	 * 		2. v2 no está en lBarrios   ->   v2 no inserta
	 *
	 * @MÉTODO : GestorVia::insertarViaOrden
	 * 		1. lVias vacía   																				   ->   Se inserta v1 sin ningún orden (ViaB)
	 * 		2. lVias contiene 1 elemento
	 * 			2.1 v3 es alfabéticamente mayor que el elemento en lVias  									   ->   v3 se inserta en primera posición (ViaA, ViaB)
	 * 			2.2 v3 es alfabéticamente menor que el elemento en lVias   									   ->   v3 se inserta en última posición  (ViaB, ViaD)
	 * 		3. lVias contiene 3 elementos
	 * 			3.1 Si la inserción en primer y último lugar funciona para una vía   						   ->   Funciona para cualquier número de vías
	 * 			3.2 v3 es alfabéticamente menor que el primer elemento y alfabéticamente mayor que el último   ->   v3 se inserta en la posición 2 (ViaB, ViaC, ViaD)
	 *
	 * @MÉTODO : Padron::alg11
	 * 		1. El nombre de la vía v4 está en el ABB
	 * 			1.1 v4 tiene 1 tramo				  ->   No se buscan más tramos en el subárbol izquierdo
	 * 			1.2 v4 tiene más de 1 tramo			  ->   Se buscan más tramos en el subárbol izquierdo (1 tramo más)
	 * 		2. v4 v1 no está en el ABB   			  ->   Se indica al usuario por consola que se ha encontrado
	 *
	 * @MÉTODO : Padron::alg12
	 * 		1. Ninguna vía comienza por la raíz				   ->  Se indica al usuario por consola que no se ha encontrado
	 * 		2. Existe al menos 1 vía que comienza por la raíz  ->  Se devuelve el subárbol
	 * 		3. Deductivamente si el algoritmo sirve para 1 vía ->  Sirve para todas
	 *
	 * @MÉTODO : Padron::filtroInOrden
	 * 		1. Al menos 1 vía comienza por la raíz   ->   Calcula el número de habitantes para la provincia dada
	 */
	void pruebaMetodosAuxiliares();

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

}

#endif /* PADRONOPENDATA_JGARCIAPFT_PRUEBAS_H_ */
