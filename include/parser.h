
#ifndef PARSER_H_

	#define PARSER_H_
	#include "compiler.h"

	extern bool error;

	bool esFinDeCadena(lista *);

	int darProduccionesPorSimbolo(int [CANT_PRODUCCIONES], int, int [CANT_PRODUCCIONES][LONG_PRODUCCIONES]);

	void pSubN(int, gram *, lista **, arbol **);

	void procesar(gram *, lista **, arbol **);

#endif
