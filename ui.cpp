//============================================================================
// Name        : UI.cpp
// Author      : Profesores de la asignatura EDI
// Version     : Curso 17/18
// Copyright   :
// Description : Interfaz de usuario
//============================================================================

#include <fstream>
#include <iostream>
#include "ui.h"
#include "timer.h"


using namespace std;

UI::UI() {
	// TODO
	ejecutar();
}

void UI::ejecutar() {


	double t_start, t_end;
	int opcion;

	bool salir = false;
	do {
		opcion = menu();
		switch (opcion) {
		case 1:


			t_start = Time::getTime();
			cout << "Cargando datos ... " << endl;
			// TODO por hacer alg. 1

			cout << "Carga finalizada ... " << endl;
			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 2:

			t_start = Time::getTime();
			// TODO por hacer alg. 2
			t_end = Time::getTime();

			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 3:

			t_start = Time::getTime();
			// TODO por hacer alg. 3
			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 4:

			t_start = Time::getTime();
			// TODO por hacer alg. 4
			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 5:
			t_start = Time::getTime();
			// TODO por hacer alg. 5
			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;

			break;
		case 6:
			t_start = Time::getTime();
			// TODO por hacer alg. 6
			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;

			break;
		case 7:

			t_start = Time::getTime();
			// TODO por hacer alg. 7
			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;

			break;
		case 8:

			t_start = Time::getTime();
			// TODO por hacer alg. 8
			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;

			break;
		case 9:
			t_start = Time::getTime();
			// TODO por hacer alg. 9
			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;

			break;
		case 10:

			t_start = Time::getTime();
			// TODO por hacer alg. 10
			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;

			break;
		case 11:

			t_start = Time::getTime();
			// TODO por hacer alg. 11
			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;

			break;
		case 12:
			t_start = Time::getTime();
			// TODO por hacer alg. 12
			t_end = Time::getTime();
			cout << "Time: " << t_end - t_start << "  " << endl;
			break;
		case 0:
			salir = true;
			break;
		default:
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
	// TODO delete a la instancia creada;
	cout << "Finalizado....";
}


/*
	// TODO  quitar el comentario para ejecutar el proyecto
int main() {
	UI ui;
	return 0;
}

*/

