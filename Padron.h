/**
 * @CLASE: Padron
 *
 * @brief
 * 		Almacena la jerarquia de la estructura de datos y provee una interfaz a la clase UI para ejecutar los algoritmos
 * 			del proyecto a partir de la entrada del usuario por la entrada estandar (cin). También maneja la reserva/liberación de la
 * 			memoria asociada a toda la estructura
 *
 * @atributo gBarrio
 * 		Instancia de la clase gestora de la lista de barrios 'GestorBarrio' y, por tanto, de toda la jerarquía de datos
 * @atributo lVias
 * 		Lista de vías auxiliar para almacenar todas las vías creadas a partir de los ficheros de datos
 * @atributo aVias
 * 		ABB de vías auxiliar para almacenar para la implementación de los algoritmos 11 y 12 en su versión EDNL.
 * 			No se garantiza el balanceado del árbol.
 * @atributo lDatDemograficos
 * 		Lista de datos demográficos auxiliar para almacenar todos los datos demográficos creados.
 * 		También se usa para liberar la memoria asociada. Como una vía puede estar compuesta de varios tramos,
 * 			y cada tramo es un objeto 'Via' en sí que apunta a los datos demográficos de todos los tramos,
 * 			ocurre que varios objetos apuntan a un mismo objeto, lo que puede ocasionar la doble liberación de punteros
 */

#ifndef PADRON_H_
#define PADRON_H_

#include "GestorBarrio.h"
#include "arbol.h"

namespace std {

class Padron {

private:
	GestorBarrio* gBarrio;
	ListaPI<Via*>* lVias;
	Arbol<Via*, ComparadorPtrVia>* aVias;
	ListaPI<DatosDemograficos*>* lDatDemograficos;

private:
	void alg11(Arbol<Via*, ComparadorPtrVia>* aVias, string nombreVia, ofstream& ofs, bool& enc);
	Arbol<Via*, ComparadorPtrVia>* alg12(Arbol<Via*, ComparadorPtrVia>* aVias, string raiz);
	int filtroInOrden(Arbol<Via*, ComparadorPtrVia>* aVias, string raiz, string nombreProvincia);

public:
	/**
	 * @brief
	 * 		CONSTRUCTOR POR DEFECTO. Reserva espacio para 'gBarrio', 'lVias', 'aVias' y 'lDatDemograficos'
	 * @pre:
	 * @post:
	 * @complejidad: O(1)
	 *
	 * @return
	 * 		Instancia de Padron inicializada por defecto
	 */
	Padron();
	/**
	 * @brief
	 * 		DESTRUCTOR. Libera toda la memoria reservada para toda la estructura de datos en cascada.
	 * 			Los datos demográficos se liberan a partir de la lista 'lDatDemograficos'
	 * 			Los nodos del ABB 'aVias' ya han sido liberados, solo se libera el ABB 'aVias'
	 *
	 * @pre:
	 * @post:
	 * @complejidad: O(n)
	 *
	 * @return
	 */
	~Padron();

	bool cargarBarrios();
	bool cargarVias();
	bool cargarDatosDemograficos();
	void alg2(string nombreBarrio);
	void alg3();
	void alg4();
	void alg5();
	void alg6();
	void alg7(int limInf, int limSup);
	void alg8(string nombreBarrio);
	void alg9();
	void alg10(string nombreProvincia);
	void alg11_EDL(string nombreVia);
	void alg11_EDNL(string nombreVia);
	void alg12_EDL(string raiz, string nombreProvincia);
	void alg12_EDNL(string raiz, string nombreProvincia);

	void mostrarEstructura();
};

}

#endif /* PADRON_H_ */
