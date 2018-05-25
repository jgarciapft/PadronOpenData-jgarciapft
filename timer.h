/**
 * @CLASE: Timer
 *
 * @brief
 * 		Sobrecarga del método 'clock_gettime' de la libería C estándar 'time.h'. Proporciona un método multiplataforma
 * 			preciso de calcular el tiempo transcurrido entre dos llamadas consecutivas a 'Timer::getTime'
 */

#ifndef TIMER_H_
#define TIMER_H_

class Time {

private:

	Time ();

public:

    /**
     * @brief
     *  	Funciona en diferentes plataformas, incluido POSIX (Linux), Windows y Mac OSX
     * @pre:
     * @post:
     * @complejidad: NO DEFINIDO
     *
     * @return
     * 		Devuelve el tiempo absoluto
     */
	static double getTime ();
};

#endif /* TIMER_H_ */
