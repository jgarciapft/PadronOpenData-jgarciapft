/**
 * @CLASE: GestorNacionalidad
 *
 * @brief
 * 		Clase gestora que encapsula una lista de nacionalidades de la población de una vía. Utilizada para
 * 			contextualizar la búsqueda/manipulación de nacionalidades en una vía concreta. A partir de una cadena
 * 			con los campos de múltiples objetos 'Nacionalidad' inicializa la lista que encapsula. Gestiona la memoria
 * 			asociada a los objetos 'Nacionalidad' almacenados en la lista que encapsula
 *
 * @atributo lNacionalidad
 * 		Lista que encapsula el gestor. Almacena las nacionalidades de la población de cada vía
 * 		@orden: Ninguna ordenación particular. El estado final de la lista es el orden inverso de lectura del fichero de
 * 			datos del padrón (orden alfabéticamente descendente de las nacionalidades)
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

private:
	void ordenarLista(ListaPI<Nacionalidad*>*& lNacion);

public:
	GestorNacionalidad();
	GestorNacionalidad(string nacionalidades);
	~GestorNacionalidad();

	void alg5(ListaPI<Nacionalidad*>*& lNacion);

	void mostrar();
};

}

#endif /* GESTORNACIONALIDAD_H_ */
