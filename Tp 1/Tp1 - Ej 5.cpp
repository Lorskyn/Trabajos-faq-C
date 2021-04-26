#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int ingresoNumeros (int N1) ;
void output (float mayorProm , int suma) ;
void operador () ;

int main () {
	operador () ;

	return 0 ;
}

// display de promedio y suma total
void output (float mayorProm , int suma) {
	cout << "El promedio mas grande es: " << mayorProm << endl ;
	cout << "La suma total es: " << suma ;
}

// operador de variables
void operador () {
	int N , aux = 0 , N1 , aux2 = 0 , n , suma = 0 ;
	float prom = 0 , sumaProm = 0 , mayorProm = 0 ;
	
	cout << "Ingrese la cantidad de juegos: " ; cin >> N ;
	while (aux < N) {
		cout << "Ingrese la cantidad de numeros en este juego: " ; cin >> N1 ;
		while (aux2 < N1) {
			cout << "Ingrese un numero: " ; cin >> n ;
			suma+= n ;
			sumaProm+= n ;
			aux2++ ;
		}
		prom = sumaProm / N1 ;
		if (prom > mayorProm) {
			mayorProm = prom ;
		}
		aux++ ;
		aux2 = 0 ;
		sumaProm = 0 ; 
	}
	output (mayorProm , suma) ;
}
