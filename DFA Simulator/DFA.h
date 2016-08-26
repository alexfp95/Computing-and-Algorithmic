typedef struct{
	int es_final;
	int n_transiciones;
	char* simbolo;
	int* destino;
} Estructura;


class DFA{
private:
	int nQ_;
	int iQ_;
	Estructura* Q_;
	char* alfabeto_;
public:
	DFA(char nombrefichero[], int &error);
	~DFA(void);
	void leer(char nombrefichero[], int &error);
	void mostrar(void);
	void estadosmuerte(void);
	void analizar(char cadena[]);
};