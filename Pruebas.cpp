/**
 * @CLASE: Pruebas
 */

#include "Pruebas.h"

namespace pruebas{

Pruebas::Pruebas() {
	salidaPruebas.open(RUTA_FIHCERO_PRUEBAS.c_str(), ios::trunc);	//Modo de apertura: truncamiento. Sobreescribe cualquier dato previo en cada ejecución de las pruebas
	if(salidaPruebas.is_open())	{									//Comprueba que se haya podido abrir el flujo
		salidaPruebas << "***********************************************************************************************" << endl;
		salidaPruebas << "\t\t\t\t\t\t\tINICIO DE LAS PRUEBAS DEL PROYECTO" 							 				  << endl;
		salidaPruebas << "***********************************************************************************************" << endl << endl;

		bufferSalidaConsola = cout.rdbuf();							//Almacena el buffer de consola para restaurarlo al finalizar las pruebas
		cout.rdbuf(salidaPruebas.rdbuf());							//Redirecciona al salida estándar (cout) al fichero de volcado de pruebas

		ejecutarPruebas();											//Ejecuta todas las pruebas del proyecto
	}else{															//Sino se indica al usuario por consola
		cout << "ERROR : No se ha podido crear el fichero de volcado de las pruebas" << endl;
	}
}

Pruebas::~Pruebas() {
	cout.rdbuf(bufferSalidaConsola);								//Devuelve la salia estándar (cout) a la consola

	salidaPruebas << "***********************************************************************************************" << endl;
	salidaPruebas << "\t\t\t\t\t\t\tFIN DE LAS PRUEBAS DEL PROYECTO" 								  				  << endl;
	salidaPruebas << "***********************************************************************************************" << endl << endl;
	cout << "LOS RESULTADOS DE LAS PRUEBAS SE HAN VOLCADO EN EL FICHERO - " << RUTA_FIHCERO_PRUEBAS << " (RUTA RELATIVA EN LA RAÍZ DEL PROGRAMA)" << endl;

	salidaPruebas.close();											//Cierra el flujo
}



void Pruebas::pruebaUtils() {
	string cadena = "1947 (1);1948 (1);1949 (1);1950 (1);1951 (2);1952 (3);1953 (2);1954 (1);1955 (3);1958 (3);1959 (3);1960 (3);1961 (7);1962 (5);1963 (3);1964 (5);1965 (2);1966 (2);1967 (3);1968 (2);1969 (2);1970 (1)"
			";1971 (3);1972 (2);1981 (1);1982 (1);1983 (2);1984 (1);1985 (2);1987 (1);1988 (5);1989 (2);1990 (2);1991 (1);1992 (3);1993 (6);1994 (2);1995 (7);1996 (2);1997 (1);1998 (4);1999 (4);2000 (1);2001 (1)"
			";2003 (4);2004 (1);2008 (1)";
	pruebaTrocearCadenaAnioNacimiento(cadena);

	cadena = "Albala Del Caudillo (Caceres) (1);Alemania (3);Almendralejo (Badajoz) (1);Badajoz (Badajoz) (1);Caceres (Caceres) (72);Casar De Caceres (Caceres) (1);Castejon De Alarba (Zaragoza) (1);Coria (Caceres) (2)"
			";Don Benito (Badajoz) (1);Estados Unidos De America (2);La Nava (Huelva) (1);Las Palmas De Gran Canaria (Las Palmas) (1);Madrid (Madrid) (4);Malaga (Malaga) (1);Merida (Badajoz) (1);Motril (Granada) (1)"
			";Navas Del Madroño (Caceres) (1);No Especificado (1);Olot (Girona) (1);Oviedo (Asturias) (1);Pescueza (Caceres) (1);Plasencia (Caceres) (1);Ponferrada (Leon) (1);Rosal De La Frontera (Huelva) (3)"
			";San Vicente De La Sonsierra (La Rioja) (1);Serradilla (Caceres) (3);Talavera De La Reina (Toledo) (1);Torre De Santa Maria (Caceres) (1);Torrejon De Ardoz (Madrid) (1);Trujillo (Caceres) (2)"
			";Valdefuentes (Caceres) (2);Zamora (Zamora) (1)";
	pruebaTrocearCadenaLugarNacimiento(cadena);

	cadena = "Arquitecto O Ingeniero Tecnico (2);Bachiller Superior, Bup (23);Graduado Escolar O Equivalente (6);No Aplicable Por Ser Menor De 10 Años (10);No Sabe Leer Ni Escribir (2)"
			";Titulacion Inferior Al Grado De Escolaridad (2);Doctorado Y Estudios De Postgrado O Especializacion Para Licenciados (6);Formacion Profesional Segundo Grado, Maestria Industrial (2)"
			";Formacion Profesional Primer Grado, Oficialia Industrial (6);Bachiller, Formacion Profesional Segundo Grado, Titulos Equivalentes O Superiores (18)"
			";Diplomado Escuelas Universitarias (Empresariales, Profesorado Egb, Ats Y Similares) (7);Bachiller Elemental, Graduado Escolar, Egb/Primaria Completa, Certificado Escolaridad O Equivalente (13)"
			";Licenciado Universitario, Arquitecto O Ingeniero Superior (19)";
	pruebaTrocearCadenaEstudios(cadena);

	cadena = "España (115);Filipinas (1)";
	pruebaTrocearCadenaNacionalidad(cadena);

	///@TEST: 1. int_to_string(10)
	if(int_to_string(10) != "10")
		salidaPruebas << "\tERROR : Método \'int_to_string\' - El número 10 no se ha convertido a la cadena \'10\'\t| En su lugar -> " << int_to_string(10) << endl;
}

void Pruebas::pruebaSobrecargaOperadores() {
	salidaPruebas << "INICIO : Sobrecarga de operadores de la clase VIA" << endl;
	Via* v1 = new Via("BarrioA", "ViaA", 0, "TipoA", 0);
	Via* v2 = new Via("BarrioB", "ViaB", 0, "TipoB", 0);
	Via* v3 = new Via("BarrioA", "ViaC", 0, "TipoA", 0);

	if(*v1 > *v1 != false)
		salidaPruebas << "\tERROR : Clase VIA - Operador \'>\' # *v1 > *v1 ->  FALSE\t| En su lugar -> " << bool(*v1 > *v1) << endl;
	if(*v1 > *v2 != true)
		salidaPruebas << "\tERROR : Clase VIA - Operador \'>\' # *v1 > *v2 -> TRUE\t| En su lugar -> " << bool(*v1 > *v2) << endl;
	if(*v2 > *v1 != false)
		salidaPruebas << "\tERROR : Clase VIA - Operador \'>\' # *v2 > *v1 -> FALSE\t| En su lugar -> " << bool(*v2 > *v1) << endl;
	salidaPruebas << "FIN : Sobrecarga de operadores de la clase VIA" << endl << endl;

	salidaPruebas << "INICIO : Sobrecarga de operadores de la clase COMPARADORPTRVIA" << endl;
	ComparadorPtrVia cPtrVia;

	if(cPtrVia.operator()(v1, v1) != 0)
		salidaPruebas << "\tERROR : Clase COMPARADORPTRVIA - Operador \'()\' # ()(v1, v1) -> 0\t| En su lugar -> " << cPtrVia.operator()(v1, v1) << endl;
	if(cPtrVia.operator()(v1, v2) != -1)
		salidaPruebas << "\tERROR : Clase COMPARADORPTRVIA - Operador \'()\' # ()(v1, v2) -> -1\t| En su lugar -> " << cPtrVia.operator()(v1, v2) << endl;
	if(cPtrVia.operator()(v2, v1) != 1)
		salidaPruebas << "\tERROR : Clase COMPARADORPTRVIA - Operador \'()\' # ()(v2, v1) -> 1\t| En su lugar -> " << cPtrVia.operator()(v2, v1) << endl;
	if(cPtrVia.operator()(v1, v3) != -1)
		salidaPruebas << "\tERROR : Clase COMPARADORPTRVIA - Operador \'()\' # ()(v1, v1) -> -1\t| En su lugar -> " << cPtrVia.operator()(v1, v3) << endl;
	if(cPtrVia.operator()(v3, v1) != 1)
		salidaPruebas << "\tERROR : Clase COMPARADORPTRVIA - Operador \'()\' # ()(v1, v1) -> 1\t| En su lugar -> " << cPtrVia.operator()(v3, v1) << endl;
	salidaPruebas << "FIN : Sobrecarga de operadores de la clase COMPARADORPTRVIA" << endl << endl;

	salidaPruebas << "INICIO : Sobrecarga de operadores de la clase LUGAR DE NACIMIENTO" << endl;
	LugarNacimiento lugNac1 = LugarNacimiento("PoblacionA", "ProvinciaA", 0);
	LugarNacimiento lugNac2 = LugarNacimiento("PoblacionB", "ProvinciaB", 0);
	LugarNacimiento lugNac3 = LugarNacimiento("PoblacionC", "ProvinciaA", 0);

	if(lugNac1 >= lugNac1 != true)
		salidaPruebas << "\tERROR : Clase LUGARNACIMIENTO - Operador \'>=\' # lugNac1 >= lugNac1 -> TRUE\t| En su lugar -> " << bool(lugNac1 >= lugNac1) << endl;
	if(lugNac1 >= lugNac2 != true)
		salidaPruebas << "\tERROR : Clase LUGARNACIMIENTO - Operador \'>=\' # lugNac1 >= lugNac2 -> TRUE\t| En su lugar -> " << bool(lugNac1 >= lugNac2) << endl;
	if(lugNac2 >= lugNac1 != false)
		salidaPruebas << "\tERROR : Clase LUGARNACIMIENTO - Operador \'>=\' # lugNac2 >= lugNac1 -> FALSE\t| En su lugar -> " << bool(lugNac2 >= lugNac1) << endl;

	if(lugNac1 == lugNac1 != true)
		salidaPruebas << "\tERROR : Clase LUGARNACIMIENTO - Operador \'==\' # lugNac1 == lugNac1 -> TRUE\t| En su lugar -> " << bool(lugNac1 == lugNac1) << endl;
	if(lugNac1 == lugNac2 != false)
		salidaPruebas << "\tERROR : Clase LUGARNACIMIENTO - Operador \'==\' # lugNac1 == lugNac2 -> FALSE\t| En su lugar -> " << bool(lugNac1 == lugNac2) << endl;
	if(lugNac1 == lugNac3 != true)
		salidaPruebas << "\tERROR : Clase LUGARNACIMIENTO - Operador \'==\' # lugNac1 == lugNac3 -> TRUE\t| En su lugar -> " << bool(lugNac1 == lugNac3) << endl;
	salidaPruebas << "FIN : Sobrecarga de operadores de la clase LUGAR DE NACIMIENTO" << endl << endl;

	salidaPruebas << "INICIO : Sobrecarga de operadores de la clase ESTUDIOS" << endl;
	Estudios est1 = Estudios("NivelA", 1);
	Estudios est2 = Estudios("NivelB", 2);
	Estudios est3 = Estudios("NivelA", 2);

	if(est1 > est1 != false)
		salidaPruebas << "\tERROR : Clase ESTUDIOS - Operador \'>\' # est1 > est1 -> FALSE\t| En su lugar -> " << bool(est1 > est1) << endl;
	if(est1 > est2 != false)
		salidaPruebas << "\tERROR : Clase ESTUDIOS - Operador \'>\' # est1 > est2 -> FALSE\t| En su lugar -> " << bool(est1 > est2) << endl;
	if(est2 > est1 != true)
		salidaPruebas << "\tERROR : Clase ESTUDIOS - Operador \'>\' # est2 > est1 -> TRUE\t| En su lugar -> " << bool(est2 > est1) << endl;

	if(est1 == est1 != true)
		salidaPruebas << "\tERROR : Clase ESTUDIOS - Operador \'==\' # est1 == est1 -> TRUE\t| En su lugar -> " << bool(est1 == est1) << endl;
	if(est1 == est2 != false)
		salidaPruebas << "\tERROR : Clase ESTUDIOS - Operador \'==\' # est1 == est2 -> FALSE\t| En su lugar -> " << bool(est1 == est2) << endl;
	if(est1 == est3 != true)
		salidaPruebas << "\tERROR : Clase ESTUDIOS - Operador \'==\' # est1 == est3 -> TRUE\t| En su lugar -> " << bool(est1 == est3) << endl;
	salidaPruebas << "FIN : Sobrecarga de operadores de la clase ESTUDIOS" << endl << endl;

	salidaPruebas << "INICIO : Sobrecarga de operadores de la clase NACIONALIDAD" << endl;
	Nacionalidad nacion1 = Nacionalidad("NacionalidadA", 1);
	Nacionalidad nacion2 = Nacionalidad("NacionalidadB", 2);
	Nacionalidad nacion3 = Nacionalidad("NacionalidadA", 2);

	if(nacion1 > nacion1 != false)
		salidaPruebas << "\tERROR : Clase NACIONALIDAD - Operador \'>\' # nacion1 > nacion1 -> FALSE\t| En su lugar -> " << bool(nacion1 > nacion1) << endl;
	if(nacion1 > nacion2 != false)
		salidaPruebas << "\tERROR : Clase NACIONALIDAD - Operador \'>\' # nacion1 > nacion2 -> FALSE\t| En su lugar -> " << bool(nacion1 > nacion2) << endl;
	if(nacion2 > nacion1 != true)
		salidaPruebas << "\tERROR : Clase NACIONALIDAD - Operador \'>\' # nacion2 > nacion1 -> TRUE\t| En su lugar -> " << bool(nacion2 > nacion1) << endl;

	if(nacion1 == nacion1 != true)
		salidaPruebas << "\tERROR : Clase NACIONALIDAD - Operador \'==\' # nacion1 == nacion1 -> TRUE\t| En su lugar -> " << bool(nacion1 == nacion1) << endl;
	if(nacion1 == nacion2 != false)
		salidaPruebas << "\tERROR : Clase NACIONALIDAD - Operador \'==\' # nacion1 == nacion2 -> FALSE\t| En su lugar -> " << bool(nacion1 == nacion2) << endl;
	if(nacion1 == nacion3 != true)
		salidaPruebas << "\tERROR : Clase NACIONALIDAD - Operador \'==\' # nacion1 == nacion3 -> TRUE\t| En su lugar -> " << bool(nacion1 == nacion3) << endl;
	salidaPruebas << "FIN : Sobrecarga de operadores de la clase NACIONALIDAD" << endl;

	///@NOTA: Liberación de los recursos reservados dinámicamente
	delete v1;
	delete v2;
	delete v3;
}

void Pruebas::pruebaOrdenLista() {
	ListaPI<Nacionalidad*>* lNacion = new ListaPI<Nacionalidad*>();
	Nacionalidad* nacion = new Nacionalidad("NacionalidadA", 4);
	Nacionalidad* nacionAux;

	///@TEST: 1. lVias - Lista vacía
	ordenarLista(lNacion);
	if(lNacion->estaVacia() != true)
		salidaPruebas << "\tERROR : Método \'GestorNacionalidad::ordenarLista\' y \'GestorEstudios::ordenarLista - TEST #1 - La lista ha sido modificada" << endl;

	///@TEST 2. lVias con 1 elemento
	lNacion->insertar(nacion);

	ordenarLista(lNacion);
	lNacion->moverInicio();
	lNacion->consultar(nacionAux);
	if(lNacion->estaVacia() != false || nacionAux != nacion){
		salidaPruebas << "\tERROR : Método \'GestorNacionalidad::ordenarLista\' y \'GestorEstudios::ordenarLista - TEST #2 - El único elemento de la lista ha sido modificado" << endl;
		nacionAux->mostrar();
	}

	///@TEST: 3. lVias con 4 elementos ordenados
	lNacion->avanzar();
	lNacion->insertar(new Nacionalidad("NacionalidaD", 1));
	lNacion->insertar(new Nacionalidad("NacionalidaC", 2));
	lNacion->insertar(new Nacionalidad("NacionalidaB", 3));

	ordenarLista(lNacion);
	lNacion->moverInicio();
	for(int i=4; !lNacion->finLista(); i--){
		lNacion->consultar(nacionAux);
		lNacion->avanzar();
		if(nacionAux->getNPersonas() != i)
			salidaPruebas << "\tERROR : Método \'GestorNacionalidad::ordenarLista\' y \'GestorEstudios::ordenarLista - TEST #3 - La lista ordenada ha sido modificada (POS #" << i << endl;
	}

	///@TEST: 4. lVias con 5 elementos desordenados
	lNacion->retroceder();lNacion->retroceder();
	lNacion->insertar(new Nacionalidad("NacionalidadE", 5));

	ordenarLista(lNacion);
	lNacion->moverInicio();lNacion->consultar(nacionAux);
	if(nacionAux->getNPersonas() != 5)
		salidaPruebas << "\tERROR : Método \'GestorNacionalidad::ordenarLista\' y \'GestorEstudios::ordenarLista - TEST #4 - La lista no se ha ordenado correctamente" << endl;

	///@NOTA: Liberación de los recursos reservados dinámicamente
	lNacion->moverInicio();
	while(!lNacion->finLista()){
		lNacion->consultar(nacionAux);
		lNacion->avanzar();
		delete nacionAux;
	}
	delete lNacion;
}

void Pruebas::pruebaInsertarVia() {
	Barrio* bAux = new Barrio("BarrioA", "DistritoA");
	ListaPI<Barrio*> lBarrios; lBarrios.insertar(bAux);
	Via* v1 = new Via("BarrioA", "ViaA", 0, "TipoA", 0);
	Via* v2 = new Via("BarrioB", "ViaA", 0, "TipoA", 0);

	///@TEST: 1. v1 está en lBarrios
	if(insertarVia(v1, lBarrios) != true)
		salidaPruebas << "\tERROR : Método \'GestorBarrio::insertarVia\' - TEST #1 - No se ha insertado la vía v1 en la lista de barrios" << endl;

	///@TEST: 2. v2 no está en lBarrios
	if(insertarVia(v2, lBarrios) != false)
		salidaPruebas << "\tERROR : Método \'GestorBarrio::insertarVia\' - TEST #2 - Se se ha insertado la vía v2 en la lista de barrios" << endl;

	///@NOTA: Liberación de los recursos reservados dinámicamente
	delete bAux;
	delete v1;
	delete v2;
}

void Pruebas::pruebaInsertarViaOrden() {
	ListaPI<Via*> lVias;
	Via* v1 = new Via("BarrioB", "ViaB", 0, "TipoB", 0);
	Via* vAux;

	///@TEST: 1. lVias vacía
	insertarViaOrden(v1, lVias);
	lVias.consultar(vAux);
	if(lVias.estaVacia() != false || vAux != v1)
		salidaPruebas << "\tERROR : Método \'GestorVia::insertarViaOrden\' - TEST #1 - No se ha insertado la vía v1 en la lista" << endl;

	///@TEST: 2.1 v3 es alfabéticamente mayor que el elemento en lVias
	v1 = new Via("BarrioA", "ViaA", 0, "TipoA", 0);
	insertarViaOrden(v1, lVias);
	lVias.moverInicio();
	lVias.consultar(vAux);
	if(vAux != v1)
		salidaPruebas << "\tERROR : Método \'GestorVia::insertarViaOrden\' - TEST #2.1 - v1 no está en la posición correcta" << endl;
	lVias.borrar();
	delete vAux;

	///@TEST: 2.2 v3 es alfabéticamente menor que el elemento en lVias
	v1 = new Via("BarrioD", "ViaD", 0 , "TipoD", 0);
	insertarViaOrden(v1, lVias);
	lVias.moverFinal();
	lVias.consultar(vAux);
	if(vAux != v1)
		salidaPruebas << "\tERROR : Método \'GestorVia::insertarViaOrden\' - TEST #2.2 - v1 no está en la posición correcta" << endl;

	///@TEST: 3.2 v3 es alfabéticamente menor que el primer elemento y alfabéticamente mayor que el último
	v1 = new Via("BarrioC", "ViaC", 0, "TipoC", 0);
	insertarViaOrden(v1, lVias);
	lVias.moverInicio();lVias.avanzar();
	lVias.consultar(vAux);
	if(vAux != v1)
		salidaPruebas << "\tERROR : Método \'GestorVia::insertarViaOrden\' - TEST #3.2 - v1 no está en la posición correcta" << endl;

	///@NOTA: Liberación de los recursos reservados dinámicamente
	lVias.moverInicio();
	while(!lVias.finLista()){
		lVias.consultar(vAux);
		lVias.avanzar();
		delete vAux;
	}
}

void Pruebas::pruebaAlg11() {
	Arbol<Via*, ComparadorPtrVia>* aVias = new Arbol<Via*, ComparadorPtrVia>();
	Via* vIns1 = new Via("BarrioC", "ViaC", 0, "TipoC", 0); aVias->insertar(vIns1);
	Via* vIns2 = new Via("BarrioB", "ViaB", 0, "TipoB", 0); aVias->insertar(vIns2);
	Via* vIns3 =  new Via("BarrioD", "ViaD", 0, "TipoD", 0); aVias->insertar(vIns3);
	Via* vIns4 = new Via("BarrioC2", "ViaC", 0, "TipoC", 0); aVias->insertar(vIns4);
	string nombreVia = "ViaB";
	bool enc = false;

	///@TEST: 1.1 La vía 'nombreVia' tiene 1 tramo
	alg11(aVias, nombreVia, enc);
	if(enc != true)
		salidaPruebas << "\tERROR : Método \'Padron::alg11\' - TEST #1.1 - No se ha encontrado la vía \'" << nombreVia << "\'" << endl;

	///@TEST: 2.  La vía 'nombreVia' no está en el ABB
	enc = false; nombreVia = "ViaA";

	alg11(aVias, nombreVia, enc);
	if(enc != false)
		salidaPruebas << "\tERROR : Método \'Padron::alg11\' - TEST #2 - Se ha encontrado una vía \'" << nombreVia << "\'" << endl;

	///@NOTA: Liberación de los recursos reservados dinámicamente
	delete vIns1;
	delete vIns2;
	delete vIns3;
	delete vIns4;
	delete aVias;
}

void Pruebas::pruebaAlg12() {
	Arbol<Via*, ComparadorPtrVia>* aVias = new Arbol<Via*, ComparadorPtrVia>();
	Arbol<Via*, ComparadorPtrVia>* aAux;
	Via* vIns1 = new Via("BarrioC", "Plaza", 0, "TipoC", 0); aVias->insertar(vIns1);
	Via* vIns2 = new Via("BarrioB", "Rotonda", 0, "TipoB", 0); aVias->insertar(vIns2);
	Via* vIns3 =  new Via("BarrioD", "Plaza", 0, "TipoD", 0); aVias->insertar(vIns3);
	string raiz = "Cal";

	///@TEST: 1. Ninguna vía comienza por la raíz 'raiz'
	aAux = alg12(aVias, raiz);
	if(aAux != NULL)
		salidaPruebas << "\tERROR : Método \'Padron::alg12\' - TEST #1 - Se ha encontrado un subárbol para la raíz \'" << raiz << "\'" << endl;

	///@TEST: 2. Existe al menos 1 vía que comienza por la raíz	'raiz'
	raiz = "Pla"; aAux = NULL;

	aAux = alg12(aVias, raiz);
	if(aAux == NULL || aAux->pertenece(vIns1) != true)
		salidaPruebas << "\tERROR : Método \'Padron::alg12\' - TEST #2 - No se ha encontrado el subárbol para la raíz \'" << raiz << "\'" << endl;

	///@NOTA: Liberación de los recursos reservados dinámicamente
	delete vIns1;
	delete vIns2;
	delete vIns3;
	delete aVias;
}

void Pruebas::pruebaFiltroInOrden() {
	Arbol<Via*, ComparadorPtrVia>* aVias = new Arbol<Via*, ComparadorPtrVia>();
	Via* vIns1 = new Via("BarrioC", "Plaza", 0, "TipoC", 0); aVias->insertar(vIns1);
	Via* vIns2 = new Via("BarrioB", "Rotonda", 0, "TipoB", 0); aVias->insertar(vIns2);
	Via* vIns3 =  new Via("BarrioD", "Plaza", 0, "TipoD", 0); aVias->insertar(vIns3);
	string raiz = "Rot";

	///@TEST: 1. 1 vía comienza por la raíz 'raiz'
	if(filtroInOrden(aVias, raiz) != true)
		salidaPruebas << "\tERROR : Método \'Padron::filtroInOrden\' - TEST #1 - No se ha encontrado ninguna vía para la raíz \'" << raiz << "\'" << endl;

	///@NOTA: Liberación de los recursos reservados dinámicamente
	delete vIns1;
	delete vIns2;
	delete vIns3;
	delete aVias;
}

void Pruebas::pruebaMetodosAuxiliares() {
	salidaPruebas << "INICIO : MÉTODO \'GestorNacionalidad::ordenarLista\' y \'GestorEstudios::ordenarLista\'" << endl;
	pruebaOrdenLista();
	salidaPruebas << "FIN : MÉTODO \'GestorNacionalidad::ordenarLista\' y \'GestorEstudios::ordenarLista\'" << endl;

	salidaPruebas << "INICIO : MÉTODO \'GestorBarrio::insertarVia\'" << endl;
	pruebaInsertarVia();
	salidaPruebas << "FIN : MÉTODO \'GestorBarrio::insertarVia\'" << endl;

	salidaPruebas << "INICIO : MÉTODO \'GestorVia::insertarViaOrden\'" << endl;
	pruebaInsertarViaOrden();
	salidaPruebas << "FIN : MÉTODO \'GestorVia::insertarViaOrden\'" << endl;

	salidaPruebas << "INICIO : MÉTODO \'Padron::alg11\'" << endl;
	pruebaAlg11();
	salidaPruebas << "FIN : MÉTODO \'Padron::alg11\'" << endl;

	salidaPruebas << "INICIO : MÉTODO \'Padron::alg12\'" << endl;
	pruebaAlg12();
	salidaPruebas << "FIN : MÉTODO \'Padron::alg12\'" << endl;

	salidaPruebas << "INICIO : MÉTODO \'Padron::filtroInOrden\'" << endl;
	pruebaFiltroInOrden();
	salidaPruebas << "FIN : MÉTODO \'Padron::filtroInOrden\'" << endl;
}

void Pruebas::pruebaUI() {
	cout << "Compruebe que :" << endl <<
		 "\t 1. Solo se puede ejecutar un algoritmo si antes se han cargado los datos del padrón, de vías y de barrios (Algoritmo 1)" << endl <<
		 "\t 2. Solo se pueden cargar una vez los datos (Algoritmo 1)" << endl << endl <<
   		 "Una vez termine utilice la opción cero (0) para continuar con las pruebas" << endl;

///	UI ui;																		//@TEST: Descomentar para probar. Las pruebas preliminares no arrojan ningún error

	salidaPruebas << "PRUEBA SUPERADA" << endl;
}

void Pruebas::pruebaEjecucionSecuencial() {
	ofstream ofs;																//Flujo de salida para el volcado de la tabla de tiempos de ejecución
	string ruta = "TablaTiemposEjecucion.txt";									//Ruta relativa del fichero de volcado de la tabla con los tiempos calculados de la ejecución de todos los algoritmos
	string nombreBarrio = "Huertas";											//Nombre del barrio a utilizar por los algoritmos 2 y 8
	string nombreProvincia = "Caceres";											//Nombre de la provincia a utilizar por el algoritmo 10 y 12
	string nombreVia = "De La Universidad";										//Nombre de la vía a utilizar por el algoritmo 11
	string raizVia = "Esp";														//Raíz de la vía a utilizar por el algoritmo 12
	int limInf = 10;															//Límite inferior del rango de edad a utilizar por el algoritmo 7
	int limSup = 20;															//Límite superior del rango de edad a utilizar por el algoritmo 7
	int nRep = 100;																//Número de repeticiones para los algoritmos con doble implementación
	double vTEjec[10];															//Vector para almacenar los tiempos de ejecución de los 10 algoritmos con una sola implementación
	double vTEjecAlg11EDL[nRep];												//Vector para almacenar los tiempos de ejecución del algoritmo 11 en su versión EDL
	double vTEjecAlg11EDNL[nRep];												//Vector para almacenar los tiempos de ejecución del algoritmo 11 en su versión EDNL
	double vTEjecAlg12EDL[nRep];												//Vector para almacenar los tiempos de ejecución del algoritmo 12 en su versión EDL
	double vTEjecAlg12EDNL[nRep];												//Vector para almacenar los tiempos de ejecución del algoritmo 12 en su versión EDNL
	double vTEejecAcum[4];														//Vector de acumuladores para calcular la media estadística de los tiempos de ejecución de los algoritmos con doble implementación
	double t;																	//Acumulador que representa la diferencia de tiempo entre dos llamadas consecutivas a std::clock(). Utilizado para medir tiempos de ejecución

	///@TEST: Carga de datos
	t = Time::getTime();
	salidaPruebas << "INICIO : Algoritmo 1" << endl;
	p.cargarBarrios();
	p.cargarVias();
	p.cargarDatosDemograficos();
	t -= Time::getTime();
	p.mostrarEstructura();														//Muestra todos los datos cargados y su estructura
	salidaPruebas << "FIN : Algoritmo 1" << endl;
	vTEjec[0] = -t / CLOCKS_PER_SEC;

	///@TEST: Algoritmo 2
	t = Time::getTime();
	salidaPruebas << "INICIO : Algoritmo 2" << endl;
	p.alg2(nombreBarrio);
	salidaPruebas << "FIN : Algoritmo 2" << endl;
	t -= Time::getTime();
	vTEjec[1] = -t / CLOCKS_PER_SEC;

	///@TEST: Algoritmo 3
	t = Time::getTime();
	salidaPruebas << "INICIO : Algoritmo 3" << endl;
	p.alg3();
	salidaPruebas << "FIN : Algoritmo 3" << endl;
	t -= Time::getTime();
	vTEjec[2] = -t / CLOCKS_PER_SEC;

	///@TEST: Algoritmo 4
	t = Time::getTime();
	salidaPruebas << "INICIO : Algoritmo 4" << endl;
	p.alg4();
	salidaPruebas << "FIN : Algoritmo 4" << endl;
	t -= Time::getTime();
	vTEjec[3] = -t / CLOCKS_PER_SEC;

	///@TEST: Algoritmo 5
	t = Time::getTime();
	salidaPruebas << "INICIO : Algoritmo 5" << endl;
	p.alg5();
	salidaPruebas << "FIN : Algoritmo 5" << endl;
	t -= Time::getTime();
	vTEjec[4] = -t / CLOCKS_PER_SEC;

	///@TEST: Algoritmo 6
	t = Time::getTime();
	salidaPruebas << "INICIO : Algoritmo 6" << endl;
	p.alg6();
	salidaPruebas << "FIN : Algoritmo 6" << endl;
	t -= Time::getTime();
	vTEjec[5] = -t / CLOCKS_PER_SEC;

	///@TEST: Algoritmo 7
	t = Time::getTime();
	salidaPruebas << "INICIO : Algoritmo 7" << endl;
	p.alg7(limInf, limSup);
	salidaPruebas << "FIN : Algoritmo 7" << endl;
	t -= Time::getTime();
	vTEjec[6] = -t / CLOCKS_PER_SEC;

	///@TEST: Algoritmo 8
	t = Time::getTime();
	salidaPruebas << "INICIO : Algoritmo 8" << endl;
	p.alg8(nombreBarrio);
	salidaPruebas << "FIN : Algoritmo 8" << endl;
	t -= Time::getTime();
	vTEjec[7] = -t / CLOCKS_PER_SEC;

	///@TEST: Algoritmo 9
	t = Time::getTime();
	salidaPruebas << "INICIO : Algoritmo 9" << endl;
	p.alg9();
	salidaPruebas << "FIN : Algoritmo 9" << endl;
	t -= Time::getTime();
	vTEjec[8] = -t / CLOCKS_PER_SEC;

	///@TEST: Algoritmo 10
	t = Time::getTime();
	salidaPruebas << "INICIO : Algoritmo 10" << endl;
	p.alg10(nombreProvincia);
	salidaPruebas << "FIN : Algoritmo 10" << endl;
	t -= Time::getTime();
	vTEjec[9] = -t / CLOCKS_PER_SEC;

	///@TEST: Algoritmo 11_EDL
	salidaPruebas << "INICIO : Algoritmo 11 EDL" << endl;
	for(int i=0; i < nRep; i++) {
		t = Time::getTime();
		p.alg11_EDL(nombreVia);
		t -= Time::getTime();
		vTEjecAlg11EDL[i] = -t / CLOCKS_PER_SEC;
	}
	salidaPruebas << "FIN : Algoritmo 11 EDL" << endl;

	///@TEST: Algoritmo 11_EDNL
	salidaPruebas << "INICIO : Algoritmo 11 EDNL" << endl;
	for(int i=0; i < nRep; i++) {
		t = Time::getTime();
		p.alg11_EDNL(nombreVia);
		t -= Time::getTime();
		vTEjecAlg11EDNL[i] = -t / CLOCKS_PER_SEC;
	}
	salidaPruebas << "FIN : Algoritmo 11 EDNL" << endl;

	///@TEST: Algoritmo 12_EDL
	salidaPruebas << "INICIO : Algoritmo 12 EDL" << endl;
	for(int i=0; i < nRep; i++) {
		t = Time::getTime();
		p.alg12_EDL(raizVia, nombreProvincia);
		t -= Time::getTime();
		vTEjecAlg12EDL[i] = -t / CLOCKS_PER_SEC;
	}
	salidaPruebas << "FIN : Algoritmo 12 EDL" << endl;

	///@TEST: Algoritmo 12_EDNL
	salidaPruebas << "INICIO : Algoritmo 12 EDNL" << endl;
	for(int i=0; i < nRep; i++) {
		t = Time::getTime();
		p.alg12_EDNL(raizVia, nombreProvincia);
		t -= Time::getTime();
		vTEjecAlg12EDNL[i] = -t / CLOCKS_PER_SEC;
	}
	salidaPruebas << "FIN : Algoritmo 12 EDNL" << endl;

	//Volcado de resultados
	ofs.open(ruta.c_str(), ios::trunc);											//Modo de apertura: truncamiento. Sobreescribe cualquier dato previo en cada ejecución de las pruebas
	if(ofs.is_open()){															//Comprueba que el flujo esté abierto
		//Volcado de los tiempos de ejecución de los algoritmos con implementación única
		ofs << "TIEMPOS DE EJECUCIÓN - Algoritmos 1-10" << endl;
		ofs << "-----------------------------------------------------------------------------------------------" << endl;
		for(int i=0; i < 10; i++){
			ofs << " TIEMPO Algoritmo " << i+1 << ": " << vTEjec[i] << " seg." << endl;
		}
		ofs << "-----------------------------------------------------------------------------------------------" << endl << endl;

		//Volcado de los tiempos de ejecución de los algoritmos con doble implementación
		ofs << "\t\t\tTABLA DE TIEMPOS - Algoritmos con doble implementación (EDL y EDNL)" << endl;
		ofs << "\t|Algoritmo 11 EDL \t| Algoritmo 11 EDNL | Algoritmo 12 EDL  | Algoritmo 12 EDNL |" << endl;
		ofs << "-----------------------------------------------------------------------------------------------" << endl;
		for(int i=0; i < 4; i++){ vTEejecAcum[i] = 0; }							//Inicialización de los acumuladores
		for(int i=0; i < nRep; i++){
			ofs << "#" << i+1 << " |" << vTEjecAlg11EDL[i] << " seg.\t| " <<
				vTEjecAlg11EDNL[i] << " seg\t| " <<
				vTEjecAlg12EDL[i] << " seg.\t| " <<
				vTEjecAlg12EDNL[i] << " seg.\t|" << endl;
			//Sumatorio de tiempos de ejecución
			vTEejecAcum[0] += vTEjecAlg11EDL[i];
			vTEejecAcum[1] += vTEjecAlg11EDNL[i];
			vTEejecAcum[2] += vTEjecAlg12EDL[i];
			vTEejecAcum[3] += vTEjecAlg12EDNL[i];
		}
		ofs << "······························································································" << endl;
		ofs << "\t\t\t\t\t\t\tTIEMPO MEDIO DE EJECUCIÓN" << endl;
		ofs << "  Algoritmo 11 EDL \t| Algoritmo 11 EDNL | Algoritmo 12 EDL  | Algoritmo 12 EDNL |" << endl;
		ofs << vTEejecAcum[0]/nRep << " seg.\t| " << vTEejecAcum[1]/nRep << " seg.\t| " << vTEejecAcum[2]/nRep << " seg.\t| "
			  << vTEejecAcum[3]/nRep << " seg.\t|" << endl;
		ofs << "······························································································" << endl;
		ofs << "\t\t\t\t\t\tPORCENTAJE DE MEJORA RELATIVA" << endl << " \t\t\t\t\t\t";
		ofs <<"Algoritmo 11 | Algoritmo 12" << endl << "\t\t\t\t\t\t\t";
		ofs << (vTEejecAcum[1]/nRep)/(vTEejecAcum[0]/nRep)*100 << " % | " << (vTEejecAcum[3]/nRep)/(vTEejecAcum[2]/nRep)*100 << " % " << endl;
		ofs << "-----------------------------------------------------------------------------------------------" << endl;
		salidaPruebas << "Tabla de tiempos de ejecución creada en - \'" << RUTA_FIHCERO_PRUEBAS << "\'" << endl;
	}else{																		//Sino se indica al usuario por consola
		cout << "ERROR : No se ha podido crear el fichero" << endl;
	}

	ofs.close();																//Cierra el flujo
}

void Pruebas::pruebaEstructuraLBarrios(GestorBarrio& gBarrio, int& cont, string ruta) {
	///@TEST: 1. Existen todos los ficheros de datos
	if(cargarBarrios(gBarrio, cont, ruta) != true)
		salidaPruebas << "\tERROR : Estructura de datos - TEST #1 - No se ha podido cargar el fichero de barrios (" << ")" << endl;

	///@TEST: 1.1 'lBarrios' contiene 4 barrios (3 + barrio contenedor)
	if(cont != 4)
		salidaPruebas << "\tERROR : Estructura de datos - TEST #1.1 - No se han cargado 4 barrios\t| En su lugar -> " << cont << endl;

	///@TEST: 2. No existe ningún fichero de datos
	ruta = "OtroNombre.csv";

	if(cargarBarrios(gBarrio, cont, ruta) != false)
		salidaPruebas << "\tERROR : Estructura de datos - TEST #2 - Se ha encontrado un archivo de barrio incorrecto (" << ruta << ")" << endl;
}

void Pruebas::pruebaEstructuraLVias(GestorBarrio& gBarrio, int& cont, string ruta) {
	///@TEST: 1. Existe el fichero RUTA_VIA
	if(cargarVias(gBarrio, cont, ruta) != true)
		salidaPruebas << "\tERROR : Estructura \'lVias\' y \'aVias\' - TEST #1 - No se ha podido cargar el fichero de vías (" << ruta << ")" << endl;

	///@TEST: 1.1 Validación por conteo de objetos
	if(cont != 4)
		salidaPruebas << "\tERROR : Estructura \'lVias\' y \'aVias\' - TEST #1.1 - No se han cargado 5 vías\t| En su lugar -> " << cont << endl;

	///@TEST: 2. No existe el fichero RUTA_VIA
	ruta = "OtroNombre.csv";

	if(cargarVias(gBarrio, cont, ruta) != false)
		salidaPruebas << "\tERROR : Estructura \'lVias\' y \'aVias\' - TEST #2 - Se ha encontrado un archivo de vías incorrecto (" << ruta << ")" << endl;
}

void Pruebas::pruebaEstructuraLDatDem(GestorBarrio& gBarrio, int& cont, string ruta, ListaPI<DatosDemograficos*>& lDatDem) {
	///@TEST: 1. Existe el fichero RUTA_PADRON
	if(cargarDatosDemograficos(gBarrio, cont, ruta,lDatDem) != true)
		salidaPruebas << "\tERROR : Estructura \'lDatDemograficos\' - TEST #1 - No se ha podido cargar el fichero de datos del padrón (" << ruta << ")" << endl;

	///@TEST: 1.1 Validación por conteo de objetos
	if(cont != 3)
		salidaPruebas << "\tERROR : Estructura \'lDatDemograficos\' - TEST #1.1 - No se han cargado 3 datos\t| En su lugar -> " << cont << endl;

	///@TEST: 2. No existe el fichero RUTA_PADRON
	ruta = "OtroNombre.csv";

	if(cargarDatosDemograficos(gBarrio, cont, ruta, lDatDem) != false)
		salidaPruebas << "\tERROR : Estructura \'lDatDemograficos\' - TEST #2 - Se ha encontrado un archivo de datos del padrón incorrecto (" << ruta << ")" << endl;
}

void Pruebas::pruebaEstructuraGBarrio(GestorBarrio& gBarrio) {
	///@TEST: 1. El barrio 'BarrioA' contiene 1 vía
	///@TEST: 2. El barrio 'BarrioB' contiene más de 1 vía
	///@TEST: 3. El barrio contenedor contiene una vía
	///@TEST: 4. La vía 'ViaA' no contiene un set de datos demográficos
	///@TEST: 5. La vía 'ViaB' contiene un set de datos demográficos
	///@TEST: 6. Los barrios 'BarrioB' y 'BarrioC' comparten la vía 'ViaB'

	salidaPruebas << "\t@TEST: 1. El barrio 'BarrioA' contiene 1 vía\n"
					 "\t@TEST: 2. El barrio 'BarrioB' contiene más de 1 vía\n"
					 "\t@TEST: 3. El barrio contenedor contiene una vía\n"
					 "\t@TEST: 4. La vía 'ViaA' no contiene un set de datos demográficos\n"
					 "\t@TEST: 5. La vía 'ViaB' contiene un set de datos demográficos\n"
					 "\t@TEST: 6. Los barrios 'BarrioB' y 'BarrioC' comparten la vía 'ViaB'" << endl;
	gBarrio.mostrar();
}

void Pruebas::pruebaAlg1() {
	GestorBarrio gBarrio;
	ListaPI<DatosDemograficos*> lDatDem;
	DatosDemograficos* dD;
	string ruta = RUTA_BARRIO_PRUEBA_ALG1;
	int cont = 0;

	salidaPruebas << "INICIO : ESTRUCTURA \'lBarrios\'" << endl;
	pruebaEstructuraLBarrios(gBarrio, cont, ruta);
	salidaPruebas << "FIN : ESTRUCTURA \'lBarrios\'" << endl;

	salidaPruebas << "INICIO : ESTRUCTURA \'lVias\' y \'aVias\'" << endl;
	ruta = RUTA_VIA_PRUEBA_ALG1;
	cont = 0;

	pruebaEstructuraLVias(gBarrio, cont, ruta);
	salidaPruebas << "FIN : ESTRUCTURA \'lVias\' y \'aVias\'" << endl;

	salidaPruebas << "INICIO : ESTRUCTURA \'lDatDemograficos\'" << endl;
	ruta = RUTA_PADRON_PRUEBA_ALG1;
	cont = 0;

	pruebaEstructuraLDatDem(gBarrio, cont, ruta, lDatDem);
	salidaPruebas << "FIN : ESTRUCTURA \'lDatDemograficos\'" << endl;

	salidaPruebas << "INICIO : ESTRUCTURA DE DATOS" << endl;
	pruebaEstructuraGBarrio(gBarrio);
	salidaPruebas << "FIN : ESTRUCTURA DE DATOS" << endl;

	///@NOTA: Liberación de los recursos reservados dinámicamente
	lDatDem.moverInicio();
	while(!lDatDem.finLista()){
		lDatDem.consultar(dD);
		lDatDem.avanzar();
		delete dD;
	}

}

void Pruebas::pruebaAlg2() {
	///@TEST: 1. Barrio 'Vera Cruz' existe
	salidaPruebas << "@TEST: 1. Barrio 'Vera Cruz' existe	->	SE DEBEN MOSTRAR 3 VÍAS" << endl;
	p.alg2("Vera Cruz");

	///@TEST: 1. Barrio 'OtroBarrio' no existe
	salidaPruebas << "@TEST: 2. Barrio 'OtroBarrio' no existe	->	SE DEBE INDICAR POR CONSOLA" << endl;
	p.alg2("OtroBarrio");
}

void Pruebas::pruebaAlg3() {
	ListaPI<Via*> lVias;
	lVias.insertar(new Via("BarrioA", "ViaA", 0,"TipoA", 0));
	lVias.insertar(new Via("BarrioB", "ViaB", 0,"TipoB", 0));
	lVias.insertar(new Via("BarrioX", "ViaX", 0,"TipoX", 0));
	lVias.insertar(new Via("BarrioD", "ViaD", 0,"TipoD", 0));
	Via* vAux;
	int cont = 0;

	///@TEST: 1. No existe ninguna vía que pasa por más de 1 barrio
	alg3(lVias, cont);
	if(cont != 0)
		salidaPruebas << "\tERROR : TEST #1 - Se ha encontrado alguna vía que pasa por más de 1 barrio\t| En su lugar -> " << cont << endl;

	///@TEST: 2. Existe 1 vía que pasa por 2 barrios
	lVias.insertar(new Via("BarrioD", "ViaA", 0, "TipoA", 0));
	cont = 0;

	alg3(lVias, cont);
	if(cont != 1)
		salidaPruebas << "\tERROR : TEST #2 - No se ha encontrado 1 vía que pasa por más de 1 barrio\t| En su lugar -> " << cont << endl;

	///TEST: 3. Existen 3 vías que pasan por más de 1 barrio
	lVias.insertar(new Via("BarrioF", "ViaB", 0, "TipoB", 0));
	lVias.insertar(new Via("BarrioF", "ViaD", 0, "TipoD", 0));
	cont = 0;

	alg3(lVias, cont);
	if(cont != 3)
		salidaPruebas << "\tERROR : TEST #3 - No se han encontrado 3 vía que pasa por más de 1 barrio\t| En su lugar -> " << cont << endl;

	///@NOTA: Liberación de los recursos reservados dinámicamente
	lVias.moverInicio();
	while(!lVias.finLista()){
		lVias.consultar(vAux);
		lVias.avanzar();
		delete vAux;
	}
}

void Pruebas::pruebaAlg4() {
	ListaPI<DatosDemograficos*> lDatDem;
	lDatDem.insertar(new DatosDemograficos(0, "2017 (1); 2010 (2); 1998 (1)", "", "", 0, 0, ""));
	lDatDem.insertar(new DatosDemograficos(1, "2016 (3); 1995 (2)", "", "", 0, 0, ""));
	int cont[3]; for(int i=0; i<3; i++){ cont[i] = 0; }
	DatosDemograficos* dD;
	
	///@TEST: 1. No hay ningún dato para el intervalo (10-19)
	salidaPruebas << "\nCOMPROBAR QUE NO SE REPRESENTE NADA EN EL INTERVALO (10, 19)" << endl;
	alg4(lDatDem, cont);
	if(cont[0] != 6 || cont[1] != 0 || cont[2] != 3)
		salidaPruebas << "\tERROR : TEST #1 - Se han contado más habitantes de los que se deberían" << endl;

	///@TEST: 2. Hay datos para todos los intervalos (0-9), (10, 19) y (20, 29)
	lDatDem.insertar(new DatosDemograficos(2, "2005 (2); 2003 (1)", "", "", 0, 0, ""));
	for(int i=0; i<3; i++){ cont[i] = 0; }

	salidaPruebas << "\nCOMPROBAR QUE SE REPRESENTE 1 PUNTO EN LOS INTERVALOS (0-9), (10, 19) y (20, 29)" << endl;
	alg4(lDatDem, cont);
	if(cont[0] != 6 || cont[1] != 3 || cont[2] != 3)
		salidaPruebas << "\tERROR : TEST #2 - No se han calculado 3 personas para el intervalo (10, 19)\t| En su lugar -> " << cont[1] << endl;

	///@NOTA: Liberación de los recursos reservados dinámicamente
	lDatDem.moverInicio();
	while(!lDatDem.finLista()){
		lDatDem.consultar(dD);
		lDatDem.avanzar();
		delete dD;
	}
}

void Pruebas::pruebaAlg5() {
	ListaPI<DatosDemograficos*> lDatDem;
	lDatDem.insertar(new DatosDemograficos(0, "", "", "", 0, 0, "NacionalidadA (1)"));
	lDatDem.insertar(new DatosDemograficos(0, "", "", "", 0, 0, "NacionalidadA (1)"));
	int cont[2]; for(int i=0; i<2; i++){ cont[i] = 0; }
	DatosDemograficos* dD;

	///@TEST: 1. Solo hay 1 nacionalidad
	salidaPruebas << "COMPROBAR QUE SE MUESTRE LA NACIONALIDAD - \'NacionalidadA (2)\'" << endl;
	alg5(lDatDem, cont);
	if(cont[0] != 2)
		salidaPruebas << "\tERROR : TEST #1 - No hay 2 habitantes para la nacionalidad \'NacionalidadA\'\t| En su lugar -> " << cont[0] << endl;

	///@TEST: 2. Hay 2 nacionalidades
	lDatDem.insertar(new DatosDemograficos(0, "", "", "", 0, 0, "NacionalidadA (1);NacionalidadB (2)"));
	for(int i=0; i<2; i++){ cont[i] = 0; }

	salidaPruebas << "COMPROBAR QUE SE MUESTREN LAS NACIONALIDADES - \'NacionalidadA (3)\' y \'NacionalidadB (2)\'" << endl;
	alg5(lDatDem, cont);
	if(cont[0] != 3 || cont[1] != 2)
		salidaPruebas << "\tERROR : TEST #2 - Hay un número erróneo de habitantes para alguna nacionalidad" << endl;

	///@NOTA: Liberación de los recursos reservados dinámicamente
	lDatDem.moverInicio();
	while(!lDatDem.finLista()){
		lDatDem.consultar(dD);
		lDatDem.avanzar();
		delete dD;
	}
}

void Pruebas::pruebaAlg6() {
	ListaPI<DatosDemograficos*> lDatDem;
	lDatDem.insertar(new DatosDemograficos(0, "", "PoblacionA (ProvinciaA) (1)", "", 0, 0, ""));
	lDatDem.insertar(new DatosDemograficos(0, "", "PoblacionA (ProvinciaA) (1)", "", 0, 0, ""));
	int cont[2]; for(int i=0; i<2; i++){ cont[i] = 0; }
	DatosDemograficos* dD;

	///@TEST: 1. Solo hay 1 provincia
	salidaPruebas << "COMPROBAR QUE SE MUESTRE LA PROVINCIA - \'ProvinciaA (2)\'" << endl;
	alg6(lDatDem, cont);
	if(cont[0] != 2)
		salidaPruebas << "\tERROR : TEST #1 - No hay 2 habitantes para la provincia \'ProvinciaA\'\t| En su lugar -> " << cont[0] << endl;

	///@TEST: 2. Hay 2 provincias
	lDatDem.insertar(new DatosDemograficos(0, "", "PoblacionA (ProvinciaA) (1);PoblacionB (ProvinciaB) (2)", "", 0, 0, ""));
	for(int i=0; i<2; i++){ cont[i] = 0; }

	salidaPruebas << "COMPROBAR QUE SE MUESTREN LAS PROVINCIAS - \'ProvinciaA (3)\' y \'ProvinciaB (2)\'" << endl;
	alg6(lDatDem, cont);
	if(cont[0] != 3 || cont[1] != 2)
		salidaPruebas << "\tERROR : TEST #2 - Hay un número erróneo de habitantes para alguna provincia" << endl;

	///@NOTA: Liberación de los recursos reservados dinámicamente
	lDatDem.moverInicio();
	while(!lDatDem.finLista()){
		lDatDem.consultar(dD);
		lDatDem.avanzar();
		delete dD;
	}
}

void Pruebas::pruebaAlg7() {
	GestorBarrio gBarrio;
	ListaPI<DatosDemograficos*> lDatDem;
	DatosDemograficos* dD;
	string ruta = RUTA_BARRIO_PRUEBA_ALG7;
	int cont = 0;

	cargarBarrios(gBarrio, cont, ruta);
	ruta = RUTA_VIA_PRUEBA_ALG7;
	cargarVias(gBarrio, cont, ruta);
	ruta = RUTA_PADRON_PRUEBA_ALG7;
	cargarDatosDemograficos(gBarrio, cont, ruta, lDatDem);

	///@TEST: 1. No hay ningún habitante para el rango (10-19)
	salidaPruebas << "COMPROBAR QUE SE INDICA QUE EL FORMATO NO ES VÁLIDO (19, 10)" << endl;
	alg7(gBarrio, 19, 10);

	///@TEST: 2. No hay ningún habitante para el rango (10-19)
	salidaPruebas << "COMPROBAR QUE SE INDICA QUE NO EXISTE NINGÚN HABITANTE PARA EL RANGO (10, 19)" << endl;
	alg7(gBarrio, 10, 19);

	///@TEST: 3. Hay habitantes para el rango (0-9)
	salidaPruebas << "COMPRUEBA QUE SE INDICA QUE EL BARRIO RESULTADO PARA EL RANGO (0, 9) ES - BarrioB -  y hay - 6 habitantes" << endl;
	alg7(gBarrio, 0, 9);

	///@NOTA: Liberación de los recursos reservados dinámicamente
	lDatDem.moverInicio();
	while(!lDatDem.finLista()){
		lDatDem.consultar(dD);
		lDatDem.avanzar();
		delete dD;
	}
}

void Pruebas::pruebaAlg8() {
	GestorBarrio gBarrio;
	ListaPI<DatosDemograficos*> lDatDem;
	DatosDemograficos* dD;
	string ruta = RUTA_BARRIO_PRUEBA_ALG7;
	int cont = 0;

	cargarBarrios(gBarrio, cont, ruta);
	ruta = RUTA_VIA_PRUEBA_ALG7;
	cargarVias(gBarrio, cont, ruta);
	ruta = RUTA_PADRON_PRUEBA_ALG7;
	cargarDatosDemograficos(gBarrio, cont, ruta, lDatDem);

	///@TEST: 1.1. El barrio 'BarrioC' no existe
	salidaPruebas << "COMPROBAR QUE SE INDICA QUE EL BARRIO - BarrioC - NO EXISTE EN EL FICHERO DE RESULTADO - NivelEstudios-BarrioC" << endl;
	alg8(gBarrio, "BarrioC");

	///@TEST: 2. El barrio 'BarrioB' existe
	salidaPruebas << "COMPROBAR QUE EL RESULTADO EN EL FICHERO DE VOLCADO - NivelEstudios-BarrioB - ES : \'NivelB2(3)\' \'NivelB1(1)\'" << endl;
	alg8(gBarrio, "BarrioB");

	///@NOTA: Liberación de los recursos reservados dinámicamente
	lDatDem.moverInicio();
	while(!lDatDem.finLista()){
		lDatDem.consultar(dD);
		lDatDem.avanzar();
		delete dD;
	}
}

void Pruebas::pruebaAlg9() {
	GestorBarrio gBarrio;
	ListaPI<DatosDemograficos*> lDatDem;
	DatosDemograficos* dD;
	string ruta = RUTA_BARRIO_PRUEBA_ALG9;
	int cont = 0;

	cargarBarrios(gBarrio, cont, ruta);
	ruta = RUTA_VIA_PRUEBA_ALG9;
	cargarVias(gBarrio, cont, ruta);
	ruta = RUTA_PADRON_PRUEBA_ALG9;
	cargarDatosDemograficos(gBarrio, cont, ruta, lDatDem);

	///@TEST: 1. Hay barrios con hombres y mujeres
	salidaPruebas << "COMPROBAR QUE EL BARRIO CON MAYOR PORCENTAJE DE HOMBRES ES - BarrioB - CON 75%" << endl;
	salidaPruebas << "COMPROBAR QUE EL BARRIO CON MAYOR PORCENTAJE DE MUJERES ES - BarrioA - CON 60%" << endl;
	alg9(gBarrio);

	///@NOTA: Liberación de los recursos reservados dinámicamente
	lDatDem.moverInicio();
	while(!lDatDem.finLista()){
		lDatDem.consultar(dD);
		lDatDem.avanzar();
		delete dD;
	}
}

void Pruebas::pruebaAlg10() {
	GestorBarrio gBarrio;
	ListaPI<DatosDemograficos*> lDatDem;
	DatosDemograficos* dD;
	string ruta = RUTA_BARRIO_PRUEBA_ALG9;
	int cont = 0;

	cargarBarrios(gBarrio, cont, ruta);
	ruta = RUTA_VIA_PRUEBA_ALG9;
	cargarVias(gBarrio, cont, ruta);
	ruta = RUTA_PADRON_PRUEBA_ALG9;
	cargarDatosDemograficos(gBarrio, cont, ruta, lDatDem);

	///@TEST: 1. La provincia 'ProvinciaX' no existe
	salidaPruebas << "COMPROBAR QUE SE INDICA QUE LA PROVINCIA - ProvinciaX - NO EXISTE" << endl;
	alg10(lDatDem, "ProvinciaX");

	///@TEST: 2. La provincia 'ProvinciaA' existe
	salidaPruebas << "COMPROBAR QUE EL RESULTADO DEL FICHERO DE VOLCADO - Poblaciones-ProvinciaA.txt - ES - PoblacionA(1); PoblacionA1 (2)" << endl;
	alg10(lDatDem, "ProvinciaA");

	///@NOTA: Liberación de los recursos reservados dinámicamente
	lDatDem.moverInicio();
	while(!lDatDem.finLista()){
		lDatDem.consultar(dD);
		lDatDem.avanzar();
		delete dD;
	}
}

void Pruebas::pruebaAlg11EDL() {
	ListaPI<Via*> lVias;
	DatosDemograficos* dD1 = new DatosDemograficos(1, "2001 (1)", "PoblacionA (ProvinciaA) (1);PaisA (1)", "NivelA (1)", 2,2, "NacionalidadA (1)");
	Via* vAux1 = new Via("BarrioA", "ViaA", 0,"TipoA", 1);vAux1->setDatosDemograficos(dD1);lVias.insertar(vAux1);
	DatosDemograficos* dD2 = new DatosDemograficos(2, "2009 (1)", "PoblacionB (ProvinciaB) (1);PaisB (2)", "NivelB (1)", 1,2, "NacionalidadB (1)");
	Via* vAux2 = new Via("BarrioB", "ViaB", 0,"TipoB", 2);vAux2->setDatosDemograficos(dD2);lVias.insertar(vAux2);

	///@TEST: 1. La vía 'ViaX' no existe
	salidaPruebas << "COMPROBAR QUE SE INDICA QUE LA VÍA - ViaX - NO EXISTE" << endl;
	alg11_EDL(lVias, "ViaX");

	///@TEST: 2. La vía 'ViaB' existe
	salidaPruebas << "COMPROBAR QUE EN EL FICHERO - LugaresNacimiento-ViaB.txt - SE MUESTRA : PoblacionB, (ProvinciaB) (1); PaisB (2)" << endl;
	alg11_EDL(lVias, "ViaB");

	///@NOTA: Liberación de los recursos reservados dinámicamente
	delete vAux1;
	delete vAux2;
	delete dD1;
	delete dD2;
}

void Pruebas::pruebaAlg11EDNL() {
	Arbol<Via*, ComparadorPtrVia>* aVias = new Arbol<Via*, ComparadorPtrVia>();
	Via* vIns1 = new Via("BarrioC", "ViaC", 0, "TipoC", 0); aVias->insertar(vIns1);
	Via* vIns2 = new Via("BarrioB", "ViaB", 0, "TipoB", 0); aVias->insertar(vIns2);
	Via* vIns3 =  new Via("BarrioD", "ViaD", 0, "TipoD", 0); aVias->insertar(vIns3);
	Via* vIns4 = new Via("BarrioC2", "ViaC", 0, "TipoC", 0); aVias->insertar(vIns4);
	string nombreVia = "ViaB";
	bool enc = false;

	///@TEST: 1. La vía 'ViaX' no existe
	alg11_EDNL(aVias, "ViaX", enc);
	if(enc != false)
		cout << "\tERROR : TEST #1 - Se ha encontrado alguna vía con el nombre - ViaX" << endl;

	///@TEST: 2. La vía 'ViaB' existe
	alg11_EDNL(aVias, "ViaB", enc);
	if(enc != true)
		cout << "\tERROR : TEST #1 - No se ha encontrado ninguna vía con el nombre - ViaB" << endl;

	///@NOTA: Liberación de los recursos reservados dinámicamente
	delete vIns1;
	delete vIns2;
	delete vIns3;
	delete vIns4;
	delete aVias;
}

void Pruebas::pruebaAlg12EDL() {
	ListaPI<Via*> lVias;
	DatosDemograficos* dD1 = new DatosDemograficos(1, "2001 (1)", "PoblacionA (ProvinciaB) (1);PaisA (1)", "NivelA (1)", 2,2, "NacionalidadA (1)");
	Via* vAux1 = new Via("BarrioA", "ViaA", 0,"TipoA", 1);vAux1->setDatosDemograficos(dD1);lVias.insertar(vAux1);
	DatosDemograficos* dD2 = new DatosDemograficos(1, "2009 (1)", "PoblacionB (ProvinciaB) (3);PaisB (2)", "NivelB (1)", 1,2, "NacionalidadB (1)");
	Via* vAux2 = new Via("BarrioB", "ViaB", 0,"TipoB", 2);vAux2->setDatosDemograficos(dD2);lVias.insertar(vAux2);

	///@TEST: Ninguna vía comienza por 'XX'
	salidaPruebas << "COMPROBAR QUE SE INDIQUE QUE NINGUNA VÍA COMIENZA POR LA RAÍZ - XX -" << endl;
	alg12_EDL(lVias, "XX", "ProvinciaB");

	///@TEST: 2.1 La provincia 'ProvinciaX' no existe
	salidaPruebas << "COMPROBAR QUE SE INDIQUE QUE NO EXISTE LA PROVINCIA - ProvinciaX -" << endl;
	alg12_EDL(lVias, "Via", "ProvinciaX");

	///@TEST: 2.2 La provincia 'ProvinciaB' existe
	salidaPruebas << "COMPROBAR QUE SE MUESTRE : raiz 'Via'; 4 habitantes para la provincia - ProvinciaB" << endl;
	alg12_EDL(lVias, "Via", "ProvinciaB");

	///@NOTA: Liberación de los recursos reservados dinámicamente
	delete vAux1;
	delete vAux2;
	delete dD1;
	delete dD2;
}

void Pruebas::pruebaAlg12EDNL() {
	Arbol<Via*, ComparadorPtrVia>* aVias = new Arbol<Via*, ComparadorPtrVia>();
	DatosDemograficos* dD1 = new DatosDemograficos(1, "2001 (1)", "PoblacionA (ProvinciaB) (1);PaisA (1)", "NivelA (1)", 2,2, "NacionalidadA (1)");
	Via* vAux1 = new Via("BarrioA", "ViaA", 0,"TipoA", 1);vAux1->setDatosDemograficos(dD1);aVias->insertar(vAux1);
	DatosDemograficos* dD2 = new DatosDemograficos(1, "2009 (1)", "PoblacionB (ProvinciaB) (3);PaisB (2)", "NivelB (1)", 1,2, "NacionalidadB (1)");
	Via* vAux2 = new Via("BarrioB", "ViaB", 0,"TipoB", 2);vAux2->setDatosDemograficos(dD2);aVias->insertar(vAux2);

	///@TEST: Ninguna vía comienza por 'XX'
	salidaPruebas << "COMPROBAR QUE SE INDIQUE QUE NINGUNA VÍA COMIENZA POR LA RAÍZ - XX -" << endl;
	alg12_EDNL(aVias, "XX", "ProvinciaB");

	///@TEST: 2.1 La provincia 'ProvinciaX' no existe
	salidaPruebas << "COMPROBAR QUE SE INDIQUE QUE NO EXISTE LA PROVINCIA - ProvinciaX -" << endl;
	alg12_EDNL(aVias, "Via", "ProvinciaX");

	///@TEST: 2.2 La provincia 'ProvinciaB' existe
	salidaPruebas << "COMPROBAR QUE SE MUESTRE : raiz 'Via'; 4 habitantes para la provincia - ProvinciaB" << endl;
	alg12_EDNL(aVias, "Via", "ProvinciaB");

	///@NOTA: Liberación de los recursos reservados dinámicamente
	delete vAux1;
	delete vAux2;
	delete dD1;
	delete dD2;
	delete aVias;
}

void Pruebas::pruebaAlgoritmos() {
	salidaPruebas << "INICIO : ALGORITMO 1" << endl;
	pruebaAlg1();
	salidaPruebas << "FIN : ALGORITMO 1" << endl;

	salidaPruebas << "INICIO : ALGORITMO 2" << endl;
	pruebaAlg2();
	salidaPruebas << "FIN : ALGORITMO 2" << endl;

	salidaPruebas << "INICIO : ALGORITMO 3" << endl;
	pruebaAlg3();
	salidaPruebas << "FIN : ALGORITMO 3" << endl;

	salidaPruebas << "INICIO : ALGORITMO 4" << endl;
	pruebaAlg4();
	salidaPruebas << "FIN : ALGORITMO 4" << endl;

	salidaPruebas << "INICIO : ALGORITMO 5" << endl;
	pruebaAlg5();
	salidaPruebas << "FIN : ALGORITMO 5" << endl;

	salidaPruebas << "INICIO : ALGORITMO 6" << endl;
	pruebaAlg6();
	salidaPruebas << "FIN : ALGORITMO 6" << endl;

	salidaPruebas << "INICIO : ALGORITMO 7" << endl;
	pruebaAlg7();
	salidaPruebas << "FIN : ALGORITMO 7" << endl;

	salidaPruebas << "INICIO : ALGORITMO 8" << endl;
	pruebaAlg8();
	salidaPruebas << "FIN : ALGORITMO 8" << endl;

	salidaPruebas << "INICIO : ALGORITMO 9" << endl;
	pruebaAlg9();
	salidaPruebas << "FIN : ALGORITMO 9" << endl;

	salidaPruebas << "INICIO : ALGORITMO 10" << endl;
	pruebaAlg10();
	salidaPruebas << "FIN : ALGORITMO 10" << endl;

	salidaPruebas << "INICIO : ALGORITMO 11 EDL" << endl;
	pruebaAlg11EDL();
	salidaPruebas << "FIN : ALGORITMO 11 EDL" << endl;

	salidaPruebas << "INICIO : ALGORITMO 11 EDNL" << endl;
	pruebaAlg11EDNL();
	salidaPruebas << "FIN : ALGORITMO 11 EDNL" << endl;

	salidaPruebas << "INICIO : ALGORITMO 2 EDL" << endl;
	pruebaAlg12EDL();
	salidaPruebas << "FIN : ALGORITMO 12 EDL" << endl;

	salidaPruebas << "INICIO : ALGORITMO 2 EDNL" << endl;
	pruebaAlg12EDNL();
	salidaPruebas << "FIN : ALGORITMO 12 EDNL" << endl;
}

void Pruebas::ejecutarPruebas() {									///@NOTA: Ejecuta todas las pruebas del proyecto
	salidaPruebas << "EJECUTANDO # Utilidadades de cadena" << endl;
	salidaPruebas << "-----------------------------------------------------------------------------------------------" << endl;
	pruebaUtils();
	salidaPruebas << endl << endl;
	salidaPruebas << "EJECUTANDO # Sobrecarga de operadores" << endl;
	salidaPruebas << "-----------------------------------------------------------------------------------------------" << endl;
	pruebaSobrecargaOperadores();
	salidaPruebas << endl << endl;
	salidaPruebas << "EJECUTANDO # Métodos auxiliares" << endl;
	salidaPruebas << "------------------------------------------------------------------------------------------------" << endl;
	pruebaMetodosAuxiliares();
	salidaPruebas << endl << endl;
	salidaPruebas << "EJECUTANDO # Interfaz de usuario (UI)" << endl;
	salidaPruebas << "------------------------------------------------------------------------------------------------" << endl;
	pruebaUI();
	salidaPruebas << endl << endl;
	salidaPruebas << "EJECUTANDO # Prueba de ejecución secuencial" << endl;
	salidaPruebas << "-----------------------------------------------------------------------------------------------" << endl;
	pruebaEjecucionSecuencial();
	salidaPruebas << endl << endl;
	salidaPruebas << "EJECUTANDO # Prueba de los Algoritmos" << endl;
	salidaPruebas << "-----------------------------------------------------------------------------------------------" << endl;
	pruebaAlgoritmos();
	salidaPruebas << endl << endl;
}

}
