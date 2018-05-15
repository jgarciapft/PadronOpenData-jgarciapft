/*
 * Via.h
 *
 *      Autor: jgarciapft
 */

#ifndef VIA_H_
#define VIA_H_

#include "DatosDemograficos.h"

namespace std {

class Via {

private:
	string barrioVia;
	string nombreVia;
	float longitudVia;
	string tipoVia;
	int codVia;
	DatosDemograficos* datDemograficos;

public:
	Via();
	Via(string barV, string nomV, float lonV, string tipV, int codV);
	~Via();

	string getBarrioVia() const;
	string getNombreVia() const;
	float getLongitudVia() const;
	string getTipoVia() const;
	int getCodVia() const;
	void setDatosDemograficos(DatosDemograficos* dD);
	int alg7(int limInf, int limSup);
	void alg8(ListaPI<Estudios*>*& lEstud);
	void alg9(float& nHombres, float& nMujeres);
	void alg11(ofstream& ofs);
	int alg12(const string& nombreProvincia);

	void mostrar();

	bool operator >(const Via& v);
};

class ComparadorPtrVia {

public:
	int operator() (const Via* v1, const Via* v2){																	/*Implementación del operador a utilizar por un ABB para comparar vías. Criterio de comparación:
 																													 * 		-Comparación de igualdad: coincidencia lexicográfica de sus nombres y los nombres de los barrios a los que pertenecen
 																													 * 		-Comparación de desigualdad: orden alfabético de sus nombres, ya que si las vías son distintas solo tiene sentido compararlas así*/
		int res;

		if(v1->getNombreVia() == v2->getNombreVia() && v1->getBarrioVia() == v2->getBarrioVia())		res = 0;
		else if(v1->getNombreVia() > v2->getNombreVia())												res = 1;	//No hace falta la doble comprobación de igualdad. Ya se sabe que no coinciden los nombres de los barrios por los que pasa
		else																							res = -1;	//Si ninguna de las condiciones anteriores se cumplen por descarte es alfabéticamente menor (por delante en el diccionario)

		return res;
	}
};

}

#endif /* VIA_H_ */
