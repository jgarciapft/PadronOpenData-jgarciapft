/*
 * Via.cpp
 *
 *      Autor: jgarciapft
 */

#include "Via.h"

namespace std {

Via::Via() {
	barrioVia = "";
	nombreVia = "";
	longitudVia = 0.0;
	tipoVia = "";
	codVia = 0;
	datDemograficos = new DatosDemograficos();
}

Via::Via(string barV, string nomV, float lonV, string tipV, int codV) {
	barrioVia = barV;
	nombreVia = nomV;
	longitudVia = lonV;
	tipoVia = tipV;
	codVia = codV;
	datDemograficos = new DatosDemograficos();
}

Via::~Via() {
	delete datDemograficos;
}

string Via::getBarrioVia() {
	return barrioVia;
}

string Via::getNombreVia() {
	return nombreVia;
}

float Via::getLongitudVia() {
	return longitudVia;
}

string Via::getTipoVia() {
	return tipoVia;
}

int Via::getCodVia() {
	return codVia;
}

}
