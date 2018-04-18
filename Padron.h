/*
 * Padron.h
 *
 *      Autor: jgarciapft
 */

#ifndef PADRON_H_
#define PADRON_H_

#include "GestorBarrio.h"

namespace std {

class Padron {
private:
	GestorBarrio* gBarrio;
	ListaPI<DatosDemograficos*>* lDatDemograficos;
	ListaPI<Via*>* lVias;
public:
	Padron();
	~Padron();
};

}

#endif /* PADRON_H_ */
