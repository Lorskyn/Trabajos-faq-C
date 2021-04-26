#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

void ingresos (char cad[] , char &letra) ;
void buscador (char cad[] , char letra , int &n) ;

int main () {
	int n = 0 ;
	char cad[100] , letra ;
	
	ingresos (cad , letra) ;
	buscador (cad , letra , n) ;
	return 0 ;
}

// ingresa la cadena y la letra a buscar
void ingresos (char cad[] , char &letra) {
	cout << "Ingrese una oracion de menos de 100 caracteres: " ; cin.getline(cad , 100) ;
	cout << "Ingrese una letra: " ; letra = getchar() ;
}

// busca la letra dada y da la cantidad de veces que aparecio
void buscador (char cad[] , char letra , int &n) {
	for (int i = 0 ; cad[i] != '\0' ; i++) {
		if (cad[i] == letra){
			cout << "Se encontro la letra en la posicion " << i+1 << endl ;
			n++ ;
		}
	}
	cout << "El total de veces que esta la letra en la oracion es " << n ;
}
