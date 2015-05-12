#include "../../include/tree.h"

void inicializarNodo(arbol **miNodo) {
	int i;

	for (i = 0; LONG_PRODUCCIONES > i; ++i) {
		(*miNodo)->hijo[i] = NULL;
	}
}

void inicializarArbol(int indToken, arbol **miArbol) {
	if ((*miArbol = (arbol *) malloc (sizeof(arbol))) == NULL) {
		printf("\n[Error] No se puedo asignar memoria para el arbol de derivacion.\n");
		exit(1);
	}

	token_t token;
	token.indToken = indToken;
	token.indTS = 0;

	inicializarNodo(miArbol);
	(*miArbol)->padre = NULL;
	(*miArbol)->token = token;
}

void agregarNodoAlArbol(token_t token, arbol **miNodo) {
	arbol *nuevoNodo;

	if ((nuevoNodo = (arbol *) malloc (sizeof(arbol))) == NULL) {
		printf("\n[Error] No se puedo asignar memoria para el nodo \"%d\" en el arbol de derivacion.\n", token.indToken);
		exit(1);
	}

	inicializarNodo(&nuevoNodo);
	nuevoNodo->padre = *miNodo;
	nuevoNodo->visible = true;
	nuevoNodo->token = token;

	int i;
	for (i = 0; (*miNodo)->hijo[i] != NULL; ++i) {}

	(*miNodo)->hijo[i] = nuevoNodo;
}

void avanzarEnArbol(int numeroNodo, arbol **miNodo) {
	*miNodo = (*miNodo)->hijo[numeroNodo];
}

void retrocederEnArbol(arbol **miNodo) {
	*miNodo = (*miNodo)->padre;
}

void eliminarTodosLosHijos(arbol **miNodo) {
	int i;
	for (i = 0; LONG_PRODUCCIONES > i; ++i) {
		if ((*miNodo)->hijo[i] != NULL) {
			avanzarEnArbol(i, miNodo);
			eliminarTodosLosHijos(miNodo);
			retrocederEnArbol(miNodo);
			free((*miNodo)->hijo[i]);
			(*miNodo)->hijo[i] = NULL;
		}
	}
}

void agregarProduccionAlArbol(int produccion[LONG_PRODUCCIONES], arbol **miNodo) {
	int i;
	token_t token;

	for (i = 1; (LONG_PRODUCCIONES > i) && (produccion[i] != -1); ++i) {
		token.indToken = produccion[i];
		token.indTS = 0;
		agregarNodoAlArbol(token, miNodo);
	}
}
