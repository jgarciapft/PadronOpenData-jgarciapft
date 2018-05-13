/*
 * DatosDemograficos.h
 *
 *      Autor: jgarciapft
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

	int getCodVia();
	int getNMujeres();
	int getNHombres();
	void alg4(ListaPI<AnioNacimiento*>*& lAnioNac);
	void alg5(ListaPI<Nacionalidad*>*& lNacion);
	void alg6(ListaPI<LugarNacimiento*>*& lLugNac);
	int alg7(int limInf, int limSup);
	void alg8(ListaPI<Estudios*>*& lEstud);
	void alg10(ListaPI<LugarNacimiento*>*& lLugNac, string nombreProvincia);
	void alg11(ofstream& ofs);

	void mostrar();
};

}

#endif /* DATOSDEMOSGRAFICOS_H_ */
