
#ifndef TREE_H_

	#define TREE_H_
	#include "compiler.h"

	typedef struct elemNodo {
		struct elemNodo *padre;
		token_t token;
		bool visible;
		struct elemNodo *hijo[LONG_PRODUCCIONES];
	} arbol;

	void inicializarNodo(arbol **);

	void inicializarArbol(int, arbol **);

	void agregarNodoAlArbol(token_t, arbol **);

	void avanzarEnArbol(int, arbol **);

	void retrocederEnArbol(arbol **);

	void eliminarTodosLosHijos(arbol **);

	void agregarProduccionAlArbol(int [LONG_PRODUCCIONES], arbol **);

#endif
