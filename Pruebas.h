/*
 * PLACEHOLDER
 */

#ifndef PRUEBAS_H
#define PRUEBAS_H

#include "Padron.h"
#include "timer.h"

using namespace std;

class Pruebas {

private:
	Padron p;

private:
	/**@SOBRECARGA_OPERADORES
	 * CLASE : Via
	 * 		*v1   >   *v1   ->  FALSE
	 * 		*v1   >   *v2   ->  FALSE
	 * 		*v2	  >   *v1   ->  TRUE
	 *
	 * CLASE : ComparadorPtrVia
	 *		v1   operator()   v1   ->	0
	 *		v1	 operator()	  v2   ->   1
	 *		v2	 operator()   v1   ->  -1
	 *
	 * CLASE : Lugar Nacimiento
	 *		lugNac1   >=   lugNac1   ->  TRUE
	 *		lugNac1   >=   lugNac2   ->  FALSE
	 *		lugNac2   >=   lugNac1   ->  TRUE
	 *
	 *		lugNac1   ==   lugNac1   ->  TRUE
	 *		lugNac1   ==   lugNac2   ->  FALSE
	 *		lugNac1   ==   lugNac3   ->  TRUE
	 *
	 * CLASE : Estudios
	 *		est1   >   est1   ->  FALSE
	 *		est1   >   est2   ->  FALSE
	 *		est2   >   est1   ->  TRUE
	 *
	 *		est1   ==  est1   ->  TRUE
	 *		est1   ==  est2   ->  FALSE
	 *		est1   ==  est3   ->  TRUE
	 *
	 * CLASE : Nacionalidad
	 * 		nacion1   >   nacion1   ->  FALSE
	 * 		nacion1   >   nacion2   ->  FALSE
	 * 		nacion2   >   nacion1   ->  TRUE
	 * 		
	 * 		nacion1   ==  nacion1   ->  TRUE
	 *		nacion1   ==  nacion2   ->  FALSE
	 *		nacion1   ==  nacion3   ->  TRUE
	 */
	void pruebaSobrecargaOperadores();

public:
	Pruebas();
	~Pruebas();

	void ejecutarPruebas();
};

#endif /* PADRONOPENDATA_JGARCIAPFT_PRUEBAS_H */
