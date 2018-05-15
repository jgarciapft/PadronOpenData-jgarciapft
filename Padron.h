/*
 * Padron.h
 *
 *      Autor: jgarciapft
 */

#ifndef PADRON_H_
#define PADRON_H_

#include "GestorBarrio.h"
#include "arbol.h"

namespace std {

class Padron {

private:
	GestorBarrio* gBarrio;
	ListaPI<Via*>* lVias;
	Arbol<Via*, ComparadorPtrVia>* aVias;
	ListaPI<DatosDemograficos*>* lDatDemograficos;
private:
	void alg11(Arbol<Via*, ComparadorPtrVia>* aVias, string nombreVia, ofstream& ofs, bool& enc);
	Arbol<Via*, ComparadorPtrVia>* alg12(Arbol<Via*, ComparadorPtrVia>* aVias, string raiz);
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
	void alg9();
	void alg10(string nombreProvincia);
	void alg11_EDL(string nombreVia);
	void alg11_EDNL(string nombreVia);
	void alg12_EDNL(string raiz, string nombreProvincia);

	void mostrarEstructura();
};

}

#endif /* PADRON_H_ */
