/*
 * PLACEHOLDER
 */

#include "Pruebas.h"

using namespace std;

Pruebas::Pruebas() {
	cout << "***********************************************************************************************" << endl;
	cout << "\t\t\t\t\t\t\tINICIO DE LAS PRUEBAS DEL PROYECTO" << endl;
	cout << "***********************************************************************************************" << endl << endl;

	ejecutarPruebas();				//Ejecuta todas las pruebas del proyecto

	cout << "***********************************************************************************************" << endl;
	cout << "\t\t\t\t\t\t\t\tFIN DE LAS PRUEBAS DEL PROYECTO" << endl;
	cout << "***********************************************************************************************" << endl << endl;
}

Pruebas::~Pruebas() {}



void Pruebas::pruebaSobrecargaOperadores() {
	cout << "INICIO : Sobrecarga de operadores de la clase VIA" << endl;
	Via* v1 = new Via("BarrioA", "Canovas", 0, "TipoA", 0);
	Via* v2 = new Via("BarrioB", "Beethoven", 0, "TipoB", 0);

	if(*v1 > *v1 != false)
		cout << "\tERROR : Clase VIA - Operador \'>\' # *v1 > *v1 == FALSE\t| En su lugar -> " << bool(*v1 > *v1) << endl;
	if(*v1 > *v2 != false)
		cout << "\tERROR : Clase VIA - Operador \'>\' # *v1 > *v2 == FALSE\t| En su lugar -> " << bool(*v1 > *v2) << endl;
	if(*v2 > *v1 != false)
		cout << "\tERROR : Clase VIA - Operador \'>\' # *v2 > *v1 == TRUE\t| En su lugar -> " << bool(*v2 > *v1) << endl;
	cout << "FIN : Sobrecarga de operadores de la clase VIA" << endl << endl;

	cout << "INICIO : Sobrecarga de operadores de la clase COMPARADORPTRVIA" << endl;
	cout << "FIN : Sobrecarga de operadores de la clase COMPARADORPTRVIA" << endl << endl;

	cout << "INICIO : Sobrecarga de operadores de la clase LUGAR DE NACIMIENTO" << endl;
	cout << "FIN : Sobrecarga de operadores de la clase LUGAR DE NACIMIENTO" << endl << endl;

	cout << "INICIO : Sobrecarga de operadores de la clase ESTUDIOS" << endl;
	cout << "FIN : Sobrecarga de operadores de la clase ESTUDIOS" << endl << endl;

	cout << "INICIO : Sobrecarga de operadores de la clase NACIONALIDAD" << endl;
	cout << "FIN : Sobrecarga de operadores de la clase NACIONALIDAD" << endl << endl;
}

void Pruebas::ejecutarPruebas() {
	cout << "EJECUTANDO # Sobrecarga de operadores" << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	pruebaSobrecargaOperadores();
	cout << "------------------------------------------------------------------------------------------------" << endl;
}
