#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

struct audiencia {
	char tipoFiesta[20] ;
	int edad ;
	bool joven = true ;
	bool tango = false ;
};

void ingresoPersona (audiencia &persona) ;
void ingresoEdad (audiencia &persona) ;
void displayJovenTango (audiencia persona) ;
void sumaContadores (audiencia persona , int &jovenes , int &jovenesOtros , int &cantidadTango , int &cantidadOtros) ;
void displayPorcentaje (int jovenes , int jovenesOtros , float &porcentajeJovenesOtros) ;
void displayMayorEspectaculo (int cantidadTango , int cantidadOtros) ;

int main () {
	audiencia persona ;
	int jovenes = 0 , jovenesOtros = 0 , cantidadTango = 0 , cantidadOtros = 0 ;
	float porcentajeJovenesOtros ; 
	 
	ingresoPersona(persona) ;
	while (persona.tipoFiesta[0] != '*') {
		ingresoEdad(persona) ;
		displayJovenTango(persona) ;
		sumaContadores(persona , jovenes , jovenesOtros , cantidadTango , cantidadOtros) ;
		
		persona.joven = true ;
		persona.tango = false ;
		ingresoPersona(persona) ;
	}
	displayPorcentaje (jovenes , jovenesOtros , porcentajeJovenesOtros) ;
	displayMayorEspectaculo(cantidadTango , cantidadOtros) ;
		
	return 0 ;
}

// ingreso del tipo de fiesta y determinacion de si la fiesta es tango u otros
void ingresoPersona (audiencia &persona) {
	fflush(stdin);
	cout << "Ingrese el tipo de fiesta en mayusculas ('*' para terminar): " ; cin.getline(persona.tipoFiesta , 20) ;
	for (int i = 0 ; i != 20 ; i++) {
		if (persona.tipoFiesta[i] == 'T' && persona.tipoFiesta[i+1] == 'G') {
			persona.tango = true ;
		}
	}
}

// ingreso de la edad de la persona y determinacion de si es mayor o menor
void ingresoEdad (audiencia &persona) {
	do {
		cout << "Ingrese la edad de la persona (entre 16 y 51): " ; cin >> persona.edad ;
	} while (persona.edad < 17 || persona.edad > 50) ;
	if (persona.edad > 30) {
		persona.joven = false ;
	}
}

// muestra la edad y un cartel que dice "TANGO" cuando la persona es joven y asiste a un tango
void displayJovenTango (audiencia persona) {
	if (persona.joven == true && persona.tango == true) {
		cout << "Edad de la persona: " << persona.edad << endl << "TANGO" << endl ;
	}
}

// suma a los contadores que cumplan con las condiciones
void sumaContadores (audiencia persona , int &jovenes , int &jovenesOtros , int &cantidadTango , int &cantidadOtros) {
	if (persona.joven == true) {
		jovenes++ ;
	}
	if (persona.joven == true && persona.tango == false) {
		jovenesOtros++ ;
	}
	if (persona.tango == true) {
		cantidadTango++ ;
	}
	else {
		cantidadOtros++ ;
	}
}

// calcula el porcentaje de jovenes que fueron a otros espectaculos entre los jovenes y lo muestra
void displayPorcentaje (int jovenes , int jovenesOtros , float &porcentajeJovenesOtros) {
	porcentajeJovenesOtros = (jovenesOtros * 100)/ jovenes ;
	cout << "El porcentaje de jovenes que fueron a otros espectaculos sobre el total de jovenes es de: " << porcentajeJovenesOtros << endl ;
}

// informa que espectaculo tuvo mayor audiencia o si tuvieron igual cantidad de audiencia
void displayMayorEspectaculo (int cantidadTango , int cantidadOtros) {
	if (cantidadTango > cantidadOtros) {
		cout << "El espectaculo que mayor audiencia tuvo es el tango." ;
	}
	else if (cantidadTango < cantidadOtros) {
		cout << "Los otros espectaculos tuvieron mayor audiencia que el tango." ;
	}
	else {
		cout << "Los otros espectaculos tuvieron la misma cantidad de audiencia que el tango." ;
	}
}
