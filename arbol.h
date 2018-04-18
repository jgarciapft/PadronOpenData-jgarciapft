/**
 * \file arbol.h
 * \brief Declaracion de la clase Arbol Binario de Busqueda
 * \author
 *   \b Autor: Profesores EDI \n
 *   \b Asignatura: Estructuras de Datos y de la Informacion \n
 *   \b Curso 13/14
 *   \b Revisado en: Curso 13/14
 */

#ifndef _ARBOL_H
#define _ARBOL_H

#include <iostream>

using namespace std;

/**
 * \class Arbol
 * \brief Esta clase implementa un Arbol Binario de Busqueda
 *
 */

template <class TipoDato, class Compare>
class Arbol {

private:

	TipoDato         datoRaiz;
	Arbol<TipoDato,Compare> *hIzq;
	Arbol<TipoDato,Compare> *hDer;

	bool  esVacio;

	Arbol<TipoDato,Compare> *borrarOrden (TipoDato dato);

public:

	Arbol ();
	Arbol (Arbol<TipoDato,Compare> *hIzq,TipoDato datoRaiz,Arbol<TipoDato,Compare> *hDer);

	Arbol    *hijoIzq();
	Arbol    *hijoDer();
	TipoDato  raiz();

	bool  vacio    ();
	bool  insertar  (const TipoDato &dato);
	void  borrar    (      TipoDato  dato);
	bool  pertenece (const TipoDato &dato);

	~Arbol();
};


/**
 * Constructor por defecto. Construye un objeto de tipo Arbol vacio
 * \param "" No recibe parametros
 * Complejidad: O(1)
 */
template <class TipoDato, class Compare>
Arbol<TipoDato,Compare>::Arbol() {

	esVacio = true;
	hIzq = NULL;
	hDer = NULL;
}


/**
 * Constructor parametrizado. Crea un objeto de tipo Arbol a partir de
 *   dos arboles (izq. y der.) y un dato.
 * \param hIzq Arbol Hijo izquierdo del arbol a crear
 * \param dato dato a insertar en la raiz
 * \param hDer Arbol Hijo derecho del arbol a crear
 * Complejidad: O(1)
 */
template <class TipoDato, class Compare>
Arbol<TipoDato,Compare>::Arbol(Arbol<TipoDato,Compare> *hIzq, TipoDato dato, Arbol<TipoDato,Compare> *hDer) {

	esVacio = false;
	this->datoRaiz = dato;
	this->hIzq = hIzq;
	this->hDer = hDer;
}


/**
 * Devuelve el subarbol izquierdo del arbol actual.
 * \return Subarbol izquierdo
 * \pre: Arbol no vacio
 * Complejidad: O(1)
 */
template <class TipoDato, class Compare>
Arbol<TipoDato,Compare> *Arbol<TipoDato,Compare>::hijoIzq() {

	return hIzq;
}


/**
 * Devuelve el subarbol derecho del arbol actual
 * \return Subarbol derecho
 * \pre: Arbol no vacio
 * Complejidad: O(1)
 */
template <class TipoDato, class Compare>
Arbol<TipoDato,Compare> *Arbol<TipoDato,Compare>::hijoDer() {

	return hDer;
}


/**
 * Devuelve la raiz de un arbol
 * \return Raiz del arbol
 * \pre: Arbol no vacio
 * Complejidad: O(1)
 */
template <class TipoDato, class Compare>
TipoDato Arbol<TipoDato,Compare>::raiz() {

	return datoRaiz;
}


/**
 * Devuelve si un arbol es vacio
 * \return true si el arbol es vacio, false en otro caso
 * Complejidad: O(1)
 */
template <class TipoDato, class Compare>
bool Arbol<TipoDato,Compare>::vacio() {

	return esVacio;
}


/**
 * Inserta el valor dato en el Arbol Binario de Busqueda
 * \param dato: Valor a insertar
 * \return Nada
 * \pre: dato no pertenece al arbol (Arbol Binario de Busqueda)
 * \post: Si dato pertenece al arbol, el arbol no varia.
 * Complejidad: O(log(n))
 */
template <class TipoDato, class Compare>
bool Arbol<TipoDato,Compare>::insertar(const TipoDato &dato) {

	bool resultado=true;
	Compare c;

	if (vacio()) {
		datoRaiz = dato;
		esVacio  = false;
	} else {

		if (c.operator() (dato , datoRaiz) != 0){

			Arbol<TipoDato, Compare> *aux;

			if (c.operator() (dato , datoRaiz)<0) {
				aux = hijoIzq();
				if (aux == NULL) {
					hIzq = aux = new Arbol<TipoDato, Compare>();
				}
			} else {
				aux = hijoDer();
				if (aux == NULL) {
					hDer = aux = new Arbol<TipoDato, Compare>();
				}
			}
			resultado = aux->insertar(dato);

		} else {
			resultado = false;
		}
	}
	return resultado;
}


/**
 * Elimina el nodo que contenga el valor de dato
 * \param dato: Valor a eliminar
 * \return No devuelve nada
 * \pre: arbol no vacio
 * Complejidad: O(log(n))
 */
template <class TipoDato, class Compare>
void Arbol <TipoDato,Compare>::borrar(TipoDato dato) {

	Compare  c;

	if (!vacio()) {

		if (c.operator() (dato, datoRaiz)<0) {

			if (hIzq != NULL) 
				hIzq = hIzq->borrarOrden(dato);

		} else if (c.operator() (dato, datoRaiz)>0) {

			if (hDer != NULL)
				hDer = hDer->borrarOrden(dato);

			// Encontrado el dato a borrar: datoRaiz
		} else {

			if ((hIzq == NULL) && (hDer == NULL)) {
				esVacio = true;
			} else {
				borrarOrden(dato);
			}

		}

	}
}


/**
 * Metodo privado auxiliar para realizar el borrado de un nodo. Reestructura el arbol tras el borrado.
 * Posibilidades:
 * 	El dato a borrar no tiene hijos (hoja): Se borra
 * 	El dato a borrar tiene un solo hijo: Se sustituye el hijo del nodo a borrar por el mismo
 * 	El dato a borrar tiene dos hijos: Se sustituye el nodo a borrar por el mayor valor de su
 * 	  subarbol izquierdo.
 * \param dato: Valor a eliminar
 * \return Arbol resultado del borrado
 * Complejidad: O(log(n))
 */
template <class TipoDato, class Compare>
Arbol<TipoDato,Compare> *Arbol<TipoDato,Compare>::borrarOrden(TipoDato dato) {

	TipoDato datoaux;
	Arbol *retorno=this, *aborrar, *candidato, *antecesor;
	Compare  c;

	if (!vacio()) {

		if (c.operator() (dato, datoRaiz)<0) {

			if (hIzq != NULL) 
				hIzq = hIzq->borrarOrden(dato);

		} else if (c.operator() (dato, datoRaiz)>0) {
			if (hDer != NULL)
				hDer = hDer->borrarOrden(dato);

		} else {

			aborrar=this;

			// 1. Si es hoja:
			if ((hDer == NULL) && (hIzq == NULL)) {

				delete aborrar;
				retorno = NULL;

			} else {

				// 2. Solo tiene un hijo
				// 2.1. Solo hijo izquierdo:
				if (hDer == NULL) {

					aborrar = hIzq;
					datoaux = datoRaiz;
					datoRaiz = hIzq->raiz();
					hIzq->datoRaiz = datoaux;
					hIzq = hIzq->hijoIzq();
					hDer = aborrar->hijoDer();

					retorno=this;

					// 2.2. Solo hijo derecho:
				} else if (hIzq == NULL) {

					aborrar = hDer;
					datoaux = datoRaiz;
					datoRaiz = hDer->raiz();
					hDer->datoRaiz = datoaux;
					hDer = hDer->hijoDer();
					hIzq = aborrar->hijoIzq();

					retorno = this;

					// 3. Tiene dos hijos.
				} else {

					candidato = hijoIzq();
					antecesor = this;
					while (candidato->hijoDer()) {
						antecesor = candidato;
						candidato = candidato->hijoDer();
					}

					// Intercambio de datos de candidato
					datoaux = datoRaiz;
					datoRaiz = candidato->raiz();
					candidato->datoRaiz = datoaux;
					aborrar = candidato;
					if (antecesor == this) {
						hIzq = candidato->hijoIzq();
					} else {
						antecesor->hDer = candidato->hijoIzq();
					}
				}

				//Eliminar solo ese nodo, no todo el subarbol
				aborrar->hIzq = NULL;
				aborrar->hDer = NULL;
				delete aborrar;
			}
		}

	}

	return retorno;
}


/**
 * Busqueda de un dato en el arbol.
 * \param dato: Valor a buscar
 * \return true: el dato se encontro en el arbol, false: en otro caso
 * \pre: arbol no vacio
 * Complejidad: O(log(n))
 */
template <class TipoDato, class Compare>
bool Arbol<TipoDato,Compare>::pertenece (const TipoDato &dato) {

	bool enc = false;
	Compare  c;

	if (vacio()) {

		enc  = false;

	} else {

		Arbol<TipoDato, Compare> *aux;

		if (c.operator() (dato, datoRaiz)<0) {

			aux = hijoIzq();
			if (aux != NULL)
				enc = aux->pertenece(dato);

		//} else if (*dato > *datoRaiz) {
		} else if (c.operator() (dato, datoRaiz)>0) {

			aux = hijoDer();
			if (aux != NULL)
				enc = aux->pertenece(dato);

		} else {
			enc = true;
		}

	}

	return enc;
}


/**
 * Destructor. Destruye un objeto de tipo Arbol, y los nodos del mismo.
 * \param "" No recibe parametros
 * \return No devuelve nada
 * Complejidad: O(n)
 */
template <class TipoDato, class Compare>
Arbol<TipoDato,Compare>::~Arbol() {

	Arbol<TipoDato, Compare> *aux;

	if (!vacio()) {

		aux = hijoIzq();
		if (aux != NULL)
			delete aux;

		aux = hijoDer();
		if (aux != NULL)
			delete aux;

		esVacio = true;
	}
}


#endif /* _ARBOL_H_ */

