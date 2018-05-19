/**
 * @CLASE: DatosDemograficos
 *
 * @brief
 * 		Clase interfaz de los datos del padrón para cada vía. Provee de métodos invocativos para explorar de forma
 * 			jerárquica y ordenada cada categoría de datos: años y lugares de nacimiento, estudios y nacionalidades.
 * 			Pasa a cada clase gestora una cadena con los campos de múltiples objetos a almacenar y gestiona la memoria asociada
 * 			a ellos
 *
 * @atributo codVia
 * 		Código númerico en el rango de [0, NUMERO DE VIAS]. Relaciona cada vía con un set de datos demográficos leídos del
 * 			archivo del padrón. Cada código es único para cada vía y es compartido por todos los tramos de vías (objetos 'Via' también) que
 * 			pertenecen a distintos barrios con el mismo nombre de vía
 * @atributo gAnioNacimiento
 * 		Instancia de la clase gestora de años de nacimiento
 * @atributo gLugarNacimiento
 * 		Instancia de la clase gestora de lugares de nacimiento
 * @atributo gEstudios
 * 		Instancia de la clase gestora de los estudios de la población
 * @atributo nMujeres
 * 		Número de mujeres de cada vía
 * @atributo nhombres
 * 		Número de hombres de cada via
 * @atributo gNacionalidad
 * 		Instancia de la clase gestora de nacionalidades
 */

#ifndef DATOSDEMOGRAFICOS_H_
#define DATOSDEMOGRAFICOS_H_

#include "GestorAnioNacimiento.h"
#include "GestorLugarNacimiento.h"
#include "GestorEstudios.h"
#include "GestorNacionalidad.h"

namespace std {

class DatosDemograficos {

private:
	int codVia;
	GestorAnioNacimiento* gAnioNacimiento;
	GestorLugarNacimiento* gLugarNacimiento;
	GestorEstudios* gEstudios;
	int nMujeres;
	int nHombres;
	GestorNacionalidad* gNacionalidad;

public:
	DatosDemograficos();
	DatosDemograficos(int _codVia, string aniosNacimiento, string lugaresNacimiento, string estudios, int _nMujeres,
			int _nHombres, string nacionalidades);
	~DatosDemograficos();

	int getCodVia() const;
	int getNMujeres() const;
	int getNHombres() const;
	void alg4(ListaPI<AnioNacimiento*>*& lAnioNac);
	void alg5(ListaPI<Nacionalidad*>*& lNacion);
	void alg6(ListaPI<LugarNacimiento*>*& lLugNac);
	int alg7(int limInf, int limSup);
	void alg8(ListaPI<Estudios*>*& lEstud);
	void alg10(ListaPI<LugarNacimiento*>*& lLugNac, string nombreProvincia);
	void alg11(ofstream& ofs);
	int alg12(string nombreProvincia);

	void mostrar();
};

}

#endif /* DATOSDEMOSGRAFICOS_H_ */
