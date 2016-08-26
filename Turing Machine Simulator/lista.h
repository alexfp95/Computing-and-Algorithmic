#pragma once
#include "nodo.h"
#include <cstdio>
#include <iostream>

using namespace std;

class lista_t {
	private:
		nodo_t* inicio_; 
		nodo_t* fin_;
		nodo_t* posicion_;
	public:
		lista_t (void);
		 ~lista_t (void);
		bool empty (void);
		void write (ostream& os);
		void insertar_empty (nodo_t* nodo);
		void insertar_inicio (nodo_t* nodo);
		void insertar_final (nodo_t* nodo);
		nodo_t* extraer_inicio (void);
		void mov_posicion(char mov);
		void set_posicion(nodo_t* nodo);
		void set_dato(int x);
		int get_dato(void);
		nodo_t* get_inicio(void);
};