#include "../../include/parser.h"

bool esFinDeCadena(lista *listaToken) {
	return (listaToken->token.indToken == -1);
}

int darProduccionesPorSimbolo(int indProducciones[CANT_PRODUCCIONES], int simbolo, int producciones[CANT_PRODUCCIONES][LONG_PRODUCCIONES]) {
	int i;
	int cantidadProducciones = 0;

	for (i = 0; CANT_PRODUCCIONES > i; ++i) {
		if (producciones[i][0] == simbolo) {
			indProducciones[cantidadProducciones] = i;
			++cantidadProducciones;
		}
	}

	return cantidadProducciones;
}

void procesar(gram *gramatica, lista **listaToken, arbol **miArbol) {
	int i;

	for (i = 0; (*miArbol)->hijo[i] != NULL; ++i) {
		avanzarEnArbol(i, miArbol);
		if ((*miArbol)->token.indToken >= CANT_SIMBOLOS) {
			pSubN((*miArbol)->token.indToken, gramatica, listaToken, miArbol);

 			if (error) {
				return;
			}
		} else {
			if ((*miArbol)->token.indToken != (*listaToken)->token.indToken) {
				error = true;
				return;
			}

			avanzarEnLista(listaToken);
		}

		retrocederEnArbol(miArbol);
	}
}

void pSubN(int simbolo, gram *gramatica, lista **listaToken, arbol **miArbol) {
	int indToken = (*listaToken)->indice;
	int indProducciones[CANT_PRODUCCIONES];
	int cantidadProducciones = darProduccionesPorSimbolo(indProducciones, simbolo, gramatica->producciones);

	int i;
	for (i = 0; cantidadProducciones > i; ++i) {
		agregarProduccionAlArbol(gramatica->producciones[indProducciones[i]], miArbol);

		error = false;
		procesar(gramatica, listaToken, miArbol);
		if (error == false) {
			return;
		}

		retrocederEnArbol(miArbol);
		eliminarTodosLosHijos(miArbol);
		retrocederEnLista(listaToken, indToken);
	}
}
