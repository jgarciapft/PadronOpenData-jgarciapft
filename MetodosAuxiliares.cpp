/*
 * PLACEHOLDER
 */

#include "MetodosAuxiliares.h"

namespace pruebas{

MetodosAuxiliares::MetodosAuxiliares() {}

MetodosAuxiliares::~MetodosAuxiliares() {}



void MetodosAuxiliares::ordenarLista(ListaPI<Nacionalidad *> *&lNacion) {
	bool siguiente;																			/* Bandera que compara si el dato modificado/insertado con el anterior (sabiendo que existe) antes de comprobar si el PI está en el inicio.
																							 * 		CONTROLA EL CASO DEL SEGUNDO ELEMENTO INSERTADO: al comprobar la condición del bucle no compararía el primer dato con el segundo,
																							 * 			por lo que siempre se insertaría en el inicio aunque fuese menor que el que estaba en el inicio
																							 * 		Para el resto de casos comprueba si el dato modificado/insertado es el mayor de la lista, por lo que lo coloca en el inicio
																							 * 			Si no lo es primero avanza el PI para insertar detrás del elemento del que es inmediatamente inferior*/
	Nacionalidad* nacionPI;																	//Puntero auxiliar que almacena el dato insertado/modificado
	Nacionalidad* nacion;																	//Puntero auxiliar para consultar la lista 'lNacion'

	if(!lNacion->enInicio()){																//CONTROLA EL CASO INICIAL: es el primer elemento a insertar, por lo que ya está ordenado
		lNacion->consultar(nacionPI);														//Guarda el dato insertado/modificado (que está apuntado por el PI) para poder borrarlo y ordenarlo
		lNacion->borrar();
																							/* Como el resto de la lista está ordenada en orden descendente y se insertan/modifican los datos de tal manera que nunca tendrán menos habitantes que antes
																							 * 		solo es necesario comprobar el dato insertado/modificado con los anteriores a él. Más detenidamente:
																							 * 			+ Cuando se modifica un dato solo puede aumentar su número de habitantes, por lo que le corresponderá una posición anterior en la lista
																							 * 			+ Cuando se inserta un dato nuevo se hace al final
																							 * 		En resumen, es imposible que un dato esté entre otros dos que sean mayor que éste, y por tanto solo es necesario compararlo con los
																							 * 			datos anteriores a éste en la lista*/
		do{
			lNacion->retroceder();
			lNacion->consultar(nacion);
			siguiente = *nacionPI > *nacion;                                                //Indica si el dato insertado/modificado es menor/mayor
		}while(siguiente && !lNacion->enInicio());
		if(!siguiente)																		//Comprueba si el dato insertado/modificado es mayor que todos los de la lista
			lNacion->avanzar();																//No lo es. Hay que insertarlo detrás del PI
		lNacion->insertar(nacionPI);														//Si era el mayor de todos se inserta el primero. Si no ya se ha avanzado el PI y se puede insertar detrás de éste
	}
}

}
