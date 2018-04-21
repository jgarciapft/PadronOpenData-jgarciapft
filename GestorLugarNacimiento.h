/*
 * GestorLugarNacimiento.h
 *
 *      Autor: jgarciapft
 */

#ifndef GESTORLUGARNACIMIENTO_H_
#define GESTORLUGARNACIMIENTO_H_

#include "Utils.h"
#include "listapi.h"
#include "LugarNacimiento.h"

namespace std {

class GestorLugarNacimiento {
private:
	ListaPI<LugarNacimiento*>* lLugarNacimiento;

	void insertarOrden(LugarNacimiento* lNac);
public:
	GestorLugarNacimiento();
	GestorLugarNacimiento(string lugaresNacimiento);
	~GestorLugarNacimiento();

	void alg6(GestorLugarNacimiento*& gLugNacimiento);
	void mostrarAlg6();
	void mostrar();
};

}

#endif /* GESTORLUGARNACIMIENTO_H_ */
