/*
 * Barrio.h
 *
 *      Autor: jgarciapft
 */

#ifndef BARRIO_H_
#define BARRIO_H_

#include "GestorVia.h"

namespace std {

class Barrio {
private:
	string nombreBarrio;
	string nombreDistrito;
	GestorVia* gVias;
public:
	Barrio();
	Barrio(string nB, string nD);
	~Barrio();

	string getNombreBarrio();
	string getNombreDistrito();
	void insertarVia(Via* v);
	void insertarDatosDemograficos(DatosDemograficos* dD);
	int alg7(int limInf, int limSup);

	void mostrarVias();
	void mostrar();
};

}

#endif /* BARRIO_H_ */
