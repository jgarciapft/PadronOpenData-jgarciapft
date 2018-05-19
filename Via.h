/**
 * @CLASE: Via
 *
 * @brief
 * 		Modela el concepto de 'vía' y su comportamiento (operadores). Cada vía está definida por su nombre, el barrio al que pertence,
 * 			su tipo (Calle, AVDA, Plaza, etc.), su longitud y un código único. Principalmente sirve para contextualizar la
 * 			búsqueda/modificación de datos del padrón en una vía
 *
 * @atributo barrioVia
 * 		Nombre del barrio al que pertenece
 * @atributo nombreVia
 * 		Nombre de la vía
 * @atributo longitudVia
 * 		Longitud de la vía en metros (m) con precisión decimal proporcionada por el tipo primitivo 'float'
 * @atributo codVia
 * 		Código númerico en el rango de [0, NUMERO DE VIAS]. Relaciona cada vía con un set de datos demográficos leídos del
 * 			archivo del padrón, representados por una instancia de la clase 'DatosDemograficos'.
 * 			Cada código es único para cada vía y es compartido por todos los tramos de vías (objetos 'Via' también) que
 * 			pertenecen a distintos barrios con el mismo nombre de vía
 * @atributo datDemograficos
 * 		Instancia de la clase 'DatosDemograficos' que almacena la información del padrón para una vía. Inicialmente apunta a
 * 			NULL y se le asigna una instancia a través del método 'Via::setDatosDemograficos', invocado en la carga de datos
 * 			demográficos
 */

#ifndef VIA_H_
#define VIA_H_

#include "DatosDemograficos.h"

namespace std {

class Via {

private:
	string barrioVia;
	string nombreVia;
	float longitudVia;
	string tipoVia;
	int codVia;
	DatosDemograficos* datDemograficos;

public:
	/**
	 * @brief
	 * 		CONSTRUCTOR POR DEFECTO. Inicializa 'datDemograficos' a NULL y el resto de atributos al valor por defecto
	 *
	 * @pre:
	 * @post: Instancia de Via inicializada por defecto
	 * @complejidad: O(1)
	 */
	Via();
	/**
	 * @brief
	 * 		CONSTRUCTOR PARAMETRIZADO. Inicializa todos los atributos de una instancia de la clase Via a partir de los parámetros
	 *
	 * @param barV
	 * 		Nombre del barrio
	 * @param nomV
	 * 		Nombre de la vía
	 * @param lonV
	 * 		Longitud de la vía
	 * @param tipV
	 * 		Tipo de la vía
	 * @param codV
	 * 		Código de la vía
	 *
	 * @pre:
	 * @post: Instancia de la clase Via inicializada paramétricamente
	 * @complejidad: O(1)
	 */
	Via(string barV, string nomV, float lonV, string tipV, int codV);
	/**
	 * @brief
	 * 		DESTRUCTOR
	 *
	 * @pre:
	 * @post:
	 * @complejidad: O(1)
	 */
	~Via();

	string getBarrioVia() const;
	string getNombreVia() const;
	float getLongitudVia() const;
	string getTipoVia() const;
	int getCodVia() const;
	void setDatosDemograficos(DatosDemograficos* dD);
	int alg7(int limInf, int limSup);
	void alg8(ListaPI<Estudios*>*& lEstud);
	void alg9(float& nHombres, float& nMujeres);
	void alg11(ofstream& ofs);
	int alg12(string nombreProvincia);

	/**
	 * @brief
	 * 		Muestra toda la información de cada vía y la relacionada con su dato demográfico (si tiene).
	 * 			Se utiliza con fines de prueba
	 *
	 * @pre:
	 * @post: Muestra los atributos de cada vía y llama a mostrar todos los datos del set de datos demográficos (si tiene)
	 * @complejidad: O(n)
	 */
	void mostrar();

	/**
	 * @brief
	 * 		Sobrecarga del operador MAYOR QUE (>)
	 * 		Criterio de comparación: Orden alfabético de 'nombreVia'
	 *
	 * @param v
	 * 		Segundo operando
	 * @return
	 * 		Resultado booleano de la operación
	 */
	bool operator >(const Via& v);
};

/**
 * @CLASE: ComparadorPtrVia
 *
 * @brief
 * 		Implementa el operador comparador de punteros a vía para definir el comportamiento de la inserción de vías en ABB
 */
class ComparadorPtrVia {

public:
	/**
	 * @brief
	 * 		Define el operador comparador de punteros a vías. Si el primer operando es alfabéticamente MAYOR por nombre de la vía
	 * 			que el segundo, el resultado es positivo (1). Si por el contrario es MENOR, el resultado es negativo (-1).
	 * 			Dos operandos son iguales si y solo si coinciden lexicográficamente los nombres de las vías y de los barrios a los
	 * 			que pertenecen. Esto permite la inserción de varios tramos de vía que comparten nombre, pero no barrio.
	 * @pre: v1 != NULL. v2 != NULL
	 * @post: Resultado de la comparación del primer operando con el segundo, en ese orden
	 * @complejidad: O(1)
	 *
	 * @param v1
	 * 		Primer operando
	 * @param v2
	 * 		Segundo operando
	 * @return
	 * 		Resultado de la comparación
	 */
	int operator() (const Via* v1, const Via* v2){
		int res;

		if(v1->getNombreVia() == v2->getNombreVia() && v1->getBarrioVia() == v2->getBarrioVia())	res = 0;
		else if(v1->getNombreVia() > v2->getNombreVia())											res = 1;
		else																						res = -1;

		return res;
	}
};

}

#endif /* VIA_H_ */
