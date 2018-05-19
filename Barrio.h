/**
 * CLASE: Barrio
 *
 * @brief
 * 		Modela el concepto de 'barrio' y su comportamiento. Cada barrio es está definido por su nombre y el distrito
 * 			al que pertenece y almacena una lista gestionada de las vías que lo componen. Principalmente contiene métodos
 * 			invocativos para los algoritmos que requieren búsquedas por barrio
 *
 * @atributo nombreBarrio
 * 		Nombre del barrio
 * @atributo nombreDistrito
 * 		Nombre del distrito
 * @atributo gVias
 * 		Instancia de la clase que gestiona la lista de vías que pertenecen al barrio
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
