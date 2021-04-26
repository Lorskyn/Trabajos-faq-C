#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

void inputFiesta (string &fecha , char &tipo , int &cantP , int &menu) ;
void seguir (bool &pregunta) ;
void displayInput (string fecha , char tipo , int cant , int menu) ;
void sumaTipoFiesta (char tipo , int &fiestaC , int &fiestaS , int &fiestaO) ;
void cantPersonasMenu (string fecha , string &fechaMenu1 , string &fechaMenu2 , int menu , int &cantPM1 , int &cantPM2 , int cantP) ;
void calcPromedio (int suma , int cantFiestas , float &promPersonas) ;
void displayFinal (int fiestaC , int fiestaS , int fiestaO , string fechaMenu1 , string fechaMenu2 , float promPersonas) ;




int main () {
	char tipo ;
	string fecha , fechaMenu1 , fechaMenu2 ;
	int cantP , menu , fiestaC = 0 , fiestaS = 0 , fiestaO = 0 , cantPM1 = 0 , cantPM2 = 0 , suma = 0 , cantFiestas = 0 ;
	bool pregunta ;
	float promPersonas ;
	
	do {
		inputFiesta (fecha , tipo , cantP , menu) ;
		displayInput (fecha , tipo , cantP , menu) ;
		sumaTipoFiesta (tipo , fiestaC , fiestaS , fiestaO ) ;
		cantPersonasMenu (fecha , fechaMenu1 , fechaMenu2 , menu , cantPM1 , cantPM2 , cantP) ;
		cantFiestas++ ;
		seguir (pregunta) ;
	} while (pregunta == true) ;
	calcPromedio (suma , cantFiestas , promPersonas) ;
	displayFinal (fiestaC , fiestaS , fiestaO , fechaMenu1 , fechaMenu2 , promPersonas) ;
	
	return 0 ;
}

// toma los ingresos
void inputFiesta (string &fecha , char &tipo , int &cantP , int &menu) {
	cout << "Ingrese la fecha de la fiesta: " ; cin >> fecha ;
	cout << "Ingrese el tipo de fiesta (C , S , O): " ; cin >> tipo ;
	cout << "Ingrese la cantidad de personas: " ; cin >> cantP ;
	cout << "Ingrese el menu(1 o 2): " ; cin >> menu ;
}

// calcula cuantas fiestas hay de cada tipo
void sumaTipoFiesta (char tipo , int &fiestaC , int &fiestaS , int &fiestaO) {
	switch (tipo) {
		case 'C' :
			fiestaC++ ;
			break ;
		case 'S' :
			fiestaS++ ;
			break ;
		case 'O' :
			fiestaO++ ;
			break ;
		}
}

// muestra los ingresos
void displayInput (string fecha , char tipo , int cantP , int menu) {
	cout << "Fecha: " << fecha << endl
	<< "Tipo de fiesta: " << tipo << endl
	<< "Cantidad de personas: " << cantP << endl
	<< "Menu elegido: " << menu << endl ;
}

// pregunta si sigue el ciclo
void seguir (bool &pregunta) {
	char aux ;
	
	cout << "Desea continuar? (S o N): " ; cin >> aux ;
	if (aux == 'S') {
		pregunta = true ;
	}
	else {
		pregunta = false ;
	}
}

// calcula si la fiesta con el menu elegido tiene mas personas que el mayor anterior
void cantPersonasMenu (string fecha , string &fechaMenu1 , string &fechaMenu2 , int menu , int &cantPM1 , int &cantPM2 , int cantP) {
	switch (menu) {
		case 1 :
			if (cantP >= cantPM1){
				cantPM1 = cantP ;
				fechaMenu1 = fecha ;
			}
		case 2 :
			if (cantP >= cantPM2) {
				cantPM2 = cantP ;
				fechaMenu2 = fecha ;
			}
	}
}

// calcula el promedio de personas
void calcPromedio (int suma , int cantFiestas , float &promPersonas) {
	promPersonas = suma / cantFiestas ;
}

// muestra los datos finales
void displayFinal (int fiestaC , int fiestaS , int fiestaO , string fechaMenu1 , string fechaMenu2 , float promPersonas) {
	cout << "Cantidad de fiestas: " << endl 
	<< "C: " << fiestaC << endl
	<< "S: " << fiestaS << endl
	<< "O: " << fiestaO << endl 
	<< "Fecha de menues con mas gente: " << endl
	<< "Menu 1: " << fechaMenu1 << endl
	<< "Menu 2: " << fechaMenu2 << endl 
	<< "Promedio de personas: " << promPersonas ;
}














































