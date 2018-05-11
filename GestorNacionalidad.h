/*
 * GestorNacionalidad.h
 *
 *      Autor: jgarciapft
 */

#ifndef GESTORNACIONALIDAD_H_
#define GESTORNACIONALIDAD_H_

#include "Utils.h"
#include "listapi.h"
#include "Nacionalidad.h"

namespace std {

class GestorNacionalidad {
private:
	ListaPI<Nacionalidad*>* lNacionalidad;
public:
	GestorNacionalidad();
	GestorNacionalidad(string nacionalidades);
	~GestorNacionalidad();

	void alg5(ListaPI<Nacionalidad*>*& lNacion);

	void mostrar();
};

}

#endif /* GESTORNACIONALIDAD_H_ */
