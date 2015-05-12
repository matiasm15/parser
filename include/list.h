
#ifndef LIST_H_
	
	#define LIST_H_
	#include "compiler.h"

	typedef struct elemLista {
		struct elemLista *anterior;
		int indice;
		token_t token;
		struct elemLista *siguiente;
	} lista;

	void avanzarEnLista(lista **);

	void retrocederEnLista(lista **, int);

	void inicializarLista(lista **);

	void agregarAlFinal(token_t, lista **);

#endif
