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

void Pruebas::ejecutarPruebas() {
	cout << "EJECUTANDO # Sobrecarga de operadores" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	pruebaSobrecargaOperadores();
	cout << "------------------------------------------------------------------------------------------------" << endl;
}
