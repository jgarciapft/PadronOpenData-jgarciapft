/*
 * GestorBarrio.h
 *
 *      Autor: jgarciapft
 */

#ifndef GESTORBARRIO_H_
#define GESTORBARRIO_H_

#include "Barrio.h"

namespace std {

class GestorBarrio {
private:
	ListaPI<Barrio*>* lBarrios;
public:
	GestorBarrio();
	~GestorBarrio();

	void insertar(Barrio* b);
	void insertarVia(Via* v);
	void insertarDatosDemograficos(DatosDemograficos* dD);
	void alg6(string nB);
	void mostrar();
};

}

#endif /* GESTORBARRIO_H_ */
