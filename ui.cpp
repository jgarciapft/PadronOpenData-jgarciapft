//============================================================================
// Name        : UI.cpp
// Author      : Profesores de la asignatura EDI
// Version     : Curso 17/18
// Copyright   :
// Description : Interfaz de usuario
//============================================================================

#include "ui.h"

using namespace std;

UI::UI() {
	ejecutar();
}

void UI::ejecutar() {
	double t_start, t_end;				//Almacena la diferencia de tiempo entre dos intervalos. Mide los tiempos de ejecución de los algoritmos
	int opcion;							//Opción del menú elegida por el usuario
	string nombreBarrio;				//Nombre del barrio a utilizar por los algoritmos 2 y 8
	string nombreProvincia;				//Nombre de la provincia a utilizar por el algoritmo 10
	string nombreVia;					//Nombre de la vía a utilizar por el algoritmo 11
	int limInf;							//Límite inferior del rango de edad a utilizar por el algoritmo 7
	int limSup;							//Límite superior del rango de edad a utilizar por el algoritmo 7

	bool salir = false;					//Bandera que indica que si el usuario ha decidido cerrar el programa
	do {
		opcion = menu();				//Obtiene la opción indicada por el usuario
		switch (opcion) {				//En base a la opción elegida pregunta datos adicionales y/o ejecuta el algoritmo seleccionado
		case 1:
			t_start = Time::getTime();
			cout << "Cargando datos ... " << endl;
			p.cargarBarrios();
			p.cargarVias();
			p.cargarDatosDemograficos();
			cout << "Carga finalizada ... " << endl;
			t_end= Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 2:
			cout << "Introduzca el nombre del BARRIO :" << endl;
			cin >> nombreBarrio;
			t_start = Time::getTime();
			p.alg2(nombreBarrio);
			t_end= Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 3:
			t_start = Time::getTime();
			p.alg3();
			t_end= Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 4:							///@PREGUNTA: Debería dar a elegir el rango de edad?
			t_start = Time::getTime();
			p.alg4();
			t_end= Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 5:
			t_start = Time::getTime();
			p.alg5();
			t_end= Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 6:
			t_start = Time::getTime();
			p.alg6();
			t_end= Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 7:
			cout << "Introduzca el LÍMITE INFERIOR del intervalo : " << endl;
			cin >> limInf;
			cout << "Introduzca el LÍMITE SUPERIOR del intervalo : " << endl;
			cin >> limSup;
			t_start = Time::getTime();
			p.alg7(limInf, limSup);
			t_end= Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 8:
			cout << "Introduzca el nombre del BARRIO :" << endl;
			cin >> nombreBarrio;
			t_start = Time::getTime();
			p.alg8(nombreBarrio);
			t_end= Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 9:
			t_start = Time::getTime();
			p.alg9();
			t_end= Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 10:
			cout << "Introduzca el nombre la PROVINCIA :" << endl;
			cin >> nombreProvincia;
			t_start = Time::getTime();
			p.alg10(nombreProvincia);
			t_end= Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 11:
			t_start = Time::getTime();
//			 TODO por hacer alg. 11
			t_end= Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 12:
			t_start = Time::getTime();
//			 TODO por hacer alg. 12
			t_end= Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 0:							//Se ha seleccionado terminar el programa
			salir = true;
			break;
		default:						//Si la opción no es válida vuelve a preguntar al usuario
			cout << "ERROR en la opcion de menu" << endl;
			break;
		}
	} while (!salir);
}

int UI::menu() {
	int opcion;

	do {
		cout << endl;
		cout << "_________________________________ MENU PRINCIPAL __________________________________"<< endl << endl;

		cout << "   1. Carga de datos                                                               "<< endl;
		cout << "   2. Mostrar vías de un barrio                                                    "<< endl;
		cout << "   3. Mostrar las vías que pertenecen a varios barrios                             "<< endl;
		cout << "   4. Mostrar el número de habitantes de Cáceres agrupados por rango de edad       "<< endl;
		cout << "   5. Listado por nacionalidades                                                   "<< endl;
		cout << "   6. Número de habitantes por provincia de nacimiento                             "<< endl;
		cout << "   7. Barrio con mayor número de habitantes para un rango de edad                  "<< endl;
		cout << "   8. Fichero por nivel de estudios de todos los ciudadanos de un barrio           "<< endl;
		cout << "   9. Barrio con mayor porcentaje de hombres/mujeres.                              "<< endl;
		cout << "  10. Fichero con los habitantes nacidos en los pueblos de una provincia           "<< endl;
		cout << "  11. Fichero por lugar de nacimiento de una determinada vía (Alg. crítico)        "<< endl;
		cout << "  12. Listado nº de personas nacidas en una provincia de las vias que comiencen por...(Alg.crítico)"<< endl;

		cout << endl;
		cout << "   0. Finalizar. " << endl;
		cout << " Opcion:  ";
		cin >> opcion;
		cin.ignore();

	} while ((opcion < 0) || (opcion > 13));

	return opcion;
}

UI::~UI() {
	cout << "Finalizado....";
}

int main() {
	UI ui;

	return 0;
}

