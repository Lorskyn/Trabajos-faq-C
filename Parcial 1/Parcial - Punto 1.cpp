#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

struct tyPedido {
	string menu ;
	char tipo ;
	float precio ;
	int cantidad ;
};

string ingresoMenu (tyPedido pedido) ;
char ingresoTipo (tyPedido pedido) ;
float ingresoPrecio (tyPedido pedido) ;
void ingresoCantidad (tyPedido &pedido) ;
void displayDePedido (tyPedido pedido) ;
void operadorGuiso (tyPedido pedido , float &guisosMayor) ;
void operadorTipos (tyPedido pedido , int &cantC , int &cantP , int &cantG) ;
void operadorCarne (tyPedido pedido , float &sumaC , int &cantidadC) ;
void displayFinal (float guisosMayor , int cantC , int cantP , int cantG , float sumaC , int cantidadC) ;

int main () {
	tyPedido pedido ;
	float guisosMayor = 0 , sumaC = 0;
	int cantC = 0 , cantP = 0 , cantG = 0 , cantidadC = 0 ;
	
	pedido.menu = ingresoMenu (pedido) ;
	while (pedido.menu != "FIN") {
		pedido.tipo = ingresoTipo (pedido) ;
		pedido.precio = ingresoPrecio (pedido) ;
		ingresoCantidad (pedido) ;
		displayDePedido (pedido) ;
		operadorGuiso (pedido , guisosMayor) ;
		operadorTipos (pedido , cantC , cantP , cantG) ;
		operadorCarne (pedido , sumaC , cantidadC) ;
		pedido.menu = ingresoMenu (pedido) ;
	}
	
	cout << "Fin de operacion." << endl ;
	displayFinal(guisosMayor , cantC , cantP , cantG , sumaC , cantidadC) ;
	
	return 0 ;
}

// ingresa la descripcion del menu y valida
string ingresoMenu (tyPedido pedido) {
	cout << "Ingrese una descripcion del menu ('FIN' para terminar): " ; cin >> pedido.menu ;
	
	return pedido.menu ;
}

// ingresa el tipo de menu y valida
char ingresoTipo (tyPedido pedido) {
	cout << "Ingrese el tipo de menu ('C' carnes, 'P' pastas o 'G' guisos): " ; cin >> pedido.tipo ;
	while (pedido.tipo != 'C' && pedido.tipo != 'c' && pedido.tipo != 'P' && pedido.tipo != 'p' && pedido.tipo != 'G' && pedido.tipo != 'g') {
		cout << "Tipo de menu no valido." << endl
		<< "Ingrese el tipo de menu ('C' carnes, 'P' pastas o 'G' guisos): " ; cin >> pedido.tipo ;
	}
	
	return pedido.tipo ;
}

// ingresa el precio y valida
float ingresoPrecio (tyPedido pedido) {
	cout << "Ingrese el precio del producto: " ; cin >> pedido.precio ;
	while (pedido.precio < 0) {
		cout << "Precio no valido." << endl
		<< "Ingrese el precio del producto: " ; cin >> pedido.precio ;
	}
	
	return pedido.precio ;
}

// ingresa la cantidad y valida
void ingresoCantidad (tyPedido &pedido) {
	cout << "Ingrese la cantidad ordenada: " ; cin >> pedido.cantidad ;
	while (pedido.cantidad < 0) {
		cout << "Cantidad no valida." << endl
		<< "Ingrese la cantidad ordenada: " ; cin >> pedido.cantidad ;
	}
}

// muestra el struct
void displayDePedido (tyPedido pedido) {
	cout << "Pedido actual:" << endl 
	<< "Menu: " << pedido.menu << endl
	<< "Tipo: " << pedido.tipo << endl
	<< "Precio: " << pedido.precio << endl
	<< "Cantidad: " << pedido.cantidad << endl ;
}

// calcula si el precio del guiso es el mayor hasta ahora
void operadorGuiso (tyPedido pedido , float &guisosMayor) {
	if ((pedido.tipo == 'G' || pedido.tipo == 'g') && pedido.precio > guisosMayor) {
		guisosMayor = pedido.precio ;
	}
}

// suma la cantidad de pedidos del tipo ordenado
void operadorTipos (tyPedido pedido , int &cantC , int &cantP , int &cantG) {
	switch(pedido.tipo) {
		case 'C' :
			cantC+= pedido.cantidad;
			break ;
		case 'c' :
			cantC+= pedido.cantidad;
			break ;
		case 'P' :
			cantP+= pedido.cantidad;
			break ;
		case 'p' :
			cantP+= pedido.cantidad;
			break ;
		case 'G' :
			cantG+= pedido.cantidad;
			break ;
		case 'g' :
			cantG+= pedido.cantidad;
			break ;
	}
}

// saca los numeros necesarios para calcular el promedio del precio de la carne
void operadorCarne (tyPedido pedido , float &sumaC , int &cantidadC) {
	if (pedido.tipo == 'C' || pedido.tipo == 'c') {
		sumaC+= pedido.precio * pedido.cantidad ; 
		cantidadC+= pedido.cantidad ;
	}
}

// muestra las respuestas del punto b y calcula el promedio del precio de carne
void displayFinal (float guisosMayor , int cantC , int cantP , int cantG , float sumaC , int cantidadC) {
	cout << "Respuestas punto b:" << endl
	<< "Precio del mayor guiso: " << guisosMayor << endl
	<< "Cantidad de menues C: " << cantC << endl
	<< "Cantidad de menues P: " << cantP << endl
	<< "Cantidad de menues G: " << cantG << endl
	<< "Promedio de precio de carne vendida: " << sumaC / cantidadC;
}
