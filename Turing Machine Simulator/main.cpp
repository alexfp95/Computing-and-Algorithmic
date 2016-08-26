#include <cstdio>
#include <iostream>

using namespace std;

#include "TM.h"

int main (void){
	char archivo[80];
	int error=0;
	int bucle=1;
	int opcion;
	char cadena[80];
	
	cout << "Computabilidad y Algoritmia. Simulacion de una Maquina de Turing." << endl;
	cout << "Alexis Daniel Fuentes Perez." << endl;
	cout << endl;
	cout << "Introduzca el nombre del fichero .TM a cargar: ";
	cin >> archivo;
	
	TM A(archivo, error);
	
	if(error != 1){
		while(bucle==1){
			cout << endl;
			cout << "[0] Leer maquina de Turing." << endl;
			cout << "[1] Mostrar maquina de Turing." << endl;
			cout << "[2] Simular maquina de Turing." << endl;
			cout << "[3] Salir." << endl;
			cout << endl;
			cout << "Introducir el numero de la opcion a realizar: ";
			cin >> opcion;
			cout << endl;
			
			switch(opcion){
				case 0: cout << "Introduzca el nombre del fichero .TM a cargar: ";
						  cin >> archivo;
						  A.~TM();
						  A.leer(archivo, error); break;
				case 1: A.mostrar(); break;
				case 2: cout << "Introduzca una cadena: ";
						  cin >> cadena;
						  A.simular(cadena); break;
				case 3: bucle = 0; break;
				default: cout << "No ha introducido ninguna opcion valida." << endl;
			}
			
			if(error == 1)
				bucle = 0;
		}
	}
}