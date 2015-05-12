#include "../../include/list.h"

void avanzarEnLista(lista **miLista) {
	*miLista = (*miLista)->siguiente;
}

void retrocederEnLista(lista **miLista, int indiceFinal) {
	int i;

	for (i = (*miLista)->indice; i != indiceFinal; --i) {
		*miLista = (*miLista)->anterior;
	}
}

void inicializarLista(lista **miLista) {
	*miLista = NULL;
}

void agregarAlFinal(token_t token, lista **miLista) {
	static int ind = 0;
	lista *nuevoNodo, *auxNodo;

	if ((nuevoNodo = (lista *) malloc (sizeof(lista))) == NULL) {
		printf("\n[Error] No se puedo asignar memoria para el token \"%d\" en la lista de tokens.\n", token.indToken);
		exit(1);
	}

	nuevoNodo->indice = ind++;
	nuevoNodo->token = token;
	nuevoNodo->anterior = NULL;	
	nuevoNodo->siguiente = NULL;

	auxNodo = *miLista;
	if (auxNodo != NULL) {
		while (auxNodo->siguiente != NULL) {
			avanzarEnLista(&auxNodo);
		}
		nuevoNodo->anterior = auxNodo;
		auxNodo->siguiente = nuevoNodo;
	} else {
		(*miLista) = nuevoNodo;
	}
}
