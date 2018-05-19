/**
 * @CLASE: GestorLugarNacimiento
 *
 * @brief
 * 		Clase gestora que encapsula una lista de lugares de nacimiento de la población de una vía. Utilizada para
 * 			contextualizar la búsqueda/manipulación de lugares de nacimiento en una vía concreta. A partir de una cadena
 * 			con los campos de múltiples objetos 'LugarNacimiento' inicializa la lista que encapsula. Gestiona la memoria
 * 			asociada a los objetos 'LugarNacimiento' almacenados en la lista que encapsula
 *
 * @atributo lLugarNacimiento
 * 		Lista que encapsula el gestor. Almacena los lugares de nacimiento de la población de cada vía
 * 		@orden: Ninguna ordenación particular. El estado final de la lista es el orden inverso de lectura del fichero de
 * 			datos del padrón (orden alfabéticamente descendente de poblaciones, si se han guardado)
 */

#ifndef GESTORLUGARNACIMIENTO_H_
#define GESTORLUGARNACIMIENTO_H_

#include "Utils.h"
#include "listapi.h"
#include "LugarNacimiento.h"
#include <fstream>

namespace std {

class GestorLugarNacimiento {

private:
	ListaPI<LugarNacimiento*>* lLugarNacimiento;

public:
	GestorLugarNacimiento();
	GestorLugarNacimiento(string lugaresNacimiento);
	~GestorLugarNacimiento();

	void alg6(ListaPI<LugarNacimiento*>*& lLugNac);
	void alg10(ListaPI<LugarNacimiento*>*& lLugNac, string nombreProvincia);
	void alg11(ofstream& ofs);
	int alg12(string nombreProvincia);

	void mostrar();
};

}

#endif /* GESTORLUGARNACIMIENTO_H_ */
