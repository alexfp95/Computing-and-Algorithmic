#pragma once
#include <cstdio>
#include <iostream>

using namespace std;

class nodo_t{
	private:
		nodo_t* next_;
		nodo_t* prev_;
		int dato_;
	public:
		nodo_t (int x);
		~nodo_t (void);
		void set_next (nodo_t* next);
		nodo_t* get_next (void);
		void set_prev (nodo_t* prev);
		nodo_t* get_prev (void);
		void set_dato (int x);
		int get_dato (void);
		void write (ostream& os);
};