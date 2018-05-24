/**
 * @CLASE: Padron
 */

#include "Padron.h"

namespace std {

Padron::Padron() {
	gBarrio = new GestorBarrio();
	lVias = new ListaPI<Via*>();										//Lista de nuevas vías creadas auxiliar
	aVias = new Arbol<Via*, ComparadorPtrVia>();						//ABB de nuevas vías vías creadas auxiliar
	lDatDemograficos = new ListaPI<DatosDemograficos*>();				//Lista de nuevos datos demográfiocos creados auxiliar
}

Padron::~Padron() {
	DatosDemograficos* dD;												//Puntero auxiliar para consultar la lista auxiliar de datos demográficos

	//Libera todos los datos demográficos creados, almacenados en la lista auxiliar 'lDatDemograficos', y la misma lista
	lDatDemograficos->moverInicio();
	while (!lDatDemograficos->finLista()) {
		lDatDemograficos->consultar(dD);
		lDatDemograficos->avanzar();
		delete dD;														//Libera cada dato demográfico
	}
	delete gBarrio;														//Desencadena los destructores de toda la estructura de datos en cascada liberando el espacio reservado, menos los datos demográficos (ya liberados)
	delete lVias;														//Libera los nodos de la lista de vías auxiliar, pero no las vías
	delete aVias;														//Libera el ABB de vías auxiliar, pero no las vías
	delete lDatDemograficos;											//Libera la lista de datos demográficos auxiliar
}

/****************************************************************************		INTERFAZ PRIVADA	****************************************************************************/

void Padron::alg11(Arbol<Via*, ComparadorPtrVia>* aVias, string nombreVia, ofstream& ofs, bool& enc) {
	Via* vRaiz = aVias->raiz();											//Puntero auxiliar para almacenar la raíz del ABB. Evita múltiples llamadas a consultar la raíz del ABB actual

	//RECORRIDO en PRE-ORDEN. Solo se explora el ABB hasta que se encuentra la vía (raíz) buscada
	if(vRaiz->getNombreVia() == nombreVia){								//Comprueba si la vía raíz es la buscada. Como cada tramo de vía contiene todos los datos de todos los tramos, no hace falta seguir buscando
		enc = true;														//Actualiza la bandera
		vRaiz->alg11(ofs);												//Ejecuta la funcionalidad del algoritmo 11
	}else if(vRaiz->getNombreVia() < nombreVia){						//Si el nombre de la vía de la ráiz es alfabéticamente MENOR que la vía a buscar se sigue buscando por el subárbol derecho (vías mayores)
		if(aVias->hijoDer() != NULL)
			alg11(aVias->hijoDer(), nombreVia, ofs, enc);
	}else if(aVias->hijoIzq() != NULL){									//Sino el nombre de la raíz es alfabéticamente MAYOR que la vía a busca y se sigue buscando por el subárbol izquierdo (vías menores)
		alg11(aVias->hijoIzq(), nombreVia, ofs, enc);
	}
}

Arbol<Via*, ComparadorPtrVia>* Padron::alg12(Arbol<Via*, ComparadorPtrVia>* aVias, string raiz) {
	Arbol<Via*, ComparadorPtrVia>* aAux = NULL;							//Puntero auxiliar con el ABB a devolver

	//RECORRIDO en PRE-ORDEN. Explora la raíz de cada nodo en cada llamada para explorar el menor número de nodos que no van a cumplir los requisitos
	if(aVias->raiz()->getNombreVia().find(raiz) == 0){					//Comprueba si se ha encontrado la ráiz que compartirán los subárboles precedentes a esta raíz
		aAux = aVias;
	}else if(aVias->raiz()->getNombreVia() < raiz){						//Si la el nombre de la vía es alfabéticamente MENOR. La búsqueda debe continuar por el subárbol derecho mientras que exista
		if (aVias->hijoDer() != NULL)
			aAux = alg12(aVias->hijoDer(), raiz);
	}else if(aVias->hijoIzq() != NULL){									//Sino el nombre de la vía es alfabéticamente MAYOR. La búsqueda debe continuar por el subárbol derecho mientras que exista
		aAux = alg12(aVias->hijoIzq(), raiz);
	}

	return aAux;
}

int	Padron::filtroInOrden(Arbol<Via*, ComparadorPtrVia>* aVias, string raiz, string nombreProvincia, ListaPI<int>*& lCoincidencias) {
	int nPersonas = 0;													//Acumulador del número total de habitantes que pertenecen a la provincia dada
	int intAux;															//Temmporal para consultar la lista de coincidencias
	bool coincidencia = false;											//Bandera para indicar si la vía actual (raíz del ABB) ha sido procesada

	//RECORRIDO en IN-ORDEN. Recorre en el orden establecido el ABB con las vías que potencialmente comienzan por la raíz dada
	if(aVias->hijoIzq() != NULL)
		nPersonas += filtroInOrden(aVias->hijoIzq(), raiz, nombreProvincia, lCoincidencias);

	if(aVias->raiz()->getNombreVia().find(raiz) == 0){					//Potencialmente el árbol completo comienza por la raíz dada pero como la inserción es imperfecta pueden haberse colado nodos menores que el actual pero mayores que el anterior al actual
		lCoincidencias->moverInicio();
		while(!lCoincidencias->finLista() && !coincidencia){			//Comprueba si la vía ya ha sido procesada
			lCoincidencias->consultar(intAux);
			lCoincidencias->avanzar();
			if(aVias->raiz()->getCodVia() == intAux)					//Si los códigos de vía coinciden es que ya se ha consultado anteriormente la vía actual y no hay que procesarla
				coincidencia = true;									//Actualiza la bandera de coincidencia
		}
		if(!coincidencia){
			nPersonas += aVias->raiz()->alg12(nombreProvincia);			//Acumula el número de habitantes de cada vía raíz que pertenecen a la provincia dada
			lCoincidencias->insertar(aVias->raiz()->getCodVia());		//Añade la vía actual a la lista de vías procesadas
		}
	}

	if(aVias->hijoDer() != NULL)
		nPersonas += filtroInOrden(aVias->hijoDer(), raiz, nombreProvincia, lCoincidencias);

	return nPersonas;
}

/****************************************************************************		INTERFAZ PÚBLICA	****************************************************************************/

bool Padron::cargarBarrios() {
	ifstream fEnt;														//Flujo de entrada del que leer los datos
	bool rutaValida = false;											//Almacena el estado de la carga
	string campos[N_CAMPOS_BARRIO];										//Almacena los campos que definen cada objeto 'Barrio'

	fEnt.open(RUTA_BARRIO.c_str());
	if(fEnt.is_open()){													//Comprueba que exista el fichero de datos comprobando si el flujo se abrió correctamente
		rutaValida = true;												//Actualiza la bandera para indicar que se pudo cargar los barrios
		getline(fEnt, campos[0]); 										//Salta la cabecera
		while(!fEnt.eof()){
			getline(fEnt, campos[0], SEP); 								//Lee el nombre del barrio
			getline(fEnt, campos[1]);									//Lee el nombre del distrito
			if(!fEnt.eof())												//Doble comprobación del FINAL DE FICHERO (EOF) para evitar leer una línea vacía adicional
				gBarrio->insertar(new Barrio(campos[0], campos[1]));	//Inicializa e inserta el nuevo objeto 'Barrio' en la estructura de datos a partir de los campos leídos
		}
		gBarrio->insertar(new Barrio(DEF_BARRIO, DEF_PLACEHOLDER));		//Barrio que contiene las vías que no tienen ningún barrio asignado
	}
	fEnt.close();														//Cierra el flujo

	return rutaValida;
}

bool Padron::cargarVias() {
	ifstream fEnt;														//Flujo de entrada del que leer los datos
	bool rutaValida = false;											//Almacena el estado de la carga
	string campos[N_CAMPOS_VIA];										//Almacena los campos que definen cada objeto Via
	Via* vAux;															//Puntero auxiliar para almacenar la vía recién creada en la lista de vías auxiliar y en su barrio correspondiente

	fEnt.open(RUTA_VIAS.c_str());
	if(fEnt.is_open()){													//Comprueba que exista el fichero de datos comprobando si el flujo se abrió correctamente
		rutaValida = true;												//Actualiza la bandera para indicar que se pudo cargar las vías
		getline(fEnt, campos[0]); 										//Salta la cabecera
		while(!fEnt.eof()){
			for(int i=0; i<N_CAMPOS_VIA-1; i++){						//Lee todos los campos de cada vía menos el último
				getline(fEnt, campos[i], SEP);
			}
			getline(fEnt, campos[4]);									//Lee el último campo
			if(campos[0] == DEF_PLACEHOLDER)							//Comprueba si la vía no está asignada a ningún barrio
				campos[0] = DEF_BARRIO;									//Entonces se le asigna al barrio contenedor
			if(!fEnt.eof()){											//Doble comprobación del FINAL DE FICHERO (EOF) para evitar leer una línea vacía adicional
				vAux = new Via(campos[0], campos[1], atof(campos[2].c_str()), campos[3], atoi(campos[4].c_str()));
				lVias->insertar(vAux);									//Insertar la vía creada en la lista de vías auxiliar
				aVias->insertar(vAux);									//Inserta la vía recién creada en el ABB. No se asegura que el ABB quede perfectamente balanceado
				gBarrio->insertarVia(vAux);								//Inserta la vía creada en la estructura de datos
			}
		}
	}
	fEnt.close();														//Cierra el flujo

	return rutaValida;
}

bool Padron::cargarDatosDemograficos() {
	ifstream fEnt;														//Flujo de entrada del que leer los datos
	bool rutaValida = false;											//Almacena el estado de la carga
	string campos[N_CAMPOS_DATOS_DEMOGRAFICOS];							//Almacena los campos que definen cada objeto
	DatosDemograficos* dD;												//Puntero auxiliar para almacenar el dato demográfico recién creado en la lista auxiliar y en su(s) vía(s) correspondiente(s)

	fEnt.open(RUTA_PADRON.c_str());
	if(fEnt.is_open()){
		rutaValida = true;												//Actualiza la bandera para indicar que se pudo cargar los datos demográficos
		getline(fEnt, campos[0]); 										//Salta la cabecera
		while(!fEnt.eof()){
			for(int i=0; i<N_CAMPOS_DATOS_DEMOGRAFICOS-1; i++){			//Lee todos los campos menos el último(año del padron, no se usará)
				getline(fEnt, campos[i], SEP);
			}
			getline(fEnt, campos[N_CAMPOS_DATOS_DEMOGRAFICOS-1]);		//Salta a la siguiente línea
			if(!fEnt.eof()){											//Doble comprobación del FINAL DE FICHERO (EOF) para evitar leer una línea vacía adicional
				dD = new DatosDemograficos(atoi(campos[0].c_str()), campos[1], campos[2], campos[3], atoi(campos[4].c_str()),
							atoi(campos[5].c_str()), campos[6]);
				lDatDemograficos->insertar(dD);							//Inserta el dato demográfico creado en la lista auxiliar de datos demográficos
				gBarrio->insertarDatosDemograficos(dD);					//Inserta el dato demográfico creado en la estructura de datos
			}
		}
	}
	fEnt.close();														//Cierra el flujo

	return rutaValida;
}

void Padron::alg2(string nombreBarrio) {								///@NOTA: Método invocativo
	gBarrio->alg2(nombreBarrio);
}

void Padron::alg3() {
	bool primerRes = true;												//Bandera que controla la impresión de la cabecera para una vía que atraviese varios barrios
	bool coincidencia = false;											//Bandera que verifica que no se haya procesado previamente la vía actual
	Via* vAux1;															//Puntero auxilar que recorre secuencialmente el bucle externo
	Via* vAux2;															//Puntero auxiliar que recorre secuencialmente el resto de vías por detrás de 'vAux1' para compararlas con ésta
	string nombreVia;													//Cadena auxiliar para consultar los nombres de vías anteriormente procesadas por el algoritmo
	ListaPI<string> lCoincidencias;										//Lista de nombres vías que ya han sido procesadas. Evita volver a procesar vías ya tratadas

	lVias->moverInicio();
	while(!lVias->finLista()){											//BUCLE EXTERNO: Lee secuencialmente todas las vías de la lista de inicio a fin
		lVias->consultar(vAux1);
		lVias->avanzar();
		lCoincidencias.moverInicio();
		while(!lCoincidencias.finLista() && !coincidencia){				//Antes de entrar al bucle interno se comprueba si la vía actual ya ha sido procesada
			lCoincidencias.consultar(nombreVia);
			lCoincidencias.avanzar();
			if(vAux1->getNombreVia() == nombreVia)
				coincidencia = true;
		}
		if(!coincidencia){												//Si no ha habido ninguna coincidencia se procesan el resto de vías en la lista
			while(!lVias->finLista()){									//BUCLE INTERNO: Para cada vía apuntada por el bucle externo procesa todas las siguientes. No se pueden asumir el número de coincidencias
				lVias->consultar(vAux2);
				lVias->avanzar();
				if(vAux1->getNombreVia() == vAux2->getNombreVia()){
					if(primerRes){										//Comprueba si es una nueva vía que atraviesa varios barrios
						cout << "Vía : " << vAux1->getNombreVia() << endl;
						cout << "-----------------------------------------------------------------------------------------------" << endl;
						cout << "Barrios que atraviesa : " << endl << endl;
						cout << vAux1->getBarrioVia() << endl;
						lCoincidencias.insertar(vAux1->getNombreVia());//Añade el nombre de la vía a la lista de vías procesadas
						primerRes = false;								//Actualiza la bandera para evitar volver a añadir el nombre de la vía acutual a la lista de coincidencias
					}
					cout << vAux2->getBarrioVia() << endl;
				}
			}
			if(!primerRes)												//Solo imprime el footer si ha habido alguna coincidencia
				cout << "-----------------------------------------------------------------------------------------------" << endl << endl;
			lVias->moverInicio();
			do {														/* El uso de la estructura 'do while' se justifica porque al final de cada ejecución del bucle interno el PI siempre apuntará a NULL, siempre se recorre el resto de la lista entera
			 															 *		No se puede asumir el número de barrios por los que pasará una vía. Moviendo el pI al inicio y consultándolo antes de hacer la comprobación elimina la comprobación trivial de que 'vAux1' nunca será 'vAux2' */
				lVias->consultar(vAux2);
				lVias->avanzar();
			} while(vAux1 != vAux2);									//Coloca el PI en la posición siguiente en relación a la que tenía al abandonar el bucle externo. No se comprueba el final de lista porque nunca puede alcanzarlo
			primerRes = true; 											//Reinicia la banera de primer resultado. Solo tiene efecto si hubo alguna coincidencia de vías
		}
		coincidencia = false;											//Reinicia la bandera de coincidencias. Solo tiene efecto si hubo alguna coincidencia con alguna vía ya tratada
	}
}

void Padron::alg4() {
	ListaPI<AnioNacimiento*>* lAnioNac = new ListaPI<AnioNacimiento*>();/* Lista en la que se almacenan los resultados del algoritmo: Cada intervalo con el numero total de habitantes es representada por un objeto 'AnioNacimiento'
																		 * 		La marca de clase del intervalo, siempre el límite inferior, se almacena en el atributo 'anio' y el número de habitantes en 'nPersonas' */
	DatosDemograficos* dD;												//Puntero auxiliar para consultar la lista de datos demográficos auxiliar
	AnioNacimiento* anNacAux;											//Puntero auxiliar para consultar la lista local 'lAnioNac'
	int nPersonas;														//Guarda el número de personas pertenecientes al rango de edad del dato actual de la lista 'lAnioNac'. Se utiliza para mostrar por pantalla dicho número de personas
	int nPersPorDiv;													//Número de personas que representan cada carácter que forma una columna en la representación gráfica. Se determina con el resultado de NPersonas(modaNPersonas) % 275 para que quede un rango adecuado dependiendo de la muestra
	int nDivisiones;													//Número de divisiones calculadas para cada intervalo
	int mayorMarca = 0;													//Mayor marca hasta ahora. Se utiliza para el espaciado entre la etiqueta y la columna en la representación gráfica
	int modaNPersonas = 0;												//Moda estadística del número de personas para cada intervalo de edad
	string carDivision = "·";											//Carácter que representa una división en la representación gráfica
	string cadDivisiones;												//Cadena para contruir la columna de cada intervalo
	string cadSep;														//Cadena para construir la separación entre la etiqueta y la columna
	string cadMayorMarca;												//Cadena para almacenar la conversión a entero de la mayor marca

	//Recorre la lista de datos demográficos auxiliar secuencialmente de inicio a fin
	lDatDemograficos->moverInicio();
	while(!lDatDemograficos->finLista()){								//También comprueba si la lista está vacía inicialmente
		lDatDemograficos->consultar(dD);
		lDatDemograficos->avanzar();
		dD->alg4(lAnioNac);
	}

	//Muestra la lista con los resultados del algoritmo una vez completado
	lAnioNac->moverInicio();
	for(int i=0; !lAnioNac->finLista(); i++){							//Recorre secuencialmente la lista de años de nacimiento de inicio a fin. Se utiliza el índice 'i' para calcular los límites del intervalo a mostrar. También comprueba si hay algún dato inicialmente
		lAnioNac->consultar(anNacAux);
		if(i*RANGO_EDAD_ALG_4 == anNacAux->getAnio()){ 					//Comprueba si el intervalo del dato de la lista 'lAnioNac' coincide con el siguiente intervalo a mostrar
			nPersonas = anNacAux->getNPersonas();
			lAnioNac->avanzar();										//SOLO se avanza la lista si el intervalo actual coincide con el intervalo a mostrar. Sino espera más iteraciones a que coincidan
			if(anNacAux->getAnio() > mayorMarca) 			            //Actualiza la mayor marca de clase
				mayorMarca = (anNacAux->getAnio());
			if(anNacAux->getNPersonas() > modaNPersonas)				//Actualiza la moda
				modaNPersonas = anNacAux->getNPersonas();
		}else{															//Sino avanza las iteraciones necesarias hasta que alcanza el intervalo correspondiente a dicho dato y se muestran 0 personas para el intervalo actual
			nPersonas = 0;
		}
		cout << i*RANGO_EDAD_ALG_4 << " a " << (i+1)*RANGO_EDAD_ALG_4 - 1 << " - " << nPersonas << " persona(s)" << endl;	//Muestra el resultado del intervalo i-ésimo con amplitud RANGO_EDAD_ALG_4
	}
	nPersPorDiv = modaNPersonas % 275;									//Crea divisiones de tamaño dependiente de la muestra. SOLO es válida para muestras con una varianza pequeña
	cadMayorMarca = int_to_string(mayorMarca);							//Convierte la mayor marca a entero para contar sus dígitos como caracteres

	//Muestra la representación gráfica de los intervalos
	cout << "\nREPRESENTACIÓN GRÁFICA - APROXIMACIÓN A UN HISTOGRAMA DE FRECUENCIAS\t" << "· = " << nPersPorDiv << " personas (aprox.)" << endl << endl;
	lAnioNac->moverInicio();
	for(int i=0; !lAnioNac->finLista(); i++){							//Recorre secuencialmente la lista de años de nacimiento de inicio a fin. Se utiliza el índice 'i' para calcular los límites del intervalo a mostrar
		lAnioNac->consultar(anNacAux);
		if(i*RANGO_EDAD_ALG_4 == anNacAux->getAnio()){ 					//Comprueba si el intervalo del dato de la lista 'lAnioNac' coincide con el siguiente intervalo a mostrar
			nDivisiones = anNacAux->getNPersonas() / nPersPorDiv;
			lAnioNac->avanzar();										//SOLO se avanza la lista si el intervalo actual coincide con el intervalo a mostrar. Sino hay que esperar a que coincidan para seguir
			if(nDivisiones == 0){ nDivisiones++; }						//Rectificación de intervalos muy pequeños en comparación con el resto para poder diferenciarlos de los vacíos
		}else{															//Sino avanza las iteraciones necesarias hasta que alcanza el intervalo correspondiente a dicho dato y se muestran 0 personas
			nDivisiones = 0;
		}
		for(int j=0; j<nDivisiones; j++){ cadDivisiones.append(carDivision); }												//Construye la cadena que representará la columna para el intervalo actual
		for(int j=0; j<(cadMayorMarca.length() - int_to_string(i*RANGO_EDAD_ALG_4).length()); j++){ cadSep.append("  "); }	//Construye la cadena de separación entre la etiqueta y la columna de la gráfica restando los dígitos de la mayor marca con los de la marca actual
		if(int_to_string(i*RANGO_EDAD_ALG_4).length() != int_to_string(i*RANGO_EDAD_ALG_4 + RANGO_EDAD_ALG_4-1).length())	//Rectificación de la separación cuando los límites del intervalo difieren en número de dígitos
			cadSep.erase(cadSep.length()-1, 1);																				//Lo más común y lógico es que exista una separación máxima de 1 entre el número de dígitos de los límites
		cout << "(" << i*RANGO_EDAD_ALG_4 << " , " << (i+1)*RANGO_EDAD_ALG_4 - 1 << ")  " << cadSep << "|" << cadDivisiones << endl;

		cadSep.clear();													//Borra la cadena de separación entre etiqueta y columna para el siguiente intervalo
		cadDivisiones.clear();											//Borra la columna para el siguiente intervalo
	}

	//Libera la memoria asociada a los nuevos años de nacimiento creados
	lAnioNac->moverInicio();
	while(!lAnioNac->finLista()){										//Recorre secuencialmente la lista de años de nacimiento de inicio a fin. También maneja que no haya ningún elemento en la lista
		lAnioNac->consultar(anNacAux);
		lAnioNac->avanzar();
		delete anNacAux;												//Libera cada año de nacimiento de la lista
	}
	delete lAnioNac;													//Libera la lista
}

void Padron::alg5() {
	ListaPI<Nacionalidad*>* lNacion = new ListaPI<Nacionalidad*>();		/* Lista en la que se almacenan los resultados del algoritmo: Cada nacionalidad con el numero total de habitantes es representada por un objeto 'Nacionalidad'
																		 * 		El nombre de la nacionalidad se almacena en el atributo 'nacionalidad' y el número de personas en 'nPersonas' */
 	DatosDemograficos* dD;												//Puntero auxiliar para consultar cada dato demográfico de la lista de datos demográficos auxiliar
	Nacionalidad* nacionAux;											//Puntero auxiliar para consultar la lista local 'lNacion'

	//Recorre la lista de datos demográficos auxiliar secuencialmente de inicio a fin
	lDatDemograficos->moverInicio();
	while(!lDatDemograficos->finLista()){								//También comprueba si la lista está vacía inicialmente
		lDatDemograficos->consultar(dD);
		lDatDemograficos->avanzar();
		dD->alg5(lNacion);												//Modifica la lista local 'lNacion' con los resultados del algoritmo
	}

	//Muestra la lista con los resultados del algoritmo una vez completado
	lNacion->moverInicio();
	while(!lNacion->finLista()){										//Recorre secuencialmente la lista de nacionalidades de inicio a fin. También comprueba si inicialmente la lista está vacía inicialmente
		lNacion->consultar(nacionAux);
		lNacion->avanzar();
		cout << nacionAux->getNacionalidad() << " (" << nacionAux->getNPersonas() << ")" << endl;
	}

	//Libera la memoria asociada a las nuevas nacionalidades creadas
	lNacion->moverInicio();
	while(!lNacion->finLista()){										//Recorre secuencialmente la lista de nacionalidades de inicio a fin. También maneja que no haya ningún elemento en la lista
		lNacion->consultar(nacionAux);
		lNacion->avanzar();
		delete nacionAux;												//Libera cada nacionalidad de la lista
	}
	delete lNacion;														//Libera la lista
}

void Padron::alg6() {
	ListaPI<LugarNacimiento*>* lLugNac = new ListaPI<LugarNacimiento*>();/* Lista en la que se almacenan los resultados del algoritmo: Cada provincia con el numero total de habitantes es representada por un objeto 'LugarNacimiento'
																		  *		El nombre de la provincia se almacena en el atributo 'provinciaPais' y el número de habitantes en 'nPersonas' */
 	DatosDemograficos* dD;												//Puntero auxiliar para consultar la lista de datos demográficos auxiliar
	LugarNacimiento* lugNacAux;											//Puntero auxiliar para consultar la lista local 'lLugNac'

	//Recorre la lista de datos demográficos auxiliar secuencialmente de inicio a fin
	lDatDemograficos->moverInicio();
	while(!lDatDemograficos->finLista()){								//También comprueba si la lista está vacía inicialmente
		lDatDemograficos->consultar(dD);
		lDatDemograficos->avanzar();
		dD->alg6(lLugNac);												//Modifica la lista con los resultados del algoritmo
	}

	//Muestra la lista con los resultados del algoritmo una vez completado
	lLugNac->moverInicio();
	while(!lLugNac->finLista()){										//Recorre secuencialmente la lista de lugares de nacimiento de inicio a fin. También comprueba si la lista está vacía inicialmente
		lLugNac->consultar(lugNacAux);
		lLugNac->avanzar();
		cout << lugNacAux->getProvinciaPais() << " (" << lugNacAux->getNPersonas() << ")" << endl;
	}

	//Libera la memoria asociada a los nuevos lugares de nacimiento creados
	lLugNac->moverInicio();
	while(!lLugNac->finLista()){										//Recorre secuencialmente la lista de lugares de nacimiento de inicio a fin. También maneja que no haya ningún elemento en la lista
		lLugNac->consultar(lugNacAux);
		lLugNac->avanzar();
		delete lugNacAux;												//Libera cada lugar de nacimiento de la lista
	}
	delete lLugNac;														//Libera la lista
}

void Padron::alg7(int limInf, int limSup) {								///@NOTA: Método invocativo
	if(limInf <= limSup)												//Comprueba que el rango sea válido. El límite inferior debe ser menor o igual que el límite superior y viceversa
		gBarrio->alg7(limInf, limSup);
	else
		cout << "ERROR : El límite inferior (" << limInf << ") debe ser inferior al límite superior (" << limSup << ")" << endl;
}

void Padron::alg8(string nombreBarrio) {								///@NOTA: Método invocativo
	gBarrio->alg8(nombreBarrio);
}

void Padron::alg9() {													///@NOTA: Método invocativo
	gBarrio->alg9();
}

void Padron::alg10(string nombreProvincia) {
	ListaPI<LugarNacimiento*>* lLugNac = new ListaPI<LugarNacimiento*>();/* Lista en la que se almacenan los resultados del algoritmo: Cada lugar de nacimiento con el numero total de habitantes es representada por un objeto 'LugarNacimiento':
																	      *		La población se almacena en el atributo 'poblacion' y el número de personas en 'nPersonas' */
	ofstream ofs;														//Flujo de salida para volcar los resultados del algoritmo a un fichero
	string ruta = "Poblaciones-";										//Ruta del fichero en el que se almacenan los resultados del algoritmo
	string extension = ".txt";											//Extensión del fichero donde se vuelcan los resultados del algoritmo
	DatosDemograficos* dD;												//Puntero auxiliar para consultar los datos demográficos de la lista de datos demográficos auxiliar
	LugarNacimiento* lugNacAux;											//Puntero auxiliar para consultar la lista local 'lLugNac'

	//Recorre la lista de datos demográficos auxiliar secuencialmente de inicio a fin
	lDatDemograficos->moverInicio();
	while (!lDatDemograficos->finLista()){								//También comprueba si la lista está vacía inicialmente
		lDatDemograficos->consultar(dD);
		lDatDemograficos->avanzar();
		dD->alg10(lLugNac, nombreProvincia);							//Actualiza la lista de poblaciones para la provincia dada con cada set de datos demográficos
	}

	//Muestra los resultados del algoritmo
	ruta += nombreProvincia + extension;								//Conforma la ruta relativa del archivo de volcado
	ofs.open(ruta.c_str(), ios::app);									//Modo de apertura : adjutar. Añade a continuación de los contenidos previos los resultados de esta ejecución
	if(ofs.is_open()){													//Comprueba que se haya abierto el flujo correctamente
		if(!lLugNac->estaVacia()){										//Comprueba que se haya leído algún dato
			ofs << "\n\nCenso de las poblaciones que pertenecen a la provincia - " << nombreProvincia << endl;
			ofs << "-----------------------------------------------------------------------------------------------" << endl;
			lLugNac->moverInicio();
			while(!lLugNac->finLista()){
				lLugNac->consultar(lugNacAux);
				lLugNac->avanzar();
				ofs << lugNacAux->getPoblacion() << " (" << lugNacAux->getNPersonas() << ")" << endl;
			}
		}else{															//Si no se ha encontrado ninguna población para la provincia dada se indica al usuario por consola
			cout << "NO SE HA ENCONTRADO NINGUNA POBLACIÓN PARA LA PROVINCIA (" << nombreProvincia << ")" << endl;
		}
	}else{																//Si no se han podido volcar los resultados del algoritmo se indica al usuario por consola
		cout << "ERROR AL CREAR EL FICHERO PARA VOLCAR LOS RESULTADOS" << endl;
	}
	ofs.close();														//Cierra el flujo

	//Libera la memoria asociada a los nuevos datos creados
	lLugNac->moverInicio();
	while(!lLugNac->finLista()){										//Recorre secuencialmente la lista de estudios de inicio a fin. También maneja que no haya ningún elemento en la lista
		lLugNac->consultar(lugNacAux);
		lLugNac->avanzar();
		delete lugNacAux;												//Libera cada lugar de nacimiento de la lista
	}
	delete lLugNac;														//Libera la lista
}

void Padron::alg11_EDL(string nombreVia) {
	ofstream ofs;														//Flujo de salida para volcar los resultados del algoritmo a un fichero
	bool enc = false;													//Bandera para salir del bucle al encontrar la vía
	string ruta = "LugaresNacimiento-";									//Ruta del fichero en el que se almacenan los resultados del algoritmo
	string extension = ".txt";											//Extensión del fichero donde se vuelcan los resultados del algoritmo
	Via* vAux;															//Puntero auxiliar para consultar la lista de vías auxiliar

	ruta += nombreVia + extension;										//Conforma la ruta relativa del archivo de volcado
	ofs.open(ruta.c_str(), ios::app);									//Modo de apertura : adjutar. Añade a continuación de los contenidos previos los resultados de esta ejecución
	if(ofs.is_open()){													//Comprueba que se haya abierto el flujo correctamente
		ofs << "\n\nLista de LUGARES de NACIMIENTO para la VIA - " << nombreVia << endl;
		ofs << "-----------------------------------------------------------------------------------------------" << endl;
		lVias->moverInicio();
		while(!lVias->finLista() && !enc){								/*Recorre la lista de vías auxiliar secuencialmente hasta que encuentra un tramo de vía; cada tramo de vía contiene la información de
 																			todos los tramos*/
			lVias->consultar(vAux);
			lVias->avanzar();
			if(vAux->getNombreVia() == nombreVia){						//Comprueba si el nombre de la vía actual coincide con el buscado
				vAux->alg11(ofs);										//Imprime todos los lugares de nacimiento asociados a la vía que ha ooincidio. El flujo se abre y se cierra en este método
				enc = true;
			}
		}
		if(!enc)
			cout << "NO SE HA ENCOTRADO LA VÍA (" << nombreVia << ")" << endl;
	}else{																//Si no se ha podido abrir el flujo se indica al usuario por consola
		cout << "ERROR AL CREAR EL FICHERO PARA VOLCAR LOS RESULTADOS" << endl;
	}
	ofs.close();														//Cierra el flujo
}

void Padron::alg11_EDNL(string nombreVia) {
	ofstream ofs;														//Flujo de salida para volcar los resultados del algoritmo a un fichero
	string ruta = "LugaresNacimiento-";									//Ruta del fichero en el que se almacenan los resultados del algoritmo
	string extension = ".txt";											//Extensión del fichero donde se vuelcan los resultados del algoritmo
	bool enc = false;													//Bandera que indica si se ha encontrado o no la vía buscada

	ruta += nombreVia + extension;										//Conforma la ruta relativa del archivo de volcado
	ofs.open(ruta.c_str(), ios::app);									//Modo de apertura : adjutar. Añade a continuación de los contenidos previos los resultados de esta ejecución
	if(ofs.is_open()){													//Comprueba que se haya abierto el flujo correctamente
		if(!aVias->vacio()){											//Comprueba que el árbol no esté vacío
			ofs << "\n\nLista de LUGARES de NACIMIENTO para la VIA - " << nombreVia << endl;
			ofs << "-----------------------------------------------------------------------------------------------" << endl;
			alg11(aVias, nombreVia, ofs, enc);							//Imprime los resultados del algoritmo
		}
	}
	ofs.close();														//Cierra el flujo

	if(!enc)															//Si no se ha encontrado ninguna vía se indica al usuario por consola
		cout << "NO SE HA ENCONTRADO NINGUNA VÍA CON EL NOMBRE (" << nombreVia << ")" << endl;
}

void Padron::alg12_EDL(string raiz, string nombreProvincia) {
	int nPersonas = 0;													//Acumulador del núemro de personas nacidas en la provincia 'nombreProvincia' y que habiten en las vías que comiencen por 'raiz'
	Via* vAux;															//Puntero auxiliar para consultar la lista de vías auxiliar
	bool coincidencia = false;											//Bandera que verifica que no se haya procesado previamente la vía actual
	int cod;															//Código de la vía actual
	ListaPI<int> lCoincidencias;										//Lista de códigos de vías que ya han sido procesadas. Evita volver a procesar vías ya tratadas, sino se multiplicarían los resultados

	lVias->moverInicio();
	while(!lVias->finLista()){											//También comprueba si la lista está vacía inicialmente
		lVias->consultar(vAux);
		lVias->avanzar();
		if(vAux->getNombreVia().find(raiz) == 0){						//Comprueba si la vía actual comienza por la raíz dada
			lCoincidencias.moverInicio();
			while(!lCoincidencias.finLista() && !coincidencia){			//Antes de tratar la vía se comprueba si ya ha sido procesada
				lCoincidencias.consultar(cod);
				lCoincidencias.avanzar();
				if(vAux->getCodVia() == cod)
					coincidencia = true;
			}
			if(!coincidencia){
				nPersonas += vAux->alg12(nombreProvincia);				//Actualiza el acumulador de personas nacidas en la provincia dada
				lCoincidencias.insertar(vAux->getCodVia());				//Añade el código de la vía a la lista de vías procesadas
			}
			coincidencia = false;										//Reinicia la bandera de coincidencias. Solo tiene efecto si hubo alguna coincidencia con alguna vía ya tratada
		}
	}

	if(nPersonas != 0){													//Comprueba que se haya encontrado alguna vía que comience por la raíz dada o que exista algún habitante nacido en la provincia dada en todas las vías
		cout << "Nº de HABITANTES nacidos en la PROVINCIA - " << nombreProvincia << " - para la todas las VÍAS comenzando por la RAÍZ - \'"
				 << raiz << "\' :\t" << nPersonas << " habitantes" << endl;
		cout << "---------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}else{																//Sino se indica al usuario por consola
		cout << "NO SE HA ENCONTRADO NINGUNA VÍA POR LA RÁIZ (" << raiz << ") O NINGÚN HABITANTE PARA LA PROVINCIA (" << nombreProvincia << ")" << endl;
	}
}



void Padron::alg12_EDNL(string raiz, string nombreProvincia) {
	Arbol<Via*, ComparadorPtrVia>* aAux;								//ABB auxiliar para almacenar el ABB cuyos datos presentan potencialmente la misma raíz
	int nPersonas;														//Total de habitantes entre todas las vías que comiencen por la raíz 'raiz'
	ListaPI<int>* lCoincidencias = new ListaPI<int>();					//Lista de códigos de vías que ya han sido procesadas. Evita volver a procesar vías ya tratadas, sino se multiplicarían los resultados

	if(!aVias->vacio()){												//Comprueba que el árbol no esté vacío inicialmente
		aAux = alg12(aVias, raiz);										//Procesa el subárbol que contiene la(s) vía(s) que comienzan por la ráiz dada

		if(aAux != NULL){												//Comprueba que se haya encontrado alguna vía que comience por la raíz indicada
			nPersonas = filtroInOrden(aAux, raiz, nombreProvincia, lCoincidencias);//Calcula el número de habitantes para la provincia dada.
			if(nPersonas != 0){											//Comprueba si se ha encontrado algún habitante para la provincia dada
				cout << "Nº de HABITANTES nacidos en la PROVINCIA - " << nombreProvincia << " - para la todas las VÍAS comenzando por la RAÍZ - \'"
					 << raiz << "\' :\t" << nPersonas << " habitantes" << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			}else{														//Si no se encuentran se indica al usuario por consola
				cout << "NO SE HA ENCONTRADO NINGÚN HABITANTE PARA LA PROVINCIA (" << nombreProvincia << ")" << endl;
			}
		}else{															//Si no se encuentran resultados se indica al usuario por consola
			cout << "NO SE HA ENCONTRADO NINGUNA VÍA QUE COMIENCE POR LA RAÍZ (" << raiz << ")" << endl;
		}
	}

	delete lCoincidencias;												//Libera la memoria asociada a la lista auxiliar de coincidencias
}

void Padron::mostrarEstructura() {
	Via* vAux;															//Puntero auxiliar para consultar las vías de la lista auxiliar de vías 'lVias'
	DatosDemograficos* dD;												//Puntero auxiliar para consultar los datos demográficos de la lista auxiliar de datos demográficos 'lDatDemograficos'

	gBarrio->mostrar();													///@TEST: Muestra toda la estructura de datos cargada

	cout << "LISTA DE VÍAS AUXILIAR" << endl;							///@TEST: Muestra la lista auxiliar de todas las vías
	cout << "***********************************************************************************************" << endl;
	lVias->moverInicio();
	while(!lVias->finLista()){											//Recorre la lista de inicio a fin. También comprueba si está vacía inicialmente
		lVias->consultar(vAux);
		lVias->avanzar();
		cout << "Via : " << vAux->getNombreVia() << " | Barrio : " << vAux->getBarrioVia() << " | Longitud : " <<
					vAux->getLongitudVia() << " | (m) Tipo : " << vAux->getTipoVia() << " | Codigo : " << vAux->getCodVia() << endl;	///@NOTA: No muestra los datos demográficos
	}
	cout << "***********************************************************************************************" << endl;

	cout << "LISTA DE DATOS DEMOGRÁFICOS AUXILIAR" << endl << endl;	///@TEST: Muestra la lista auxiliar de todos los datos demograficos auxiliares
	cout << "***********************************************************************************************" << endl;
	lDatDemograficos->moverInicio();
	while(!lDatDemograficos->finLista()){								//Recorre la lista de inicio a fin. También comprueba si está vacía inicialmente
		lDatDemograficos->consultar(dD);
		lDatDemograficos->avanzar();
		dD->mostrar();													//Llama a mostrar cada dato de cada dato demográfico
	}
	cout << "***********************************************************************************************" << endl;
}

}
