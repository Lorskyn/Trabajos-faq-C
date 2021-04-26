#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int ingreso () ;
void output () ;
void operador (int num) ;

int main () {
	int n ;
	
	n = ingreso () ;
	operador (n) ;
	
	return 0 ;
}

// ingreso de variables
int ingreso () {
	int num ;
	
	cout << "Ingresar un numero (-1 para terminar): " ; cin >> num ;
	return num ;
}

// display de interrupciones y cantidad de numeros
void output (int interrupciones , int cantidad) {
	cout << "Cantidad de numeros en serie anterior: " << cantidad << endl 
	<< "Cantidad de interrupciones: " << interrupciones << endl ;
}

// operador de variables
void operador (int num) {
	int aux , interrupciones = 0 , cantidad = 0 ;
	
	num = ingreso () ;
	aux = num-1 ;
	while (num != -1) {
		if (aux >= num) {
			interrupciones++ ;
			output (interrupciones , cantidad) ;
		}
		else {
			cantidad++ ;
		}
		aux = num ;
		num = ingreso() ;
	}
	output (interrupciones , cantidad) ;
	
}

