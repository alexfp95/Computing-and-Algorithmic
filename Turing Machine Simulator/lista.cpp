#include "lista.h"

using namespace std;

lista_t::lista_t (void):
	inicio_(NULL),
	fin_(NULL),
	posicion_(NULL){}

lista_t::~lista_t (void){ 
	nodo_t* aux = inicio_;
	while(inicio_ != NULL){
		inicio_ = inicio_->get_next();
		delete aux;
		aux = inicio_;
	}
}

bool lista_t::empty (void){
	if(inicio_ == NULL) return true;
	else return false;
}

void lista_t::write(ostream& os){
	nodo_t* aux = inicio_;
	while(aux != NULL){ 
		aux->write(os);
		aux = aux->get_next();
	}
}

void lista_t::insertar_empty(nodo_t* nodo){
	inicio_ = nodo;
	fin_ = nodo;
}

void lista_t::insertar_inicio(nodo_t* nodo){
	if(empty()) 
		insertar_empty(nodo);
	else{
		nodo->set_next(inicio_);
		inicio_->set_prev(nodo);
		inicio_ = nodo;
	}
}

void lista_t::insertar_final(nodo_t* nodo){
	if(empty())
		insertar_empty(nodo);
	else{
		fin_->set_next(nodo);
		nodo->set_prev(fin_);
		fin_ = nodo;
	}
}

nodo_t* lista_t::extraer_inicio(void){
	if(inicio_ == fin_){ 
		nodo_t* aux = inicio_;
		inicio_ = NULL; 
		fin_ = NULL; 
		return aux;
	}
	else{
		nodo_t* aux = inicio_;
		inicio_ = inicio_->get_next();
		return aux;
	}
}

void lista_t::mov_posicion(char mov){
	if(mov == 'R'){
		if(posicion_ == fin_){
			nodo_t* aux = new nodo_t(36);
			insertar_final(aux);
			posicion_ = posicion_->get_next();
		}
		else
			posicion_ = posicion_->get_next();
	}
	
	if(mov == 'L')
		if(posicion_ == inicio_){
			nodo_t* aux = new nodo_t(36);
			insertar_inicio(aux);
			posicion_ =  posicion_->get_prev();
		}
		else
			posicion_ =  posicion_->get_prev();
}

void lista_t::set_dato(int x){
	posicion_->set_dato(x);
}

int lista_t::get_dato(void){
	return posicion_->get_dato();
}

void lista_t::set_posicion(nodo_t* nodo){
	posicion_ = nodo;
}

nodo_t* lista_t::get_inicio(){
	return inicio_->get_next();
}