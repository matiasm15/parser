
#ifndef GRAMMAR_H_

	#define GRAMMAR_H_
	#define CANT_SIMBOLOS 150
	#define CANT_PRODUCCIONES 250
	#define LONG_SIMBOLO 50
	#define LONG_PRODUCCIONES 50

	typedef struct {
		int indToken;
		int indTS;
	} token_t;

	typedef struct {
		int simboloDistiguido;
		int producciones[CANT_PRODUCCIONES][LONG_PRODUCCIONES];
	} gram;

	enum {
		ID_FUNCION, ID_VARIABLE, CONST_ENTERA, ABRIR_PAR, CERRAR_PAR, ABRIR_LL, CERRAR_LL, SUMA, MULT, MENOS, OR, AND, NO,
		VERDADERO, FALSO, PARA, DESDE, HASTA, SI, ENTONCES, ASIGN, IGUAL, MENOR,
		MAYOR, MENOR_IGUAL, MAYOR_IGUAL, COMA, PUNTO_COMA, ENTERO, LOGICO, REGRESAR, ERROR
	};

	enum {
		P = CANT_SIMBOLOS, DV, DF, LC, TIPO, LP, LPCont, CAsignacion,
		CPara, CSiEntonces, CLLamadoFuncion, LLPar, LLParCont, EXP_ENTERA, TERMINO, FACTOR, EXP_LOGICA, OperandoLogico,
		FACTOR_LOGICO, CONST_LOGICA, COMPARACION, OPERADOR, Nuevo_NT_A
	};

	void inicializarProducciones(int [CANT_PRODUCCIONES][LONG_PRODUCCIONES]);

	void definirGramatica(gram *);

#endif
