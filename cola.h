/*
 * cola.h
 *
 *  Created on: 3/04/2013
 *      Author: Profesores de EDI
 */


#ifndef COLA_H_
#define COLA_H_
#include <iostream>

/**
* Clase genérica Cola
* contiene Nodos de tipo genérico también y dos punteros (frente y fin) al primer y último nodo introducido
*/
template <class TipoDato>
class Cola {

private:
	/**
	* Clase genérica Nodo
	* representa los Nodos que se almacenan en la Cola
	* cada Nodo contiene un dato de tipo genérico y un puntero al siguiente nodo
	*/
	class Nodo {

	public:
		/** Dato almacenado en cada nodo */
		TipoDato  dato;
		/** Enlace al siguiente elemento */
		Nodo     *siguiente;

		Nodo (TipoDato dato) {
			this->dato      = dato;
			this->siguiente = NULL;
		}
	};
	/** Puntero al inicio de la cola*/
	Nodo *frente;
	/** Puntero al final de la cola*/
	Nodo *fin;

public:
	/*
	 * Constructor por defecto
	 * Pre ={}
	 * Post= {Crea/inicializa la instancia de la clase}
	 * \param ""  No recibe parametros
	 * \return Retorna Objeto Cola
	 */
	Cola();

    /* Comprueba si una cola esta vacia
     * Pre =  La instancia de cola debe estar creada
     * \param ""  No recibe parametros
     * \return true si la cola esta vacia o false si la cola no esta vacia
     * Complejidad:   O(1)
     */
	bool vacia () const;

    /* Devuelve el elemento en el frente de la cola
     * Pre = La instancia de cola debe estar creada. Cola.vacia() = false
     * \param  dato -> elemento en el frente de la cola
     * \return  No retorna ningun valor
     * Complejidad:   O(1)
     */
	void primero (TipoDato &dato) const;

    /* Inserta un elemento en la cola
     * Pre = La instancia de cola debe estar creada
     * Post = El número de elementos de la cola aumenta en 1
     * \param dato -> elemento a insertar
     * \return No retorna ningun valor
     * Complejidad:   O(1)
     */
	void encolar (const TipoDato &dato);

    /* Elimina el elemento en el frente de la cola
     * Pre = La instancia de cola debe estar creada. Cola.vacia() = false
     * Post = El número de elementos en la cola se reduce en 1
     * \param "" No recibe parametros
     * \return  No retorna ningun valor
     * \Complejidad: O(1)
     */
	void desencolar ();

	/**
	* Metodo destructor de la clase Cola
	* \param ""  No recibe parametros
	* \return No retorna ningun valor
	* Complejidad: O(1)
	*/
	~Cola();
};



template <class TipoDato>
Cola<TipoDato>::Cola() {
	frente = NULL;
	fin    = NULL;

}

template <class TipoDato>
bool Cola<TipoDato>::vacia () const {
    return (frente == NULL);
}



template <class TipoDato>
void Cola<TipoDato>::primero (TipoDato &dato) const {
	dato = frente->dato;
}


template <class TipoDato>
void Cola<TipoDato>::encolar (const TipoDato &dato) {
	Nodo *aux;
	aux = new Nodo(dato);
	if(!vacia()){
		fin->siguiente=aux;
	}else{
		frente=aux;
	}
	fin=aux;
}


template <class TipoDato>
void Cola<TipoDato>::desencolar () {

    Nodo *aux;

    aux = frente;
    frente = frente->siguiente;

    delete aux;
}


template <class TipoDato>
Cola<TipoDato>::~Cola () {

    Nodo *aux;

    while (! vacia()) {
    	aux    = frente;
    	frente = frente->siguiente;
    	delete aux;
    }

    frente = NULL;
    fin    = NULL;
}

#endif /* COLA_H_ */
