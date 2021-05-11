#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int operador () ;
void display (int respuesta) ;

int main () {
	int respuesta ;
	
	respuesta = operador() ;
	display (respuesta) ;
	
	return 0 ;
}

int operador () {
	char letra1 , letra2 , cad[51] ;
	cout << "Ingrese una cadena: " ; cin.getline(cad , 50) ;
	cout << "Ingrese la letra 1: " ; cin >> letra1 ;
	cout << "Ingrese la letra 2: " ; cin >> letra2 ;
	
	for (int i = 0 ; i != strlen(cad) ; i++) {
		if (cad[i] == letra1 || cad[i] == letra2) {
			cout << "La posicion donde se encontro la primera de alguna de las letras ingresada fue: " << i  << endl ; // va a devolver la posicion segun la cadena, si quisiera la posicion segun el lector hay que sumarle 1. no me quedo claro en la consigna cual de las 2 posiciones buscaban pero para arreglarlo simplemente tendria que poner i+1
			return 0 ;
		}
	}
	
	return -1 ;
}

void display (int respuesta) {
	if (respuesta == -1) {
		cout << "NO ESTAN" ;
	}
	else {
		cout << "AL MENOS UNO" ;
	}
}



