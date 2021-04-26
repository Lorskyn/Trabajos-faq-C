#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

void longitudes (char cad1[] , char cad2[]) ;

int main () {
	char cad1[41] , cad2[41] = "universidad nacional de avellaneda" ;
	
	strcpy(cad1 , cad2) ;
	longitudes (cad1 , cad2) ;
	return 0 ;
}

// da la cantidad de caracteres de ambas cadenas
void longitudes (char cad1[] , char cad2[]) {
	cout << "La longitud de la cad1 es: " << strlen(cad1) << endl ;
	cout << "La longitud de la cad2 es: " << strlen(cad2) ;
}

