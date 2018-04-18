/*
 * GestorEstudios.h
 *
 *      Autor: jgarciapft
 */

#ifndef GESTORESTUDIOS_H_
#define GESTORESTUDIOS_H_

#include "Utils.h"
#include "listapi.h"
#include "Estudios.h"

namespace std {

class GestorEstudios {
private:
	ListaPI<Estudios*>* lEstudios;
public:
	GestorEstudios();
	GestorEstudios(string estudios);
	~GestorEstudios();

	void mostrar();
};

}

#endif /* GESTORESTUDIOS_H_ */
