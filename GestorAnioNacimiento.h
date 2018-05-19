/**
 * @CLASE: GestorAnioNacimiento
 *
 * @brief
 * 		Clase gestora que encapsula una lista de años de nacimiento de la población de una vía. Utilizada para
 * 			contextualizar la búsqueda/manipulación de años de nacimiento en una vía concreta. A partir de una cadena
 * 			con los campos de múltiples objetos 'AnioNacimiento' inicializa la lista que encapsula. Gestiona la memoria
 * 			asociada a los objetos 'AnioNacimiento' almacenados en la lista que encapsula
 *
 * @atributo lAnioNacimiento
 * 		Lista que encapsula el gestor. Almacena los años de nacimiento de la población de cada vía
 * 		@orden: Ninguna ordenación particular. El estado final de la lista es el orden inverso de lectura del fichero de
 * 			datos del padrón (orden ascendente de años de nacimiento)
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
	/**
	 * @brief
	 * 		CONSTRUCTOR POR DEFECTO. Reserva memoria para la lista que encapsula
	 * @pre:
	 * @post:
	 * @complejidad: O(1)
	 *
	 * @return
	 * 		Instancia de GestorAnioNacimiento inicializada por defecto
	 */
	GestorAnioNacimiento();
	GestorAnioNacimiento(string aniosNacimiento);
	~GestorAnioNacimiento();

	void alg4(ListaPI<AnioNacimiento*>*& lAnioNac);
	int alg7(int limInf, int limSup);

	void mostrar();
};

}

#endif /* GESTORANIONACIMIENTO_H_ */
