#include "lista.h"

typedef struct{
	int Qactual;
	int entrada;
	int escribe;
	char mov;
	int Qsiguiente;
} Tuplas;

class TM{
private:
	int nQ_;
	int Qfinal_;
	int ntuplas_;
	Tuplas* tuplas_;
	lista_t cinta_;
public:
	TM(char nombrefichero[], int &error);
	~TM(void);
	void leer(char nombrefichero[], int &error);
	void mostrar(void);
	void simular(char cadena[]);
	void imprimir(void);
};