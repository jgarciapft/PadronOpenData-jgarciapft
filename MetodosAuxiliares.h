/*
 * PLACEHOLDER
 */

#include "Padron.h"

namespace pruebas {

	/**@TEST: Implementación de las pruebas de utilidades de cadenas. (DEL PROYECTO BASE)
	 *
	 * @param text
	 * @param salidaPruebas
	 * 		Flujo de salida del archivo de volcado de pruebas
	 */
	static void pruebaTrocearCadenaAnioNacimiento(string text, ofstream& salidaPruebas);

	/**@TEST: Implementación de las pruebas de utilidades de cadenas. (DEL PROYECTO BASE)
	 *
	 * @param text
	 * @param salidaPruebas
	 * 		Flujo de salida del archivo de volcado de pruebas
	 */
	static void pruebaTrocearCadenaLugarNacimiento(string text, ofstream& salidaPruebas);

	/**@TEST: Implementación de las pruebas de utilidades de cadenas. (DEL PROYECTO BASE)
	 *
	 * @param text
	 * @param salidaPruebas
	 * 		Flujo de salida del archivo de volcado de pruebas
	 */
	static void pruebaTrocearCadenaEstudios(string text, ofstream& salidaPruebas);

	/**@TEST: Implementación de las pruebas de utilidades de cadenas. (DEL PROYECTO BASE)
	 *
	 * @param text
	 * @param salidaPruebas
	 * 		Flujo de salida del archivo de volcado de pruebas
	 */
	static void pruebaTrocearCadenaNacionalidad(string text, ofstream& salidaPruebas);

	/**@TEST: Implementación de prueba del método GestorNacionalidad::ordenarLista y GestorEstudios::ordenarLista
	 *
	 * @param lNacion
	 * 		Simula la lista encapsulada 'lNacionalidad' y 'lEstudios' del gestor GestorNacionalidad y GestorEstudios
	 */
	static void ordenarLista(ListaPI<Nacionalidad*>*& lNacion);

	/**@TEST: Implementación de prueba del método GestorBarrio::insertarVia
	 *
	 * @param v
	 * 		Vía a buscar en la lista de barrios \param lBarrios
	 * @param lBarrios
	 * 		Simula la lista de barrios encapsulada del gestor GestorBarrio
	 * @return
	 * 		Devuelve si la vía pertence a algún barrio de la lista \param lBarrios
	 */
	static bool insertarVia(Via* v, ListaPI<Barrio*>& lBarrios);



void pruebaTrocearCadenaAnioNacimiento(string text, ofstream& salidaPruebas) {

    char delim = ';';
	vector<string> vText = splitStringToVector(text, delim);
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);
		salidaPruebas << "Año: "<< vString[0]<< "  nº personas: "<< atoi(vString[1].c_str())<<endl;
	}
}

void pruebaTrocearCadenaLugarNacimiento(string text, ofstream& salidaPruebas) {
    char delim = ';';
	vector<string> vText = splitStringToVector(text, delim);
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);
		if ( vString.size()== 2)
			salidaPruebas << "Poblacion: "<< " "<< " Provincia : "<< vString[0]<<"  nº personas: "<< atoi(vString[1].c_str())<<endl;
		else
			salidaPruebas << "Poblacion: "<< vString[0]<< " Provincia : "<< vString[1]<<"  nº personas: "<< atoi(vString[2].c_str())<<endl;
	}
}

void pruebaTrocearCadenaEstudios(string text, ofstream& salidaPruebas) {
    char delim = ';';
	vector<string> vText = splitStringToVector(text, delim);
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);
		salidaPruebas << "Estudios: "<< vString[0]<< "  nº personas: "<< atoi(vString[1].c_str())<<endl;
	}
}

void pruebaTrocearCadenaNacionalidad(string text, ofstream& salidaPruebas) {
    char delim = ';';
	vector<string> vText = splitStringToVector(text, delim);
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);
		salidaPruebas << "Pais: "<< vString[0]<< "  nº personas: "<< atoi(vString[1].c_str())<<endl;
	}
}

void ordenarLista(ListaPI<Nacionalidad*>*& lNacion) {
	bool siguiente;
	Nacionalidad* nacionPI;
	Nacionalidad* nacion;

	if(!lNacion->enInicio()){
		lNacion->consultar(nacionPI);
		lNacion->borrar();
		do{
			lNacion->retroceder();
			lNacion->consultar(nacion);
			siguiente = *nacionPI > *nacion;
		}while(siguiente && !lNacion->enInicio());
		if(!siguiente)
			lNacion->avanzar();
		lNacion->insertar(nacionPI);
	}
}

bool insertarVia(Via* v, ListaPI<Barrio*>& lBarrios) {
	bool enc = false;
	Barrio* bAux;

	lBarrios.moverInicio();
	while(!lBarrios.finLista() && !enc){
		lBarrios.consultar(bAux);
		lBarrios.avanzar();
		if(bAux->getNombreBarrio() == v->getBarrioVia()){
			enc = true;
		}
	}

	return enc;
}

}
