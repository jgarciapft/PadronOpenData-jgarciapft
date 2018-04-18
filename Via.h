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

	string getBarrioVia();
	string getNombreVia();
	float getLongitudVia();
	string getTipoVia();
	int getCodVia();
	void setDatosDemograficos(DatosDemograficos* dD);

	bool operator >(const Via& v);
};

}

#endif /* VIA_H_ */
