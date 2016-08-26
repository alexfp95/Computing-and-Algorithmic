#include <fstream>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#include "TM.h"

TM::TM(char nombrefichero [], int &error):
	nQ_(0),
	Qfinal_(0),
	ntuplas_(0),
	tuplas_(NULL),
	cinta_(){
			
		char * pch; char extension[] = ".TM";
		
		pch = strchr(nombrefichero,'.');
		if(pch == NULL){
			cerr << "Error en la extension del fichero." << endl;
			error = 1;
		}
		else{
			if(strcmp(pch, extension) != 0){
				cerr << "Error en la extension del fichero." << endl;
				error = 1;
			}
		}
		
		if(error != 1){
	
			ifstream fichero;
			fichero.open(nombrefichero);
			
			if(!fichero.is_open()){
				cerr << "Error de apertura." << endl;
				error = 1;
			}
			
			else{
				int nlineas=0; char var;
				
				fichero >> nQ_; nlineas++;
				fichero >> Qfinal_; nlineas++;
				
				fichero >> ntuplas_; nlineas++;
				tuplas_ = new Tuplas [ntuplas_];
				
				for(int i=0; i<ntuplas_; i++){
					fichero >> tuplas_[i].Qactual;
					fichero >> var;
					tuplas_[i].entrada = (int)var;
					fichero >> var;
					tuplas_[i].escribe = (int)var;
					fichero >> tuplas_[i].mov;
					fichero >> tuplas_[i].Qsiguiente; nlineas++;
				}
				
				if(nlineas != (3 + ntuplas_)){
					cerr << "Error en el formato del fichero." << endl;
					error = 1;
				}
			}
		}
}

TM::~TM(void){
	if(tuplas_ != NULL){
		delete [] tuplas_;
		tuplas_ = NULL;
	}
}

void TM::leer(char nombrefichero[], int &error){
		char * pch; char extension[] = ".TM";
		
		pch = strchr(nombrefichero,'.');
		if(pch == NULL){
			cerr << "Error en la extension del fichero." << endl;
			error = 1;
		}
		else{
			if(strcmp(pch, extension) != 0){
				cerr << "Error en la extension del fichero." << endl;
				error = 1;
			}
		}
		
		if(error != 1){
	
			ifstream fichero;
			fichero.open(nombrefichero);
			
			if(!fichero.is_open()){
				cerr << "Error de apertura." << endl;
				error = 1;
			}
			
			else{
				int nlineas=0; char var;
				
				fichero >> nQ_; nlineas++;
				fichero >> Qfinal_; nlineas++;
				
				fichero >> ntuplas_; nlineas++;
				tuplas_ = new Tuplas [ntuplas_];
				
				for(int i=0; i<ntuplas_; i++){
					fichero >> tuplas_[i].Qactual;
					fichero >> var;
					tuplas_[i].entrada = (int)var;
					fichero >> var;
					tuplas_[i].escribe = (int)var;
					fichero >> tuplas_[i].mov;
					fichero >> tuplas_[i].Qsiguiente; nlineas++;
				}
				
				if(nlineas != (3 + ntuplas_)){
					cerr << "Error en el formato del fichero." << endl;
					error = 1;
				}
			}
		}
}

void TM::mostrar(void){
	cout << nQ_ << endl;
	cout << Qfinal_ << endl;
	cout << ntuplas_ << endl;

	for(int i=0; i<ntuplas_; i++){
		cout << tuplas_[i].Qactual << " " << (char)tuplas_[i].entrada << " " << (char)tuplas_[i].escribe << " " << tuplas_[i].mov << " " << tuplas_[i].Qsiguiente << endl;
	}
}

void TM::simular(char cadena[]){
	int estadoactual=0; int existet=1;
	nodo_t* bin = new nodo_t(36);
	nodo_t* bfi = new nodo_t(36);
	int szcadena = strlen(cadena);
	
	cinta_.insertar_final(bin);
	for(int i=0; i<szcadena; i++){
		nodo_t* aux = new nodo_t((int)cadena[i]);
		cinta_.insertar_final(aux);
	}
	cinta_.insertar_final(bfi);

	cout << "Estado actual: q" << estadoactual << "   "; imprimir();
	
	cinta_.set_posicion(cinta_.get_inicio());
	
	while(existet==1){
		existet=0;
		for(int i=0; i<ntuplas_; i++){
			if(tuplas_[i].Qactual == estadoactual){
				if(tuplas_[i].entrada == cinta_.get_dato()){
					existet=1;
					cinta_.set_dato(tuplas_[i].escribe);
					cinta_.mov_posicion(tuplas_[i].mov);
					estadoactual = tuplas_[i].Qsiguiente;
					cout << "Estado actual: q" << estadoactual << "   "; imprimir();
				}
			}
		}
	}
	
	if(estadoactual >= Qfinal_)
		cout << "Cadena aceptada." << endl;
	else
		cout << "Cadena rechazada." << endl;
		
	cinta_.~lista_t();
		
}

void TM::imprimir(){
	cout << "...";
	cinta_.write(cout);
	cout << "..." << endl;
}