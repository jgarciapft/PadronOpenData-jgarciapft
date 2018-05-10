/*
 * GestorAnioNacimiento.h
 *
 *      Autor: jgarciapft
 */

#ifndef GESTORANIONACIMIENTO_H_
#define GESTORANIONACIMIENTO_H_

#include "Utils.h"
#include "listapi.h"
#include "AnioNacimiento.h"

namespace std {

class GestorAnioNacimiento {
private:
	ListaPI<AnioNacimiento*> *lAnioNacimiento;
public:
	GestorAnioNacimiento();
	GestorAnioNacimiento(string aniosNacimiento);
	~GestorAnioNacimiento();

	void alg4(ListaPI<AnioNacimiento*>*& lAnioNac);

	void mostrar();
};

}

#endif /* GESTORANIONACIMIENTO_H_ */
