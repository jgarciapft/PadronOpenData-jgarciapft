//============================================================================
// Name        : UI.h
// Author      : profesores de la asignatura EDI
// Version     : curso 17/18
// Copyright   :
// Description : Interfaz de usuario
//============================================================================

#ifndef UI_H_
#define UI_H_

#include "Padron.h"
#include "timer.h"
#include "Pruebas.h"

class UI {

private:
	Padron p;

private:
	int  menu     ();
	void ejecutar ();
	void pausa();

public:
	 UI();
	~UI();
};

#endif /* UI_H_ */
