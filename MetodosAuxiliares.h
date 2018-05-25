/**
 * @brief
 * 		Ampliación del espacio de nombres de pruebas 'pruebas'
 */

#include "Padron.h"

namespace pruebas {

/******************************************************* CONSTANTES DE PRUEBAS *******************************************************/

	const string RUTA_FIHCERO_PRUEBAS = "Pruebas.txt";									//Ruta relativa del fichero de volcado para la ejecución de las pruebas

	///@TEST: Pruebas del algoritmo 1 (Carga de datos)		\SET_DATOS: SET_1
	const string RUTA_BARRIO_PRUEBA_ALG1 = "SetDatos_Pruebas/SetDatos_1_Barrios.csv";	//Ruta relativa del fichero de barrios para el set de pruebas 1
	const string RUTA_VIA_PRUEBA_ALG1 = "SetDatos_Pruebas/SetDatos_1_Vias.csv";			//Ruta relativa del fichero de vías para el set de pruebas 1
	const string RUTA_PADRON_PRUEBA_ALG1 = "SetDatos_Pruebas/SetDatos_1_Padron.csv";	//Ruta relativa del fichero de datos del padrón (Año 2016) para el set de pruebas 1

	///@TEST: Pruebas de los algoritmos 7 y 8				\SET_DATOS: SET_2
	const string RUTA_BARRIO_PRUEBA_ALG7 = "SetDatos_Pruebas/SetDatos_2_Barrios.csv";	//Ruta relativa del fichero de barrios para el set de pruebas 2
	const string RUTA_VIA_PRUEBA_ALG7 = "SetDatos_Pruebas/SetDatos_2_Vias.csv";			//Ruta relativa del fichero de vías para el set de pruebas 2
	const string RUTA_PADRON_PRUEBA_ALG7 = "SetDatos_Pruebas/SetDatos_2_Padron.csv";	//Ruta relativa del fichero de datos del padrón (Año 2016) para el set de pruebas 2

	///@TEST: Pruebas de los algoritmos 9, 10, 11 y 12		\SET_DATOS: SET_2
	const string RUTA_BARRIO_PRUEBA_ALG9 = "SetDatos_Pruebas/SetDatos_3_Barrios.csv";	//Ruta relativa del fichero de barrios para el set de pruebas 3
	const string RUTA_VIA_PRUEBA_ALG9 = "SetDatos_Pruebas/SetDatos_3_Vias.csv";			//Ruta relativa del fichero de vías para el set de pruebas 3
	const string RUTA_PADRON_PRUEBA_ALG9 = "SetDatos_Pruebas/SetDatos_3_Padron.csv";	//Ruta relativa del fichero de datos del padrón (Año 2016) para el set de pruebas 3

/******************************************************* CONSTANTES DE PRUEBAS *******************************************************/

	/**@TEST: Implementación de las pruebas de utilidades de cadenas. (DEL PROYECTO BASE)
	 *
	 * @param text
	 * 		Cadena con toda la información que debe convertirse en objetos a almacenar por los gestores
	 */
	static void pruebaTrocearCadenaAnioNacimiento(string text);
	static void pruebaTrocearCadenaLugarNacimiento(string text);
	static void pruebaTrocearCadenaEstudios(string text);
	static void pruebaTrocearCadenaNacionalidad(string text);

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
	 * @param raiz
	 * 		Subcadena con la que comparar la ráiz de cada vía
	 * @return
	 * 		Devuelve si se ha encntrado alguna vía por el nombre \param raiz
	 */
	static bool filtroInOrden(Arbol<Via*, ComparadorPtrVia>* aVias, string raiz);

	/** @TEST: Implementación de la prueba del Algoritmo 1 (Carga de datos)
	 *
	 * @param gBarrio
	 * 		Simula el gestor de barrios que encapsula la clase Padron
	 * @param cont
	 * 		Contador de datos cargados
	 * @param ruta
	 * 		Ruta del fichero de datos
	 * @param lDatDem
	 * 		Lista auxiliar de datos demográficos para liberarlos posteriormente
	 * @return
	 * 		Devuelve el estado de la carga de datos
	 */
	static bool cargarBarrios(GestorBarrio& gBarrio, int& cont, string& ruta);
	static bool cargarVias(GestorBarrio& gBarrio, int& cont, string& ruta);
	static bool cargarDatosDemograficos(GestorBarrio& gBarrio, int& cont, string& ruta, ListaPI<DatosDemograficos*>& lDatDem);

	/**@TEST: Implementación de la prueba del Algoritmo 3
	 *
	 * @param lVias
	 * 		Simula la lista de vías auxiliar de la clase Padron
	 * @param cont
	 * 		Número de vías que pasan por más de 1 barrio en la lista 'lVias'
	 */
	static void alg3(ListaPI<Via*>& lVias, int& cont);

	/**@TEST: Implementación de la prueba del Algoritmo 4
	 *
	 * @param lDatDem
	 * 		Simula la lista de datos demográficos auxiliar de la clase Padron
	 * @param cont[]
	 * 		Vector de contadores de personas para cada rango de edad
	 */
	static void alg4(ListaPI<DatosDemograficos*>& lDatDem, int cont[]);

	/**@TEST: Implementación de la prueba del Algoritmo 5
	 *
	 * @param lDatDem
	 * 		Simula la lista de datos demográficos auxiliar de la clase Padron
	 * @param cont[]
	 * 		Vector de contadores de personas para cada nacionalidad
	 */
	static void alg5(ListaPI<DatosDemograficos*>& lDatDem, int cont[]);

	/**@TEST: Implementación de la prueba del Algoritmo 6
	 *
	 * @param lDatDem
	 * 		Simula la lista de datos demográficos auxiliar de la clase Padron
	 * @param cont[]
	 * 		Vector de contadores de personas para cada provincia
	 */
	static void alg6(ListaPI<DatosDemograficos*>& lDatDem, int cont[]);

	/**@TEST: Implementación de la prueba del Algoritmo 7
	 *
	 * @param gBarrio
	 * 		Simula el gestor de barrios que encapsula la clase Padron
	 * @param limInf
	 * 		Límite inferior del rango de edad
	 * @param limSup
	 * 		Límite superior del rango de edad
	 */
	static void alg7(GestorBarrio& gBarrio, int limInf, int limSup);

	/**@TEST: Implementación de la prueba del Algoritmo 8
	 *
	 * @param gBarrio
	 * 		Simula el gestor de barrios que encapsula la clase Padron
	 * @param nombreBarrio
	 * 		Nombre del barrio a buscar
	 */
	static void alg8(GestorBarrio& gBarrio, string nombreBarrio);

	/**@TEST: Implementación de la prueba del Algoritmo 9
	 *
	 * @param gBarrio
	 * 		Simula el gestor de barrios que encapsula la clase Padron
	 */
	static void alg9(GestorBarrio& gBarrio);

	/**@TEST: Implementación de la prueba del Algoritmo 10
	 *
	 * @param lDatDem
	 * 		Simula la lista auxiliar de datos demográfico de la clase Padron
	 * @param nombreProvincia
	 * 		Nombre de la provincia a buscar
	 */
	static void alg10(ListaPI<DatosDemograficos*>& lDatDem, string nombreProvincia);

	/**@TEST: Implementación de la prueba del Algoritmo 11 EDL
	 *
	 * @param lVias
	 * 		Simula lista auxiliar de vías de la clase Padron
	 * @param nombreVia
	 * 		Nombre de la vía a buscar
	 */
	static void alg11_EDL(ListaPI<Via*>& lVias, string nombreVia);

	/**@TEST: Implementación de la prueba del Algoritmo 11 EDNL
	 *
	 * @param aVias
	 * 		Simula el ABB auxiliar de vías de la clase Padron
	 * @param nombreVia
	 * 		Nombre de la vía a buscar
	 */
	static void alg11_EDNL(Arbol<Via*, ComparadorPtrVia>* aVias, string nombreVia, bool& enc);

	/**@TEST: Implementación de la prueba edl Algoritmo 12 EDL
	 *
	 * @param lVias
	 * 		Simula la lista auxiliar de vías de la clase Padron
	 * @param raiz
	 * 		Subcadena por la que deben comenzar las vías
	 * @param nombreProvincia
	 * 		Nombre de la provincia a buscar
	 */
	static void alg12_EDL(ListaPI<Via*>& lVias, string raiz, string nombreProvincia);

	/**
	 * @NOTA: Nueva implementación para probar con el Algoritmo 12 EDNL
	 */
	static int	filtroInOrden(Arbol<Via*, ComparadorPtrVia>* aVias, string raiz, string nombreProvincia, ListaPI<int>*& lCoincidencias);

	/**@TEST; Implementación de la prueba del Algoritmo 12 EDNL
	 *
	 * @param aVias
	 * 		Simula el ABB auxiliar de vías de la clase Padron
	 * @param raiz
	 * 		Subcadena por la que deben comenzar las vías
	 * @param nombreProvincia
	 * 		Nombre de la provincia a buscar
	 */
	static void alg12_EDNL(Arbol<Via*, ComparadorPtrVia>* aVias, string raiz, string nombreProvincia);


/*************************************************************	IMPLEMENTACIÓN	***********************************************************************/

void pruebaTrocearCadenaAnioNacimiento(string text) {

    char delim = ';';
	vector<string> vText = splitStringToVector(text, delim);
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);
		cout << "Año: "<< vString[0]<< "  nº personas: "<< atoi(vString[1].c_str())<<endl;
	}
}

void pruebaTrocearCadenaLugarNacimiento(string text) {
    char delim = ';';
	vector<string> vText = splitStringToVector(text, delim);
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);
		if ( vString.size()== 2)
			cout << "Poblacion: "<< " "<< " Provincia : "<< vString[0]<<"  nº personas: "<< atoi(vString[1].c_str())<<endl;
		else
			cout << "Poblacion: "<< vString[0]<< " Provincia : "<< vString[1]<<"  nº personas: "<< atoi(vString[2].c_str())<<endl;
	}
}

void pruebaTrocearCadenaEstudios(string text) {
    char delim = ';';
	vector<string> vText = splitStringToVector(text, delim);
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);
		cout << "Estudios: "<< vString[0]<< "  nº personas: "<< atoi(vString[1].c_str())<<endl;
	}
}

void pruebaTrocearCadenaNacionalidad(string text) {
    char delim = ';';
	vector<string> vText = splitStringToVector(text, delim);
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);
		cout << "Pais: "<< vString[0]<< "  nº personas: "<< atoi(vString[1].c_str())<<endl;
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

bool cargarBarrios(GestorBarrio& gBarrio, int& cont, string& ruta) {
	ifstream fEnt;
	bool rutaValida = false;
	string campos[N_CAMPOS_BARRIO];

	fEnt.open(ruta.c_str());
	if(fEnt.is_open()){
		rutaValida = true;
		getline(fEnt, campos[0]);
		while(!fEnt.eof()){
			getline(fEnt, campos[0], SEP);
			getline(fEnt, campos[1]);
			if(!fEnt.eof()){
				gBarrio.insertar(new Barrio(campos[0], campos[1]));
				cont++;
			}
		}
		gBarrio.insertar(new Barrio(DEF_BARRIO, DEF_PLACEHOLDER));
		cont++;
	}
	fEnt.close();

	return rutaValida;
}

bool cargarVias(GestorBarrio& gBarrio, int& cont, string& ruta) {
	ifstream fEnt;
	bool rutaValida = false;
	string campos[N_CAMPOS_VIA];
	Via* vAux;

	fEnt.open(ruta.c_str());
	if(fEnt.is_open()){
		rutaValida = true;
		getline(fEnt, campos[0]);
		while(!fEnt.eof()){
			for(int i=0; i<N_CAMPOS_VIA-1; i++){
				getline(fEnt, campos[i], SEP);
			}
			getline(fEnt, campos[4]);
			if(campos[0] == DEF_PLACEHOLDER)
				campos[0] = DEF_BARRIO;
			if(!fEnt.eof()){
				vAux = new Via(campos[0], campos[1], atof(campos[2].c_str()), campos[3], atoi(campos[4].c_str()));
				gBarrio.insertarVia(vAux);
				cont++;
			}
		}
	}
	fEnt.close();

	return rutaValida;
}

bool cargarDatosDemograficos(GestorBarrio& gBarrio, int& cont, string& ruta, ListaPI<DatosDemograficos*>& lDatDem) {
	ifstream fEnt;
	bool rutaValida = false;
	string campos[N_CAMPOS_DATOS_DEMOGRAFICOS];
	DatosDemograficos* dD;

	fEnt.open(ruta.c_str());
	if(fEnt.is_open()){
		rutaValida = true;
		getline(fEnt, campos[0]);
		while(!fEnt.eof()){
			for(int i=0; i<N_CAMPOS_DATOS_DEMOGRAFICOS-1; i++){
				getline(fEnt, campos[i], SEP);
			}
			getline(fEnt, campos[N_CAMPOS_DATOS_DEMOGRAFICOS-1]);
			if(!fEnt.eof()){
				dD = new DatosDemograficos(atoi(campos[0].c_str()), campos[1], campos[2], campos[3], atoi(campos[4].c_str()),
							atoi(campos[5].c_str()), campos[6]);
				gBarrio.insertarDatosDemograficos(dD);
				lDatDem.insertar(dD);
				cont++;
			}
		}
	}
	fEnt.close();

	return rutaValida;
}

void alg3(ListaPI<Via*>& lVias, int& cont) {
	bool primerRes = true;												
	bool coincidencia = false;											
	Via* vAux1;															
	Via* vAux2;															
	string nombreVia;													
	ListaPI<string> lCoincidencias;										

	lVias.moverInicio();
	while(!lVias.finLista()){											
		lVias.consultar(vAux1);
		lVias.avanzar();
		lCoincidencias.moverInicio();
		while(!lCoincidencias.finLista() && !coincidencia){				
			lCoincidencias.consultar(nombreVia);
			lCoincidencias.avanzar();
			if(vAux1->getNombreVia() == nombreVia)
				coincidencia = true;
		}
		if(!coincidencia){												
			while(!lVias.finLista()){									
				lVias.consultar(vAux2);
				lVias.avanzar();
				if(vAux1->getNombreVia() == vAux2->getNombreVia()){
					if(primerRes){										
						lCoincidencias.insertar(vAux1->getNombreVia());
						primerRes = false;								
					}
					cout << vAux2->getBarrioVia() << endl;
					cont++;
				}
			}
			lVias.moverInicio();
			do {														
				lVias.consultar(vAux2);
				lVias.avanzar();
			} while(vAux1 != vAux2);									
			primerRes = true; 											
		}
		coincidencia = false;											
	}
}

void alg4(ListaPI<DatosDemograficos*>& lDatDem, int cont[]) {
	ListaPI<AnioNacimiento*>* lAnioNac = new ListaPI<AnioNacimiento*>();
	DatosDemograficos* dD;												
	AnioNacimiento* anNacAux;											
	int nPersonas;														
	int nPersPorDiv;													
	int nDivisiones;													
	int mayorMarca = 0;													
	int modaNPersonas = 0;												
	string carDivision = "·";											
	string cadDivisiones;												
	string cadSep;														
	string cadMayorMarca;

	lDatDem.moverInicio();
	while(!lDatDem.finLista()){								
		lDatDem.consultar(dD);
		lDatDem.avanzar();
		dD->alg4(lAnioNac);
	}

	lAnioNac->moverInicio();
	for(int i=0; !lAnioNac->finLista(); i++){							
		lAnioNac->consultar(anNacAux);
		if(i*RANGO_EDAD_ALG_4 == anNacAux->getAnio()){ 					
			nPersonas = anNacAux->getNPersonas();
			cont[i] += nPersonas;
			lAnioNac->avanzar();										
			if(anNacAux->getAnio() > mayorMarca) 			            
				mayorMarca = (anNacAux->getAnio());
			if(anNacAux->getNPersonas() > modaNPersonas)				
				modaNPersonas = anNacAux->getNPersonas();
		}else{															
			nPersonas = 0;
		}
		cout << i*RANGO_EDAD_ALG_4 << " a " << (i+1)*RANGO_EDAD_ALG_4 - 1 << " - " << nPersonas << " persona(s)" << endl;	//Muestra el resultado del intervalo i-ésimo con amplitud RANGO_EDAD_ALG_4
	}
	nPersPorDiv = modaNPersonas % 275;									
	cadMayorMarca = int_to_string(mayorMarca);							

	cout << "\nREPRESENTACIÓN GRÁFICA - APROXIMACIÓN A UN HISTOGRAMA DE FRECUENCIAS\t" << "· = " << nPersPorDiv << " personas (aprox.)" << endl << endl;
	lAnioNac->moverInicio();
	for(int i=0; !lAnioNac->finLista(); i++){							
		lAnioNac->consultar(anNacAux);
		if(i*RANGO_EDAD_ALG_4 == anNacAux->getAnio()){ 					
			nDivisiones = anNacAux->getNPersonas() / nPersPorDiv;
			lAnioNac->avanzar();										
			if(nDivisiones == 0){ nDivisiones++; }						
		}else{															
			nDivisiones = 0;
		}
		for(int j=0; j<nDivisiones; j++){ cadDivisiones.append(carDivision); }												
		for(int j=0; j<(cadMayorMarca.length() - int_to_string(i*RANGO_EDAD_ALG_4).length()); j++){ cadSep.append("  "); }	
		if(int_to_string(i*RANGO_EDAD_ALG_4).length() != int_to_string(i*RANGO_EDAD_ALG_4 + RANGO_EDAD_ALG_4-1).length())	
			cadSep.erase(cadSep.length()-1, 1);																				
		cout << "(" << i*RANGO_EDAD_ALG_4 << " , " << (i+1)*RANGO_EDAD_ALG_4 - 1 << ")  " << cadSep << "|" << cadDivisiones << endl;

		cadSep.clear();		
		cadDivisiones.clear();
	}

	lAnioNac->moverInicio();
	while(!lAnioNac->finLista()){										
		lAnioNac->consultar(anNacAux);
		lAnioNac->avanzar();
		delete anNacAux;												
	}
	delete lAnioNac;													
}

void alg5(ListaPI<DatosDemograficos*>& lDatDem, int cont[]) {
	ListaPI<Nacionalidad*>* lNacion = new ListaPI<Nacionalidad*>();
 	DatosDemograficos* dD;
	Nacionalidad* nacionAux;
	int i = 0;

	lDatDem.moverInicio();
	while(!lDatDem.finLista()){
		lDatDem.consultar(dD);
		lDatDem.avanzar();
		dD->alg5(lNacion);
	}

	lNacion->moverInicio();
	while(!lNacion->finLista()){
		lNacion->consultar(nacionAux);
		lNacion->avanzar();
		cont[i] += nacionAux->getNPersonas();
		cout << nacionAux->getNacionalidad() << " (" << nacionAux->getNPersonas() << ")" << endl;
		i++;
	}

	lNacion->moverInicio();
	while(!lNacion->finLista()){
		lNacion->consultar(nacionAux);
		lNacion->avanzar();
		delete nacionAux;
	}
	delete lNacion;
}

void alg6(ListaPI<DatosDemograficos*>& lDatDem, int cont[]) {
	ListaPI<LugarNacimiento*>* lLugNac = new ListaPI<LugarNacimiento*>();
 	DatosDemograficos* dD;												
	LugarNacimiento* lugNacAux;
	int i = 0;

	lDatDem.moverInicio();
	while(!lDatDem.finLista()){								
		lDatDem.consultar(dD);
		lDatDem.avanzar();
		dD->alg6(lLugNac);												
	}

	lLugNac->moverInicio();
	while(!lLugNac->finLista()){										
		lLugNac->consultar(lugNacAux);
		lLugNac->avanzar();
		cont[i] += lugNacAux->getNPersonas();
		cout << lugNacAux->getProvinciaPais() << " (" << lugNacAux->getNPersonas() << ")" << endl;
		i++;
	}

	lLugNac->moverInicio();
	while(!lLugNac->finLista()){										
		lLugNac->consultar(lugNacAux);
		lLugNac->avanzar();
		delete lugNacAux;												
	}
	delete lLugNac;														
}

void alg7(GestorBarrio& gBarrio, int limInf, int limSup) {
	if(limInf <= limSup)
		gBarrio.alg7(limInf, limSup);
	else
		cout << "ERROR : El límite inferior (" << limInf << ") debe ser inferior al límite superior (" << limSup << ")" << endl;
}

void alg8(GestorBarrio& gBarrio, string nombreBarrio) {								///@NOTA: Método invocativo
	gBarrio.alg8(nombreBarrio);
}

void alg9(GestorBarrio& gBarrio) {
	gBarrio.alg9();
}

void alg10(ListaPI<DatosDemograficos*>& lDatDem, string nombreProvincia) {
	ListaPI<LugarNacimiento*>* lLugNac = new ListaPI<LugarNacimiento*>();
	ofstream ofs;
	string ruta = "Poblaciones-";
	string extension = ".txt";
	DatosDemograficos* dD;
	LugarNacimiento* lugNacAux;

	lDatDem.moverInicio();
	while (!lDatDem.finLista()){
		lDatDem.consultar(dD);
		lDatDem.avanzar();
		dD->alg10(lLugNac, nombreProvincia);
	}

	ruta += nombreProvincia + extension;
	ofs.open(ruta.c_str(), ios::app);
	if(ofs.is_open()){
		if(!lLugNac->estaVacia()){
			ofs << "\n\nCenso de las poblaciones que pertenecen a la provincia - " << nombreProvincia << endl;
			ofs << "-----------------------------------------------------------------------------------------------" << endl;
			lLugNac->moverInicio();
			while(!lLugNac->finLista()){
				lLugNac->consultar(lugNacAux);
				lLugNac->avanzar();
				ofs << lugNacAux->getPoblacion() << " (" << lugNacAux->getNPersonas() << ")" << endl;
			}
		}else{
			cout << "NO SE HA ENCONTRADO NINGUNA POBLACIÓN PARA LA PROVINCIA (" << nombreProvincia << ")" << endl;
		}
	}else{
		cout << "ERROR AL CREAR EL FICHERO PARA VOLCAR LOS RESULTADOS" << endl;
	}
	ofs.close();

	//Libera la memoria asociada a los nuevos datos creados
	lLugNac->moverInicio();
	while(!lLugNac->finLista()){
		lLugNac->consultar(lugNacAux);
		lLugNac->avanzar();
		delete lugNacAux;
	}
	delete lLugNac;
}

void alg11_EDL(ListaPI<Via*>& lVias, string nombreVia) {
	ofstream ofs;
	bool enc = false;
	string ruta = "LugaresNacimiento-";
	string extension = ".txt";
	Via* vAux;

	ruta += nombreVia + extension;
	ofs.open(ruta.c_str(), ios::app);
	if(ofs.is_open()){
		ofs << "\n\nLista de LUGARES de NACIMIENTO para la VIA - " << nombreVia << endl;
		ofs << "-----------------------------------------------------------------------------------------------" << endl;
		lVias.moverInicio();
		while(!lVias.finLista() && !enc){
			lVias.consultar(vAux);
			lVias.avanzar();
			if(vAux->getNombreVia() == nombreVia){
				vAux->alg11(ofs);
				enc = true;
			}
		}
		if(!enc)
			cout << "NO SE HA ENCOTRADO LA VÍA (" << nombreVia << ")" << endl;
	}else{
		cout << "ERROR AL CREAR EL FICHERO PARA VOLCAR LOS RESULTADOS" << endl;
	}
	ofs.close();
}

void alg11_EDNL(Arbol<Via*, ComparadorPtrVia>* aVias, string nombreVia, bool& enc) {
	ofstream ofs;
	string ruta = "LugaresNacimiento-";
	string extension = ".txt";

	ruta += nombreVia + extension;
	ofs.open(ruta.c_str(), ios::app);
	if(ofs.is_open()){
		if(!aVias->vacio()){
			ofs << "\n\nLista de LUGARES de NACIMIENTO para la VIA - " << nombreVia << endl;
			ofs << "-----------------------------------------------------------------------------------------------" << endl;
			alg11(aVias, nombreVia, enc);
		}
	}
	ofs.close();

	if(!enc)
		cout << "NO SE HA ENCONTRADO NINGUNA VÍA CON EL NOMBRE (" << nombreVia << ")" << endl;
}

void alg12_EDL(ListaPI<Via*>& lVias, string raiz, string nombreProvincia) {
	int nPersonas = 0;
	Via* vAux;
	bool coincidencia = false;
	int cod;
	ListaPI<int> lCoincidencias;

	lVias.moverInicio();
	while(!lVias.finLista()){
		lVias.consultar(vAux);
		lVias.avanzar();
		if(vAux->getNombreVia().find(raiz) == 0){
			lCoincidencias.moverInicio();
			while(!lCoincidencias.finLista() && !coincidencia){
				lCoincidencias.consultar(cod);
				lCoincidencias.avanzar();
				if(vAux->getCodVia() == cod)
					coincidencia = true;
			}
			if(!coincidencia){
				nPersonas += vAux->alg12(nombreProvincia);
				lCoincidencias.insertar(vAux->getCodVia());
			}
			coincidencia = false;
		}
	}

	if(nPersonas != 0){
		cout << "Nº de HABITANTES nacidos en la PROVINCIA - " << nombreProvincia << " - para la todas las VÍAS comenzando por la RAÍZ - \'"
				 << raiz << "\' :\t" << nPersonas << " habitantes" << endl;
		cout << "---------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}else{
		cout << "NO SE HA ENCONTRADO NINGUNA VÍA POR LA RÁIZ (" << raiz << ") O NINGÚN HABITANTE PARA LA PROVINCIA (" << nombreProvincia << ")" << endl;
	}
}

int	filtroInOrden(Arbol<Via*, ComparadorPtrVia>* aVias, string raiz, string nombreProvincia, ListaPI<int>*& lCoincidencias) {
	int nPersonas = 0;
	int intAux;
	bool coincidencia = false;

	if(aVias->hijoIzq() != NULL)
		nPersonas += filtroInOrden(aVias->hijoIzq(), raiz, nombreProvincia, lCoincidencias);

	if(aVias->raiz()->getNombreVia().find(raiz) == 0){
		lCoincidencias->moverInicio();
		while(!lCoincidencias->finLista() && !coincidencia){
			lCoincidencias->consultar(intAux);
			lCoincidencias->avanzar();
			if(aVias->raiz()->getCodVia() == intAux)
				coincidencia = true;
		}
		if(!coincidencia){
			nPersonas += aVias->raiz()->alg12(nombreProvincia);
			lCoincidencias->insertar(aVias->raiz()->getCodVia());
		}
	}

	if(aVias->hijoDer() != NULL)
		nPersonas += filtroInOrden(aVias->hijoDer(), raiz, nombreProvincia, lCoincidencias);

	return nPersonas;
}

void alg12_EDNL(Arbol<Via*, ComparadorPtrVia>* aVias, string raiz, string nombreProvincia) {
	Arbol<Via*, ComparadorPtrVia>* aAux;
	int nPersonas;
	ListaPI<int>* lCoincidencias = new ListaPI<int>();

	if(!aVias->vacio()){
		aAux = alg12(aVias, raiz);

		if(aAux != NULL){
			nPersonas = filtroInOrden(aAux, raiz, nombreProvincia, lCoincidencias);//Calcula el número de habitantes para la provincia dada.
			if(nPersonas != 0){
				cout << "Nº de HABITANTES nacidos en la PROVINCIA - " << nombreProvincia << " - para la todas las VÍAS comenzando por la RAÍZ - \'"
					 << raiz << "\' :\t" << nPersonas << " habitantes" << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			}else{
				cout << "NO SE HA ENCONTRADO NINGÚN HABITANTE PARA LA PROVINCIA (" << nombreProvincia << ")" << endl;
			}
		}else{
			cout << "NO SE HA ENCONTRADO NINGUNA VÍA QUE COMIENCE POR LA RAÍZ (" << raiz << ")" << endl;
		}
	}

	delete lCoincidencias;
}

}
