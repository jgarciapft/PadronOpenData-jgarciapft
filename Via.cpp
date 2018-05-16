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
	datDemograficos = NULL;						///@NOTA: No se reserva memoria para los datos demograficos porque se asignan mediante el método 'Via::setDatosDemograficos'
}

Via::Via(string barV, string nomV, float lonV, string tipV, int codV) {
	barrioVia = barV;
	nombreVia = nomV;
	longitudVia = lonV;
	tipoVia = tipV;
	codVia = codV;
	datDemograficos = NULL;						///@NOTA: No se reserva memoria para los datos demograficos porque se asignan mediante el método 'Via::setDatosDemograficos'
}

Via::~Via() {}									///@NOIA: No se libera la memoria asociada a los datos demográficos porque se liberan el la clase 'Padron' para evitar dobles liberaciones



string Via::getBarrioVia() const {
	return barrioVia;
}

string Via::getNombreVia() const {
	return nombreVia;
}

float Via::getLongitudVia() const {
	return longitudVia;
}

string Via::getTipoVia() const {
	return tipoVia;
}

int Via::getCodVia() const {
	return codVia;
}

void Via::setDatosDemograficos(DatosDemograficos* dD) {
	datDemograficos = dD;
}

int Via::alg7(int limInf, int limSup) {			///@NOTA: Método invocativo
	int ret = 0;

	if(datDemograficos != NULL)					//Comprueba que la vía contenga un set de datos demográficos
		ret =  datDemograficos->alg7(limInf, limSup);

	return ret;
}

void Via::alg8(ListaPI<Estudios*>*& lEstud) {	///@NOTA: Método invocativo
	if(datDemograficos != NULL)					//Comprueba que la vía contenga un set de datos demográficos
		datDemograficos->alg8(lEstud);
}

void Via::alg9(float& nHombres, float& nMujeres) {
	if(datDemograficos != NULL){				//Comprueba que exista un set de datos demográficos y actualiza los acumuladores
		nHombres += datDemograficos->getNHombres();
		nMujeres += datDemograficos->getNMujeres();
	}
}

void Via::alg11(ofstream& ofs) {				///@NOTA: Método invocativo
	if(datDemograficos != NULL)					//Comprueba que exista un set de datos demográficos
		datDemograficos->alg11(ofs);
}

int Via::alg12(string& nombreProvincia) {		///@NOTA: Método invocativo
	int res = 0;

	if(datDemograficos != NULL)					//Comprueba que exista un set de datos demográficos
		res = datDemograficos->alg12(nombreProvincia);

	return res;
}



void Via::mostrar() {							///@NOTA: Muestra la información de cada vía
	cout << "Via : " << nombreVia << " | Barrio : " << barrioVia << " | Longitud : " <<
			longitudVia << " (m) | Tipo : " << tipoVia << " | Código : " << codVia << endl;
	if(datDemograficos != NULL)					//Comprueba que exista un set de datos demográficos
		datDemograficos->mostrar();				//Llama a mostrar toda la información de los datos demográficos
}



bool Via::operator >(const Via& v) {
	return v.nombreVia > nombreVia;				//Criterio de comparación: Orden alfabético de 'nombreVia'
}

}
