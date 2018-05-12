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
	datDemograficos = NULL;						//No se reserva memoria para los datos demograficos porque se asignan mediante el método 'setDatosDemograficos'
}

Via::Via(string barV, string nomV, float lonV, string tipV, int codV) {
	barrioVia = barV;
	nombreVia = nomV;
	longitudVia = lonV;
	tipoVia = tipV;
	codVia = codV;
	datDemograficos = NULL;						//No se reserva memoria para los datos demograficos porque se asignan mediante el método 'setDatosDemograficos'
}

Via::~Via() {}									//No libera la memoria de los datos demográficos porque se liberan el la clase 'Padron' para evitar liberar dos veces el mismo puntero



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

int Via::alg7(int limInf, int limSup) {			///@NOTA: Nombre provisional	@NOTA: Método invocativo
	return datDemograficos->alg7(limInf, limSup);
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
