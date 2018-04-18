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
};

}

#endif /* GESTORBARRIO_H_ */
