/*
 * PLACEHOLDER
 */

#include "MetodosAuxiliares.h"

namespace pruebas{

MetodosAuxiliares::MetodosAuxiliares() {}

MetodosAuxiliares::~MetodosAuxiliares() {}



void MetodosAuxiliares::ordenarLista(ListaPI<Nacionalidad*>*& lNacion) {
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

}
