/*
 * GestorVia.h
 *
 *      Autor: jgarciapft
 */

#ifndef GESTORVIA_H_
#define GESTORVIA_H_

#include "Via.h"

namespace std {

class GestorVia {
private:
	ListaPI<Via*>* lVias;
public:
	GestorVia();
	~GestorVia();

	void insertarViaOrden(Via* v);
	void insertarDatosDemograficos(DatosDemograficos* dD);
	int alg7(int limInf, int limSup);
	void alg8();

	void mostrarVias();
	void mostrar();
};

}

#endif /* GESTORVIA_H_ */
