/**
 * @CLASE: UI
 *
 * @brief
 * 		Clase para manejar la interfaz de usuario (UI) y gestiona la entrada/salida de datos. Proporciona una rutina
 * 			de menú para mostrar las opciones al usuario por pantalla en consola. Ésta será repetida hasta que el usuario
 * 			decida terminar el programa mediante la opción cero (0).
 *
 * 			La entrada de datos es manejada por la entrada estándar (cin) para la selección de opción y para aquellos
 * 			algoritmos que requieran de parámetros de entrada. La salida puede manejarse mediante la salida estándar (cout)
 * 			consola y/o fichero de datos.
 *
 * 			También maneja la llamada a ejecución de las pruebas.
 *
 * @atributo p
 * 		Instancia de la clase principal Padron para ejecutar las opciones (algoritmos) del programa
 */

#ifndef UI_H_
#define UI_H_

#include "Padron.h"
#include "timer.h"
#include "Pruebas.h"

class UI {

private:
	Padron p;

private:
	int  menu();
	void ejecutar();
	void pausa();

public:
	 UI();
	~UI();
};

#endif /* UI_H_ */
