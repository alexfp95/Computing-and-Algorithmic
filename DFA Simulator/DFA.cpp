#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#include "DFA.h"

DFA::DFA(char nombrefichero[], int &error):
	nQ_(0),
	iQ_(0),
	Q_(NULL),
	alfabeto_(NULL){
		
		ifstream fichero;
		fichero.open(nombrefichero);
		
		if(!fichero.is_open()){
			cout << "Error de apertura." << endl;
			error = 1;
		}
		
		else{
			fichero >> nQ_;
			Q_ = new Estructura [nQ_];
			
			fichero >> iQ_;
			
			int Qactual; int dato; char simbolo; bool existealfa;
			
			for(int i=0; i<nQ_; i++){
				fichero >> Qactual;
				
				fichero >> dato;
				Q_[Qactual].es_final = dato;
				fichero >> dato;
				Q_[Qactual].n_transiciones = dato;
				
				Q_[Qactual].simbolo = new char [Q_[Qactual].n_transiciones];
				Q_[Qactual].destino = new int [Q_[Qactual].n_transiciones];
				
				for(int i=0; i<Q_[Qactual].n_transiciones; i++){
					fichero >> simbolo;
					Q_[Qactual].simbolo[i] = simbolo;
					fichero >> dato;
					Q_[Qactual].destino[i] = dato;
				}
				
				if(Qactual == 0){
					alfabeto_ = new char [Q_[Qactual].n_transiciones];
					for(int a=0; a<Q_[Qactual].n_transiciones; a++){
						alfabeto_[a] = Q_[Qactual].simbolo[a];
					}
				}
			}
			
			for(int i=0; i<nQ_; i++){
				for(int j=0; j<Q_[i].n_transiciones; j++){
					existealfa=false;
					for(int z=0; z<Q_[i].n_transiciones; z++){
						if(Q_[i].simbolo[j] == alfabeto_[z])
							existealfa=true;
					}
					if(existealfa == false)
						error = 1;
				}
			}
			
			for(int i=0; i<nQ_; i++){
				if(Q_[0].n_transiciones != Q_[i].n_transiciones)
					error = 1;
			}
			
			for(int i=0; i<nQ_; i++){
				for(int j=0; j<Q_[i].n_transiciones; j++){
					for(int z=0; z<Q_[i].n_transiciones; z++){
						if(j != z){
							if(Q_[i].simbolo[j] == Q_[i].simbolo[z])
								error = 1;
						}
					}
				}
			}
			
			if(error == 1)
				cout << "Error en la definicion del DFA." << endl;
		}
}
	
	
DFA::~DFA(void){
	for(int i=0; i<nQ_; i++){
		if(Q_[i].simbolo != NULL){
			delete [] Q_[i].simbolo;
			Q_[i].simbolo = NULL;
		}
		if(Q_[i].destino != NULL){
			delete [] Q_[i].destino;
			Q_[i].destino = NULL;
		}
	}	
	if(Q_ != NULL){
		delete [] Q_;
		Q_ = NULL;
	}
}

void DFA::leer(char nombrefichero[], int &error){
		ifstream fichero;
		fichero.open(nombrefichero);
		
		if(!fichero.is_open()){
			cout << "Error de apertura." << endl;
			error = 1;
		}
		
		else{
			fichero >> nQ_;
			Q_ = new Estructura [nQ_];
			
			fichero >> iQ_;
			
			int Qactual; int dato; char simbolo; bool existealfa;
			
			for(int i=0; i<nQ_; i++){
				fichero >> Qactual;
				
				fichero >> dato;
				Q_[Qactual].es_final = dato;
				fichero >> dato;
				Q_[Qactual].n_transiciones = dato;
				
				Q_[Qactual].simbolo = new char [Q_[Qactual].n_transiciones];
				Q_[Qactual].destino = new int [Q_[Qactual].n_transiciones];
				
				for(int i=0; i<Q_[Qactual].n_transiciones; i++){
					fichero >> simbolo;
					Q_[Qactual].simbolo[i] = simbolo;
					fichero >> dato;
					Q_[Qactual].destino[i] = dato;
				}
				
				if(Qactual == 0){
					alfabeto_ = new char [Q_[Qactual].n_transiciones];
					for(int a=0; a<Q_[Qactual].n_transiciones; a++){
						alfabeto_[a] = Q_[Qactual].simbolo[a];
					}
				}
			}
			
			for(int i=0; i<nQ_; i++){
				for(int j=0; j<Q_[i].n_transiciones; j++){
					existealfa=false;
					for(int z=0; z<Q_[i].n_transiciones; z++){
						if(Q_[i].simbolo[j] == alfabeto_[z])
							existealfa=true;
					}
					if(existealfa == false)
						error = 1;
				}
			}
			
			for(int i=0; i<nQ_; i++){
				if(Q_[0].n_transiciones != Q_[i].n_transiciones)
					error = 1;
			}
			
			for(int i=0; i<nQ_; i++){
				for(int j=0; j<Q_[i].n_transiciones; j++){
					for(int z=0; z<Q_[i].n_transiciones; z++){
						if(j != z){
							if(Q_[i].simbolo[j] == Q_[i].simbolo[z])
								error = 1;
						}
					}
				}
			}
			
			if(error == 1)
				cout << "Error en la definicion del DFA." << endl;
		}
}

void DFA::mostrar(void){
	cout << nQ_ << endl;
	cout << iQ_ << endl;
	for(int i=0; i<nQ_; i++){
		cout << i << " " << Q_[i].es_final << " " << Q_[i].n_transiciones << " ";
		for(int j=0; j<Q_[i].n_transiciones; j++){
			cout << Q_[i].simbolo[j] << " " << Q_[i].destino[j] << " ";
		}
		cout << endl;
	}
}

void DFA::estadosmuerte(void){
	bool existe = false;
	for(int i=0; i<nQ_; i++){
		bool destinosiguales = true;
		for(int j=0; j<Q_[i].n_transiciones; j++){
			if(Q_[i].destino[j] != i){
				destinosiguales = false;
			}
		}
		if(destinosiguales == true){
			cout << "El estado " << i << " es un estado de muerte." << endl;
			existe = true;
		}
	}
	if(existe == false)
		cout << "No presenta estados de muerte." << endl;
}

void DFA::analizar(char cadena[]){
	int actual = iQ_; 
	int siguiente = iQ_;
	bool existealfa;
	bool error=false;
	
	for(int i=0; i<strlen(cadena); i++){
		existealfa=false;
		for(int j=0; j<Q_[0].n_transiciones; j++){
			if(cadena[i] == alfabeto_[j])
				existealfa=true;
		}
		if(existealfa == false){
			error=true;
			cout << "La cadena introducida presenta simbolos que no estan en el alfabeto." << endl;
		}
			
	}
	
	if(error == false){
		cout << "Cadena de entrada: " << cadena << endl;
		cout << "Estado actual			Entrada			Siguiente estado" << endl;
		
		for(int i=0; i<strlen(cadena); i++){
			actual = siguiente;
			for(int j=0; j<Q_[actual].n_transiciones; j++){
				if(Q_[actual].simbolo[j] == cadena[i])
					siguiente = Q_[actual].destino[j];
			}
			cout << actual << "				" << cadena[i] << "				" << siguiente << endl;
		}
		
		if(Q_[siguiente].es_final == 1)
			cout << "Cadena de entrada ACEPTADA." << endl;
		else
			cout << "Cadena de entrada NO ACEPTADA." << endl;
	}
}