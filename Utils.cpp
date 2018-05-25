/**
 * @brief
 * 		Implementación de las utilidades de cadenas
 */

#include "Utils.h"

vector<string> splitStringToVector(string text, char delim) {

	vector<string> tokens;

	std::string::size_type beg_index, end_index;
	beg_index = text.find_first_not_of(delim);

	while (beg_index != std::string::npos) {
		end_index = text.find_first_of(delim, beg_index);
		if (end_index == std::string::npos)
			end_index = text.length();

		tokens.push_back(text.substr(beg_index, end_index - beg_index));

		beg_index = text.find_first_not_of(delim, end_index);
	}

	return tokens;
}

vector<string> splitString(string text) {

	std::string::size_type pos = text.find('(');

	while (pos != std::string::npos) {
		text.replace(pos - 1, 2, ";");
		pos = text.find('(');
	}

	pos = text.find(')');
	while (pos != std::string::npos) {
		text.erase(pos, 1);
		pos = text.find(')');
	}

	vector<string> vText = splitStringToVector(text, DELIM);


	return vText;

}

std::string int_to_string(int n) {
	ostringstream sStream;				//Flujo de salida de cadenas
	std::string str;					//Cadena con la conversión

	sStream << n;						//Conversión de entero a cadena
	return sStream.str();
}
