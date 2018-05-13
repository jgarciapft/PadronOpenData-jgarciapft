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

class UI {

private:
	Padron p;				//Instancia de la clase principal

	int  menu     ();
	void ejecutar ();
public:
	 UI();
	~UI();
};

#endif /* UI_H_ */
