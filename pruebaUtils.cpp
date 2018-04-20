//============================================================================
// Name        : pruebaUtils.h
// Author      : profesores de la asignatura EDI
// Version     : curso 17/18
// Copyright   :
// Description : Pruebas para trocear cadenas
//============================================================================
#include "Utils.h"
#include "timer.h"

//@TEST includes para testeo
#include "Padron.h"

// EJEMPLO DE USO DE LA LIBRERIA UTILS PARA TROCEAR UNA CADENA
void pruebaTrocearCadenaAnioNacimiento(string text){
    char delim = ';';
	vector<string> vText = splitStringToVector(text, delim);
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);
		cout << "Año: "<< vString[0]<< "  nº personas: "<< atoi(vString[1].c_str())<<endl;
	}
}
void pruebaTrocearCadenaLugarNacimiento(string text){
    char delim = ';';
	vector<string> vText = splitStringToVector(text, delim);
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);
		if ( vString.size()== 2)
			cout << "Poblacion: "<< " "<< " Provincia : "<< vString[0]<<"  nº personas: "<< atoi(vString[1].c_str())<<endl;
		else
			cout << "Poblacion: "<< vString[0]<< " Provincia : "<< vString[1]<<"  nº personas: "<< atoi(vString[2].c_str())<<endl;
	}
}

void pruebaTrocearCadenaEstudios(string text){
    char delim = ';';
	vector<string> vText = splitStringToVector(text, delim);
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);
		cout << "Estudios: "<< vString[0]<< "  nº personas: "<< atoi(vString[1].c_str())<<endl;
	}
}

void pruebaTrocearCadenaNacionalidad(string text){
    char delim = ';';
	vector<string> vText = splitStringToVector(text, delim);
	for (int i = 0; i < static_cast<int>(vText.size()); i++) {
		vector<string> vString = splitString(vText[i]);
		cout << "Pais: "<< vString[0]<< "  nº personas: "<< atoi(vString[1].c_str())<<endl;
	}
}

void pruebaTrocearCadenas(){
	string cadena = "1947 (1);1948 (1);1949 (1);1950 (1);1951 (2);1952 (3);1953 (2);1954 (1);1955 (3);1958 (3);1959 (3);1960 (3);1961 (7);1962 (5);1963 (3);1964 (5);1965 (2);1966 (2);1967 (3);1968 (2);1969 (2);1970 (1);1971 (3);1972 (2);1981 (1);1982 (1);1983 (2);1984 (1);1985 (2);1987 (1);1988 (5);1989 (2);1990 (2);1991 (1);1992 (3);1993 (6);1994 (2);1995 (7);1996 (2);1997 (1);1998 (4);1999 (4);2000 (1);2001 (1);2003 (4);2004 (1);2008 (1)";
	pruebaTrocearCadenaAnioNacimiento(cadena);

	cadena = "Albala Del Caudillo (Caceres) (1);Alemania (3);Almendralejo (Badajoz) (1);Badajoz (Badajoz) (1);Caceres (Caceres) (72);Casar De Caceres (Caceres) (1);Castejon De Alarba (Zaragoza) (1);Coria (Caceres) (2);Don Benito (Badajoz) (1);Estados Unidos De America (2);La Nava (Huelva) (1);Las Palmas De Gran Canaria (Las Palmas) (1);Madrid (Madrid) (4);Malaga (Malaga) (1);Merida (Badajoz) (1);Motril (Granada) (1);Navas Del Madroño (Caceres) (1);No Especificado (1);Olot (Girona) (1);Oviedo (Asturias) (1);Pescueza (Caceres) (1);Plasencia (Caceres) (1);Ponferrada (Leon) (1);Rosal De La Frontera (Huelva) (3);San Vicente De La Sonsierra (La Rioja) (1);Serradilla (Caceres) (3);Talavera De La Reina (Toledo) (1);Torre De Santa Maria (Caceres) (1);Torrejon De Ardoz (Madrid) (1);Trujillo (Caceres) (2);Valdefuentes (Caceres) (2);Zamora (Zamora) (1)";
	pruebaTrocearCadenaLugarNacimiento(cadena);


	cadena = "Arquitecto O Ingeniero Tecnico (2);Bachiller Superior, Bup (23);Graduado Escolar O Equivalente (6);No Aplicable Por Ser Menor De 10 Años (10);No Sabe Leer Ni Escribir (2);Titulacion Inferior Al Grado De Escolaridad (2);Doctorado Y Estudios De Postgrado O Especializacion Para Licenciados (6);Formacion Profesional Segundo Grado, Maestria Industrial (2);Formacion Profesional Primer Grado, Oficialia Industrial (6);Bachiller, Formacion Profesional Segundo Grado, Titulos Equivalentes O Superiores (18);Diplomado Escuelas Universitarias (Empresariales, Profesorado Egb, Ats Y Similares) (7);Bachiller Elemental, Graduado Escolar, Egb/Primaria Completa, Certificado Escolaridad O Equivalente (13);Licenciado Universitario, Arquitecto O Ingeniero Superior (19)";
	pruebaTrocearCadenaEstudios(cadena);

	cadena = "España (115);Filipinas (1)";
	pruebaTrocearCadenaNacionalidad(cadena);
}

int main(){					//@TEST: main de pruebas
	Padron p;
	double tStart, tEnd;

	//pruebaTrocearCadenas();

	//@TEST: Carga de datos
	tStart = Time::getTime();
	p.cargarBarrios();
	p.cargarVias();
	p.cargarDatosDemograficos();
	tEnd = Time::getTime();
	cout << "Tiempo de carga de datos : " << tEnd-tStart << " seg."<< endl;

	//@TEST: Algoritmo 6
//	tStart = Time::getTime();
//	p.alg6();
//	tEnd = Time::getTime();
//	cout << "Tiempo alg6 : " << tEnd-tStart << " seg."<< endl;

	//@TEST: Algoritmo 2
	tStart = Time::getTime();
	p.alg2("Moctezuma");
	tEnd = Time::getTime();
	cout << "Tiempo alg2 : " << tEnd-tStart << " seg."<< endl;
}
