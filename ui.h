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
	/**
	 * @brief
	 * 		Rutina de menú para manejar la interacción del usuario con el programa. Presenta una selección de opciones con
	 * 			los algoritmos del programa
	 *
	 * @pre:
	 * @post: Proporciona al usuario un menú por consola con las diferentes opciones del programa (algoritmos). Maneja la selección
	 * 			de opción (con validación) del usuario por consola mediante la entrada estandar (cin)
	 * @complejidad: O(1) (Depende de la interacción de usuario)
	 *
	 * @return
	 * 		Opción del menú elegida por el usuario representada por un entero
	 */
	int  menu();
	/**
	 * @brief
	 * 		Rutina principal que sirve de puente entre la implementación de los algoritmos y la selección de usuario. Ejecuta
	 * 			el menú entre cada selección de opción haciendo una pausa entre medias para permitir al usuario
	 * 			visualizar los resultados del algoritmo seleccionado
	 *
	 * @pre:
	 * @post:
	 * @complejidad: O(n^2) (Máxima complejidad de los algoritmos del proyecto)
	 */
	void ejecutar();
	/**
	 * @brief
	 * 		Método para generar una pausa en la ejecución del programa hasta que el usuario pulse la tecla correspondiente.
	 *
	 * @pre:
	 * @post: Pausa la ejecución del programa hasta que se pulse la tecla \const TECLA_MENU. La pulsación se recoge mediante
	 * 			la entrada estándar (cin) en una cadena, por lo que se requiere una pulsación adicional de la tecla ENTER
	 * @complejidad: O(1) (Depende de la interacción de usuario)
	 */
	void pausa();

public:
	/**
	 * @brief
	 * 		CONSTRUCTOR POR DEFECTO. Invoca el método principal 'UI::ejecutar'
	 *
	 * @pre:
	 * @post: Instancia de UI inicializada por defecto
	 * @complejidad: O(n^2) (Máxima complejidad de los algoritmos del proyecto)
	 */
	 UI();
	 /**
	 * @brief
	 * 		DESTRUCTOR. Desencadena la liberación de memoria de toda la estructura de datos
	 *
	 * @pre:
	 * @post:
	 * @complejidad: O(n)
	 */
	~UI();
};

#endif /* UI_H_ */
