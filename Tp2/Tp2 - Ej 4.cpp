#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

void ingreso (char cad[] , int size) ;
void operador (char cad[] , int qLetras , int &qPalabras) ;
void resultados (char cad[] , int qPalabras) ;

int main () {
	char cad[200];
	int qLetras = -1 , qPalabras = 0 , longitud , size = sizeof(cad) ;
	
	ingreso (cad , size) ;
	operador (cad , qLetras , qPalabras) ;
	//cout << endl << "cantidad palabras: " << qPalabras ;
	resultados (cad , qPalabras) ;
	
	
	return 0 ;
}

// ingresa la oracion y chequea el limite de la cadena
void ingreso (char cad[] , int size) {
	cout << "La longitud de la cadena es de " << size << " caracteres." << endl
	<< "Ingresar una oracion con menos caracteres que esa cantidad: " ; cin.getline(cad , 200) ;
}

// cuenta palabras, letras por palabra y escribe las palabras que componen el parrafo
void operador (char cad[] , int qLetras , int &qPalabras) {
	cout << "entro" << endl ;
	for (int i = 0 ; i != strlen(cad)+1 ; i++) {
		// controla que el caracter no sea un simbolo para poder escribir las palabras
		if (cad[i] != '.' && cad[i] != ',' && cad[i] != ';' && cad[i] != ':' && cad[i] != '!' && cad[i] != '?') {
			cout << cad[i] ;
			qLetras++ ;
			// controla los ' ' y el '\0' para saber cuando terminan las palabras, las suma y dice cuantas letras tenia cada una
			if (cad[i] == ' ' || cad[i] == '\0') {
				cout << endl ;
				qPalabras++ ;
				cout << "Cantidad de letras en la palabra: " << qLetras << endl ;
				qLetras = -1 ;
			}
		}
	}
}

// muestra la cantidad de palabras y la longitud del parrafo ingresado
void resultados (char cad[] , int qPalabras) {
	cout << "Cantidad de palabras: " << qPalabras << endl
	<< "Longitud total del parrafo: " << strlen(cad) ;
}
