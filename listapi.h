/*
 * ListaPI.h
 *
 *  Created on: 29/04/2013
 *      Author: Profesores de EDI
 */

#ifndef LISTAPI_H_
#define LISTAPI_H_


#include <cstdlib>



using namespace std;


template <class TipoDato>
class ListaPI {

private:

	class Nodo {

	public:

		TipoDato  dato;
		Nodo     *siguiente;
		Nodo     *anterior;

		Nodo (const TipoDato &dato) {
			this->dato      = dato;
			this->siguiente = NULL;
			this->anterior  = NULL;
		}
	};

	Nodo *inicio;
	Nodo *fin;
	Nodo *pI;


public:

    /* DESC:   Crea una lista con punto de interes vacia
     * PRE:    -
     * POST:   Lista vacia
     * PARAM:  -
     * RET:    -
     * COMP:   O(1)
     */
	ListaPI ();

    /* DESC:   Consulta si la lista esta vacia
     * PRE:    Lista creada
     * POST:   -
     * PARAM:  -
     * RET:    TRUE:  lista vacia
     *         FALSE: lista no vacia
     * COMP:   O(1)
     */
	bool  estaVacia ();

    /* DESC:   Coloca el PI al inicio de la lista
     * PRE:    Lista creada
     * POST:   PI apunta al primero elemento o a NULL si la lista esta vacia
     * PARAM:  -
     * RET:    -
     * COMP:   O(1)
     */
	void  moverInicio ();

	/* DESC:   Coloca el PI al final de la lista
     * PRE:    Lista creada
     * POST:   PI apunta al ultimo elemento o a NULL si la lista esta vacia
     * PARAM:  -
     * RET:    -
     * COMP:   O(1)
     */
	void  moverFinal ();

    /* DESC:   Coloca el PI apuntando al siguiente elemento de la lista
     * PRE:    Lista creada
     * POST:   PI apunta al siguiente elemento o a NULL si la lista esta vacia
     * PARAM:  -
     * RET:    -
     * COMP:   O(1)
     */
	void  avanzar ();

    /* DESC:   Coloca el PI apuntando al anterior elemento de la lista
     * PRE:    Lista creada
     * POST:   PI apunta al anterior elemento o a NULL si la lista esta vacia
     * PARAM:  -
     * RET:    -
     * COMP:   O(1)
     */
	void  retroceder ();

    /* DESC:   Consulta si el PI apunta al elemento inicial de la lista
     * PRE:    Lista creada
     * POST:   -
     * PARAM:  -
     * RET:    TRUE:  Si el PI apunta al primer elemento de la lista
     *         FALSE: Si el PI no apunta al primer elemento de la lista
     * COMP:   O(1)
     */
	bool  enInicio ();

    /* DESC:   Consulta si el PI apunta al ultimo elemento de la lista
     * PRE:    Lista creada
     * POST:   -
     * PARAM:  -
     * RET:    TRUE:  Si el PI apunta al ultimo elemento de la lista
     *         FALSE: Si el PI no apunta al ultimo elemento de la lista
     * COMP:   O(1)
     */
	bool  enFin ();

    /* DESC:   Consulta si el PI apunta despues del ultimo elemento de la lista
     * PRE:    Lista creada
     * POST:   -
     * PARAM:  -
     * RET:    TRUE:  Si el PI apunta despues del ultimo elemento de la lista
     *         FALSE: Si el PI no apunta despues del ultimo elemento de la lista
     * COMP:   O(1)
     */
	bool  finLista ();

    /* DESC:   Inserta un elemento en la lista, justo delante del PI
     * PRE:    Lista creada.
     * POST:   Lista con un elemento mas. PI apunta al elemento insertado.
     * PARAM:  E: dato -> Elemento a insertar
     * RET:    -
     * COMP:   O(1)
     */
	void  insertar (const TipoDato &dato);

	/* DESC:   Devuelve el elemento de la lista apuntado por el PI
	 * PRE:    Lista creada.
	 * POST:   -
	 * PARAM:  S: dato -> Elemento apuntado por PI (si PI apunta a un elemento valido)
	 * RET:    -
	 * COMP:   O(1)
	 */
	void  consultar (TipoDato &dato);

	/* DESC:   Borra el elemento de la lista apuntado por el PI
	 * PRE:    Lista creada.
	 * POST:   Num. elementos en la lista disminuye en 1 si se puede borrar.
	 *         PI queda apuntando al siguiente elemento.
	 * PARAM:  -
	 * RET:    -
	 * COMP:   O(1)
	 */
	void  borrar ();

	/* DESC:   Libera la memoria ocupada por los nodos de la lista
	 * PRE:    Lista creada.
	 * POST:   Num. elementos en la lista = 0. Lista vacia == TRUE
	 * PARAM:  -
	 * RET:    -
	 * COMP:   O(n)
	 */
     ~ListaPI();

};




template <class TipoDato>
ListaPI<TipoDato>::ListaPI () {
	inicio = NULL;
	fin    = NULL;
	pI     = NULL;
}

template <class TipoDato>
bool ListaPI<TipoDato>::estaVacia () {
	return (inicio == NULL);
}

template <class TipoDato>
void ListaPI<TipoDato>::moverInicio (){
	pI = inicio;
}

template <class TipoDato>
void ListaPI<TipoDato>::moverFinal (){
	pI= fin;
}

template <class TipoDato>
void ListaPI<TipoDato>::avanzar () {

	if (pI != NULL) {
		pI = pI->siguiente;
	}
}

template <class TipoDato>
void ListaPI<TipoDato>::retroceder (){

	if (pI != inicio) {
		if (pI != NULL) {
			pI = pI->anterior;
		} else {
			pI = fin;
		}
	}
}

template <class TipoDato>
bool ListaPI<TipoDato>::enInicio (){
	return (pI == inicio);
}

template <class TipoDato>
bool ListaPI<TipoDato>::enFin (){
	return (pI == fin);
}

template <class TipoDato>
bool ListaPI<TipoDato>::finLista (){
	return (pI == NULL);
}

template <class TipoDato>
void ListaPI<TipoDato>::consultar (TipoDato &dato){

	if (pI != NULL) {
		dato = pI->dato;
	}
}

template <class TipoDato>
void ListaPI<TipoDato>::insertar (const TipoDato &dato) {


	Nodo *nuevo = new Nodo (dato);

	if (pI == NULL){

		if (estaVacia()) { // Lista vacia
			nuevo->siguiente = pI;
			inicio = nuevo;
			fin    = nuevo;
		} else { // pI apunta al elemento siguiente al final: el nodo se inserta al final
			nuevo->anterior = fin;
			fin->siguiente  = nuevo;
			fin = nuevo;
		}

	} else {

		if (pI->anterior == NULL) { // Insercion el primero de la lista
			inicio = nuevo;
			nuevo->siguiente = pI;
			nuevo->anterior = NULL;
			pI->anterior = nuevo;
		} else {  // Insercion en posicion intermedia
			nuevo->anterior  = pI->anterior;
			nuevo->siguiente = pI;
			(pI->anterior)->siguiente = nuevo;
			pI->anterior = nuevo;
		}

	}

	// El PI apunta al nuevo nodo insertado
	pI = nuevo;
}

template <class TipoDato>
void ListaPI<TipoDato>::borrar () {

	Nodo *pAux;

	if (!estaVacia() && !finLista()) {

		pAux=pI;

		if (pI == inicio) // El nodo a borrar es el primero
			inicio = inicio->siguiente;
		if (pI == fin)    // El nodo a borrar es el ultimo
			fin = fin->anterior;

		pI = pI->siguiente; // El PI apunta al siguiente

		if (pAux->anterior!=NULL)
			(pAux->anterior)->siguiente = pI;
		if (pAux->siguiente!=NULL)
			pI->anterior = pAux->anterior;

		delete pAux;
	}
}

template <class TipoDato>
ListaPI<TipoDato>::~ListaPI() {
	moverInicio();
		while (!estaVacia())
			borrar();

	inicio = NULL;
	fin    = NULL;
	pI     = NULL;
}




#endif /* LISTAPI_H_ */
