/*
 * Padron.h
 *
 *      Autor: jgarciapft
 */

#ifndef PADRON_H_
#define PADRON_H_

#include "GestorBarrio.h"
#include <fstream>

namespace std {

class Padron {

private:
	GestorBarrio* gBarrio;
	ListaPI<DatosDemograficos*>* lDatDemograficos;
	ListaPI<Via*>* lVias;
public:
	Padron();
	~Padron();

	void cargarBarrios();
	void cargarVias();
	void cargarDatosDemograficos();
	void alg2(string nB);
	void alg3();
	void alg4();
	void alg6();
	void mostrarEstructura();
};

}

#endif /* PADRON_H_ */
