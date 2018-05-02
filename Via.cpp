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
	datDemograficos = NULL;
}

Via::Via(string barV, string nomV, float lonV, string tipV, int codV) {
	barrioVia = barV;
	nombreVia = nomV;
	longitudVia = lonV;
	tipoVia = tipV;
	codVia = codV;
	datDemograficos = NULL;
}

Via::~Via() {
//	delete datDemograficos;
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

void Via::setDatosDemograficos(DatosDemograficos* dD) {
	datDemograficos = dD;
}

void Via::mostrar() {							//Muestra la información de cada vía
	cout << "Via : " << nombreVia << " | Barrio : " << barrioVia << " | Longitud : " <<
			longitudVia << " (m) | Tipo : " << tipoVia << " | Codigo : " << codVia << endl;
	if(datDemograficos != NULL)
		datDemograficos->mostrar();				//Llama a mostrar toda la información de los datos demográficos
}

bool Via::operator >(const Via& v) {			//Compara alfabéticamente las vías por su nombre
	return nombreVia.compare(v.nombreVia) < 0;
}

}
