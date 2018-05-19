/**
 * @CLASE: Estudios
 *
 * @brief
 * 		Clase que modela el concepto de 'nivel de estudios' y su comportamiento (operadores). Cada nivel de estudios
 * 		está definido por el título que lo categoriza y el número de personas que lo ostentan
 *
 * @atributo nivEstudios
 * 		Titulación categorizada
 * @atributo nPersonas
 * 		Número de personas que ostentan la titulación 'nivEstudios'
 */

#ifndef ESTUDIOS_H_
#define ESTUDIOS_H_

#include <iostream>

namespace std {

class Estudios {

private:
	string nivEstudios;
	int nPersonas;

public:
	/**
	 * @brief
	 * 		CONSTRUCTOR POR DEFECTO. Inicializa los atributos al valor por defecto
	 * @pre:
	 * @post:
	 * @complejidad: O(1)
	 *
	 * @return
	 * 		Instancia de Estudios inicializada por defecto
	 */
	Estudios();
	Estudios(string nEst, int nP);
	/**
	 * @brief
	 * 		DESTRUCTOR
	 *
	 * @pre:
	 * @post:
	 * @complejidad: O(1)
	 *
	 * @return
	 */
	~Estudios();

	string getNivEstudios() const;
	int getNPersonas() const;
	void incNPersonas(int nP);

	void mostrar();

	bool operator >(const Estudios& estudio);
	bool operator ==(const Estudios& estudio);
};

}

#endif /* ESTUDIOS_H_ */
