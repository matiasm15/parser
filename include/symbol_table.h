
#ifndef SYMBOL_TABLE_H_

	#define SYMBOL_TABLE_H_
	#include "compiler.h"

	typedef struct {
		int indToken;
		char lexema[LONG_SIMBOLO];
		int tipo; 
	} elemTS_t;

	typedef elemTS_t tablaSimbolos_t[CANT_SIMBOLOS];

	extern tablaSimbolos_t tablaSimbolos;

	void inicializarTS();

	void agregarTokenTS(token_t *, char *);

	int darIndiceTS(char *);

#endif
