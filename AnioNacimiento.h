/*
 * AnioNacimiento.h
 *
 *      Autor: jgarciapft
 */

#ifndef ANIONACIMIENTO_H_
#define ANIONACIMIENTO_H_

namespace std {

class AnioNacimiento {
private:
	int anio;
	int nPersonas;
public:
	AnioNacimiento();
	AnioNacimiento(int aN, int nP);
	~AnioNacimiento();

	int getAnio();
	int getNPersonas();
};

}

#endif /* ANIONACIMIENTO_H_ */
