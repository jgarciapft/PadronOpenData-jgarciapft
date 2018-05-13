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

	void mostrar();

	bool operator >(const Via& v);
};

class ComparadorPtrVia {
public:
	int operator() (const Via* v1, const Via* v2){
		int res;

		if(v1->getNombreVia() == v2->getNombreVia())		res = 0;
		else if(v1->getNombreVia() > v2->getNombreVia())	res = 1;
		else												res = -1;

		return res;
	}
};

}

#endif /* VIA_H_ */
