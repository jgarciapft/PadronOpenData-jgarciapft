/*
 * GestorVia.h
 *
 *      Autor: jgarciapft
 */

#ifndef GESTORVIA_H_
#define GESTORVIA_H_

#include "Via.h"
#include "arbol.h"
#include <fstream>

namespace std {

class GestorVia {
private:
	ListaPI<Via*>* lVias;
	Arbol<Via*, ComparadorPtrVia>* aVias;
public:
	GestorVia();
	~GestorVia();

	void insertarViaOrden(Via* v);
	void insertarDatosDemograficos(DatosDemograficos* dD);
	int alg7(int limInf, int limSup);
	void alg8();
	void alg9(float& pHombres, float& pMujeres);

	void mostrarVias();
	void mostrar();
};

}

#endif /* GESTORVIA_H_ */
