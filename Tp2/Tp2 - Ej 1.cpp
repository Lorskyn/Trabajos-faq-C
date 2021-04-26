#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int calculador (char cad[]) ;
void ingreso (char cad[]) ;
void verificador (char cad[] , int q) ;

int main () {
	int q ;
	char cad[50] ;
	
	ingreso (cad) ;
	q = calculador(cad) ;
	verificador (cad , q) ;
	return 0 ;
}

// cuenta la cantidad de caracteres
int calculador (char cad[]) {
	int i = 0 ;
	for (i ; cad[i] != '\0' ; i++) ;
	return i ;
}

// toma el ingreso de la palabra
void ingreso (char cad[]) {
	cout << "Ingrese una palabra u oracion de menos de 50 letras: " ; cin.getline(cad , 50) ;
}

// verifica la longitud de la cadena con strlen
void verificador (char cad[] , int q) {
	cout << "Longitud segun la funcion hecha: " << q << endl ;
	cout << "Longitud segun strlen: " << strlen(cad) ;
}
