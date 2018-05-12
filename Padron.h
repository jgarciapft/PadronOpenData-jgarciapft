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
	void alg2(string nombreBarrio);
	void alg3();
	void alg4();
	void alg5();
	void alg6();
	void alg7(int limInf, int limSup);
	void alg8(string nombreBarrio);
	void mostrarEstructura();
};

}

#endif /* PADRON_H_ */
