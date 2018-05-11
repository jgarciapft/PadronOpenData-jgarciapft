/*
 * Padron.cpp
 *
 *      Autor: jgarciapft
 */

#include "Padron.h"

namespace std {

/*** DEFINCIÓN DE CONSTANTES *** 										@NOTA: Pensar declaracion/inicializacion de constantes */
const string RUTA_BARRIO = "Barrio.csv"; 								//Ruta relativa del fichero que contiene la información de los barrios
const string RUTA_VIAS = "Via.csv"; 									//Ruta relativa del fichero que contiene la información de las vías
const string RUTA_DATOS_DEMOGRAFICOS = "InformacionPadron.csv";	 		//Ruta relativa del fichero que contiene la informacion del padrón (Año 2016)
const int N_CAMPOS_BARRIO = 2; 											//Número de campos del fichero de datos de barrios
const int N_CAMPOS_VIA = 5;												//Número de campos del fichero de datos de vías
const int N_CAMPOS_DATOS_DEMOGRAFICOS = 7;								//Número de campos del fichero de datos de datos demográficos
const char SEP = '#'; 													//Carácter separador de campos en los ficheros de datos
const string DEF_BARRIO = "BARRIO CONTENEDOR";							//Nombre del distrito del objeto barrio que incluirá las vías que no tienen ningún barrio asignado
extern const int RANGO_EDAD_ALG_4 = 10;									//Amplitud del intervalo de edad que usa el algorimto 4 para agrupar los años de nacimiento de los habitantes


Padron::Padron() {
	gBarrio = new GestorBarrio();
	lVias = new ListaPI<Via*>();										//Lista de nuevas vías creadas auxiliar
	lDatDemograficos = new ListaPI<DatosDemograficos*>();				//Lista de nuevos datos demográfiocos creados auxiliar
}

Padron::~Padron() {
	DatosDemograficos* dD;												//Puntero auxiliar para recorrer la lista auxiliar de datos demográficos

	//Libera todos los datos demográficos creados, que están almacenados en la lista auxiliar 'lDatDemograficos', y la misma lista
	lDatDemograficos->moverInicio();
	while(!lDatDemograficos->finLista()){
		lDatDemograficos->consultar(dD);
		lDatDemograficos->avanzar();
		delete dD;														//Libera cada dato demográfico
	}
	delete lDatDemograficos;											//Libera la lista auxiliar
	delete lVias;														//Libera los nodos de la lista de vías auxiliar, pero no las vías
	delete gBarrio;														//Desencadena los destructores de toda la estructura de datos liberando el espacio reservado para todos los datos, menos los datos demográficos
}



void Padron::cargarBarrios() {
	ifstream fEnt;
	string campos[N_CAMPOS_BARRIO];										//Almacena los campos que definen cada objeto Barrio

	fEnt.open(RUTA_BARRIO.c_str());
	if(fEnt.is_open()){													//Comprueba que exista el fichero de datos comprobando si el flujo se abrió correctamente
		getline(fEnt, campos[0]); 										//Salta la cabecera
		while(!fEnt.eof()){
			getline(fEnt, campos[0], SEP); 								//Lee el nombre del barrio
			getline(fEnt, campos[1]);									//Lee el nombre del distrito
			if(!fEnt.eof())												//Doble comprobación del FINAL DE FICHERO para evitar leer una línea vacía adicional
				gBarrio->insertar(new Barrio(campos[0], campos[1]));	//Inicializa e inserta el nuevo objeto Barrio a partir de los campos leídos en la estructura de datos
		}
	}
	gBarrio->insertar(new Barrio("", DEF_BARRIO));						//Barrio que contendrá las vías que no tengan ningún barrio asignado

	fEnt.close();
}

void Padron::cargarVias() {
	ifstream fEnt;
	string campos[N_CAMPOS_VIA];										//Almacena los campos que definen cada objeto Via
	Via* vAux;															//Puntero a objeto Via auxiliar para almacenar la vía recién creada en la lista auxiliar y en su barrio correspondiente

	fEnt.open(RUTA_VIAS.c_str());
	if(fEnt.is_open()){													//Comprueba que exista el fichero de datos comprobando si el flujo se abrió correctamente
		getline(fEnt, campos[0]); 										//Salta la cabecera
		while(!fEnt.eof()){
			for(int i=0; i<N_CAMPOS_VIA-1; i++){						//Lee todos los campos de cada vía menos el último
				getline(fEnt, campos[i], SEP);
			}
			getline(fEnt, campos[4]);									//Lee el último campo
			if(!fEnt.eof()){											//Doble comprobación del FINAL DE FICHERO para evitar leer una línea vacía adicional
				vAux = new Via(campos[0], campos[1], atof(campos[2].c_str()), campos[3], atoi(campos[4].c_str()));
				lVias->insertar(vAux);									//Insertar la vía creada en la lista auxiliar de vías
				lVias->avanzar();
				gBarrio->insertarVia(vAux);								//Inserta la vía creada en la estructura de datos
			}
		}
	}

	fEnt.close();
}

void Padron::cargarDatosDemograficos() {
	ifstream fEnt;
	string campos[N_CAMPOS_DATOS_DEMOGRAFICOS];							//Almacena los campos que definen cada objeto
	DatosDemograficos* dD;												//Puntero a objeto 'DatosDemograficos' auxiliar para almacenar el dato recién creado en la lista auxiliar y en su vía correspondiente

	fEnt.open(RUTA_DATOS_DEMOGRAFICOS.c_str());
	if(fEnt.is_open()){
		getline(fEnt, campos[0]); 										//Salta la cabecera
		while(!fEnt.eof()){
			for(int i=0; i<N_CAMPOS_DATOS_DEMOGRAFICOS-1; i++){			//Lee todos los campos de cada dato menos el último
				getline(fEnt, campos[i], SEP);
			}
			getline(fEnt, campos[6]);									//Lee el último campo
			if(!fEnt.eof()){											//Doble comprobación del FINAL DE FICHERO para evitar leer una línea vacía adicional
				dD = new DatosDemograficos(atoi(campos[0].c_str()), campos[1], campos[2], campos[3], atoi(campos[4].c_str()),
							atoi(campos[5].c_str()), campos[6]);
				lDatDemograficos->insertar(dD);							//Inserta el dato demográfico creado en la lista auxiliar de datos demográficos
				lDatDemograficos->avanzar();
				gBarrio->insertarDatosDemograficos(dD);					//Inserta el dato demográfico creado en la estructura de datos
			}
		}
	}

	fEnt.close();
}

void Padron::alg2(string nB) {											///@NOTA: Nombre provisional
	gBarrio->alg2(nB);
}

void Padron::alg3() {
	bool primerRes = true;												//Bandera que controla la impresión de la cabecera de para una vía que atraviese varios barrios
	bool coincidencia = false;											//Bandera que verifica que no se haya procesado previamente la vía actual
	Via* vAux1;															//Puntero auxilar que recorre secuencialmente el bucle externo
	Via* vAux2;															//Puntero auxiliar que recorre secuencialmente el resto de vías por detrás de 'vAux1' para compararlas con ésta
	string nombreVia;													//Cadena auxiliar para consultar los nombres de vías anteriormente procesadas por el algoritmo
	ListaPI<string> lCoincidencias;										//Lista de vías que ya han sido procesadas. Evita volver a procesar casos ya tratados

	lVias->moverInicio();
	while(!lVias->finLista()){											//BUCLE EXTERNO: Lee secuencialmente todas las vías de arriba a abajo
		lVias->consultar(vAux1);
		lVias->avanzar();
		lCoincidencias.moverInicio();
		while(!lCoincidencias.finLista() && !coincidencia){				//Antes de entrar al bucle interno hay que comprobar que no hayamos procesado ya la vía apuntada actualmente
			lCoincidencias.consultar(nombreVia);
			lCoincidencias.avanzar();
			if(vAux1->getNombreVia() == nombreVia)
				coincidencia = true;
		}
		if(!coincidencia){												//Si no ha habido ninguna coincidencia se procede a procesar el resto de vías en la lista
			while(!lVias->finLista()){									//BUCLE INTERNO: Para cada vía apuntada por el bucle externo procesa todas las siguientes. No podemos asumir el número máximo de coincidencias
				lVias->consultar(vAux2);
				lVias->avanzar();
				if(vAux1->getNombreVia() == vAux2->getNombreVia()){
					if(primerRes){										//Comprueba si es una nueva vía que atraviesa varios barrios
						//Imprime una cabecera
						cout << "Vía : " << vAux1->getNombreVia() << endl;
						cout << "***********************************************************************************************" << endl;
						cout << "Barrios que atraviesa : " << endl << endl;
						cout << vAux1->getBarrioVia() << endl;
						lCoincidencias.insertar(vAux1->getNombreVia());	//Añade el nombr de la vía a la lista de vías procesadas una sola vez, la primera vez que encuentre un duplicado
						primerRes = false;								//Actualiza la bandera para evitar volver a imprimir la cabeceras
					}
					cout << vAux2->getBarrioVia() << endl;				//Para el resto de vías simplemente imprime el nombre de su barrio
				}
			}
			if(!primerRes)												//Solo imprime el footer si ha habido alguna coincidencia
				cout << "***********************************************************************************************" << endl << endl;
			lVias->moverInicio();
			/*El uso de la estructura 'do while' se justifica porque al final de cada ejecución del bucle interno el pI siempre apuntará a NULL
			 *		porque hay que recorrer el resto de la lista entera. No podemos suponer el número de barrios por los que pasará una vía.
			 *		Moviendo el pI al inicio y consultándolo antes de hacer la comprobación nos libra de comprobar la certeza de que 'vAux1' nunca será 'vAux2'
			 */
			do{
				lVias->consultar(vAux2);
				lVias->avanzar();
			}while(vAux1 != vAux2);
			primerRes = true; 											//Reinicia la banera de primer resultado. Solo tiene efecto si hubo alguna coincidencia de vías
		}
		coincidencia = false;											//Reinicia la bandera de coincidencias. Solo tiene efecto si hubo alguna coincidencia con alguna vía ya tratada, y pueda volver a tratar otra vía
	}
}

void Padron::alg4() {													///@NOTA: Nombre provisional
	ListaPI<AnioNacimiento*>* lAnioNac = new ListaPI<AnioNacimiento*>();/* Lista en la que se almacenan los resultados del algoritmo. Cada intervalo con el numero total de habitantes es representada por un objeto 'AnioNacimiento'
																		 * La marca de clase del intervalo, siempre el límite inferior,  se almacena en el atributo 'anio' y el número de habitantes en 'nPersonas' */
	DatosDemograficos* dD;												//Puntero auxiliar para consultar la lista de datos demográficos auxiliar
	AnioNacimiento* anNacAux;											//Puntero auxiliar para consultar la lista local 'lAnioNac'
	int nPersonas;														//Guarda el número de personas pertenecientes al rango de edad del dato actual de la lista 'lAnioNac'. Se utiliza para mostrar por pantalla dicho número de personas
	int nPersPorDiv;													//Número de personas que representan cada carácter que forma una columna en la representación gráfica. Se determina con el resultado de NPersonas(modaNPersonas) % 275 para que quede un rango adecuado dependiendo de la muestra
	int nDivisiones;													//Número de divisiones calculadas para cada intervalo
	int mayorMarca = 0;													//Mayor marca hasta ahora. Se utiliza para el espaciado de la etiqueta y la columna en la representación gráfica
	int modaNPersonas = 0;												//Moda estadística del número de personas para cada intervalo de edad
	string carDivision = "·";											//Carácter que representa una división el la representación gráfica
	string cadDivisiones;												//Cadena para contruir la columna de cada intervalo
	string cadSep;														//Cadena para construir la separación entre la etiqueta y la columna
	string cadMayorMarca;												//Cadena para almacenar la conversión de la mayor marca

	//Recorre la lista de datos demográficos auxiliar secuencialmente de inicio a fin
	lDatDemograficos->moverInicio();
	while (!lDatDemograficos->finLista()){
		lDatDemograficos->consultar(dD);
		lDatDemograficos->avanzar();
		dD->alg4(lAnioNac);
	}

	//Muestra la lista con los resultados del algoritmo una vez completado
	lAnioNac->moverInicio();
	for (int i=0; !lAnioNac->finLista(); i++) {							//Recorre secuencialmente la lista de años de nacimiento de inicio a fin. Se utiliza el índice 'i' para calcular los límites del intervalo a mostrar
		lAnioNac->consultar(anNacAux);
		if(i*RANGO_EDAD_ALG_4 == anNacAux->getAnio()){ 					//Comprueba si el intervalo del dato de la lista 'lAnioNac' coincide con el siguiente intervalo a mostrar
			nPersonas = anNacAux->getNPersonas();
			lAnioNac->avanzar();										//SOLO se avanza la lista si el intervalo actual coincide con el intervalo a mostrar. Sino hay que esperar a que coincidan para seguir
			if(anNacAux->getAnio() > mayorMarca) 			            //Actualiza la mayor marca de clase
				mayorMarca = (anNacAux->getAnio());
			if(anNacAux->getNPersonas() > modaNPersonas)				//Actualiza la moda
				modaNPersonas = anNacAux->getNPersonas();
		}else{															//Sino avanza las iteraciones necesarias hasta que alcanza el intervalo correspondiente a dicho dato y se muestran 0 personas
			nPersonas = 0;
		}
		cout << i*RANGO_EDAD_ALG_4 << " a " << (i+1)*RANGO_EDAD_ALG_4 - 1 << " - " << nPersonas << " persona(s)" << endl;	//Muestra el resultado del intervalo i-ésimo con amplitud RANGO_EDAD_ALG_4
	}
	nPersPorDiv = modaNPersonas % 275;									//Crea divisiones de tamaño dependiente de la muestra. SOLO es válida para muestras con una varianza pequeña
	cadMayorMarca = int_to_string(mayorMarca);							//Convierte la mayor marca a cadena para contar sus dígitos como caracteres

	//Muestra la representación gráfica de los intervalos obtenidos
	cout << endl <<"REPRESENTACIÓN GRÁFICA - APROXIMACIÓN A UN HISTOGRAMA DE FRECUENCIAS\t" << "· = " << nPersPorDiv << " personas (aprox.)" << endl << endl;
	lAnioNac->moverInicio();
	for (int i=0; !lAnioNac->finLista(); i++) {							//Recorre secuencialmente la lista de años de nacimiento de inicio a fin. Se utiliza el índice 'i' para calcular los límites del intervalo a mostrar
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
			cadSep.erase(cadSep.length()-1, 1);
		cout << "(" << i*RANGO_EDAD_ALG_4 << " , " << (i+1)*RANGO_EDAD_ALG_4 - 1 << ")  " << cadSep << "|"  << cadDivisiones << endl;

		cadSep.clear();													//Bora la cadena se separación entre etiqueta y columna para el siguiente intervalo
		cadDivisiones.clear();											//Borra la columna para el siguiente intervalo
	}

	//Libera la memoria asociada a los nuevos años de nacimiento creados por el algoritmo 4
	lAnioNac->moverInicio();
	while (!lAnioNac->finLista()){										//Recorre secuencialmente la lista de lugares de nacimiento de inicio a fin
		lAnioNac->consultar(anNacAux);
		lAnioNac->avanzar();
		delete anNacAux;												//Libera cada año de nacimiento de la lista
	}
	delete lAnioNac;													//Libera la lista
}

void Padron::alg5() {													///@NOTA: Nombre provisional
	ListaPI<Nacionalidad*>* lNacion = new ListaPI<Nacionalidad*>();/* Lista en la que se almacenan los resultados del algoritmo. Cada nacionalidad con el numero total de habitantes es representada por un objeto 'Nacionalidad'
																		  *	El nombre de la nacionalidad se almacena en el atributo 'nacionalidad' y el número de personas en 'nPersonas' */
 	DatosDemograficos* dD;												//Puntero auxiliar para consultar cada dato demográfico de la lista de datos demográficos auxiliar
	Nacionalidad* nacionAux;											//Puntero auxiliar para consultar la lista local 'lNacion'

	//Recorre la lista de datos demográficos auxiliar secuencialmente de inicio a fin
	lDatDemograficos->moverInicio();
	while(!lDatDemograficos->finLista()){
		lDatDemograficos->consultar(dD);
		lDatDemograficos->avanzar();
		dD->alg5(lNacion);
	}

	//Muestra la lista con los resultados del algoritmo una vez completado
	lNacion->moverInicio();
	while(!lNacion->finLista()){									//Recorre secuencialmente la lista de nacionalidades de inicio a fin
		lNacion->consultar(nacionAux);
		lNacion->avanzar();
		cout << nacionAux->getNacionalidad() << " (" << nacionAux->getNPersonas() << ")" << endl;
	}

	//Libera la memoria asociada a las nuevas nacionalidades creadas por el algoritmo 5
	lNacion->moverInicio();
	while(!lNacion->finLista()){									//Recorre secuencialmente la lista de lugares de nacimiento de inicio a fin
		lNacion->consultar(nacionAux);
		lNacion->avanzar();
		delete nacionAux;												//Libera cada nacionalidad de la lista
	}
	delete lNacion;												//Libera la lista
}

void Padron::alg6() {													///@NOTA: Nombre provisional
	ListaPI<LugarNacimiento*>* lLugNac = new ListaPI<LugarNacimiento*>();/* Lista en la que se almacenan los resultados del algoritmo. Cada provincia con el numero total de habitantes es representada por un objeto 'LugarNacimiento'
																		  *	El nombre de la provincia se almacena en el atributo 'provinciaPais' y el número de habitantes en 'nPersonas' */
 	DatosDemograficos* dD;												//Puntero auxiliar para consultar cada dato demográfico de la lista de datos demográficos auxiliar
	LugarNacimiento* lugNacAux;											//Puntero auxiliar para consultar la lista local 'lLugNac'

	//Recorre la lista de datos demográficos auxiliar secuencialmente de inicio a fin
	lDatDemograficos->moverInicio();
	while(!lDatDemograficos->finLista()){
		lDatDemograficos->consultar(dD);
		lDatDemograficos->avanzar();
		dD->alg6(lLugNac);
	}

	//Muestra la lista con los resultados del algoritmo una vez completado
	lLugNac->moverInicio();
	while(!lLugNac->finLista()){										//Recorre secuencialmente la lista de lugares de nacimiento de inicio a fin
		lLugNac->consultar(lugNacAux);
		lLugNac->avanzar();
		cout << lugNacAux->getProvinciaPais() << " (" << lugNacAux->getNPersonas() << ")" << endl;
	}

	//Libera la memoria asociada a los nuevos lugares de nacimiento creados por el algoritmo 6
	lLugNac->moverInicio();
	while(!lLugNac->finLista()){										//Recorre secuencialmente la lista de lugares de nacimiento de inicio a fin
		lLugNac->consultar(lugNacAux);
		lLugNac->avanzar();
		delete lugNacAux;												//Libera cada lugar de nacimiento de la lista
	}
	delete lLugNac;														//Libera la lista
}

void Padron::mostrarEstructura() {										///@TEST: Muestra toda la estructura de datos cargada y las estructuras auxiliares
	Via* vAux;															//Puntero auxiliar para mostrar las vías almacenadas en la lista auxiliar de vías 'lVias'
	DatosDemograficos* dD;												//Puntero auxiliar para mostrar los datos demográficos en la lista auxiliar de datos demográficos 'lDatDemograficos'

	gBarrio->mostrar();													///@TEST: Muestra toda la estructura de datos cargada

	cout << "LISTA DE VÍAS AUXILIAR" << endl;							///@TEST: Muestra la lista auxiliar de todas las vías
	cout << "***********************************************************************************************" << endl;
	lVias->moverInicio();
	while(!lVias->finLista()){
		lVias->consultar(vAux);
		lVias->avanzar();
		cout << "Via : " << vAux->getNombreVia() << " | Barrio : " << vAux->getBarrioVia() << " | Longitud : " <<
					vAux->getLongitudVia() << " | (m) Tipo : " << vAux->getTipoVia() << " | Codigo : " << vAux->getCodVia() << endl;	///@NOTA: No muestra los datos demográficos
	}
	cout << "***********************************************************************************************" << endl;

	cout << "LISTA DE DATOS DEMOGRÁFICOS AUXILIAR" << endl << endl;		///@TEST: Muestra la lista auxiliar de todos los datos demograficos auxiliares
	cout << "***********************************************************************************************" << endl;
	lDatDemograficos->moverInicio();
	while(!lDatDemograficos->finLista()){
		lDatDemograficos->consultar(dD);
		lDatDemograficos->avanzar();
		dD->mostrar();
	}
	cout << "***********************************************************************************************" << endl;
}

}
