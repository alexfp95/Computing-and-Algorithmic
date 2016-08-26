#include "nodo.h"

using namespace std;

nodo_t::nodo_t (int x):
	next_(NULL),
	dato_(x){}

nodo_t::~nodo_t (void){}

void nodo_t::set_next (nodo_t* x){
	next_ = x;
}

nodo_t* nodo_t::get_next (void){
	return next_;
}

void nodo_t::set_prev(nodo_t* x){
	prev_ = x;
}

nodo_t* nodo_t::get_prev (void){
	return prev_;
}

void nodo_t::set_dato (int x){
	dato_ = x;
}

int nodo_t::get_dato (void){
	return dato_;
}

void nodo_t::write(ostream& os){
	os << (char)dato_;
}