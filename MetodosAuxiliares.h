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

	/**@TEST: Implementación de la prueba del método GestorVia::insertarViaOrden
	 *
	 * @param v
	 * 		Vía a insertar en la lista de vías 'lVias'
	 * @param lVias
	 * 		Simula la lista de vías encapsulada del gestor GestorVia
	 */
	static void insertarViaOrden(Via* v, ListaPI<Via*>& lVias);

	/**@TEST: Implementación de la prueba del método Padron::alg11
	 *
	 * @param aVias
	 * 		Simula el ABB de vías auxiliar que encapsula la clase Padron
	 * @param nombreVia
	 * 		Nombre de la vía a buscar
	 * @param enc
	 * 		Devuelve si se ha encntrado alguna vía por el nombre \param nombreVia
	 */
	static void alg11(Arbol<Via*, ComparadorPtrVia>* aVias, string nombreVia, bool& enc);

	/**@TEST: Implementación de la prueba del método Padron::alg12
	 *
	 * @param aVias
	 * 		Simula el ABB de vías auxiliar que encapsula la clase Padron
	 * @param raiz
	 * 		Subcadena con la que comparar la ráiz de cada vía
	 * @return
	 * 		Devuelve un ABB con todas las potenciales vías (sino todas) que comienzan por la raíz \param raiz
	 */
	static Arbol<Via*, ComparadorPtrVia>* alg12(Arbol<Via*, ComparadorPtrVia>* aVias, string raiz);

	/**@TEST: Implementación de la prueba del método Padron::filtroInOrden
	 *
	 * @param aVias
	 * 		Simula el ABB de vías auxiliar que encapsula la clase Padron
	 *
	 * @param raiz
	 * 		Subcadena con la que comparar la ráiz de cada vía
	 *
	 * 	@return
	 * 		Devuelve si se ha encntrado alguna vía por el nombre \param raiz
	 */
	static bool filtroInOrden(Arbol<Via*, ComparadorPtrVia>* aVias, string raiz);

/********************************************************************************************************************************************************/

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

void insertarViaOrden(Via* v, ListaPI<Via*>& lVias) {
	bool enc = false;
	Via* vAux;

	lVias.moverInicio();
	while(!lVias.finLista() && !enc){
		lVias.consultar(vAux);
		if(*v > *vAux)
			enc = true;
		else
			lVias.avanzar();
	}
	lVias.insertar(v);
}

void alg11(Arbol<Via*, ComparadorPtrVia>* aVias, string nombreVia, bool& enc) {
	Via* vRaiz = aVias->raiz();

	if(vRaiz->getNombreVia() == nombreVia){
		enc = true;
	}else if(vRaiz->getNombreVia() < nombreVia){
		if(aVias->hijoDer() != NULL)
			alg11(aVias->hijoDer(), nombreVia, enc);
	}else if(aVias->hijoIzq() != NULL){
		alg11(aVias->hijoIzq(), nombreVia, enc);
	}
}

Arbol<Via*, ComparadorPtrVia>* alg12(Arbol<Via*, ComparadorPtrVia>* aVias, string raiz) {
	Arbol<Via*, ComparadorPtrVia>* aAux = NULL;

	if(aVias->raiz()->getNombreVia().find(raiz) == 0){
		aAux = aVias;
	}else if(aVias->raiz()->getNombreVia() < raiz){
		if (aVias->hijoDer() != NULL)
			aAux = alg12(aVias->hijoDer(), raiz);
	}else if(aVias->hijoIzq() != NULL){
		aAux = alg12(aVias->hijoIzq(), raiz);
	}

	return aAux;
}

bool filtroInOrden(Arbol<Via*, ComparadorPtrVia>* aVias, string raiz) {
	bool enc = false;

	if(aVias->hijoIzq() != NULL)
		enc = filtroInOrden(aVias->hijoIzq(), raiz);

	if(aVias->raiz()->getNombreVia().find(raiz) == 0)
		enc = true;

	if(aVias->hijoDer() != NULL)
		enc = filtroInOrden(aVias->hijoDer(), raiz);

	return enc;
}

}
