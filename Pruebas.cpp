/*
 * PLACEHOLDER
 */

#include "Pruebas.h"

using namespace std;

Pruebas::Pruebas() {
	cout << "***********************************************************************************************" << endl;
	cout << "				INICIO DE LAS PRUEBAS DEL PROYECTO" 							 				  << endl;
	cout << "***********************************************************************************************" << endl << endl;

	ejecutarPruebas();				//Ejecuta todas las pruebas del proyecto

	cout << "***********************************************************************************************" << endl;
	cout << "				FIN DE LAS PRUEBAS DEL PROYECTO" 								  				  << endl;
	cout << "***********************************************************************************************" << endl << endl;
}

Pruebas::~Pruebas() {}



void Pruebas::pruebaSobrecargaOperadores() {
	cout << "INICIO : Sobrecarga de operadores de la clase VIA" << endl;
	Via* v1 = new Via("BarrioA", "Canovas", 0, "TipoA", 0);
	Via* v2 = new Via("BarrioB", "Beethoven", 0, "TipoB", 0);

	if(*v1 > *v1 != false)
		cout << "\tERROR : Clase VIA - Operador \'>\' # *v1 > *v1 ->  FALSE\t| En su lugar -> " << bool(*v1 > *v1) << endl;
	if(*v1 > *v2 != false)
		cout << "\tERROR : Clase VIA - Operador \'>\' # *v1 > *v2 -> FALSE\t| En su lugar -> " << bool(*v1 > *v2) << endl;
	if(*v2 > *v1 != true)
		cout << "\tERROR : Clase VIA - Operador \'>\' # *v2 > *v1 -> TRUE\t| En su lugar -> " << bool(*v2 > *v1) << endl;
	cout << "FIN : Sobrecarga de operadores de la clase VIA" << endl << endl;

	cout << "INICIO : Sobrecarga de operadores de la clase COMPARADORPTRVIA" << endl;
	ComparadorPtrVia cPtrVia;

	if(cPtrVia.operator()(v1, v1) != 0)
		cout << "\tERROR : Clase COMPARADORPTRVIA - Operador \'()\' # ()(v1, v1) -> 0\t| En su lugar -> " << cPtrVia.operator()(v1, v1) << endl;
	if(cPtrVia.operator()(v1, v2) != 1)
		cout << "\tERROR : Clase COMPARADORPTRVIA - Operador \'()\' # ()(v1, v2) -> 1\t| En su lugar -> " << cPtrVia.operator()(v1, v2) << endl;
	if(cPtrVia.operator()(v2, v1) != -1)
		cout << "\tERROR : Clase COMPARADORPTRVIA - Operador \'()\' # ()(v2, v1) -> -1\t| En su lugar -> " << cPtrVia.operator()(v2, v1) << endl;
	cout << "FIN : Sobrecarga de operadores de la clase COMPARADORPTRVIA" << endl << endl;

	cout << "INICIO : Sobrecarga de operadores de la clase LUGAR DE NACIMIENTO" << endl;
	LugarNacimiento lugNac1 = LugarNacimiento("PoblacionA", "Caceres", 0);
	LugarNacimiento lugNac2 = LugarNacimiento("PoblacionB", "Badajoz", 0);
	LugarNacimiento lugNac3 = LugarNacimiento("PoblacionC", "Caceres", 0);

	if(lugNac1 >= lugNac1 != true)
		cout << "\tERROR : Clase LUGARNACIMIENTO - Operador \'>=\' # lugNac1 >= lugNac1 -> TRUE\t| En su lugar -> " << bool(lugNac1 >= lugNac1) << endl;
	if(lugNac1 >= lugNac2 != false)
		cout << "\tERROR : Clase LUGARNACIMIENTO - Operador \'>=\' # lugNac1 >= lugNac2 -> FALSE\t| En su lugar -> " << bool(lugNac1 >= lugNac2) << endl;
	if(lugNac2 >= lugNac1 != true)
		cout << "\tERROR : Clase LUGARNACIMIENTO - Operador \'>=\' # lugNac2 >= lugNac1 -> TRUE\t| En su lugar -> " << bool(lugNac2 >= lugNac1) << endl;

	if(lugNac1 == lugNac1 != true)
		cout << "\tERROR : Clase LUGARNACIMIENTO - Operador \'==\' # lugNac1 == lugNac1 -> TRUE\t| En su lugar -> " << bool(lugNac1 == lugNac1) << endl;
	if(lugNac1 == lugNac2 != false)
		cout << "\tERROR : Clase LUGARNACIMIENTO - Operador \'==\' # lugNac1 == lugNac2 -> FALSE\t| En su lugar -> " << bool(lugNac1 == lugNac2) << endl;
	if(lugNac1 == lugNac3 != true)
		cout << "\tERROR : Clase LUGARNACIMIENTO - Operador \'==\' # lugNac1 == lugNac3 -> TRUE\t| En su lugar -> " << bool(lugNac1 == lugNac3) << endl;
	cout << "FIN : Sobrecarga de operadores de la clase LUGAR DE NACIMIENTO" << endl << endl;

	cout << "INICIO : Sobrecarga de operadores de la clase ESTUDIOS" << endl;
	Estudios est1 = Estudios("Nivel_A", 1);
	Estudios est2 = Estudios("Nivel_B", 2);
	Estudios est3 = Estudios("Nivel_A", 2);

	if(est1 > est1 != false)
		cout << "\tERROR : Clase ESTUDIOS - Operador \'>\' # est1 > est1 -> FALSE\t| En su lugar -> " << bool(est1 > est1) << endl;
	if(est1 > est2 != false)
		cout << "\tERROR : Clase ESTUDIOS - Operador \'>\' # est1 > est2 -> FALSE\t| En su lugar -> " << bool(est1 > est2) << endl;
	if(est2 > est1 != true)
		cout << "\tERROR : Clase ESTUDIOS - Operador \'>\' # est2 > est1 -> TRUE\t| En su lugar -> " << bool(est2 > est1) << endl;

	if(est1 == est1 != true)
		cout << "\tERROR : Clase ESTUDIOS - Operador \'==\' # est1 == est1 -> TRUE\t| En su lugar -> " << bool(est1 == est1) << endl;
	if(est1 == est2 != false)
		cout << "\tERROR : Clase ESTUDIOS - Operador \'==\' # est1 == est2 -> FALSE\t| En su lugar -> " << bool(est1 == est2) << endl;
	if(est1 == est3 != true)
		cout << "\tERROR : Clase ESTUDIOS - Operador \'==\' # est1 == est3 -> TRUE\t| En su lugar -> " << bool(est1 == est3) << endl;
	cout << "FIN : Sobrecarga de operadores de la clase ESTUDIOS" << endl << endl;

	cout << "INICIO : Sobrecarga de operadores de la clase NACIONALIDAD" << endl;
	Nacionalidad nacion1 = Nacionalidad("NacionalidadA", 1);
	Nacionalidad nacion2 = Nacionalidad("NacionalidadB", 2);
	Nacionalidad nacion3 = Nacionalidad("NacionalidadA", 2);

	if(nacion1 > nacion1 != false)
		cout << "\tERROR : Clase NACIONALIDAD - Operador \'>\' # nacion1 > nacion1 -> FALSE\t| En su lugar -> " << bool(nacion1 > nacion1) << endl;
	if(nacion1 > nacion2 != false)
		cout << "\tERROR : Clase NACIONALIDAD - Operador \'>\' # nacion1 > nacion2 -> FALSE\t| En su lugar -> " << bool(nacion1 > nacion2) << endl;
	if(nacion2 > nacion1 != true)
		cout << "\tERROR : Clase NACIONALIDAD - Operador \'>\' # nacion2 > nacion1 -> TRUE\t| En su lugar -> " << bool(nacion2 > nacion1) << endl;

	if(nacion1 == nacion1 != true)
		cout << "\tERROR : Clase NACIONALIDAD - Operador \'==\' # nacion1 == nacion1 -> TRUE\t| En su lugar -> " << bool(nacion1 == nacion1) << endl;
	if(nacion1 == nacion2 != false)
		cout << "\tERROR : Clase NACIONALIDAD - Operador \'==\' # nacion1 == nacion2 -> FALSE\t| En su lugar -> " << bool(nacion1 == nacion2) << endl;
	if(nacion1 == nacion3 != true)
		cout << "\tERROR : Clase NACIONALIDAD - Operador \'==\' # nacion1 == nacion3 -> TRUE\t| En su lugar -> " << bool(nacion1 == nacion3) << endl;
	cout << "FIN : Sobrecarga de operadores de la clase NACIONALIDAD" << endl << endl;

	///@NOTA: Liberación de los recursos reservados dinámicamente
	delete v1;
	delete v2;
}

void Pruebas::pruebaEjecucionSecuencial() {
	ofstream ofs;									//Flujo de salida para el volcado de la tabla de tiempos de ejecución
	string ruta = "TablaTiemposEjecucion.txt";		//Ruta relativa del fichero de volcado de la tabla con los tiempos calculados de la ejecución de todos los algoritmos
	string nombreBarrio = "Huertas";				//Nombre del barrio a utilizar por los algoritmos 2 y 8
	string nombreProvincia = "Caceres";				//Nombre de la provincia a utilizar por el algoritmo 10 y 12
	string nombreVia = "De La Universidad";			//Nombre de la vía a utilizar por el algoritmo 11
	string raizVia = "Esp";							//Raíz de la vía a utilizar por el algoritmo 12
	int limInf = 10;								//Límite inferior del rango de edad a utilizar por el algoritmo 7
	int limSup = 20;								//Límite superior del rango de edad a utilizar por el algoritmo 7
	int nRep = 100;									//Número de repeticiones para los algoritmos con doble implementación
	double vTEjec[10];								//Vector para almacenar los tiempos de ejecución de los 10 algoritmos con una sola implementación
	double vTEjecAlg11EDL[nRep];					//Vector para almacenar los tiempos de ejecución del algoritmo 11 en su versión EDL
	double vTEjecAlg11EDNL[nRep];					//Vector para almacenar los tiempos de ejecución del algoritmo 11 en su versión EDNL
	double vTEjecAlg12EDL[nRep];					//Vector para almacenar los tiempos de ejecución del algoritmo 12 en su versión EDL
	double vTEjecAlg12EDNL[nRep];					//Vector para almacenar los tiempos de ejecución del algoritmo 12 en su versión EDNL
	double t;										//Acumulador que representa la diferencia de tiempo entre dos llamadas consecutivas a std::clock(). Utilizado para medir tiempos de ejecución

	///@TEST: Carga de datos
	t = Time::getTime();
	p.cargarBarrios();
	p.cargarVias();
	p.cargarDatosDemograficos();
	t -= Time::getTime();
	p.mostrarEstructura();							//Muestra todos los datos cargados y su estructura
	vTEjec[0] = -t / CLOCKS_PER_SEC;

	///@TEST: Algoritmo 2
	t = Time::getTime();
	p.alg2(nombreBarrio);
	t -= Time::getTime();
	vTEjec[1] = -t / CLOCKS_PER_SEC;

	///@TEST: Algoritmo 3
	t = Time::getTime();
	p.alg3();
	t -= Time::getTime();
	vTEjec[2] = -t / CLOCKS_PER_SEC;

	///@TEST: Algoritmo 4
	t = Time::getTime();
	p.alg4();
	t -= Time::getTime();
	vTEjec[3] = -t / CLOCKS_PER_SEC;

	///@TEST: Algoritmo 5
	t = Time::getTime();
	p.alg5();
	t -= Time::getTime();
	vTEjec[4] = -t / CLOCKS_PER_SEC;

	///@TEST: Algoritmo 6
	t = Time::getTime();
	p.alg6();
	t -= Time::getTime();
	vTEjec[5] = -t / CLOCKS_PER_SEC;

	///@TEST: Algoritmo 7
	t = Time::getTime();
	p.alg7(limInf, limSup);
	t -= Time::getTime();
	vTEjec[6] = -t / CLOCKS_PER_SEC;

	///@TEST: Algoritmo 8
	t = Time::getTime();
	p.alg8(nombreBarrio);
	t -= Time::getTime();
	vTEjec[7] = -t / CLOCKS_PER_SEC;

	///@TEST: Algoritmo 9
	t = Time::getTime();
	p.alg9();
	t -= Time::getTime();
	vTEjec[8] = -t / CLOCKS_PER_SEC;

	///@TEST: Algoritmo 10
	t = Time::getTime();
	p.alg10(nombreProvincia);
	t -= Time::getTime();
	vTEjec[9] = -t / CLOCKS_PER_SEC;

	///@TEST: Algoritmo 11_EDL
	for(int i=0; i < nRep; i++) {
		t = Time::getTime();
		p.alg11_EDL(nombreVia);
		t -= Time::getTime();
		vTEjecAlg11EDL[i] = -t / CLOCKS_PER_SEC;
	}

	///@TEST: Algoritmo 11_EDNL
	for(int i=0; i < nRep; i++) {
		t = Time::getTime();
		p.alg11_EDNL(nombreVia);
		t -= Time::getTime();
		vTEjecAlg11EDNL[i] = -t / CLOCKS_PER_SEC;
	}

	///@TEST: Algoritmo 12_EDL
	for(int i=0; i < nRep; i++) {
		t = Time::getTime();
		p.alg12_EDL(raizVia, nombreProvincia);
		t -= Time::getTime();
		vTEjecAlg12EDL[i] = -t / CLOCKS_PER_SEC;
	}

	///@TEST: Algoritmo 12_EDNL
	for(int i=0; i < nRep; i++) {
		t = Time::getTime();
		p.alg12_EDNL(raizVia, nombreProvincia);
		t -= Time::getTime();
		vTEjecAlg12EDNL[i] = -t / CLOCKS_PER_SEC;
	}

	ofs.open(ruta.c_str(), ios::trunc);				//Modo de apertura: truncamiento. Sobreescribe cualquier dato previo en cada ejecución de las pruebas
	if(ofs.is_open()){								//Comprueba que el flujo esté abierto
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
		for(int i=0; i < nRep; i++){
			ofs << "#" << i+1 << " |" << vTEjecAlg11EDL[i] << " seg." <<
				   "\t| " << vTEjecAlg11EDNL[i] << " seg." <<
				   "\t| " << vTEjecAlg12EDL[i] << " seg." <<
				   "\t| " << vTEjecAlg12EDNL[i] << " seg.\t|" << endl;
		}
		ofs << "-----------------------------------------------------------------------------------------------" << endl;
	}

	ofs.close();									//Cierra el flujo
}



void Pruebas::ejecutarPruebas() {
	cout << "EJECUTANDO # Sobrecarga de operadores" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	pruebaSobrecargaOperadores();
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "EJECUTANDO # Prueba de ejecución secuencial" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	pruebaEjecucionSecuencial();
	cout << "------------------------------------------------------------------------------------------------" << endl;
}
