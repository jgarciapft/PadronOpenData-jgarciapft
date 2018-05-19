/**
 *	@CLASE: Pruebas
 *
 *	@brief
 *		Coordina la implementación de las pruebas del proyecto.
 *		Maneja el flujo de salida de volcado de las pruebas y la salida por consola visible al usuario
 *
 *	@atributo p
 *		Instancia de la clase principal para incluir toda la implementación del proyecto
 *	@atributo salidaPruebas
 *		Flujo de salida para el volcado de los resultados de las pruebas. La ruta del fichero está
 *			especificada en \constante RUTA_FICEHRO_PRUEBAS
 *	@atributo bufferSalidaConsola
 *		Almacena el buffer de consola para restaurarlo al final de las pruebas
 */

#ifndef PRUEBAS_H_
#define PRUEBAS_H_

#include "ui.h"
#include "timer.h"

///@TEST: Inclusiones de pruebas
#include "MetodosAuxiliares.h"

namespace pruebas{

class Pruebas {

private:
	Padron p;
	streambuf* bufferSalidaConsola;
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
	 * 		*v1   >   *v2   ->  TRUE
	 * 		*v2	  >   *v1   ->  FALSE
	 *
	 * @CLASE : ComparadorPtrVia
	 *		v1   operator()   v1   ->	0
	 *		v1	 operator()	  v2   ->  -1
	 *		v2	 operator()   v1   ->   1
	 *		v1   operator()   v3   ->  -1
	 *		v3   operator()   v1   ->   1
	 *
	 * @CLASE : Lugar Nacimiento
	 *		lugNac1   >=   lugNac1   ->  TRUE
	 *		lugNac1   >=   lugNac2   ->  TRUE
	 *		lugNac2   >=   lugNac1   ->  FALSE
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
	 * 			2.1 v3 es alfabéticamente mayor que el elemento en lVias  									   ->   v1 se inserta en primera posición (ViaA, ViaB)
	 * 			2.2 v3 es alfabéticamente menor que el elemento en lVias   									   ->   v1 se inserta en última posición  (ViaB, ViaD)
	 * 		3. lVias contiene 3 elementos
	 * 			3.1 Si la inserción en primer y último lugar funciona para una vía   						   ->   Funciona para cualquier número de vías
	 * 			3.2 v3 es alfabéticamente menor que el primer elemento y alfabéticamente mayor que el último   ->   v1 se inserta en la posición 2 (ViaB, ViaC, ViaD)
	 *
	 * @MÉTODO : Padron::alg11
	 * 		1. La vía 'nombreVia' está en el ABB
	 * 			1.1 La vía 'nombreVia' tiene 1 tramo			->   enc = true
	 * 			1.2 La vía 'nombreVia' tiene más de 1 tramo	    ->   Cada tramo de vía contiene todos los datos demográficos de todos los tramos. Encontrar 1 tramo es suficiente
	 * 		2.  La vía 'nombreVia' no está en el ABB   			->   enc = false
	 *
	 * @MÉTODO : Padron::alg12
	 * 		1. Ninguna vía comienza por la raíz	'raiz'		   ->  ABB == NULL. Se indica al usuario por consola que no se ha encontrado
	 * 		2. Existe 1 vía que comienza por la raíz 'raiz'    ->  Se devuelve el subárbol (ABB :Plaza->NULL
	 * 																								  ->Plaza)
	 * 		3. Deductivamente si el algoritmo sirve para 1 vía ->  Sirve para 'n' vías
	 *
	 * @MÉTODO : Padron::filtroInOrden
	 * 		1. 1 vía comienza por la raíz 'raiz'   				->   enc = true
	 * 		2. Deductivamente si el algoritmo sirve para 1 vía	->   Sirve para 'n' vías
	 */
	void pruebaMetodosAuxiliares();
	void pruebaOrdenLista();
	void pruebaInsertarVia();
	void pruebaInsertarViaOrden();
	void pruebaAlg11();
	void pruebaAlg12();
	void pruebaFiltroInOrden();

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

	/**@PRUEBA	Validación de la carga de datos. Datos: \SET_DATOS SetDatos_1
	 * 				-Un fichero con los BARRIOS. 			RUTA_BARRIO (\constante RUTA_BARRIO_ALG_1)
	 * 				-Un fichero con las VÍAS.				RUTA_VIA	(\constante RUTA_VIA_ALG_1)
	 * 				-Un fichero con los datos del PADRON.	RUTA_PADRON	(\constante RUTA_PADRON_ALG_1)
	 *
	 * @ESTRUCTURA: Lista de barrios que encapsula la clase 'GestorBarrio'
	 * 			1. Existe el fichero RUTA_BARRIO								->	\return = true
	 * 				1.1 'lBarrios' contiene 4 barrios (3 + barrio contenedor)	->	cont = 4
	 * 			2. No existe el fichero RUTA_BARRIO								->	\return = false
	 *
	 * @ESTRUCTURA: Lista de vías auxiliar 'lVias' en la clase 'Padron'
	 *  		1. Existe el fichero RUTA_VIA				->	\return = tru
	 *  			1.1 Validación por conteo de objetos	->	cont = 5
	 *  		2. No existe el fichero RUTA_VIA			->	\return = false
	 *
	 * @ESTRUCTURA: ABB de vías auxiliar 'aVias' en la clase 'Padron'
	 *  		1. Deductivamente si los métodos auxiliares son correctos y si se carga correctamente 'lVias': 'aVias' también es correcto
	 *
	 * @ESTRUCTURA: Lista de datos demográficos auxiliar 'lDatDemograficos' en la clase 'Padron'
	 *  		1. Existe el fichero RUTA_PADRON			->	\return = true
	 *  			1.1 Validación por conteo de objetos	->	cont = 3
	 *  		2. No existe el fichero RUTA_PADRON			->  \return = false
	 *
	 * @ESTRUCTURA: Estructura de datos según en diagrama UML a partir de 'gBarrio' en la clase 'Padron'
	 * 			1. El barrio 'BarrioA' contiene 1 vía 						->	ViaA
	 * 			2. El barrio 'BarrioB' contiene más de 1 vía 				-> 	Deductivamente si el algoritmo sirve para 1 vía, sirve para 'n' vías
	 * 			3. El barrio contenedor contiene una vía					->	ViaContenedor
	 * 			4. La vía 'ViaA' no contiene un set de datos demográficos	->	No se muestra nada
	 * 			5. La vía 'ViaB' contiene un set de datos demográficos		->	[AñoNacB, LugNacB, EstudB, NacionB]
	 * 			6. Los barrios 'BarrioB' y 'BarrioC' comparten la vía 'ViaB'->	Ambos tramos de vía deben compartir set de datos demográficos
	 */
	void pruebaAlg1();
	void pruebaEstructuraLBarrios(GestorBarrio& gBarrio, int& cont, string ruta);
	void pruebaEstructuraLVias(GestorBarrio& gBarrio, int& cont, string ruta);
	void pruebaEstructuraLDatDem(GestorBarrio& gBarrio, int& cont, string ruta, ListaPI<DatosDemograficos*>& lDatDem);
	void pruebaEstructuraGBarrio(GestorBarrio& gBarrio);

	/**@PRUEBA: Validación del Algoritmo 2. Datos: \SET_DATOS SET_ESTANDAR
	 *
	 * 1. Barrio 'Vera Cruz' existe		  ->   Se muestran 3 VIAS
	 * 2. Barrio 'OtroBarrio' no existe   ->   Se indica que no se ha encontrado el barrio 'OtroBarrio'
	 */
	void pruebaAlg2();

	/**
	 * @NOTA: Método invocativo para llamar a todas las pruebas de todos los algoritmos
	 */
	void pruebaAlgoritmos();

public:
	Pruebas();
	~Pruebas();

	void ejecutarPruebas();
};

}

#endif /* PRUEBAS_H_ */
