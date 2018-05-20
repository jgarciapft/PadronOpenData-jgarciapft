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
	 *
	 * @pre:
	 * @post: Instancia de Estudios inicializada por defecto
	 * @complejidad: O(1)
	 */
	Estudios();
	/**
	 * @brief
	 * 		CONSTRUCTOR PARAMETRIZADO. Inicializa todos los atributos de una instancia de la clase Estudios
	 * 			a partir de los parámetros
	 *
	 * @param nEst
	 * 		Titulación categorizada
	 * @param nP
	 * 		Número de personas que ostentan la titulación 'nEst'
	 *
	 * @pre:
	 * @post: Instancia de la clase Estudios inicializada paramétricamente
	 * @complejidad: O(1)
	 */
	Estudios(string nEst, int nP);
	/**
	 * @brief
	 * 		DESTRUCTOR
	 *
	 * @pre:
	 * @post:
	 * @complejidad: O(1)
	 */
	~Estudios();

	/**
	 * GETTERS
	 */
	string getNivEstudios() const;
	int getNPersonas() const;
	/**
	 * SETTERS
	 */
	void incNPersonas(int nP);

	/**
	 * @brief
	 * 		Muestra la información de cada estudio. Se utiliza con fines de prueba
	 *
	 * @pre:
	 * @post: Muestra los atributos de cada objeto 'Estudios'
	 * @complejidad: O(1)
	 */
	void mostrar();

	/**
	 * @brief
	 * 		Sobrecarga del operador MAYOR QUE (>)
	 * 		Criterio de comparación: Orden matemático de 'nPeronas'
	 *
	 * @param estudio
	 * 		Segundo operando
	 * @return
	 * 		Resultado booleano de la operación
	 */
	bool operator >(const Estudios& estudio);
	/**
	 * @brief
	 * 		Sobrecarga del operador IGUALDAD (==)
	 * 		Criterio de comparación: comparación lexicográfica de 'nivEsudios'
	 *
	 * @param estudio
	 * 		Segundo operando
	 * @return
	 * 		Resultado booleano de la operación
	 */
	bool operator ==(const Estudios& estudio);
};

}

#endif /* ESTUDIOS_H_ */
