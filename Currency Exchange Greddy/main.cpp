#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int seleccion(int suma, int cantidad, int M_[], int &icandidato){
	for(int i=icandidato; i<15; i++){
		if(suma + M_[i] <= cantidad){
			icandidato=i;
			return M_[i];
		}
	}
	return 0;
}

vector<int> devolver_cambio(int cantidad){
	int M_[15] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
	vector<int> C_;
	int suma = 0;
	int aux = 0;
	int icandidato=0;
	
	while(suma != cantidad){
		aux = seleccion(suma, cantidad, M_, icandidato);
		if(aux != 0){
			C_.push_back(aux);
			suma += aux;
		}
		else{
			C_.clear();
			return C_;
		}
	}
	return C_;
}

int main(void)
{
	vector<int> S_; 
	float cantidad;
	int acumulado=1;
	int billetes=0;
	int monedas=0;
	
	cout << "Computabilidad y Algoritmia. Practica 12. Cambio de monedas (Greedy)" << endl;
	cout << "Alexis Daniel Fuentes Perez" << endl;
	
	cout << endl;
		
	cout << "Introduzca la cantidad a cambiar: ";
	cin >> cantidad;
	
	cantidad *= 100; 
	cantidad = (int)cantidad;
	
	S_ = devolver_cambio(cantidad);
	
	if(S_.size() != 0){
		cout << "Solucion: ";
		for(int i=0; i<S_.size(); i++){
			if(S_[i] == S_[i+1])
				acumulado++;
			else{
				if(S_[i] >= 100){
					cout << acumulado << "x" << S_[i]/100 << "euro ";
					acumulado=1;
				}
				else{
					cout << acumulado << "x" << S_[i] << "c ";
					acumulado=1;
				}
			}
		}
		
		cout << endl;
		
		for(int i=0; i<S_.size(); i++){
			if(S_[i] > 200)
				billetes++;
			else
				monedas++;
		}
		
		cout << "Numero de billetes: " << billetes << endl;
		cout << "Numero de monedas: " << monedas << endl;
	}
	
	else{
		cout << "No hay solucion." << endl;
	}
}