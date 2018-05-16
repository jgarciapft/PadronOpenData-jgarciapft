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

	string getNombreBarrio() const ;
	string getNombreDistrito() const;
	void insertarVia(Via* v);
	void insertarDatosDemograficos(DatosDemograficos* dD);
	int alg7(int limInf, int limSup);
	void alg8();
	void alg9(float& pHombres, float& pMujeres);

	void mostrarVias();
	void mostrar();
};

}

#endif /* BARRIO_H_ */
