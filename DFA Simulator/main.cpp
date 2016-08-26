#include <cstdio>
#include <iostream>

using namespace std;

#include "DFA.h"

int main(void)
{
	char archivo[100];
	int error=0;
	int bucle=1;
	char opcion;
	char cadena[80];
	
	cout << "Computabilidad y Algoritmia. Simulacion de un DFA." << endl;
	cout << "Alexis Daniel Fuentes Pérez." << endl;
	cout << "Introduzca el nombre del fichero .dfa a cargar: ";
	cin >> archivo;
	
	DFA A(archivo, error);
	
	if(error != 1){
		while(bucle==1){
			cout << endl;
			cout << "[0] Leer DFA." << endl;
			cout << "[1] Mostrar DFA." << endl;
			cout << "[2] Identificar estados de muerte." << endl;
			cout << "[3] Analizar cadena." << endl;
			cout << "[4] Finalizar el programa." << endl;
			cout << "Introduzca el numero de la opcion a realizar: ";
			cin >> opcion;
			cout << endl;
			
			switch(opcion){
				case '0': cout << "Introduzca el nombre del fichero .dfa a cargar: ";
						cin >> archivo; 
						A.~DFA();
						A.leer(archivo, error); break;
				case '1': A.mostrar(); break;
				case '2': A.estadosmuerte(); break;
				case '3': cout << "Introduzca una cadena: ";
						  cin >> cadena;
						  A.analizar(cadena); break;
				case '4': bucle=0; break;
				default: cout << "No ha introducido ninguna opcion valida." << endl;
			}
			
			if(error == 1)
				bucle=0;
		}
	}
}
